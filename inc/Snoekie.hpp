/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snoekie.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:33:10 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/05 17:03:50 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include "IEntity.hpp"

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

class Snoekie: public IEntity
{
	public:
		Snoekie(void);
		~Snoekie(void);
		Snoekie(Snoekie const&);
		Snoekie &operator=(const Snoekie&);
		
		virtual void Render(IRenderer *);
		virtual void Update(IRenderer *);

		bool	eatFood(void);
		bool	collision(Vec);

		void	makeFood(void);
		void	grow(void);
		void	shrink(void);
		void	Move(Vec pos);
		 
		std::vector<Vec>	getSnoekie(void);

	private:
		std::vector<Vec>	Body;
		Vec					dir;
		IRenderer 			*m_Renderer;

		
	protected:	
};