/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:38:36 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/31 14:09:02 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibblerpch.hpp"
#include "Game.hpp"

int main(int ac, char *av[])
{
	srand(time(NULL));
	try
	{
		if (ac == 3)
			Game::Set(new Game(std::stoi(av[1]), std::stoi(av[2]), "Nibbler", 300));
		else
			Game::Set(new Game(50, 50, "Nibbler", 300));
		Game::Get()->Run();
	}
	catch(const Exceptions::LibraryNotFound& e)
	{
		std::cerr << e.what() << '\n';
	}
}
