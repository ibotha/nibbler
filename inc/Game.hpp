/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:12:47 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/31 14:53:53 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRenderer.hpp"
#include "Snoekie.hpp"
#include "Food.hpp"
#include "Exceptions.hpp"

typedef std::chrono::milliseconds t_milli;
typedef IRenderer *(*fun_t)(int, int, std::string const &);

class Game
{
public:
	Game(int width, int height, std::string name, int fps);
	Game(const Game &);
	Game &operator=(const Game &);
	~Game();

	static Game *Get();
	static void Set(Game *g);

	void GetInput();
	void Update();
	void Render();

	void KillSnake();

	void LoadDLL(std::string const &path);

	void Run();

private:
	static Game *s_Instance;
	Snoekie *s;
	Food	*f;

	Game();
	t_milli getCurrentTime();

	int m_FPS;
	int m_Width;
	int m_Height;
	int	score;
	std::string m_Name;
	IRenderer *m_Renderer;
	void *m_DLLHandle;
	int xv, yv;
	int m_Difficulty;
	fun_t m_CreateFun;
};
