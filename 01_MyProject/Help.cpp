#include "Help.h"

using namespace Scene;

VOID Help::Initialize(HWND hWnd)
{
	return;
}

VOID Help::Release(VOID)
{
	return;
}

VOID Help::Update(VOID)
{
	return;
}

VOID Help::Draw(HDC hDC)
{
	static const WCHAR* msg1 = TEXT("1. You can go to Title with pressing 'ESC' on keyboard.");
	static const WCHAR* msg2 = TEXT("2. You can shut down this program with clicking 'QUIT' button on Title.");
	static const WCHAR* msg3 = TEXT("3. You can have fun with clicking 'START' button on Title.");
	static const WCHAR* msg4 = TEXT("4. In the game, you can get 1 'point' with clicking red rectangle, which represents a mole.");
	static const WCHAR* msg5 = TEXT("5. In the game, you can lose 1 'life point' when miss red rectangle.");
	static const WCHAR* msg6 = TEXT("6. In the game, it is game-over when the life point is '0'.");

	MyClear();
	MyFinish();

	TextOut(hDC, 100, 100, msg1, lstrlenW(msg1));
	TextOut(hDC, 100, 150, msg2, lstrlenW(msg2));
	TextOut(hDC, 100, 200, msg3, lstrlenW(msg3));
	TextOut(hDC, 100, 250, msg4, lstrlenW(msg4));
	TextOut(hDC, 100, 300, msg5, lstrlenW(msg5));
	TextOut(hDC, 100, 350, msg6, lstrlenW(msg6));
}