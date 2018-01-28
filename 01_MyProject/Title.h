#pragma once

#include "Graphics.h"
#include "Button.h"

namespace Scene
{
	class Title
	{
	public:
		static Button* B1;
		static Button* B2;
		static Button* B3;

		static VOID Initialize(HWND hWnd);
		static VOID Release(VOID);

		static VOID Update(VOID);
		static VOID Draw(HDC hDC);
	};
}