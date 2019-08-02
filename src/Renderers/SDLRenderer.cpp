#include "nibblerpch.hpp"
#include "Renderers/SDLRenderer.hpp"

int32_t ToNBKey(int32_t scancode)
{
	switch (scancode)
	{
		case SDL_SCANCODE_UNKNOWN: return NB_KEY_UNKNOWN;
		case SDL_SCANCODE_A: return NB_KEY_A;
		case SDL_SCANCODE_B: return NB_KEY_B;
		case SDL_SCANCODE_C: return NB_KEY_C;
		case SDL_SCANCODE_D: return NB_KEY_D;
		case SDL_SCANCODE_E: return NB_KEY_E;
		case SDL_SCANCODE_F: return NB_KEY_F;
		case SDL_SCANCODE_G: return NB_KEY_G;
		case SDL_SCANCODE_H: return NB_KEY_H;
		case SDL_SCANCODE_I: return NB_KEY_I;
		case SDL_SCANCODE_J: return NB_KEY_J;
		case SDL_SCANCODE_K: return NB_KEY_K;
		case SDL_SCANCODE_L: return NB_KEY_L;
		case SDL_SCANCODE_M: return NB_KEY_M;
		case SDL_SCANCODE_N: return NB_KEY_N;
		case SDL_SCANCODE_O: return NB_KEY_O;
		case SDL_SCANCODE_P: return NB_KEY_P;
		case SDL_SCANCODE_Q: return NB_KEY_Q;
		case SDL_SCANCODE_R: return NB_KEY_R;
		case SDL_SCANCODE_S: return NB_KEY_S;
		case SDL_SCANCODE_T: return NB_KEY_T;
		case SDL_SCANCODE_U: return NB_KEY_U;
		case SDL_SCANCODE_V: return NB_KEY_V;
		case SDL_SCANCODE_W: return NB_KEY_W;
		case SDL_SCANCODE_X: return NB_KEY_X;
		case SDL_SCANCODE_Y: return NB_KEY_Y;
		case SDL_SCANCODE_Z: return NB_KEY_Z;
		case SDL_SCANCODE_1: return NB_KEY_1;
		case SDL_SCANCODE_2: return NB_KEY_2;
		case SDL_SCANCODE_3: return NB_KEY_3;
		case SDL_SCANCODE_4: return NB_KEY_4;
		case SDL_SCANCODE_5: return NB_KEY_5;
		case SDL_SCANCODE_6: return NB_KEY_6;
		case SDL_SCANCODE_7: return NB_KEY_7;
		case SDL_SCANCODE_8: return NB_KEY_8;
		case SDL_SCANCODE_9: return NB_KEY_9;
		case SDL_SCANCODE_0: return NB_KEY_0;
		case SDL_SCANCODE_RETURN: return NB_KEY_ENTER;
		case SDL_SCANCODE_ESCAPE: return NB_KEY_ESCAPE;
		case SDL_SCANCODE_BACKSPACE: return NB_KEY_BACKSPACE;
		case SDL_SCANCODE_TAB: return NB_KEY_TAB;
		case SDL_SCANCODE_SPACE: return NB_KEY_SPACE;
		case SDL_SCANCODE_MINUS: return NB_KEY_MINUS;
		case SDL_SCANCODE_EQUALS: return NB_KEY_EQUAL;
		case SDL_SCANCODE_LEFTBRACKET: return NB_KEY_LEFT_BRACKET;
		case SDL_SCANCODE_RIGHTBRACKET: return NB_KEY_RIGHT_BRACKET;
		case SDL_SCANCODE_BACKSLASH: return NB_KEY_BACKSLASH;
		case SDL_SCANCODE_NONUSHASH: return NB_KEY_WORLD_2;
		case SDL_SCANCODE_SEMICOLON: return NB_KEY_SEMICOLON;
		case SDL_SCANCODE_APOSTROPHE: return NB_KEY_APOSTROPHE;
		case SDL_SCANCODE_GRAVE: return NB_KEY_GRAVE_ACCENT;
		case SDL_SCANCODE_COMMA: return NB_KEY_COMMA;
		case SDL_SCANCODE_PERIOD: return NB_KEY_PERIOD;
		case SDL_SCANCODE_SLASH: return NB_KEY_SLASH;
		case SDL_SCANCODE_CAPSLOCK: return NB_KEY_CAPS_LOCK;
		case SDL_SCANCODE_F1: return NB_KEY_F1;
		case SDL_SCANCODE_F2: return NB_KEY_F2;
		case SDL_SCANCODE_F3: return NB_KEY_F3;
		case SDL_SCANCODE_F4: return NB_KEY_F4;
		case SDL_SCANCODE_F5: return NB_KEY_F5;
		case SDL_SCANCODE_F6: return NB_KEY_F6;
		case SDL_SCANCODE_F7: return NB_KEY_F7;
		case SDL_SCANCODE_F8: return NB_KEY_F8;
		case SDL_SCANCODE_F9: return NB_KEY_F9;
		case SDL_SCANCODE_F10: return NB_KEY_F10;
		case SDL_SCANCODE_F11: return NB_KEY_F11;
		case SDL_SCANCODE_F12: return NB_KEY_F12;
		case SDL_SCANCODE_PRINTSCREEN: return NB_KEY_PRINT_SCREEN;
		case SDL_SCANCODE_SCROLLLOCK: return NB_KEY_SCROLL_LOCK;
		case SDL_SCANCODE_PAUSE: return NB_KEY_PAUSE;
		case SDL_SCANCODE_INSERT: return NB_KEY_INSERT;
		case SDL_SCANCODE_HOME: return NB_KEY_HOME;
		case SDL_SCANCODE_PAGEUP: return NB_KEY_PAGE_UP;
		case SDL_SCANCODE_DELETE: return NB_KEY_DELETE;
		case SDL_SCANCODE_END: return NB_KEY_END;
		case SDL_SCANCODE_PAGEDOWN: return NB_KEY_PAGE_DOWN;
		case SDL_SCANCODE_RIGHT: return NB_KEY_RIGHT;
		case SDL_SCANCODE_LEFT: return NB_KEY_LEFT;
		case SDL_SCANCODE_DOWN: return NB_KEY_DOWN;
		case SDL_SCANCODE_UP: return NB_KEY_UP;
		case SDL_SCANCODE_NUMLOCKCLEAR: return NB_KEY_NUM_LOCK;
		case SDL_SCANCODE_KP_DIVIDE: return NB_KEY_KP_DIVIDE;
		case SDL_SCANCODE_KP_MULTIPLY: return NB_KEY_KP_MULTIPLY;
		case SDL_SCANCODE_KP_MINUS: return NB_KEY_KP_SUBTRACT;
		case SDL_SCANCODE_KP_PLUS: return NB_KEY_KP_ADD;
		case SDL_SCANCODE_KP_ENTER: return NB_KEY_KP_ENTER;
		case SDL_SCANCODE_KP_1: return NB_KEY_KP_1;
		case SDL_SCANCODE_KP_2: return NB_KEY_KP_2;
		case SDL_SCANCODE_KP_3: return NB_KEY_KP_3;
		case SDL_SCANCODE_KP_4: return NB_KEY_KP_4;
		case SDL_SCANCODE_KP_5: return NB_KEY_KP_5;
		case SDL_SCANCODE_KP_6: return NB_KEY_KP_6;
		case SDL_SCANCODE_KP_7: return NB_KEY_KP_7;
		case SDL_SCANCODE_KP_8: return NB_KEY_KP_8;
		case SDL_SCANCODE_KP_9: return NB_KEY_KP_9;
		case SDL_SCANCODE_KP_0: return NB_KEY_KP_0;
		case SDL_SCANCODE_KP_PERIOD: return NB_KEY_KP_DECIMAL;
		case SDL_SCANCODE_NONUSBACKSLASH: return NB_KEY_WORLD_2;
		case SDL_SCANCODE_APPLICATION: return NB_KEY_LEFT_SUPER;
		case SDL_SCANCODE_POWER: return NB_KEY_6;
		case SDL_SCANCODE_KP_EQUALS: return NB_KEY_KP_EQUAL;
		case SDL_SCANCODE_F13: return NB_KEY_F13;
		case SDL_SCANCODE_F14: return NB_KEY_F14;
		case SDL_SCANCODE_F15: return NB_KEY_F15;
		case SDL_SCANCODE_F16: return NB_KEY_F16;
		case SDL_SCANCODE_F17: return NB_KEY_F17;
		case SDL_SCANCODE_F18: return NB_KEY_F18;
		case SDL_SCANCODE_F19: return NB_KEY_F19;
		case SDL_SCANCODE_F20: return NB_KEY_F20;
		case SDL_SCANCODE_F21: return NB_KEY_F21;
		case SDL_SCANCODE_F22: return NB_KEY_F22;
		case SDL_SCANCODE_F23: return NB_KEY_F23;
		case SDL_SCANCODE_F24: return NB_KEY_F24;
		case SDL_SCANCODE_EXECUTE: return NB_KEY_RIGHT_SUPER;
		case SDL_SCANCODE_HELP: return NB_KEY_F1;
		case SDL_SCANCODE_MENU: return NB_KEY_MENU;
		default: return -1;
	}
}

SDLRenderer::SDLRenderer()
{
}

SDLRenderer::SDLRenderer(int width, int height, std::string const &name)
{
	m_Width = width;
	m_Height = height;
	m_Name = name;
	m_ShouldClose = false;
	if (!SDL_WasInit(SDL_INIT_EVERYTHING))
	{
		std::cout << "SDLRenderer is initializing" << std::endl;
		if (SDL_Init(SDL_INIT_EVERYTHING == -1))
		{
			std::cout << SDL_GetError() << std::endl;
			throw InitFail();
		}
	}
	if (!(win = SDL_CreateWindow(m_Name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN)))
	{
		std::cout << SDL_GetError() << std::endl;
		throw InitFail();
	}
	if (!(ren = SDL_CreateRenderer(win, 0, 0)))
	{
		std::cout << SDL_GetError() << std::endl;
		throw InitFail();
	}
	std::memset(m_Keys, 0, sizeof(int) * NB_KEY_LAST);
}

SDLRenderer::SDLRenderer(const SDLRenderer &rhs)
{
	*this = rhs;
}

SDLRenderer &SDLRenderer::operator=(const SDLRenderer &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

SDLRenderer::~SDLRenderer()
{
	std::cout << "SDLRenderer is exiting" << std::endl;
	SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}

void SDLRenderer::GetInput()
{

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				SetKey(ToNBKey(event.key.keysym.scancode), 1);
				break;
			case SDL_KEYUP:
				SetKey(ToNBKey(event.key.keysym.scancode), 0);
				break;
			default:
				break;
		}
	}
}

void SDLRenderer::SetClearColour(const Color &c)
{
	m_ClearColor = c;
}

void SDLRenderer::DrawSquare(int x, int y, const Color &c)
{
	SDL_Rect r;
	r.x = (x / (double) m_Width) * SCREEN_W;
	r.y = ((-y - 1) / (double) m_Height) * SCREEN_H + SCREEN_W;
	r.w = (1 / (double) m_Width) * SCREEN_W;
	r.h = (1 / (double) m_Height) * SCREEN_H;
	SDL_SetRenderDrawColor(ren, c.r * 255, c.g * 255, c.b * 255, c.a * 255);
	SDL_RenderDrawRect(ren, &r);
}

void SDLRenderer::BeginFrame()
{
	SDL_SetRenderDrawColor(ren, m_ClearColor.r * 255, m_ClearColor.g * 255, m_ClearColor.b * 255, m_ClearColor.a * 255);
	SDL_RenderClear(ren);
}

void SDLRenderer::EndFrame()
{
	SDL_RenderPresent(ren);
}

bool SDLRenderer::ShouldClose()
{
	return m_ShouldClose;
}

int SDLRenderer::GetWidth() const { return m_Width; }
int SDLRenderer::GetHeight() const { return m_Height; }
std::string const &SDLRenderer::GetName() const { return m_Name; }

int32_t SDLRenderer::GetKey(int32_t key) const
{
	if (key > NB_KEY_UNKNOWN && key < NB_KEY_LAST)
		return m_Keys[key];
	else
		return 0;
}

void SDLRenderer::SetKey(int32_t key, int32_t val)
{
	if (key > NB_KEY_UNKNOWN && key < NB_KEY_LAST)
		m_Keys[key] = val;
}

void SDLRenderer::SetShouldClose(int val)
{
	m_ShouldClose = val;
}

const char *SDLRenderer::InitFail::what() const throw()
{
	return "SDLRenderer Init Fail";
}

#ifdef __cplusplus

extern "C" {
	IRenderer *CreateRenderer(int width, int height, std::string const &name)
	{
		return (IRenderer*)(new SDLRenderer(width, height, name));
	}
}

#endif // __cplusplus
