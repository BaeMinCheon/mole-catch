#include "GameOver.h"

using namespace Scene;

Button* GameOver::B1 = nullptr;
UINT GameOver::nResult = 0;

VOID GameOver::Initialize(HWND hWnd)
{
	B1 = new Button(hWnd, 340, 300, 120, 70, 3);
	return;
}

VOID GameOver::Release(VOID)
{
	delete B1;
	return;
}

VOID GameOver::Update(VOID)
{
	B1->Update();
	return;
}

VOID GameOver::Draw(HDC hDC)
{
	RECT rcButton = { 0 };
	INT nPrev = 0;
	COLORREF cPrev = 0;
	static const WCHAR* msg1 = TEXT("Press ESC to go back to Title, or Press button to quit.");
	static WCHAR msg2[20];

	MyClear();

	// G
	MyRectangle(80, 100, 60, 100, pGray);
	MyRectangle(100, 120, 40, 20, pWhite);
	MyRectangle(100, 140, 20, 40, pWhite);

	// A
	MyRectangle(160, 100, 60, 100, pGray);
	MyRectangle(180, 120, 20, 20, pWhite);
	MyRectangle(180, 160, 20, 40, pWhite);

	// M
	MyRectangle(240, 100, 60, 100, pGray);
	MyRectangle(252, 120, 12, 80, pWhite);
	MyRectangle(276, 120, 12, 80, pWhite);

	// E
	MyRectangle(320, 100, 60, 100, pGray);
	MyRectangle(340, 120, 40, 20, pWhite);
	MyRectangle(340, 160, 40, 20, pWhite);

	// O
	MyRectangle(420, 100, 60, 100, pGray);
	MyRectangle(440, 120, 20, 60, pWhite);

	// V
	MyRectangle(500, 100, 60, 100, pGray);
	MyRectangle(520, 100, 20, 80, pWhite);

	// E
	MyRectangle(580, 100, 60, 100, pGray);
	MyRectangle(600, 120, 40, 20, pWhite);
	MyRectangle(600, 160, 40, 20, pWhite);

	// R
	MyRectangle(660, 100, 60, 100, pGray);
	MyRectangle(680, 120, 20, 20, pWhite);
	MyRectangle(680, 160, 20, 40, pWhite);
	MyRectangle(700, 140, 20, 20, pWhite);

	B1->Draw(hDC);
	MyFinish();

	nPrev = GetBkMode(hDC);
	cPrev = GetTextColor(hDC);
	SetBkMode(hDC, TRANSPARENT);

	TextOut(hDC, 230, 250, msg1, lstrlenW(msg1));
	wsprintfW(msg2, L"Your Score is %d !", nResult);
	TextOut(hDC, 230, 270, msg2, lstrlenW(msg2));
	SetTextColor(hDC, RGB(255, 255, 255));
	SetRect(&rcButton, 340, 300, 340 + 120, 300 + 70);
	DrawText(hDC, TEXT("QUIT"), lstrlen(TEXT("QUIT")), &rcButton, DT_CENTER | DT_SINGLELINE | DT_VCENTER);

	SetBkMode(hDC, nPrev);
	SetTextColor(hDC, cPrev);

	return;
}