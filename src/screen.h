#pragma once

#include<Windows.h>

#include<string>

using namespace std;

static int g_screen_index;
static HANDLE g_screen[2];

void InitScreen();
void FlipScreen();
void ClearScreen();
void ReleaseScreen();
void PrintScreen(int x, int y, string string);