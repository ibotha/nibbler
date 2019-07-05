#include "nibblerpch.hpp"
#include "Renderers/SDLRenderer.hpp"

SDLRenderer::SDLRenderer()
{
}

SDLRenderer::SDLRenderer(int width, int height, std::string const &name)
{
	m_Width = width;
	m_Height = height;
	m_Name = name;
	m_ShouldClose = false;
	if (!SDL_Init(SDL_INIT_EVERYTHING))
		throw InitFail();
	if (!(win = SDL_CreateWindow(m_Name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN)))
		throw InitFail();
	if (!(ren = SDL_CreateRenderer(win, 0, 0)))
		throw InitFail();
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
	SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
	SDL_Quit();
}

void SDLRenderer::GetInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				SetKey(event.key.keysym.scancode, 1);
			case SDL_KEYUP:
				SetKey(event.key.keysym.scancode, 0);
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
	r.y = (y / (double) m_Height) * SCREEN_H;
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
int SDLRenderer::GetHeight() const { return m_Width; }
std::string const &SDLRenderer::GetName() const { return m_Name; }

uint32_t SDLRenderer::GetKey(uint32_t key) const
{
	return m_Keys[key];
}

void SDLRenderer::SetKey(uint32_t key, uint32_t val)
{
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