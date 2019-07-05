/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snoekie.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:33:10 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/05 13:01:46 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#define LIFESPAN 10

struct	Vec
{
	int		x;
	int		y;
	int		z;
};

struct Food
{
	Vec 	pos;
	double	LifeSpan;
};

class Snoekie
{
	public:
		Snoekie(void);
		~Snoekie(void);
		Snoekie(Snoekie const&);
		Snoekie &operator=(const Snoekie&);
		

		bool	eatFood(void);
		bool	collision(void);

		void	makeFood(void);
		void	grow(void);
		void	shrink(void);
		void	Move(Vec pos);
		 
		std::vector<Vec>	getSnoekie(void);

	private:
		std::vector<Vec> Body;
		Food			food;
		Vec				dir;

		
	protected:	
};