/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MLXRenderer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:38:33 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/04 16:09:31 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IRenderer.hpp"
#include "mlx.h"

struct t_xy {
	int x;
	int y;
}

class MLXRenderer : public IRenderer {
	public:

		MLXRenderer(int width, int height, std::string const &name);
		MLXRenderer(const MLXRenderer &rhs);
		virtual MLXRenderer &operator=(const MLXRenderer &rhs);
		virtual ~MLXRenderer();

		virtual void SetClearColour(const Color &c);
		virtual void BeginFrame();
		virtual void GetInput();
		virtual void EndFrame();

		virtual void DrawSquare(int x, int y, const Color &c);

		virtual bool ShouldClose();
		virtual void SetShouldClose(int val);

		virtual uint32_t GetKey(uint32_t key) const;

		class InitFail : public std::exception {
			const char *what() const throw();
		};

		virtual int GetWidth() const;
		virtual int GetHeight() const;
		virtual std::string const &GetName() const;
		virtual void SetKey(uint32_t key, uint32_t val);

		void drawLiney(t_xy a, t_xy b, Color c);
		void drawLine(t_xy a, t_xy b, Color c);
		void putPixel(int x, int y, Color c);
		void drawBox(t_xy a, t_xy b, Color c);

	private:
	
		MLXRenderer();
		int m_Width;
		int m_Height;
		int m_Keys[NB_KEY_LAST];
		std::string m_Name;
		void *win;
		void *img;
		void *mlx_ptr;
		int sizeline;
		int bpp;
		int endian;
		char *raw_data;
		int should_close;

	protected:
};

extern "C" {
	IRenderer *CreateRenderer(int width, int height, std::string const &name);
}