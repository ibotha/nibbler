/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snoekie.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:50:11 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/08 08:38:14 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snoekie.hpp"
#include <iostream>

Snoekie::Snoekie(void){
	for(int i = 0; i < 4; i++)
	{
		Vec s;
		s.x = i;
		s.y = i;
		this->Body.push_back(s);
	}
}

Snoekie::Snoekie(Snoekie const& rhs) {
	this->Body = rhs.Body;
}

Snoekie::~Snoekie(void) {
    
}

Snoekie 	&Snoekie::operator=(const Snoekie& rhs) {
	this->Body = rhs.Body;
	return *this;
}

bool 		Snoekie::eatFood(Vec pos) {
    Vec		head;

	head = this->Body.front();
	return (collision(pos));	
}

void 		Snoekie::grow(void) {
	 Vec		body;

	body = this->Body.back();
	this->Body.push_back(body);
}

void 		Snoekie::shrink(void) {
//		if (collision({0, 0, 0}))
//			this->Body.pop_back();
}

bool 		Snoekie::collision(Vec col) {
    Vec		head;

	head = this->Body.front();
	return (head.x == col.x && head.y == col.y);
}

std::vector<Vec>		Snoekie::getSnoekie(void) { return this->Body; }

void 		Snoekie::Move(Vec dir) {
    Vec		body;

	body = this->Body.back();
	Vec N = {body.x + dir.x, body.y + dir.y, 0};
	std::cout << "moving to x::" << dir.x << " && y::" << dir.y << std::endl;
	this->Body.push_back(N);
	this->Body.erase(this->Body.begin());
}

void					Snoekie::Render(IRenderer *render) const
{
	for (auto a: this->Body)
		render->DrawSquare(a.x, a.y, {1, 0, 0, 1});	
}

void					Snoekie::Update(IRenderer *render) const
{
	(void)render;
}