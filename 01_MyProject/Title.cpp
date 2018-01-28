#include "Title.h"

using namespace Scene;

Button* Title::B1 = nullptr;
Button* Title::B2 = nullptr;
Button* Title::B3 = nullptr;

VOID Title::Initialize(HWND hWnd)
{
	B1 = new Button(hWnd, 600, 100, 125, 75, 1);
	B2 = new Button(hWnd, 600, 250, 125, 75, 2);
	B3 = new Button(hWnd, 600, 400, 125, 75, 3);
	return;
}

VOID Title::Release(VOID)
{
	delete B1;
	delete B2;
	delete B3;
	return;
}

VOID Title::Update(VOID)
{
	B1->Update();
	B2->Update();
	B3->Update();
	return;
}

VOID Title::Draw(HDC hDC)
{
	RECT rcButton1 = { 0 },
		rcButton2 = { 0 },
		rcButton3 = { 0 };
	INT nPrev = 0;
	COLORREF cPrev = 0;
	static const WCHAR* msg1 = TEXT("MyProject with WinAPI >:D !");

	MyClear();
	B1->Draw(hDC);
	B2->Draw(hDC);
	B3->Draw(hDC);

	// M
	MyRectangle(50, 150, 125, 100, pRed);
	MyRectangle(75, 175, 25, 75, pWhite);
	MyRectangle(125, 175, 25, 75, pWhite);
	// O
	MyRectangle(190, 150, 100, 100, pRed);
	MyRectangle(215, 175, 50, 50, pWhite);
	// L
	MyRectangle(305, 150, 100, 100, pRed);
	MyRectangle(335, 150, 75, 75, pWhite);
	// E
	MyRectangle(420, 150, 100, 100, pRed);
	MyRectangle(450, 170, 75, 20, pWhite);
	MyRectangle(450, 210, 75, 20, pWhite);
	// C
	MyRectangle(50, 275, 80, 100, pGray);
	MyRectangle(80, 310, 50, 30, pWhite);
	// A
	MyRectangle(140, 275, 80, 100, pGray);
	MyRectangle(170, 290, 20, 30, pWhite);
	MyRectangle(170, 345, 20, 30, pWhite);
	// T
	MyRectangle(230, 275, 80, 30, pGray);
	MyRectangle(255, 275, 30, 100, pGray);
	// C
	MyRectangle(320, 275, 80, 100, pGray);
	MyRectangle(350, 310, 50, 30, pWhite);
	// H
	MyRectangle(410, 275, 80, 100, pGray);
	MyRectangle(435, 275, 30, 30, pWhite);
	MyRectangle(435, 345, 30, 30, pWhite);
	// !
	MyRectangle(500, 275, 20, 100, pGray);
	MyRectangle(500, 340, 20, 15, pWhite);

	MyFinish();

	nPrev = GetBkMode(hDC);
	cPrev = GetTextColor(hDC);
	SetBkMode(hDC, TRANSPARENT);
	
	TextOut(hDC, 100, 100, msg1, lstrlen(msg1));
	SetTextColor(hDC, RGB(255, 255, 255));
	SetRect(&rcButton1, 600, 100, 600 + 125, 100 + 75);
	DrawText(hDC, TEXT("START"), lstrlen(TEXT("START")), &rcButton1, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	SetRect(&rcButton2, 600, 250, 600 + 125, 250 + 75);
	DrawText(hDC, TEXT("HELP"), lstrlen(TEXT("HELP")), &rcButton2, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	SetRect(&rcButton3, 600, 400, 600 + 125, 400 + 75);
	DrawText(hDC, TEXT("QUIT"), lstrlen(TEXT("QUIT")), &rcButton3, DT_CENTER | DT_SINGLELINE | DT_VCENTER);

	SetBkMode(hDC, nPrev);
	SetTextColor(hDC, cPrev);

	return;
}