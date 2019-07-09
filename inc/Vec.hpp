/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:04:20 by jwolf             #+#    #+#             */
/*   Updated: 2019/07/09 14:16:03 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Vec
{
	public:
		Vec(void): x(0), y(0), z(0){};
		Vec(T x, T y, T z): x(x), y(y), z(z){};
		Vec(const Vec &cpy) { *this = cpy; };
		~Vec(){};
		Vec &operator=(const Vec& cpy)
		{
			if (this != &cpy)
			{
				this->x = cpy.getX();
				this->y = cpy.getY();
				this->z = cpy.getZ();
			}
			return *this;
		};
		bool operator!=(const Vec &rhs) const
		{
			return (
				this->x != rhs.getX() &&
				this->y != rhs.getY() &&
				this->z != rhs.getZ()
				);
		};
		bool operator==(const Vec &rhs) const
		{
			return (
				this->x == rhs.getX() &&
				this->y == rhs.getY() &&
				this->z == rhs.getZ()
				);
		};

		Vec operator+(const Vec &v)
		{
			return Vec<T>(x + v.x, y + v.y, z + v.z);
		}

		Vec operator-(const Vec &v)
		{
			return Vec<T>(x - v.x, y - v.y, z - v.z);
		}

		Vec operator*(const Vec &v)
		{
			return Vec<T>(x * v.x, y * v.y, z * v.z);
		}

		Vec operator/(const Vec &v)
		{
			return Vec<T>(x / v.x, y / v.y, z / v.z);
		}

		T	getX(void) const { return this->x; };
		T	getY(void) const { return this->y; };
		T	getZ(void) const { return this->z; };

	private:
		T x;
		T y;
		T z;
};
