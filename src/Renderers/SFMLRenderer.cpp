#include "nibblerpch.hpp"
#include "Renderers/SFMLRenderer.hpp"

SFMLRenderer::SFMLRenderer()
{
}

SFMLRenderer::SFMLRenderer(int width, int height, std::string const &name)
{
	m_Width = width;
	m_Height = height;
	m_Name = name;

	win = new sf::Window(sf::VideoMode(SCREEN_W, SCREEN_H), m_Name.c_str());
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
	win->close();
	delete win;
}

void SFMLRenderer::GetInput()
{
	sf::Event event;
        while (win->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_ShouldClose = true;
        }
}

void SFMLRenderer::SetClearColour(const Color &c)
{
	(void)c;
}

void SFMLRenderer::DrawSquare(int x, int y, const Color &c)
{
	(void)c;
	(void)x;
	(void)y;
}

void SFMLRenderer::BeginFrame()
{

}

void SFMLRenderer::EndFrame()
{

}

bool SFMLRenderer::ShouldClose()
{
	return m_ShouldClose;
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
	m_ShouldClose = val;
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