/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenGLRenderer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <jwolf@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:38:33 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/31 11:29:18 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IRenderer.hpp"
#include <glad/glad.h>
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <GLFW/glfw3.h>

class OpenGLRenderer : public IRenderer {
	public:

		OpenGLRenderer(int width, int height, std::string const &name);
		OpenGLRenderer(const OpenGLRenderer &rhs);
		virtual OpenGLRenderer &operator=(const OpenGLRenderer &rhs);
		virtual ~OpenGLRenderer();

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

		OpenGLRenderer();
		int m_Width;
		int m_Height;
		int m_Keys[NB_KEY_LAST];
		bool m_Clear[NB_KEY_LAST];
		std::string m_Name;
		GLFWwindow *m_Win;
		GLuint m_Shader;
		GLuint m_VertexArray;
		GLuint m_VertexBuffer;
		GLuint m_IndexBuffer;

	protected:
};

extern "C" {
	IRenderer *CreateRenderer(int width, int height, std::string const &name);
}
