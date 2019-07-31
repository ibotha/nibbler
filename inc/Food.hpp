/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Food.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:50:35 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/08 16:10:04 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <random>
#include "IEntity.hpp"
#include "Vec.hpp"

class Food: public IEntity
{
	public:
		Food();
		Food(Vec<int>);
		~Food();
		Food(Food const&);
		Food &operator=(const Food&);
		
		virtual void Render(IRenderer*) const;
		virtual void Update(IRenderer*);
		virtual bool collision(IEntity*) const;
		virtual bool inBounds(const Vec<int>&) const;

	private:
		float	LifeSpan;
		bool	respawn;
		Vec		<int>pos;
		Vec		<int>Limits;
};
