/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:12:47 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/02 15:22:30 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Renderer.hpp"

typedef std::chrono::milliseconds t_milli;

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

	void Run();

private:
	Game();
	t_milli getCurrentTime();
	
	int m_FPS;
	std::string m_Name;
	Renderer *m_Renderer;
	double x, y, xv, yv;
};
