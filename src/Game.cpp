/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:20:24 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/05 13:10:14 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibblerpch.hpp"
#include "Game.hpp"
#include "Snoekie.hpp"

t_milli Game::getCurrentTime()
{
	return std::chrono::duration_cast<t_milli>(
		std::chrono::system_clock::now().time_since_epoch()
	);
}

Game::Game(int width, int height, std::string name, int fps)
	:m_FPS(fps), m_Width(width), m_Height(height),  m_Name(name), m_DLLHandle(nullptr)
{
	LoadDLL("lib/libOpengl.so");
	m_Renderer = m_CreateFun(width, height, name);
	if (!m_Renderer)
		throw std::exception();
}

Game::Game()
{
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
	if (m_Renderer->GetKey(NB_KEY_UP) == NB_PRESS && !(yv < 0))
	{
		xv = 0;
		yv = 1;
	}
	else if (m_Renderer->GetKey(NB_KEY_DOWN) == NB_PRESS && !(yv > 0))
	{
		xv = 0;
		yv = -1;
	}
	else if (m_Renderer->GetKey(NB_KEY_LEFT) == NB_PRESS && !(xv > 0))
	{
		yv = 0;
		xv = -1;
	}
	else if (m_Renderer->GetKey(NB_KEY_RIGHT) == NB_PRESS && !(xv < 0))
	{
		yv = 0;
		xv = 1;
	}

	y += yv;
	x += xv;

		

	s.Move(Vec{static_cast<int>(xv), static_cast<int>(yv), 0});

	if (x > m_Renderer->GetWidth() - 1)
		x = 0;
	if (y > m_Renderer->GetHeight() - 1)
		y = 0;
	if (x < 0)
		x = m_Renderer->GetWidth();
	if (y < 0)
		y = m_Renderer->GetHeight();

	if (m_Renderer->GetKey(NB_KEY_SPACE))
	{
	}
	if (s.collision())
	{
		//Die
	}
}

void Game::Render()
{
	auto snakes = s.getSnoekie();

	for (auto x: snakes)
	{
		m_Renderer->DrawSquare(x.x, x.y, {1,0,0,1});
	}
}

void Game::Run()
{
	m_Renderer->SetClearColour({1, 1, 1, 1});
	
	x = 0;
	y = 0;
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
	{
		dlclose(m_DLLHandle);
	}
	m_DLLHandle = dlopen(path.c_str(), RTLD_NOW | RTLD_GLOBAL);
	char* lError = dlerror();
	if (lError)
	{
		std::cout << "Error: " <<  lError << std::endl;
		throw std::exception();
	}
	*(void **)(&m_CreateFun) = dlsym(m_DLLHandle, "CreateRenderer");
	lError = dlerror();
	if (lError)
	{
		std::cout << "Error: " <<  lError << std::endl;
		throw std::exception();
	}
}