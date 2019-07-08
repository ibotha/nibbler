/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snoekie.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:33:10 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/08 08:35:18 by jwolf            ###   ########.fr       */
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

class Snoekie: public IEntity
{
	public:
		Snoekie(void);
		~Snoekie(void);
		Snoekie(Snoekie const&);
		Snoekie &operator=(const Snoekie&);

		virtual void Render(IRenderer*) const;
		virtual void Update(IRenderer*) const;

		bool	eatFood(Vec);
		bool	collision(Vec);

		void	makeFood(void);
		void	grow(void);
		void	shrink(void);
		void	Move(Vec pos);
		 
		std::vector<Vec>	getSnoekie(void);

	private:
		std::vector<Vec>	Body;
		IRenderer 			*m_Renderer;

		
	protected:	
};