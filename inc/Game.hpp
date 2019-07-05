/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:12:47 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/05 11:05:21 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRenderer.hpp"

typedef std::chrono::milliseconds t_milli;
typedef IRenderer *(*fun_t)(int, int, std::string const &);

class Game
{
public:
	Game(int width, int height, std::string name, int fps);
	Game(const Game &);
	Game &operator=(const Game &);
	~Game();

	void GetInput();
	void Update();
	void Render();

	void LoadDLL(std::string const &path);

	void Run();

private:
	Snoekie s;
	Game();
	t_milli getCurrentTime();
	
	int m_FPS;
	int m_Width;
	int m_Height;
	std::string m_Name;
	IRenderer *m_Renderer;
	void *m_DLLHandle;
	double x, y, xv, yv;
	fun_t m_CreateFun;
};
