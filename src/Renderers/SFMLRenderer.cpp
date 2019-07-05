#include "nibblerpch.hpp"
#include "Renderers/OpenGLRenderer.hpp"

static GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

OpenGLRenderer::OpenGLRenderer()
{
}

OpenGLRenderer::OpenGLRenderer(int width, int height, std::string const &name)
{
	m_Width = width;
	m_Height = height;
	m_Name = name;
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


	m_Win = glfwCreateWindow(SCREEN_W, SCREEN_W, name.c_str(), NULL, NULL);
	if (m_Win == nullptr)
	{
		std::cout << "failed to init window" << std::endl;
		throw InitFail();
	}
	glfwMakeContextCurrent(m_Win);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	if (status == 0)
	{
		std::cout << "failed to init glad" << std::endl;
		throw InitFail();
	}
	m_Shader = LoadShaders("OpenGL.vertexshader.glsl", "OpenGL.fragmentshader.glsl");
	glUseProgram(m_Shader);
	glfwSetInputMode(m_Win, GLFW_STICKY_KEYS, GL_TRUE);

	glGenVertexArrays(1, &m_VertexArray);
	glBindVertexArray(m_VertexArray);
	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
	glGenBuffers(1, &m_IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
	GLint loc = glGetUniformLocation(m_Shader, "u_Dimentions");
	if (loc != -1)
	{
		glUniform2f(loc, width, height);
	}
	std::memset(m_Keys, 0, sizeof(int) * NB_KEY_LAST);
	glfwSetWindowUserPointer(m_Win, this);

	glfwSetKeyCallback(m_Win, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		(void)scancode;
		(void)mods;
		OpenGLRenderer& r = *(OpenGLRenderer*)glfwGetWindowUserPointer(window);
		r.SetKey(key, action);
	});
}

OpenGLRenderer::OpenGLRenderer(const OpenGLRenderer &rhs)
{
	*this = rhs;
}

OpenGLRenderer &OpenGLRenderer::operator=(const OpenGLRenderer &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

OpenGLRenderer::~OpenGLRenderer()
{
	glDeleteBuffers(1, &m_IndexBuffer);
	glDeleteBuffers(1, &m_VertexBuffer);
	glDeleteVertexArrays(1, &m_VertexArray);
	glDeleteProgram(m_Shader);
	glfwDestroyWindow(m_Win);
	glfwTerminate();
}

void OpenGLRenderer::GetInput()
{
	glfwPollEvents();
}

void OpenGLRenderer::SetClearColour(const Color &c)
{
	glClearColor(c.r, c.g, c.b, c.a);
}

void OpenGLRenderer::DrawSquare(int x, int y, const Color &c)
{
	GLfloat gx = x;
	GLfloat gy = y;
	(void)c;
	if (!(x < m_Width && x > -1 && y > -1 && y < m_Height))
		return;
	GLfloat g_vertex_buffer_data[] = {
		gx    , gy    , 0, 1, 0, 0,
		gx + 1, gy    , 0, 1, 0, 0,
		gx + 1, gy + 1, 0, 1, 0, 0,
		gx    , gy + 1, 0, 1, 0, 0
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	static const GLuint g_index_buffer_data[] = {
		0, 1, 2,
		2, 3, 0
	};

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_index_buffer_data), g_index_buffer_data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		4 * 6,
		(void*)0
	);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		4 * 6,
		(void*)(4 * 3)
	);
	glUseProgram(m_Shader);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void OpenGLRenderer::BeginFrame()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void OpenGLRenderer::EndFrame()
{
	glfwSwapBuffers(m_Win);
}

bool OpenGLRenderer::ShouldClose()
{
	return glfwWindowShouldClose(m_Win);
}

int OpenGLRenderer::GetWidth() const { return m_Width; }
int OpenGLRenderer::GetHeight() const { return m_Width; }
std::string const &OpenGLRenderer::GetName() const { return m_Name; }

uint32_t OpenGLRenderer::GetKey(uint32_t key) const
{
	return m_Keys[key];
}

void OpenGLRenderer::SetKey(uint32_t key, uint32_t val)
{
	m_Keys[key] = val;
}

void OpenGLRenderer::SetShouldClose(int val)
{
	glfwSetWindowShouldClose(m_Win, val);
}

const char *OpenGLRenderer::InitFail::what() const throw()
{
	return "OpenGLRenderer Init Fail";
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

#ifdef __cplusplus

extern "C" {
	IRenderer *CreateRenderer(int width, int height, std::string const &name)
	{
		return (IRenderer*)(new OpenGLRenderer(width, height, name));
	}
}

#endif // __cplusplus