/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snoekie.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:50:11 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/08 15:06:29 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snoekie.hpp"
#include <iostream>

Snoekie::Snoekie(void)
{
	for(int i = 0; i < 4; i++)
	{
		Vec<int> s(i, i, 0);
		this->Body.push_back(s);
	}
}

Snoekie::Snoekie(Snoekie const& rhs)
{
	this->Body = rhs.Body;
}

Snoekie::~Snoekie(void) {}

Snoekie 	&Snoekie::operator=(const Snoekie& rhs)
{
	this->Body = rhs.Body;
	return *this;
}

bool 		Snoekie::eatFood(Vec<int> pos)
{
    Vec<int>	head;

	head = this->Body.front();
	return (head == pos);
}

void 		Snoekie::grow(void)
{
	 Vec<int>		body;

	body = this->Body.back();
	this->Body.push_back(body);
}

void 		Snoekie::shrink(void) {}

std::vector<Vec<int>>		Snoekie::getSnoekie(void) { return this->Body; }

void 		Snoekie::Move(Vec<int> dir, bool overFood)
{
    Vec<int>		body;

	body = this->Body.back();
	Vec N(body.getX() + dir.getX(), body.getY() + dir.getY(), 0);
	this->Body.push_back(N);
	if (!overFood) this->Body.erase(this->Body.begin());
}

void					Snoekie::Render(IRenderer *render) const
{
	for (auto a: this->Body)
		render->DrawSquare(a.getX(), a.getY(), {1, 0, 0, 1});	
}

void					Snoekie::Update(IRenderer *render)
{
	(void)render;
}

bool					Snoekie::collision(IEntity *ent) const
{
	Vec<int> head = this->Body.back();
	if (!ent) return false;
	return (ent->inBounds(head));
}

bool					Snoekie::inBounds(Vec<int> pos) const
{
	Vec<int> head = this->Body.back();
	return (head == pos);
}