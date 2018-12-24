#include <iostream>
#include <windows.h>

using namespace std;

void Space()
{
	INPUT input;
	WORD vkey = VK_SPACE;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
	input.ki.wVk = vkey;
	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}

bool BunnyHop = false;

void Bunnyhop()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		Sleep(100);
		BunnyHop = true;
	}

	if (GetAsyncKeyState(VK_CONTROL))
	{
		Sleep(100);
		BunnyHop = false;
	}

	if (BunnyHop)
	{
		Space();
	}
}

int main()
{
	while (true)
	{
		Bunnyhop();
	}
}