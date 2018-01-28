#include "Tunnel.h"
#include "Start.h"

UINT Tunnel::nRange = 0;
UINT Tunnel::nMin = 0;

Tunnel::Tunnel(HWND hWnd, INT X, INT Y, UINT iWidth, UINT iHeight, UINT iID)
{
	this->hWnd = hWnd;
	this->bHover = FALSE;
	this->bClick = FALSE;
	this->bPrevClick = GetKeyState(VK_LBUTTON) & 0x8000;
	this->iID = iID;
	this->leftTime = rand() % nRange + nMin;

	// X1
	rc.left = X;
	// Y1
	rc.top = Y;
	// X2
	rc.right = iWidth;
	// Y2
	rc.bottom = iHeight;
}

Tunnel::~Tunnel(VOID)
{
	;
}

VOID Tunnel::Update(VOID)
{
	if (leftTime < 0)
	{
		if (Scene::Start::nLife > 0)
		{
			Scene::Start::nLife -= 1;
		}
		leftTime = rand() % nRange + nMin;
	}

	POINT ptCursor = { 0, 0 };

	GetCursorPos(&ptCursor);
	ScreenToClient(hWnd, &ptCursor);

	if (ptCursor.x > rc.left
		&& ptCursor.x < (rc.left + rc.right)
		&& ptCursor.y > rc.top
		&& ptCursor.y < (rc.top + rc.bottom))
	{
		bHover = TRUE;
	}
	else
	{
		bHover = FALSE;
	}

	if ((GetKeyState(VK_LBUTTON) & 0x8000)
		&& GetActiveWindow() == hWnd)
	{
		if (bHover && !bPrevClick)
		{
			bClick = TRUE;
			bPrevClick = TRUE;
		}
		else if (!bHover)
		{
			bPrevClick = TRUE;
		}
	}
	else
	{
		if (bClick && bHover
			&& leftTime < 10)
		{
			Scene::Start::nScore += 1;
			leftTime = rand() % nRange + nMin;
		}
		bClick = FALSE;
		bPrevClick = FALSE;
	}

	return;
}

VOID Tunnel::Draw(HDC hDC)
{
	if (!bHover)
	{
		MyRectangle(rc.left, rc.top, rc.right, rc.bottom, pBlack);
		if (leftTime > 10)
		{
			MyRectangle(rc.left, rc.top, rc.right, rc.bottom, pYellow);
		}
		else
		{
			MyRectangle(rc.left, rc.top, rc.right, rc.bottom, pRed, leftTime);
		}
	}
	else
	{
		if (bClick)
		{
			MyRectangle(rc.left, rc.top, rc.right, rc.bottom, pWhite);
		}
		else
		{
			MyRectangle(rc.left, rc.top, rc.right, rc.bottom, pGray);
			if (leftTime > 10)
			{
				MyRectangle(rc.left, rc.top, rc.right, rc.bottom, pYellow);
			}
			else
			{
				MyRectangle(rc.left, rc.top, rc.right, rc.bottom, pRed, leftTime);
			}
		}
	}
	
	return;
}