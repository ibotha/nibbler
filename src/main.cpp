/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:38:36 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/31 11:11:37 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibblerpch.hpp"
#include "Game.hpp"

int main()
{
	srand(time(NULL));
	try
	{
		Game::Get()->Run();
	}
	catch(const Exceptions::LibraryNotFound& e)
	{
		std::cerr << e.what() << '\n';
	}
}
