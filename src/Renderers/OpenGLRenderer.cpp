#include "nibblerpch.hpp"
#include "Renderer.hpp"
#include <glad/glad.h>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

struct GLData {
	GLFWwindow *win;
	GLuint shader;
	GLuint vertexArray;
	GLuint vertexBuffer;
	GLuint indexBuffer;
};

static GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

Renderer::Renderer()
{
}

Renderer::Renderer(int width, int height, std::string name)
{
	m_Width = width;
	m_Height = height;
	m_Data = new GLData;
	GLData *data = static_cast<GLData*>(m_Data);
	if (!glfwInit())
	{
		std::cout << "failed to init GLFW" << std::endl;
		throw InitFail();
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwSetErrorCallback([](int code, const char *message) {std::cout << "GLFW Error " << code << ": "<< message << std::endl;});


	data->win = glfwCreateWindow(600, 600, name.c_str(), NULL, NULL);
	if (data->win == nullptr)
	{
		std::cout << "failed to init window" << std::endl;
		throw InitFail();
	}
	glfwMakeContextCurrent(data->win);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	if (status == 0)
	{
		std::cout << "failed to init glad" << std::endl;
		throw InitFail();
	}
	data->shader = LoadShaders("OpenGL.vertexshader.glsl", "OpenGL.fragmentshader.glsl");
	glUseProgram(data->shader);
	glfwSetInputMode(data->win, GLFW_STICKY_KEYS, GL_TRUE);

	glGenVertexArrays(1, &data->vertexArray);
	glBindVertexArray(data->vertexArray);
	glGenBuffers(1, &data->vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, data->vertexBuffer);
	glGenBuffers(1, &data->indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data->indexBuffer);
	GLint loc = glGetUniformLocation(data->shader, "u_Dimentions");
	if (loc != -1)
	{
		std::cout << "setting" << std::endl;
		glUniform2f(loc, width, height);
	}
	std::memset(m_Keys, 0, sizeof(int) * NB_KEY_LAST);
	glfwSetWindowUserPointer(data->win, this);

	glfwSetKeyCallback(data->win, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		(void)scancode;
		(void)mods;
		Renderer& r = *(Renderer*)glfwGetWindowUserPointer(window);
		r.SetKey(key, action);
	});
}

Renderer::Renderer(const Renderer &rhs)
{
	*this = rhs;
}

Renderer &Renderer::operator=(const Renderer &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

Renderer::~Renderer()
{
	GLData *data = static_cast<GLData*>(m_Data);
	glfwDestroyWindow(data->win);
	glfwTerminate();
	delete data;
}

void Renderer::GetInput()
{
	glfwPollEvents();
}

void Renderer::SetClearColour(const Color &c)
{
	glClearColor(c.r, c.g, c.b, c.a);
}

void Renderer::DrawSquare(int x, int y, const Color &c)
{
	GLfloat gx = x;
	GLfloat gy = y;
	GLData *data = static_cast<GLData*>(m_Data);
	(void)c;
	if (!(x < m_Width && x > -1 && y > -1 && y < m_Height))
		return;
	GLfloat g_vertex_buffer_data[] = {
		gx    , gy    , 0, 0, 0, 0,
		gx + 1, gy    , 0, 0, 1, 0,
		gx + 1, gy + 1, 0, 0, 0, 1,
		gx    , gy + 1, 0, 1, 1, 1
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	static const GLuint g_index_buffer_data[] = {
		0, 1, 2,
		2, 3, 0
	};

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_index_buffer_data), g_index_buffer_data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, data->vertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data->indexBuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		4 * 6,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		4 * 6,                  // stride
		(void*)(4 * 3)            // array buffer offset
	);
	// Draw the triangle !
	glUseProgram(data->shader);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void Renderer::BeginFrame()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void Renderer::EndFrame()
{
	GLData *data = static_cast<GLData*>(m_Data);
	glfwSwapBuffers(data->win);
}

bool Renderer::ShouldClose()
{
	GLData *data = static_cast<GLData*>(m_Data);
	return glfwWindowShouldClose(data->win);
}

int Renderer::GetWidth() const { return m_Width; }
int Renderer::GetHeight() const { return m_Width; }

uint32_t Renderer::GetKey(uint32_t key) const
{
	return m_Keys[key];
}

void Renderer::SetKey(uint32_t key, uint32_t val)
{
	m_Keys[key] = val;
}

void Renderer::SetShouldClose(int val)
{
	GLData *data = static_cast<GLData*>(m_Data);
	glfwSetWindowShouldClose(data->win, val);
}

const char *Renderer::InitFail::what() const throw()
{
	return "Renderer Init Fail";
}

static GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path){

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if(VertexShaderStream.is_open()){
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		VertexShaderCode = sstr.str();
		VertexShaderStream.close();
	}else{
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if(FragmentShaderStream.is_open()){
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}
	
	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);
	
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}