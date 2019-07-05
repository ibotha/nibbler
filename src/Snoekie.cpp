/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snoekie.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:50:11 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/05 11:08:39 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snoekie.hpp"

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
	this->food = rhs.food;
	this->Body = rhs.Body;
}

Snoekie::~Snoekie(void) {
    
}

Snoekie 	&Snoekie::operator=(const Snoekie& rhs) {
	this->food = rhs.food;
	this->Body = rhs.Body;
	return *this;
}

void 		Snoekie::makeFood(void) {
	if (eatFood)
	{
		Vec newPos;
		
		newPos.x = rand() % 50;
		newPos.y = rand() % 50;

		this->food.pos.x = newPos.x;
		this->food.pos.y = newPos.y;
		this->food.LifeSpan = LIFESPAN;
	}
}

bool 		Snoekie::eatFood(void) {
    Vec		head;

	head = this->Body.front();
	return (head.x == food.pos.x || head.y == food.pos.y);	
}

void 		Snoekie::grow(void) {
	 Vec		body;

	body = this->Body.back();
	body.x += dir.x;
	body.y += dir.y;
	body.z += dir.z;
	this->Body.push_back(body);
}

void 		Snoekie::shrink(void) {
		if (collision)
			this->Body.pop_back();
}

bool 		Snoekie::collision(void) {
    Vec		head;

	head = this->Body.front();
	for (auto a: this->Body)
	{
		if (
			head.x + 1 == a.x ||
			head.x - 1 == a.x ||
			head.y + 1 == a.y ||
			head.y - 1 == a.y 
		)
			return true;
	}
	return false;
}

auto		Snoekie::getSnoekie(void) { return this->Body; }

void 		Snoekie::Move(Vec dir) {
    Vec		body;

	body = this->Body.back();
	this->Body.pop_back();
	std::vector<Vec> cpy;
	cpy = this->Body;
	this->Body.clear();
	body.x += dir.x;
	body.y += dir.y;
	body.z += dir.z;
	this->Body.push_back(body);
	for(auto b: cpy)
		this->Body.push_back(b);
}
