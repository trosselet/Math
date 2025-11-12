#pragma once

#include <Windows.h>

class Screen
{
public:
	Screen();
	~Screen();

	void SetConsoleSize(int width, int height);
	void ClearConsole();
	void ShowCursor();
	void HideCursor();
	void SetCursorStartPos();
	void Display(char character);


private:
	HANDLE		m_hConsole;
	DWORD		m_mode;
	COORD		m_bufferSize;
	SMALL_RECT	m_windowSize;
};

