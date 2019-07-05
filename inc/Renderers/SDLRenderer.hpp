/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDLRenderer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:38:33 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/05 10:56:33 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IRenderer.hpp"
#include "SDL.h"

class SDLRenderer : public IRenderer {
	public:

		SDLRenderer(int width, int height, std::string const &name);
		SDLRenderer(const SDLRenderer &rhs);
		virtual SDLRenderer &operator=(const SDLRenderer &rhs);
		virtual ~SDLRenderer();

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

	private:
	
		SDLRenderer();
		int m_Width;
		int m_Height;
		int m_Keys[NB_KEY_LAST];
		std::string m_Name;
		SDL_Window *win;
		SDL_Renderer* ren;
		int m_ShouldClose;
		Color m_ClearColor;

	protected:
};

extern "C" {
	IRenderer *CreateRenderer(int width, int height, std::string const &name);
}