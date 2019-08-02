/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:20:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/08/02 09:29:23 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibblerpch.hpp"
#include "Game.hpp"
#include "Snoekie.hpp"

Game *Game::s_Instance;

t_milli Game::getCurrentTime()
{
	return std::chrono::duration_cast<t_milli>(
		std::chrono::system_clock::now().time_since_epoch()
	);
}

Game::Game(int width, int height, std::string name, int fps)
	:m_FPS(fps), m_Width(width), m_Height(height), score(0), m_Name(name), m_DLLHandle(nullptr)
{
	m_Width = std::clamp(width, 10, SCREEN_W / 2);
	m_Height = std::clamp(height, 10, SCREEN_H / 2);
	LoadDLL("lib/libOpengl.so");
	m_Renderer = m_CreateFun(m_Width, m_Height, name);
	if (!m_Renderer)
		throw std::exception();
	m_Difficulty = 5;
	s = new Snoekie(m_Renderer);
	f = new Food(Vec((rand() % (m_Width)), (rand() % (m_Height)), 0));
	m_Techno = false;
}

Game::Game()
{
}

Game *Game::Get()
{
	return s_Instance;
}

void Game::Set(Game *game)
{
	s_Instance = game;
}

void Game::KillSnake()
{
	std::fstream SomeFileToHoldScore;
	SomeFileToHoldScore.open("score.txt");
	int highscore = 0;
	SomeFileToHoldScore >> highscore;
	SomeFileToHoldScore.close();
	SomeFileToHoldScore.open("score.txt");
	std::cout << "\033[0;35mCongratulations!!! you scored a total " << this->score << " points!!\033[0;0m" << std::endl;
	if (this->score <= highscore)
		std::cout << "\033[0;31mYou couldn't even beat the highscore, LOSER!!!\033[0;0m" << std::endl;
	else
	{
		std::cout << "\033[0;32mYou managed to beat the highscore!!! wtf!\033[0;0m" << std::endl;
		SomeFileToHoldScore << std::to_string(this->score);
	}
	m_Renderer->SetShouldClose(1);
}

Game::Game(const Game &rhs)
{
	*this = rhs;
}

Game &Game::operator=(const Game &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

Game::~Game()
{
	delete m_Renderer;
}

void Game::GetInput()
{
	m_Renderer->GetInput();
}

void Game::Update()
{
	static int lxv = xv, lyv = yv;
	static int tick = 100;
	try
	{
		std::stringstream ss;
		if (m_Renderer->GetKey(NB_KEY_1) == NB_PRESS)
		{
			delete m_Renderer;
			LoadDLL("lib/libOpengl.so");
			ss << m_Name << " ::OpenGL::";
			m_Renderer = m_CreateFun(m_Width, m_Height, ss.str());
		}
		if (m_Renderer->GetKey(NB_KEY_2) == NB_PRESS)
		{
			delete m_Renderer;
			LoadDLL("lib/libSDL.so");
			ss << m_Name << " ::SDL::";
			m_Renderer = m_CreateFun(m_Width, m_Height, ss.str());
		}
		if (m_Renderer->GetKey(NB_KEY_3) == NB_PRESS)
		{
			delete m_Renderer;
			LoadDLL("lib/libSFML.so");
			ss << m_Name << " ::SFML::";
			m_Renderer = m_CreateFun(m_Width, m_Height, ss.str());
		}
	} catch (const std::exception &e)
	{
		throw Exceptions::LibraryNotFound(e.what());
	}
	if (m_Renderer->GetKey(NB_KEY_UP) == NB_PRESS && !(lyv < 0))
	{
		xv = 0;
		yv = 1;
	}
	else if (m_Renderer->GetKey(NB_KEY_DOWN) == NB_PRESS && !(lyv > 0))
	{
		xv = 0;
		yv = -1;
	}
	else if (m_Renderer->GetKey(NB_KEY_LEFT) == NB_PRESS && !(lxv > 0))
	{
		yv = 0;
		xv = -1;
	}
	else if (m_Renderer->GetKey(NB_KEY_RIGHT) == NB_PRESS && !(lxv < 0))
	{
		yv = 0;
		xv = 1;
	}
	static int timestep = 0;
	if (timestep > 25)
	{
		timestep = 0;
		if (m_Techno)
			(this->m_Tick == 1) ? m_Renderer->SetClearColour({0.3, 0.3, 0.7, 1}) : m_Renderer->SetClearColour({0.3,0.7,0.6, 1});
		else
			m_Renderer->SetClearColour({0,0,0,1});
		if (m_Tick == 1) m_Tick = 0; else m_Tick = 1;
	}
	timestep++;
	if ((tick += m_Difficulty) >= 100)
	{
		lxv = xv, lyv = yv;
		tick = 0;

		bool overFood = (f) ? s->collision(f) : false;
		s->Move({static_cast<int>(xv), static_cast<int>(yv), 0}, overFood);
		if (overFood)
		{
			this->score += (m_Techno) ? 2 : 1;
			this->m_Difficulty += 5;
			delete f;
			f = nullptr;
		}
		if (f == nullptr)
			f = new Food(Vec((rand() % (m_Width)), (rand() % (m_Height)), 0));
		if(s->inBounds(s->getSnoekie().back() + Vec<int>({xv, yv, 0})))
			KillSnake();
		if (m_Renderer->GetKey(NB_KEY_SPACE))
		{
		}
		s->Update(m_Renderer);
		if (this->score >= 4 && !m_Techno)
			m_Techno = true;
	}
}

void Game::Render()
{
	f->Render(m_Renderer);
	s->Render(m_Renderer);
}

void Game::Run()
{
	m_Renderer->SetClearColour({1, 1, 1, 1});

	xv = 1;
	yv = 0;
	t_milli t1, t2;
	double mspf = (1 / (double)m_FPS) * 1000;
	t1 = getCurrentTime();


	while(!m_Renderer->ShouldClose())
	{
		t2 = getCurrentTime();
		double diff = t2.count() - t1.count();
		while (diff < mspf)
		{
			t2 = getCurrentTime();
			diff = t2.count() - t1.count();
		}
		t1 = t2;
		m_Renderer->BeginFrame();

		GetInput();
		Update();
		Render();

		if (m_Renderer->GetKey(NB_KEY_ESCAPE) == NB_PRESS)
			m_Renderer->SetShouldClose(1);
		m_Renderer->EndFrame();
	}
}

void Game::LoadDLL(std::string const &path)
{
	if (m_DLLHandle)
		dlclose(m_DLLHandle);
	m_DLLHandle = dlopen(path.c_str(), RTLD_NOW | RTLD_GLOBAL);
	char* lError = dlerror();
	if (lError)
		throw Exceptions::LibraryNotFound(lError);
	*(void **)(&m_CreateFun) = dlsym(m_DLLHandle, "CreateRenderer");
	lError = dlerror();
	if (lError)
		throw Exceptions::LibraryNotFound(lError);
}
