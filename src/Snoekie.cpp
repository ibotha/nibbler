/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snoekie.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:50:11 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/05 17:04:43 by jwolf            ###   ########.fr       */
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
	this->Body = rhs.Body;
}

Snoekie::~Snoekie(void) {
    
}

Snoekie 	&Snoekie::operator=(const Snoekie& rhs) {
	this->Body = rhs.Body;
	return *this;
}

void 		Snoekie::makeFood(void) {
	if (eatFood())
	{
		Vec newPos;
		
		newPos.x = rand() % 50;
		newPos.y = rand() % 50;
	}
}

bool 		Snoekie::eatFood(void) {
    Vec		head;

	head = this->Body.front();
	return false;
	// return (head.x == food.pos.x || head.y == food.pos.y);	
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
		if (collision())
			this->Body.pop_back();
}

bool 		Snoekie::collision(Vec col) {
    Vec		head;

	head = this->Body.front();
	return (head.x == col.x && head.y == col.y);
	// for (auto a: this->Body)
	// {
	// 	if (
	// 		head.x + 1 == a.x ||
	// 		head.x - 1 == a.x ||
	// 		head.y + 1 == a.y ||
	// 		head.y - 1 == a.y 
	// 	)
	// 		return true;
	// }
	// return false;
}

std::vector<Vec>		Snoekie::getSnoekie(void) { return this->Body; }

void 		Snoekie::Move(Vec dir) {
    Vec		body;

	body = this->Body.back();
	Vec N = {body.x + dir.x, body.y + dir.y, 0};
	this->Body.push_back(N);
	this->Body.erase(this->Body.begin());
}

void					Snoekie::Render(IRenderer *render)
{
	for (auto a: this->Body)
		render->DrawSquare(a.x, a.y, {1, 0, 0, 1});	
}

void					Snoekie::Update(IRenderer *render)
{
	
}