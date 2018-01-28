#pragma once

#include "Graphics.h"
#include "Button.h"

namespace Scene
{
	class GameOver
	{
	public:
		static Button* B1;

		static UINT nResult;

		static VOID Initialize(HWND hWnd);
		static VOID Release(VOID);

		static VOID Update(VOID);
		static VOID Draw(HDC hDC);
	};
}