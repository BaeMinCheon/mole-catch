#pragma once

#include "Graphics.h"
#include "Button.h"
#include "Tunnel.h"

namespace Scene
{
	class Start
	{
	public:
		static HWND hWnd;
		
		static Tunnel* T[9];

		static BOOL bClick;
		static BOOL bPrevClick;

		static INT nLife;
		static UINT nScore;

		static VOID Initialize(HWND hWnd);
		static VOID Release(VOID);

		static VOID Update(VOID);
		static VOID Draw(HDC hDC);
	};
}