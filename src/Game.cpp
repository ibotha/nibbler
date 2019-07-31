/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:20:24 by ibotha            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/07/31 13:27:06 by jwolf            ###   ########.fr       */
=======
/*   Updated: 2019/07/31 11:27:42 by ibotha           ###   ########.fr       */
>>>>>>> f3bc33ab352ad65437f3c15772f4ec3c2a3ed355
/*                                                                            */
/* ************************************************************************** */

#include "nibblerpch.hpp"
#include "Game.hpp"
#include "Snoekie.hpp"

Game *Game::s_Instance = new Game(50, 50, "Nibbler", 300);

t_milli Game::getCurrentTime()
{
	return std::chrono::duration_cast<t_milli>(
		std::chrono::system_clock::now().time_since_epoch()
	);
}

Game::Game(int width, int height, std::string name, int fps)
	:m_FPS(fps), m_Width(width), m_Height(height), score(0), m_Name(name), m_DLLHandle(nullptr)
{
	LoadDLL("lib/libOpengl.so");
	m_Renderer = m_CreateFun(width, height, name);
	if (!m_Renderer)
		throw std::exception();
	m_Difficulty = 10;
}

Game::Game()
{
}

Game *Game::Get()
{
	return s_Instance;
}

void Game::KillSnake()
{
	std::cout << "Congratulations!!! you scored a total " << this->score << " points!!" << std::endl;
	if (this->score <=3)
		std::cout << "You couldn't even beat the highscore, LOSER!!!" << std::endl;
	else
		std::cout << "You managed to beat the highscore!!! wtf!" << std::endl;
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
		if (m_Renderer->GetKey(NB_KEY_1) == NB_PRESS && !(yv < 0))
		{
			delete m_Renderer;
			LoadDLL("lib/libOpengl.so");
			m_Renderer = m_CreateFun(m_Width, m_Height, m_Name);
		}
		if (m_Renderer->GetKey(NB_KEY_2) == NB_PRESS && !(yv < 0))
		{
			delete m_Renderer;
			LoadDLL("lib/libSDL.so");
			m_Renderer = m_CreateFun(m_Width, m_Height, m_Name);
		}
		if (m_Renderer->GetKey(NB_KEY_3) == NB_PRESS && !(yv < 0))
		{
			delete m_Renderer;
			LoadDLL("lib/libSFML.so");
			m_Renderer = m_CreateFun(m_Width, m_Height, m_Name);
		}
	} catch (const std::exception &e)
	{
		throw Exceptions::LibraryNotFound(e.what());
	}
	if (m_Renderer->GetKey(NB_KEY_UP) == NB_PRESS && !(lyv < 0))
	{
		xv = 0;
		yv = 1;
		//std::cout << "UP" << std::endl;
	}
	else if (m_Renderer->GetKey(NB_KEY_DOWN) == NB_PRESS && !(lyv > 0))
	{
		xv = 0;
		yv = -1;
		//std::cout << "DOWN" << std::endl;
	}
	else if (m_Renderer->GetKey(NB_KEY_LEFT) == NB_PRESS && !(lxv > 0))
	{
		yv = 0;
		xv = -1;
		//std::cout << "LEFT" << std::endl;
	}
	else if (m_Renderer->GetKey(NB_KEY_RIGHT) == NB_PRESS && !(lxv < 0))
	{
		yv = 0;
		xv = 1;
		//std::cout << "RIGHT" << std::endl;
	}
	if ((tick += m_Difficulty) >= 100)
	{
		lxv = xv, lyv = yv;
		tick = 0;

		bool overFood = (f) ? s.collision(f) : false;
		if (overFood)
		{
			this->score++;
			//this->m_Difficulty += 10;
			delete f;
			f = nullptr;
		}
		if (f == nullptr)
			f = new Food(Vec((rand() % (m_Width)), (rand() % (m_Height)), 0));
		if(s.inBounds(s.getSnoekie().back() + Vec<int>({xv, yv, 0})))
			KillSnake();
		s.Move({static_cast<int>(xv), static_cast<int>(yv), 0}, overFood);
		if (m_Renderer->GetKey(NB_KEY_SPACE))
		{
		}
		s.Update(m_Renderer);
	}
}

void Game::Render()
{
	s.Render(m_Renderer);
	f->Render(m_Renderer);
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
