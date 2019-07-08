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

class IEntity
{
	public:
		~IEntity(){};
		virtual void Render(IRenderer *) const = 0;
		virtual void Update(IRenderer *) const = 0;
};