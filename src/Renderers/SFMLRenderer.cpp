/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SFMLRenderer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:40:42 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/31 10:40:44 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nibblerpch.hpp"
#include "Renderers/SFMLRenderer.hpp"

int toNbKey(sf::Keyboard::Key key)
{
	switch (key)
	{
		case sf::Keyboard::Key::Unknown: return (NB_KEY_UNKNOWN);
		case sf::Keyboard::Key::A: return (NB_KEY_A);
		case sf::Keyboard::Key::B: return (NB_KEY_B);
		case sf::Keyboard::Key::C: return (NB_KEY_C);
		case sf::Keyboard::Key::D: return (NB_KEY_D);
		case sf::Keyboard::Key::E: return (NB_KEY_E);
		case sf::Keyboard::Key::F: return (NB_KEY_F);
		case sf::Keyboard::Key::G: return (NB_KEY_G);
		case sf::Keyboard::Key::H: return (NB_KEY_H);
		case sf::Keyboard::Key::I: return (NB_KEY_I);
		case sf::Keyboard::Key::J: return (NB_KEY_J);
		case sf::Keyboard::Key::K: return (NB_KEY_K);
		case sf::Keyboard::Key::L: return (NB_KEY_L);
		case sf::Keyboard::Key::M: return (NB_KEY_M);
		case sf::Keyboard::Key::N: return (NB_KEY_N);
		case sf::Keyboard::Key::O: return (NB_KEY_O);
		case sf::Keyboard::Key::P: return (NB_KEY_P);
		case sf::Keyboard::Key::Q: return (NB_KEY_Q);
		case sf::Keyboard::Key::R: return (NB_KEY_R);
		case sf::Keyboard::Key::S: return (NB_KEY_S);
		case sf::Keyboard::Key::T: return (NB_KEY_T);
		case sf::Keyboard::Key::U: return (NB_KEY_U);
		case sf::Keyboard::Key::V: return (NB_KEY_V);
		case sf::Keyboard::Key::W: return (NB_KEY_W);
		case sf::Keyboard::Key::X: return (NB_KEY_X);
		case sf::Keyboard::Key::Y: return (NB_KEY_Y);
		case sf::Keyboard::Key::Z: return (NB_KEY_Z);
		case sf::Keyboard::Key::Num0: return (NB_KEY_0);
		case sf::Keyboard::Key::Num1: return (NB_KEY_1);
		case sf::Keyboard::Key::Num2: return (NB_KEY_2);
		case sf::Keyboard::Key::Num3: return (NB_KEY_3);
		case sf::Keyboard::Key::Num4: return (NB_KEY_4);
		case sf::Keyboard::Key::Num5: return (NB_KEY_5);
		case sf::Keyboard::Key::Num6: return (NB_KEY_6);
		case sf::Keyboard::Key::Num7: return (NB_KEY_7);
		case sf::Keyboard::Key::Num8: return (NB_KEY_8);
		case sf::Keyboard::Key::Num9: return (NB_KEY_9);
		case sf::Keyboard::Key::Escape: return (NB_KEY_ESCAPE);
		case sf::Keyboard::Key::LControl: return (NB_KEY_LEFT_CONTROL);
		case sf::Keyboard::Key::LShift: return (NB_KEY_LEFT_SHIFT);
		case sf::Keyboard::Key::LAlt: return (NB_KEY_LEFT_ALT);
		case sf::Keyboard::Key::LSystem: return (NB_KEY_LEFT_SUPER);
		case sf::Keyboard::Key::RControl: return (NB_KEY_RIGHT_CONTROL);
		case sf::Keyboard::Key::RShift: return (NB_KEY_RIGHT_SHIFT);
		case sf::Keyboard::Key::RAlt: return (NB_KEY_RIGHT_ALT);
		case sf::Keyboard::Key::RSystem: return (NB_KEY_RIGHT_SUPER);
		case sf::Keyboard::Key::Menu: return (NB_KEY_MENU);
		case sf::Keyboard::Key::LBracket: return (NB_KEY_LEFT_BRACKET);
		case sf::Keyboard::Key::RBracket: return (NB_KEY_RIGHT_BRACKET);
		case sf::Keyboard::Key::Semicolon: return (NB_KEY_SEMICOLON);
		case sf::Keyboard::Key::Comma: return (NB_KEY_COMMA);
		case sf::Keyboard::Key::Period: return (NB_KEY_PERIOD);
		case sf::Keyboard::Key::Quote: return (NB_KEY_APOSTROPHE);
		case sf::Keyboard::Key::Slash: return (NB_KEY_SLASH);
		case sf::Keyboard::Key::Backslash: return (NB_KEY_BACKSLASH);
		case sf::Keyboard::Key::Tilde: return (NB_KEY_GRAVE_ACCENT);
		case sf::Keyboard::Key::Equal: return (NB_KEY_EQUAL);
		case sf::Keyboard::Key::Hyphen: return (NB_KEY_MINUS);
		case sf::Keyboard::Key::Space: return (NB_KEY_SPACE);
		case sf::Keyboard::Key::Enter: return (NB_KEY_ENTER);
		case sf::Keyboard::Key::Backspace: return (NB_KEY_BACKSPACE);
		case sf::Keyboard::Key::Tab: return (NB_KEY_TAB);
		case sf::Keyboard::Key::PageUp: return (NB_KEY_PAGE_UP);
		case sf::Keyboard::Key::PageDown: return (NB_KEY_PAGE_DOWN);
		case sf::Keyboard::Key::End: return (NB_KEY_END);
		case sf::Keyboard::Key::Home: return (NB_KEY_HOME);
		case sf::Keyboard::Key::Insert: return (NB_KEY_INSERT);
		case sf::Keyboard::Key::Delete: return (NB_KEY_DELETE);
		case sf::Keyboard::Key::Add: return (NB_KEY_KP_ADD);
		case sf::Keyboard::Key::Subtract: return (NB_KEY_KP_SUBTRACT);
		case sf::Keyboard::Key::Multiply: return (NB_KEY_KP_MULTIPLY);
		case sf::Keyboard::Key::Divide: return (NB_KEY_KP_DIVIDE);
		case sf::Keyboard::Key::Left: return (NB_KEY_LEFT);
		case sf::Keyboard::Key::Right: return (NB_KEY_RIGHT);
		case sf::Keyboard::Key::Up: return (NB_KEY_UP);
		case sf::Keyboard::Key::Down: return (NB_KEY_DOWN);
		case sf::Keyboard::Key::Numpad0: return (NB_KEY_KP_0);
		case sf::Keyboard::Key::Numpad1: return (NB_KEY_KP_1);
		case sf::Keyboard::Key::Numpad2: return (NB_KEY_KP_2);
		case sf::Keyboard::Key::Numpad3: return (NB_KEY_KP_3);
		case sf::Keyboard::Key::Numpad4: return (NB_KEY_KP_4);
		case sf::Keyboard::Key::Numpad5: return (NB_KEY_KP_5);
		case sf::Keyboard::Key::Numpad6: return (NB_KEY_KP_6);
		case sf::Keyboard::Key::Numpad7: return (NB_KEY_KP_7);
		case sf::Keyboard::Key::Numpad8: return (NB_KEY_KP_8);
		case sf::Keyboard::Key::Numpad9: return (NB_KEY_KP_9);
		case sf::Keyboard::Key::F1: return (NB_KEY_F1);
		case sf::Keyboard::Key::F2: return (NB_KEY_F2);
		case sf::Keyboard::Key::F3: return (NB_KEY_F3);
		case sf::Keyboard::Key::F4: return (NB_KEY_F4);
		case sf::Keyboard::Key::F5: return (NB_KEY_F5);
		case sf::Keyboard::Key::F6: return (NB_KEY_F6);
		case sf::Keyboard::Key::F7: return (NB_KEY_F7);
		case sf::Keyboard::Key::F8: return (NB_KEY_F8);
		case sf::Keyboard::Key::F9: return (NB_KEY_F9);
		case sf::Keyboard::Key::F10: return (NB_KEY_F10);
		case sf::Keyboard::Key::F11: return (NB_KEY_F11);
		case sf::Keyboard::Key::F12: return (NB_KEY_F12);
		case sf::Keyboard::Key::F13: return (NB_KEY_F13);
		case sf::Keyboard::Key::F14: return (NB_KEY_F14);
		case sf::Keyboard::Key::F15: return (NB_KEY_F15);
		case sf::Keyboard::Key::Pause: return (NB_KEY_PAUSE);
		case sf::Keyboard::Key::KeyCount: return (NB_KEY_LAST);
	default:
		return NB_KEY_UNKNOWN;
	}
}

SFMLRenderer::SFMLRenderer()
{
}

SFMLRenderer::SFMLRenderer(int width, int height, std::string const &name)
{
	m_Width = width;
	m_Height = height;
	m_Name = name;

	m_Win.create(sf::VideoMode(SCREEN_W, SCREEN_H), m_Name.c_str());
	std::memset(m_Keys, 0, sizeof(int) * NB_KEY_LAST);
}

SFMLRenderer::SFMLRenderer(const SFMLRenderer &rhs)
{
	*this = rhs;
}

SFMLRenderer &SFMLRenderer::operator=(const SFMLRenderer &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

SFMLRenderer::~SFMLRenderer()
{
}

void SFMLRenderer::GetInput()
{
	sf::Event e;
	while (m_Win.pollEvent(e))
	{
		(void)e;
	}
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i)))
			m_Keys[toNbKey(static_cast<sf::Keyboard::Key>(i))] = 1;
		else
			m_Keys[toNbKey(static_cast<sf::Keyboard::Key>(i))] = 0;
	}
}

void SFMLRenderer::SetClearColour(const Color &c)
{
	m_ClearColor = c;
}

void SFMLRenderer::DrawSquare(int x, int y, const Color &c)
{
	(void)x;
	(void)y;
	(void)c;
	sf::Vector2f p(
		(x / (double) m_Width) * SCREEN_W,
		(-y / (double) m_Height) * SCREEN_H + SCREEN_W
	);

	sf::Vector2f s(
		(1 / (double) m_Width) * SCREEN_W,
		(1 / (double) m_Height) * SCREEN_H
	);
	sf::RectangleShape r(s);
	r.setPosition(p);
	sf::Color newCol = {static_cast<uint8_t>(c.r * 255), static_cast<uint8_t>(c.g * 255), static_cast<uint8_t>(c.b * 255), static_cast<uint8_t>(c.a * 255)};
	r.setFillColor(newCol);

	m_Win.draw(r);
}

void SFMLRenderer::PrintText(int x, int y, const char *string)
{
	(void)x;
	(void)y;
	(void)string;
	//SDL_SetRenderDrawColor(ren, c.r * 255, c.g * 255, c.b * 255, c.a * 255);
	//SDL_RenderDrawRect(ren, &r);
}

void SFMLRenderer::BeginFrame()
{
	m_Win.clear();
}

void SFMLRenderer::EndFrame()
{
	m_Win.display();
}

bool SFMLRenderer::ShouldClose()
{
	return !m_Win.isOpen();
}

int SFMLRenderer::GetWidth() const { return m_Width; }
int SFMLRenderer::GetHeight() const { return m_Width; }
std::string const &SFMLRenderer::GetName() const { return m_Name; }

int32_t SFMLRenderer::GetKey(int32_t key) const
{
	return m_Keys[key];
}

void SFMLRenderer::SetKey(int32_t key, int32_t val)
{
	m_Keys[key] = val;
}

void SFMLRenderer::SetShouldClose(int val)
{
	if (val)
		m_Win.close();
}

const char *SFMLRenderer::InitFail::what() const throw()
{
	return "SFMLRenderer Init Fail";
}

#ifdef __cplusplus

extern "C" {
	IRenderer *CreateRenderer(int width, int height, std::string const &name)
	{
		return (IRenderer*)(new SFMLRenderer(width, height, name));
	}
}

#endif // __cplusplus
