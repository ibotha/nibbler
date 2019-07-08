/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snoekie.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:33:10 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/08 16:10:28 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include "IEntity.hpp"
#include "Vec.hpp"


class Snoekie: public IEntity
{
	public:
		Snoekie(void);
		~Snoekie(void);
		Snoekie(Snoekie const&);
		Snoekie &operator=(const Snoekie&);

		virtual void Render(IRenderer*) const;
		virtual void Update(IRenderer*);
		virtual bool collision(IEntity*) const;
		virtual bool inBounds(const Vec<int>&) const;

		bool	eatFood(Vec<int>);

		void	grow(void);
		void	shrink(void);
		void	Move(Vec<int>, bool);
		 
		std::vector<Vec<int>>	getSnoekie(void);

	private:
		std::vector<Vec<int>>	Body;
		
	protected:	
};