#pragma once

#include "Graphics.h"

class Tunnel
{
private:
	HWND hWnd;
	BOOL bHover;
	BOOL bPrevClick;
	BOOL bClick;
	RECT rc;

	UINT iID;

public:
	Tunnel(HWND hWnd, INT X, INT Y, UINT iWidth, UINT iHeight, UINT iID);
	virtual ~Tunnel(VOID);

	VOID Update(VOID);
	VOID Draw(HDC hDC);

	INT leftTime;
	static UINT nRange;
	static UINT nMin;
};