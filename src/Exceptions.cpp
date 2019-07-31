/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:50:40 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/31 11:15:06 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

Exceptions::Exceptions(){}

Exceptions::Exceptions(const Exceptions &cpy)
{
	*this = cpy;
}

Exceptions::~Exceptions(){}

Exceptions &Exceptions::operator=(const Exceptions &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

Exceptions::LibraryNotFound::LibraryNotFound(){}

Exceptions::LibraryNotFound::LibraryNotFound(std::string reason)
{
	this->reason = reason;
}

Exceptions::LibraryNotFound::LibraryNotFound(const Exceptions::LibraryNotFound &rhs)
{
	*this = rhs;
}

Exceptions::LibraryNotFound::~LibraryNotFound() throw(){}

Exceptions::LibraryNotFound &Exceptions::LibraryNotFound::operator=(const Exceptions::LibraryNotFound &rhs)
{
	if (this != &rhs)
	{
		this->reason = rhs.reason;
	}
	return *this;
}

const char *Exceptions::LibraryNotFound::LibraryNotFound::what() const throw()
{
	return this->reason.c_str();
}
