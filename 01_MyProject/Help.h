#pragma once

#include "Graphics.h"

namespace Scene
{
	class Help
	{
	public:
		static VOID Initialize(HWND hWnd);
		static VOID Release(VOID);

		static VOID Update(VOID);
		static VOID Draw(HDC hDC);
	};
}