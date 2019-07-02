/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renderer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotha <ibotha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:38:33 by ibotha            #+#    #+#             */
/*   Updated: 2019/07/02 15:43:30 by ibotha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define NB_KEY_UNKNOWN            -1

/* Printable keys */
#define NB_KEY_SPACE              32
#define NB_KEY_APOSTROPHE         39  /* ' */
#define NB_KEY_COMMA              44  /* , */
#define NB_KEY_MINUS              45  /* - */
#define NB_KEY_PERIOD             46  /* . */
#define NB_KEY_SLASH              47  /* / */
#define NB_KEY_0                  48
#define NB_KEY_1                  49
#define NB_KEY_2                  50
#define NB_KEY_3                  51
#define NB_KEY_4                  52
#define NB_KEY_5                  53
#define NB_KEY_6                  54
#define NB_KEY_7                  55
#define NB_KEY_8                  56
#define NB_KEY_9                  57
#define NB_KEY_SEMICOLON          59  /* ; */
#define NB_KEY_EQUAL              61  /* = */
#define NB_KEY_A                  65
#define NB_KEY_B                  66
#define NB_KEY_C                  67
#define NB_KEY_D                  68
#define NB_KEY_E                  69
#define NB_KEY_F                  70
#define NB_KEY_G                  71
#define NB_KEY_H                  72
#define NB_KEY_I                  73
#define NB_KEY_J                  74
#define NB_KEY_K                  75
#define NB_KEY_L                  76
#define NB_KEY_M                  77
#define NB_KEY_N                  78
#define NB_KEY_O                  79
#define NB_KEY_P                  80
#define NB_KEY_Q                  81
#define NB_KEY_R                  82
#define NB_KEY_S                  83
#define NB_KEY_T                  84
#define NB_KEY_U                  85
#define NB_KEY_V                  86
#define NB_KEY_W                  87
#define NB_KEY_X                  88
#define NB_KEY_Y                  89
#define NB_KEY_Z                  90
#define NB_KEY_LEFT_BRACKET       91  /* [ */
#define NB_KEY_BACKSLASH          92  /* \ */
#define NB_KEY_RIGHT_BRACKET      93  /* ] */
#define NB_KEY_GRAVE_ACCENT       96  /* ` */
#define NB_KEY_WORLD_1            161 /* non-US #1 */
#define NB_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define NB_KEY_ESCAPE             256
#define NB_KEY_ENTER              257
#define NB_KEY_TAB                258
#define NB_KEY_BACKSPACE          259
#define NB_KEY_INSERT             260
#define NB_KEY_DELETE             261
#define NB_KEY_RIGHT              262
#define NB_KEY_LEFT               263
#define NB_KEY_DOWN               264
#define NB_KEY_UP                 265
#define NB_KEY_PAGE_UP            266
#define NB_KEY_PAGE_DOWN          267
#define NB_KEY_HOME               268
#define NB_KEY_END                269
#define NB_KEY_CAPS_LOCK          280
#define NB_KEY_SCROLL_LOCK        281
#define NB_KEY_NUM_LOCK           282
#define NB_KEY_PRINT_SCREEN       283
#define NB_KEY_PAUSE              284
#define NB_KEY_F1                 290
#define NB_KEY_F2                 291
#define NB_KEY_F3                 292
#define NB_KEY_F4                 293
#define NB_KEY_F5                 294
#define NB_KEY_F6                 295
#define NB_KEY_F7                 296
#define NB_KEY_F8                 297
#define NB_KEY_F9                 298
#define NB_KEY_F10                299
#define NB_KEY_F11                300
#define NB_KEY_F12                301
#define NB_KEY_F13                302
#define NB_KEY_F14                303
#define NB_KEY_F15                304
#define NB_KEY_F16                305
#define NB_KEY_F17                306
#define NB_KEY_F18                307
#define NB_KEY_F19                308
#define NB_KEY_F20                309
#define NB_KEY_F21                310
#define NB_KEY_F22                311
#define NB_KEY_F23                312
#define NB_KEY_F24                313
#define NB_KEY_F25                314
#define NB_KEY_KP_0               320
#define NB_KEY_KP_1               321
#define NB_KEY_KP_2               322
#define NB_KEY_KP_3               323
#define NB_KEY_KP_4               324
#define NB_KEY_KP_5               325
#define NB_KEY_KP_6               326
#define NB_KEY_KP_7               327
#define NB_KEY_KP_8               328
#define NB_KEY_KP_9               329
#define NB_KEY_KP_DECIMAL         330
#define NB_KEY_KP_DIVIDE          331
#define NB_KEY_KP_MULTIPLY        332
#define NB_KEY_KP_SUBTRACT        333
#define NB_KEY_KP_ADD             334
#define NB_KEY_KP_ENTER           335
#define NB_KEY_KP_EQUAL           336
#define NB_KEY_LEFT_SHIFT         340
#define NB_KEY_LEFT_CONTROL       341
#define NB_KEY_LEFT_ALT           342
#define NB_KEY_LEFT_SUPER         343
#define NB_KEY_RIGHT_SHIFT        344
#define NB_KEY_RIGHT_CONTROL      345
#define NB_KEY_RIGHT_ALT          346
#define NB_KEY_RIGHT_SUPER        347
#define NB_KEY_MENU               348

#define NB_KEY_LAST               NB_KEY_MENU

#define NB_MOUSE_BUTTON_1         0
#define NB_MOUSE_BUTTON_2         1
#define NB_MOUSE_BUTTON_3         2
#define NB_MOUSE_BUTTON_4         3
#define NB_MOUSE_BUTTON_5         4
#define NB_MOUSE_BUTTON_6         5
#define NB_MOUSE_BUTTON_7         6
#define NB_MOUSE_BUTTON_8         7
#define NB_MOUSE_BUTTON_LAST      NB_MOUSE_BUTTON_8
#define NB_MOUSE_BUTTON_LEFT      NB_MOUSE_BUTTON_1
#define NB_MOUSE_BUTTON_RIGHT     NB_MOUSE_BUTTON_2
#define NB_MOUSE_BUTTON_MIDDLE    NB_MOUSE_BUTTON_3

#define NB_RELEASE				0
#define NB_PRESS				1
#define NB_REPEAT				2

struct Color
{
	float r, g, b, a;
};

class Renderer {
	public:

		Renderer(int width, int height, std::string name);
		Renderer(const Renderer &rhs);
		Renderer &operator=(const Renderer &rhs);
		~Renderer();

		void SetClearColour(const Color &c);
		void BeginFrame();
		void GetInput();
		void EndFrame();

		void DrawSquare(int x, int y, const Color &c);

		bool ShouldClose();
		void SetShouldClose(int val);

		uint32_t GetKey(uint32_t key) const;
		void SetKey(uint32_t key, uint32_t val);

		class InitFail : public std::exception {
			const char *what() const throw();
		};

		int GetWidth() const;
		int GetHeight() const;

	private:
		Renderer();
		void *m_Data;
		int m_Width;
		int m_Height;
		int m_Keys[NB_KEY_LAST];
	protected:
};