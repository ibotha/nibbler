/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFMLRenderer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:38:33 by ibotha            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/07/31 11:27:36 by jwolf            ###   ########.fr       */
=======
/*   Updated: 2019/07/31 10:47:26 by ibotha           ###   ########.fr       */
>>>>>>> f3bc33ab352ad65437f3c15772f4ec3c2a3ed355
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IRenderer.hpp"
#include <SFML/Graphics.hpp>

class SFMLRenderer : public IRenderer {
	public:

		SFMLRenderer(int width, int height, std::string const &name);
		SFMLRenderer(const SFMLRenderer &rhs);
		virtual SFMLRenderer &operator=(const SFMLRenderer &rhs);
		virtual ~SFMLRenderer();

		virtual void SetClearColour(const Color &c);
		virtual void BeginFrame();
		virtual void GetInput();
		virtual void EndFrame();

		virtual void DrawSquare(int x, int y, const Color &c);

		virtual bool ShouldClose();
		virtual void SetShouldClose(int val);

		virtual int32_t GetKey(int32_t key) const;

		class InitFail : public std::exception {
			const char *what() const throw();
		};

		virtual int GetWidth() const;
		virtual int GetHeight() const;
		virtual std::string const &GetName() const;
		virtual void SetKey(int32_t key, int32_t val);

	private:

		SFMLRenderer();
		int m_Width;
		int m_Height;
		int m_Keys[NB_KEY_LAST];
		std::string m_Name;
		sf::RenderWindow m_Win;
		Color m_ClearColor = {0, 0, 0, 0};

	protected:
};

extern "C" {
	IRenderer *CreateRenderer(int width, int height, std::string const &name);
}
