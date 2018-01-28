#include "Callback.h"
#include "Graphics.h"
// for using sprintf_s()
#include <stdio.h>
#pragma comment(lib, "winmm.lib")
// sequence headers
#include "Sequence.h"
#include "Title.h"
#include "Start.h"
#include "Help.h"
#include "GameOver.h"

HDC hDC, hCom;
HBITMAP hBack = NULL, hOld = NULL;
BYTE* pMem = reinterpret_cast<BYTE*>(malloc(800 * 600 * 4));
Sequence nSeq = Sequence::Title;

LRESULT __stdcall WndProc(_In_ HWND p_hWnd,
	_In_ UINT p_iMessage,
	_In_ WPARAM p_wParam,
	_In_ LPARAM p_lParam)
{
	switch (p_iMessage)
	{
	case WM_CREATE:
		hDC = GetDC(p_hWnd);
		hCom = CreateCompatibleDC(hDC);
		hBack = CreateCompatibleBitmap(hDC, 800, 600);
		hOld = reinterpret_cast<HBITMAP>(SelectObject(hCom, hBack));
		srand(timeGetTime());
		Scene::Title::Initialize(p_hWnd);
		Scene::Start::Initialize(p_hWnd);
		Scene::Help::Initialize(p_hWnd);
		Scene::GameOver::Initialize(p_hWnd);
		break;
	case WM_MYBUTTON:
		switch (p_wParam)
		{
		case 1:
			nSeq = Sequence::Start;
			SetTimer(p_hWnd, 1, 1000, NULL);
			break;
		case 2:
			nSeq = Sequence::Help;
			break;
		case 3:
			PostQuitMessage(WM_QUIT);
			break;
		}
		break;
	case WM_TIMER:
		switch (p_wParam)
		{
		case 1:
			TunnelProc();
			break;
		default:
			break;
		}
		break;
	case WM_KEYDOWN:
		if (p_wParam == VK_ESCAPE)
		{
			if (nSeq == Sequence::Start)
			{
				KillTimer(p_hWnd, 1);
				nSeq = Sequence::Title;

				Scene::Start::Release();
				Scene::Start::Initialize(p_hWnd);
			}
			else
			{
				nSeq = Sequence::Title;
			}
		}
		break;
	case WM_DESTROY:
		SelectObject(hCom, hOld);
		DeleteObject(hBack);
		DeleteDC(hCom);
		ReleaseDC(p_hWnd, hDC);

		// delete pMem
		free(pMem);
		// delete Sequence
		Scene::Title::Release();
		Scene::Start::Release();
		Scene::Help::Release();
		Scene::GameOver::Release();
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(p_hWnd, p_iMessage, p_wParam, p_lParam);
}

HRESULT __stdcall OnPaint(_In_ HWND p_hWnd)
{
	HRESULT hResult = S_OK;

	static const UINT iTestCount = 500;
	static DWORD timePrev = timeGetTime();
	static UINT iCount = 0;
	static CHAR timeStr[20] = { 0 };

	switch (nSeq)
	{
	case Sequence::Title:
		Scene::Title::Update();
		Scene::Title::Draw(hCom);
		break;
	case Sequence::Start:
		Scene::Start::Update();
		Scene::Start::Draw(hCom);
		break;
	case Sequence::Help:
		Scene::Help::Update();
		Scene::Help::Draw(hCom);
		break;
	case Sequence::Gameover:
		Scene::GameOver::Update();
		Scene::GameOver::Draw(hCom);
	default:
		break;
	}

	if (iCount == iTestCount)
	{
		sprintf_s<20>(timeStr, "%f", 1000.f / static_cast<float>((timeGetTime() - timePrev))*static_cast<float>(iTestCount));
		iCount = 0;
		timePrev = timeGetTime();
		if (nSeq == Sequence::Start)
		{
			TunnelProc();
		}
	}
	++iCount;

	TextOutA(hCom, 0, 0, timeStr, strnlen_s(timeStr, 20));
	BitBlt(hDC, 0, 0, 800, 600, hCom, 0, 0, SRCCOPY);

	return S_OK;
}

void CALLBACK getOver(HWND hWnd)
{
	KillTimer(hWnd, 1);
	nSeq = Sequence::Gameover;

	Scene::Start::Release();
	Scene::Start::Initialize(hWnd);
}

void CALLBACK sendScore(HWND hWnd)
{
	Scene::GameOver::nResult = Scene::Start::nScore;
}

void CALLBACK TunnelProc()
{
	for (int i = 0; i < 9; ++i)
	{
		Scene::Start::T[i]->leftTime -= 1;
	}
	switch (Scene::Start::nScore)
	{
	case 10:
	case 20:
	case 30:
	case 40:
	case 50:
	case 60:
	case 70:
	case 80:
	case 90:
	case 100:
	case 110:
	case 120:
	case 130:
	case 140:
	case 150:
	case 160:
	case 170:
	case 180:
	case 190:
		if (Tunnel::nRange > 1)
		{
			Tunnel::nRange -= 1;
		}
		break;
	default:
		break;
	}
}