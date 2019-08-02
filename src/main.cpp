/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:38:36 by ibotha            #+#    #+#             */
/*   Updated: 2019/08/02 08:22:11 by jwolf            ###   ########.fr       */
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
		{
			std::stringstream ss;
			try
			{
				ss << "Nibbler - Custom Resolution" << std::stoi(av[1]) << "x" << std::stoi(av[2]);
				Game::Set(new Game(std::stoi(av[1]), std::stoi(av[2]), ss.str(), 300));
			}
			catch(const std::invalid_argument &e)
			{
				std::cout << "\033[0;31mInvalid Parameters passed :)\033[0;0m" << std::endl;
				std::cout << "\033[0;36mDefaulting to 50x50\033[0;0m" << std::endl;
				Game::Set(new Game(50, 50, "Nibbler - Default", 300));
			}
			catch(const std::out_of_range &e)
			{
				std::cout << "\033[0;31mInvalid Parameters passed :)\033[0;0m" << std::endl;
				std::cout << "\033[0;36mDefaulting to 50x50\033[0;0m" << std::endl;
				Game::Set(new Game(50, 50, "Nibbler - Default", 300));
			}
		}
		else
			Game::Set(new Game(50, 50, "Nibbler", 300));
		Game::Get()->Run();
	}
	catch(const Exceptions::LibraryNotFound& e)
	{
		std::cerr << e.what() << '\n';
	}
}
