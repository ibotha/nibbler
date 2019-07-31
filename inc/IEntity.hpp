/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:47:08 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/05 16:47:08 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IRenderer.hpp"
#include "Vec.hpp"

class IEntity
{
	public:
		virtual ~IEntity(){};
		virtual void Render(IRenderer *) const = 0;
		virtual void Update(IRenderer *) = 0;
		virtual bool collision(IEntity*) const = 0;
		virtual bool inBounds(const Vec<int>&) const = 0;
};