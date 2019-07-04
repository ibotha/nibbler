#include "nibblerpch.hpp"
#include "Renderers/MLXRenderer.hpp"

void MLXRenderer::drawLiney(t_xy a, t_xy b, Color c)
{
	double	change;
	double	grad;
	double	i;

	if (b.y < a.y)
		std::swap(a, b);
	change = b.y - a.y;
	grad = (b.x - a.x) / change;
	i = -1;
	while (++i < (change))
		putPixel(a.x + i * grad, a.y + i, c);
}

void MLXRenderer::drawLine(t_xy a, t_xy b, Color c)
{
	double	change;
	double	ychange;
	double	grad;
	double	i;

	change = b.x - a.x;
	ychange = b.y - a.y;
	if ((ychange < 0 ? -ychange : ychange) > (change < 0 ? -change : change))
		drawLiney(a, b, c);
	else
	{
		grad = ychange / change;
		i = -1;
		while (++i < (change < 0 ? -change : change))
			putPixel(a.x + i, a.y + i * grad, c);
	}
}

void MLXRenderer::putPixel(int x, int y, Color c)
{
	int				i;
	const double	perc = c.a / 255.0;

	if (x < 0 || y < 0 || x >= 600 || y >= 600)
		return ;
	i = x * bpp + y * sizeline;
	raw_data[i] *= 1 - perc;
	raw_data[i] += c.b * perc;
	raw_data[i + 1] *= 1 - perc;
	raw_data[i + 1] += c.g * perc;
	raw_data[i + 2] *= 1 - perc;
	raw_data[i + 2] += c.b * perc;
}

void MLXRenderer::drawBox(t_xy start, t_xy end, Color c)
{
	int y;
	int x;

	if (start.x > end.x)
		std::swap(start.x, end.x);
	if (start.y > end.y)
		std::swap(start.y, end.y);
	y = start.y - 1;
	while (++y < end.y)
	{
		x = start.x - 1;
		while (++x < end.x)
			putPixel(x, y, c);
	}
}

MLXRenderer::MLXRenderer()
{
}

MLXRenderer::MLXRenderer(int width, int height, std::string const &name)
{
	m_Width = width;
	m_Height = height;
	m_Name = name;
	
	mlx_ptr = mlx_init();
	win = mlx_new_window(mlx_ptr, 600, 600, "Nibbler mlx");
	img = mlx_new_image(mlx_ptr, 600, 600);
	raw_data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
}

MLXRenderer::MLXRenderer(const MLXRenderer &rhs)
{
	*this = rhs;
}

MLXRenderer &MLXRenderer::operator=(const MLXRenderer &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

MLXRenderer::~MLXRenderer()
{
	mlx_destroy_image(mlx_ptr, img);
	mlx_destroy_window(mlx_ptr, win);
}

void MLXRenderer::GetInput()
{
	glfwPollEvents();
}

void MLXRenderer::SetClearColour(const Color &c)
{
	(void)c;
}

void MLXRenderer::DrawSquare(int x, int y, const Color &c)
{
	int gx = x;
	int gy = y;
	(void)c;
	if (!(x < m_Width && x > -1 && y > -1 && y < m_Height))
		return;
	gx = (x + 1) / (double)m_Width * 600;
	gy = (y + 1) / (double)m_Height * 600;
	x = (x) / (double)m_Width * 600;
	y = (y) / (double)m_Height * 600;
	drawBox({x, y}, {gx, gy}, {1.0, 0, 0, 1.0});
}

void MLXRenderer::BeginFrame()
{
	std::memset(raw_data, 0, sizeline * 600);
}

void MLXRenderer::EndFrame()
{
	mlx_put_image_to_window(mlx_ptr, win, img, 0, 0);
}

bool MLXRenderer::ShouldClose()
{
	return should_close;
}

int MLXRenderer::GetWidth() const { return m_Width; }
int MLXRenderer::GetHeight() const { return m_Width; }
std::string const &MLXRenderer::GetName() const { return m_Name; }

uint32_t MLXRenderer::GetKey(uint32_t key) const
{
	return m_Keys[key];
}

void MLXRenderer::SetKey(uint32_t key, uint32_t val)
{
	m_Keys[key] = val;
}

void MLXRenderer::SetShouldClose(int val)
{
	should_close = val;
}

const char *MLXRenderer::InitFail::what() const throw()
{
	return "MLXRenderer Init Fail";
}

#ifdef __cplusplus

extern "C" {
	IRenderer *CreateRenderer(int width, int height, std::string const &name)
	{
		return (IRenderer*)(new MLXRenderer(width, height, name));
	}
}

#endif // __cplusplus