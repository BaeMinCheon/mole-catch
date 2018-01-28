#include "Start.h"
#include <strsafe.h>
#include "Callback.h"

#include <Windows.h>

using namespace Scene;

HWND Start::hWnd = nullptr;
BOOL Start::bClick = FALSE;
BOOL Start::bPrevClick = FALSE;
Tunnel* Start::T[9] = { nullptr };
INT Start::nLife = 0;
UINT Start::nScore = 0;

const static int left_x = 100;
const static int top_y = 100;

VOID Start::Initialize(HWND _hWnd)
{
	Start::hWnd = _hWnd;
	nScore = 0;
	nLife = 10;
	Tunnel::nRange = 20;
	Tunnel::nMin = 10;

	T[0] = new Tunnel(hWnd, left_x, top_y, 100, 100, 2);
	T[1] = new Tunnel(hWnd, left_x + 150, top_y, 100, 100, 3);
	T[2] = new Tunnel(hWnd, left_x + 300, top_y, 100, 100, 4);
	T[3] = new Tunnel(hWnd, left_x, top_y + 150, 100, 100, 5);
	T[4] = new Tunnel(hWnd, left_x + 150, top_y + 150, 100, 100, 6);
	T[5] = new Tunnel(hWnd, left_x + 300, top_y + 150, 100, 100, 7);
	T[6] = new Tunnel(hWnd, left_x, top_y + 300, 100, 100, 8);
	T[7] = new Tunnel(hWnd, left_x + 150, top_y + 300, 100, 100, 9);
	T[8] = new Tunnel(hWnd, left_x + 300, top_y + 300, 100, 100, 10);

	return;
}

VOID Start::Release(VOID)
{
	for (int i = 0; i < 9; ++i)
	{
		delete T[i];
	}

	return;
}

VOID Start::Update(VOID)
{
	if (nLife <= 0)
	{
		sendScore(hWnd);
		Sleep(1000);
		getOver(hWnd);
	}

	POINT ptCursor = { 0 };
	UINT iIndex = 0;
	BOOL bSuccess = TRUE;
	static INT nSuccess = 0;

	GetCursorPos(&ptCursor);
	ScreenToClient(hWnd, &ptCursor);

	for (int i = 0; i < 9; ++i)
	{
		T[i]->Update();
	}

	// check click
	if ((GetKeyState(VK_LBUTTON) & 0x8000) && (GetActiveWindow() == hWnd))
	{
		// is new click ?
		if (!bClick && !bPrevClick)
		{
			bClick = bPrevClick = TRUE;
		}
		// keep clicking
		else
		{
			bPrevClick = TRUE;
		}
	}
	// not clicked
	else
	{
		bClick = bPrevClick = FALSE;
	}

	return;
}

VOID Start::Draw(HDC hDC)
{
	INT nPrev = 0;
	COLORREF cPrev = 0;
	static WCHAR strLife[10] = { 0 };
	static WCHAR strScore[10] = { 0 };
	static WCHAR strRank[10] = { 0 };

	MyClear();
	for (int i = 0; i < 9; ++i)
	{
		T[i]->Draw(hDC);
	}
	
	// Heart
	MyRectangle(600, 100, 32, 30, pRed);
	MyRectangle(600, 100, 4, 4, pWhite);
	MyRectangle(614, 100, 4, 4, pWhite);
	MyRectangle(628, 100, 4, 4, pWhite);
	MyRectangle(600, 118, 4, 4, pWhite);
	MyRectangle(628, 118, 4, 4, pWhite);
	MyRectangle(600, 122, 8, 4, pWhite);
	MyRectangle(624, 122, 8, 4, pWhite);
	MyRectangle(600, 126, 12, 4, pWhite);
	MyRectangle(620, 126, 12, 4, pWhite);
	// :
	MyRectangle(650, 107, 6, 18, pBlack);
	MyRectangle(650, 113, 6, 6, pWhite);

	// P
	MyRectangle(600, 150, 32, 30, pBlack);
	MyRectangle(611, 156, 10, 6, pWhite);
	MyRectangle(611, 168, 21, 12, pWhite);
	// :
	MyRectangle(650, 155, 6, 18, pBlack);
	MyRectangle(650, 161, 6, 6, pWhite);

	MyFinish();

	nPrev = GetBkMode(hDC);
	cPrev = GetTextColor(hDC);
	SetBkMode(hDC, TRANSPARENT);
	
	// nLife
	wsprintfW(strLife, L"%02d", nLife);
	TextOut(hDC, 670, 107, strLife, lstrlenW(strLife));
	// nScore
	wsprintfW(strScore, L"%d", nScore);
	TextOut(hDC, 670, 157, strScore, lstrlenW(strScore));

	SetBkMode(hDC, nPrev);
	SetTextColor(hDC, cPrev);
}