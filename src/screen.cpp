#include"screen.h"

void InitScreen()
{
	CONSOLE_CURSOR_INFO console_cursor_info;

	g_screen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_screen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	console_cursor_info.dwSize = 1;
	console_cursor_info.bVisible = FALSE;
	SetConsoleCursorInfo(g_screen[0], &console_cursor_info);
	SetConsoleCursorInfo(g_screen[1], &console_cursor_info);
}

void FlipScreen()
{
	SetConsoleActiveScreenBuffer(g_screen[g_screen_index]);
	g_screen_index = !g_screen_index;
}

void ClearScreen()
{
	COORD coordinate = { 0,0 };
	DWORD dword;
	FillConsoleOutputCharacter(g_screen[g_screen_index], ' ', 80 * 25, coordinate, &dword);
}

void ReleaseScreen()
{
	CloseHandle(g_screen[0]);
	CloseHandle(g_screen[1]);
}

void PrintScreen(int x, int y, string string)
{
	DWORD dword;
	COORD cursor_position = { x, y };
	SetConsoleCursorPosition(g_screen[g_screen_index], cursor_position);
	WriteFile(g_screen[g_screen_index], string.c_str(), string.size(), &dword, NULL);
}