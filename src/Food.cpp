/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:55:52 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/08 16:20:50 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibblerpch.hpp"
#include "Food.hpp"

Food::Food(void)
{
	this->respawn = true;
	this->LifeSpan = 30.0f;
}

Food::Food(Vec<int> pos)
{
	this->respawn = true;
	this->pos = pos;
	this->LifeSpan = 30.f;
}

Food::Food(Food const &cpy)
{
	*this = cpy;
}

Food	&Food::operator=(const Food &cpy)
{
	if (this != &cpy)
		*this = cpy;
	return *this;
}

Food::~Food(){}

void	Food::Render(IRenderer *render) const
{
	render->DrawSquare(this->pos.getX(), this->pos.getY(), {0, 1, 0, 1});
}

void	Food::Update(IRenderer *render)
{
	(void)render;
}

bool	Food::collision(IEntity *ent) const
{
	return (ent->inBounds(this->pos));
}

bool	Food::inBounds(const Vec<int> &pos) const
{
	return (this->pos == pos);
}