#define UNICODE
#include <windows.h>
#include "resource.h"

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
void				InitDictionary(void);
void				InitRegistry(void);
void				SaveRegistry(void);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
WNDPROC				OldWndProc;
LRESULT APIENTRY	EKWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT APIENTRY	ES1WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT APIENTRY	ES2WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT APIENTRY	EBWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

char				sk;
void				InitSearch();
void				SearchPrev();
void				SearchNorm();
void				SearchNext();

void Set1();
void Set1Back();
void Set2();
void Set2Back();

HWND hWnd, hWndEK, hWndES1, hWndES2, hWndEB1, hWndEB2, hwndB1, hwndB2, hwndB3, hwndBUp1, hwndBDn1, hwndBSr1, hwndBUp2, hwndBDn2, hwndBSr2;

HANDLE hf, hf1, hf2;

WCHAR	dWgs[64] = TEXT("A, a ");
WCHAR	dWgf[64];
WCHAR	dBgf[8192];

WCHAR	dWgf1[64];
WCHAR	dBgf1[8192];

WCHAR	dWgf2[64];
WCHAR	dBgf2[8192];

int dp = 0;
byte buffer[4096];
int dp1 = 0;
byte buffer1[4096];
int dp2 = 0;
byte buffer2[4096];
DWORD lpNumberOfBytesRead;

long HshMin;
long HshMax;
long HshMin1 = 0;
long HshMax1 = 12901792;
long HshMin2 = 0;
long HshMax2 = 6568102;


long	iCurPos;
int		iCurBufPos;
long	iCurPos1;
int		iCurBufPos1;
long	iCurPos2;
int		iCurBufPos2;

int	LngWgs = 0;
int	LngWgf = 0;
int	LngBgf = 0;
int	LngWgf1 = 0;
int	LngBgf1 = 0;
int	LngWgf2 = 0;
int	LngBgf2 = 0;

RECT Rect;
int	wX = 60;
int	wY = 1;
int	wW = 400;
int	wH = 400;
int	wW2015 = 9;
int	wH2015 = 4;

float er = (float)0.4;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	MSG msg;

	MyRegisterClass(hInstance);
	InitRegistry();
	InitInstance(hInstance, nCmdShow);
	InitDictionary();
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("prMainhattan");

	return RegisterClass(&wc);
}

void InitRegistry(void)
{

	TCHAR szPrT[4];
	DWORD dwBfL = 4;
	DWORD dwDisposition;
	HKEY hKey;

//	if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Tallassa\\prMainhattan"), 0, NULL, 0, KEY_WRITE, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS)
	if (RegCreateKey(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Tallassa\\prMainhattan"), &hKey) == ERROR_SUCCESS)
	{
		if (RegQueryValueEx(hKey, TEXT("wX"), NULL, NULL, (LPBYTE)szPrT, &dwBfL) == ERROR_SUCCESS) wX = szPrT[0];
		if (RegQueryValueEx(hKey, TEXT("wY"), NULL, NULL, (LPBYTE)szPrT, &dwBfL) == ERROR_SUCCESS) wY = szPrT[0];
		if (RegQueryValueEx(hKey, TEXT("wW"), NULL, NULL, (LPBYTE)szPrT, &dwBfL) == ERROR_SUCCESS) wW = szPrT[0];
		if (RegQueryValueEx(hKey, TEXT("wH"), NULL, NULL, (LPBYTE)szPrT, &dwBfL) == ERROR_SUCCESS) wH = szPrT[0];
		RegCloseKey(hKey);
	}
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HFONT a = CreateFont(13, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, (LPCTSTR)TEXT("Tahoma"));
	HICON hIconEntr = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	HICON hIconNext = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
	HICON hIconPrev = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON3));
	HICON hIconEn = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON4));
	HICON hIconRu = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON5));
	//--
	hWnd = CreateWindowEx(NULL, TEXT("prMainhattan"), TEXT("prMainhattan"), WS_OVERLAPPEDWINDOW, wX, wY, wW, wH, NULL, NULL, hInstance, NULL);
	//--
	hWndEK = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 0, 0, wW - 46, 19, hWnd, NULL, hInstance, NULL);
	OldWndProc = (WNDPROC)SetWindowLong(hWndEK, GWL_WNDPROC, (LONG)EKWndProc);
	SendMessage(hWndEK, WM_SETFONT, (WPARAM)a, (LPARAM)TRUE);

	hwndB1 = CreateWindow(TEXT("BUTTON"), TEXT("s"), WS_VISIBLE | WS_CHILD | BS_ICON, wW - 45, 1, 18, 18, hWnd, NULL, hInstance, NULL);
	SendMessage(hwndB1, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconEntr);
	hwndB2 = CreateWindow(TEXT("BUTTON"), TEXT("."), WS_VISIBLE | WS_CHILD | BS_ICON, wW - 26, 1, 18, 9, hWnd, NULL, hInstance, NULL);
	SendMessage(hwndB2, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconEn);
	hwndB3 = CreateWindow(TEXT("BUTTON"), TEXT("."), WS_VISIBLE | WS_CHILD | BS_ICON, wW - 26, 10, 18, 9, hWnd, NULL, hInstance, NULL);
	SendMessage(hwndB3, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconRu);
	//--
	hWndES1 = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 19, 20, wW - 65, 19, hWnd, NULL, hInstance, NULL);
	OldWndProc = (WNDPROC)SetWindowLong(hWndES1, GWL_WNDPROC, (LONG)ES1WndProc);
	SendMessage(hWndES1, WM_SETFONT, (WPARAM)a, (LPARAM)TRUE);

	hwndBUp1 = CreateWindow(TEXT("BUTTON"), TEXT("<"), WS_VISIBLE | WS_CHILD | BS_ICON, 0, 21, 18, 18, hWnd, NULL, hInstance, NULL);
	SendMessage(hwndBUp1, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconPrev);
	hwndBDn1 = CreateWindow(TEXT("BUTTON"), TEXT(">"), WS_VISIBLE | WS_CHILD | BS_ICON, wW - 26, 21, 18, 18, hWnd, NULL, hInstance, NULL);
	SendMessage(hwndBDn1, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconNext);
	hwndBSr1 = CreateWindow(TEXT("BUTTON"), TEXT("s"), WS_VISIBLE | WS_CHILD | BS_ICON, wW - 45, 21, 18, 18, hWnd, NULL, hInstance, NULL);
	SendMessage(hwndBSr1, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconEntr);

	hWndEB1 = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | WS_BORDER, 0, 40, wW - 8, (int)(er*wH), hWnd, NULL, hInstance, NULL);
	OldWndProc = (WNDPROC)SetWindowLong(hWndEB1, GWL_WNDPROC, (LONG)EBWndProc);
	SendMessage(hWndEB1, WM_SETFONT, (WPARAM)a, (LPARAM)TRUE);
	//--
	hWndES2 = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 19, (int)(er*wH) + 41, wW - 65, 19, hWnd, NULL, hInstance, NULL);
	OldWndProc = (WNDPROC)SetWindowLong(hWndES2, GWL_WNDPROC, (LONG)ES2WndProc);
	SendMessage(hWndES2, WM_SETFONT, (WPARAM)a, (LPARAM)TRUE);

	hwndBUp2 = CreateWindow(TEXT("BUTTON"), TEXT("<"), WS_VISIBLE | WS_CHILD | BS_ICON, 0, (int)(er*wH) + 41 + 1, 18, 18, hWnd, NULL, hInstance, NULL);
	SendMessage(hwndBUp2, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconPrev);
	hwndBDn2 = CreateWindow(TEXT("BUTTON"), TEXT(">"), WS_VISIBLE | WS_CHILD | BS_ICON, wW - 26, (int)(er*wH) + 41 + 1, 18, 18, hWnd, NULL, hInstance, NULL);
	SendMessage(hwndBDn2, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconNext);
	hwndBSr2 = CreateWindow(TEXT("BUTTON"), TEXT("s"), WS_VISIBLE | WS_CHILD | BS_ICON, wW - 45, (int)(er*wH) + 41 + 1, 18, 18, hWnd, NULL, hInstance, NULL);
	SendMessage(hwndBSr2, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconEntr);

	hWndEB2 = CreateWindow(TEXT("EDIT"), NULL, WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | WS_BORDER, 0, (int)(er*wH) + 41 + 1 + 19, wW - 8, wH - ((int)(er*wH) + 41 + 1 + 19) - 27, hWnd, NULL, hInstance, NULL);
	OldWndProc = (WNDPROC)SetWindowLong(hWndEB2, GWL_WNDPROC, (LONG)EBWndProc);
	SendMessage(hWndEB2, WM_SETFONT, (WPARAM)a, (LPARAM)TRUE);
	//--
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

void InitDictionary(void)
{
	//hf1= CreateFile(TEXT("E:\\Dict\\DeEnDe.dat"), GENERIC_READ, FILE_SHARE_READ, (LPSECURITY_ATTRIBUTES) NULL, OPEN_EXISTING, FILE_FLAG_RANDOM_ACCESS, (HANDLE) NULL);
	hf1 = CreateFile(TEXT("DeEnDe.dat"), GENERIC_READ, FILE_SHARE_READ, (LPSECURITY_ATTRIBUTES)NULL, OPEN_EXISTING, FILE_FLAG_RANDOM_ACCESS, (HANDLE)NULL);
	//hf2= CreateFile(TEXT("E:\\Dict\\DeuRus.dat"), GENERIC_READ, FILE_SHARE_READ, (LPSECURITY_ATTRIBUTES) NULL, OPEN_EXISTING, FILE_FLAG_RANDOM_ACCESS, (HANDLE) NULL);
	hf2 = CreateFile(TEXT("DeuRus.dat"), GENERIC_READ, FILE_SHARE_READ, (LPSECURITY_ATTRIBUTES)NULL, OPEN_EXISTING, FILE_FLAG_RANDOM_ACCESS, (HANDLE)NULL);
	if (hf1 == INVALID_HANDLE_VALUE) { MessageBox(NULL, TEXT("Shit happens e!"), TEXT("msg"), MB_OK); PostQuitMessage(0); }
	if (hf2 == INVALID_HANDLE_VALUE) { MessageBox(NULL, TEXT("Shit happens r!"), TEXT("msg"), MB_OK); PostQuitMessage(0); }

	ReadFile(hf1, &buffer1, 4096, &lpNumberOfBytesRead, NULL);
	ReadFile(hf2, &buffer2, 4096, &lpNumberOfBytesRead, NULL);
	iCurBufPos1 = 2;
	iCurBufPos2 = 2;
}

void SaveRegistry(void)
{
	HKEY hKey = NULL;
	DWORD dwDisposition;
	LONG rW, rH;

	ShowWindow(hWnd, SW_RESTORE);

	GetWindowRect(hWnd, &Rect);
	rW = (Rect.right - Rect.left);
	rH = (Rect.bottom - Rect.top);
//	if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Tallassa\\prMainhattan"), 0, NULL, 0, KEY_WRITE, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS)
	if (RegCreateKey(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Tallassa\\prMainhattan"), &hKey) == ERROR_SUCCESS)
	{
		RegSetValueEx(hKey, TEXT("wX"), 0, REG_DWORD, (LPBYTE)&Rect.left, sizeof(DWORD));
		RegSetValueEx(hKey, TEXT("wY"), 0, REG_DWORD, (LPBYTE)&Rect.top, sizeof(DWORD));
		RegSetValueEx(hKey, TEXT("wW"), 0, REG_DWORD, (LPBYTE)&rW, sizeof(DWORD));
		RegSetValueEx(hKey, TEXT("wH"), 0, REG_DWORD, (LPBYTE)&rH, sizeof(DWORD));
		RegCloseKey(hKey);
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		if ((HWND)lParam == hwndB1)
		{
			sk = 'k';
			InitSearch();
		}
		if ((HWND)lParam == hwndB2)
		{
			SendMessage(hWndEB1, WM_COPY, (WPARAM)NULL, (LPARAM)NULL);
			SendMessage(hWndES1, WM_SETTEXT, (WPARAM)0, (LPARAM)NULL);
			SendMessage(hWndES1, WM_PASTE, (WPARAM)NULL, (LPARAM)NULL);
			sk = '1';
			InitSearch();
		}
		if ((HWND)lParam == hwndB3)
		{
			SendMessage(hWndEB1, WM_COPY, (WPARAM)NULL, (LPARAM)NULL);
			SendMessage(hWndES2, WM_SETTEXT, (WPARAM)0, (LPARAM)NULL);
			SendMessage(hWndES2, WM_PASTE, (WPARAM)NULL, (LPARAM)NULL);
			sk = '2';
			InitSearch();
		}
		if ((HWND)lParam == hwndBUp1)
		{
			sk = '1';
			Set1();
			SearchPrev();
			Set1Back();
		}
		if ((HWND)lParam == hwndBDn1)
		{
			sk = '1';
			Set1();
			SearchNext();
			Set1Back();
		}
		if ((HWND)lParam == hwndBSr1)
		{
			sk = '1';
			InitSearch();
		}
		if ((HWND)lParam == hwndBUp2)
		{
			sk = '2';
			Set2();
			SearchPrev();
			Set2Back();
		}
		if ((HWND)lParam == hwndBDn2)
		{
			sk = '2';
			Set2();
			SearchNext();
			Set2Back();
		}
		if ((HWND)lParam == hwndBSr2)
		{
			sk = '2';
			InitSearch();
		}
		break;
	case WM_KEYDOWN:
		if (wParam == 27) PostQuitMessage(0);
		break;
	case WM_CHAR:
		SetFocus(hWndEK);
		SendMessage(hWndEK, (UINT)message, (WPARAM)wParam, (LPARAM)lParam);
		if (wParam == 1) SendMessage(hWndEK, EM_SETSEL, (WPARAM)0, (LPARAM)-1);
		break;
	case WM_ACTIVATE:
		SetFocus(hWndEK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		SaveRegistry();
		break;
	case WM_SIZE:
		GetWindowRect(hWnd, &Rect);
		wX = Rect.left;
		wY = Rect.top;
		wW = Rect.right - Rect.left;
		wH = Rect.bottom - Rect.top;
		MoveWindow(hWndEK, 0, 0, wW - 46 - wW2015, 19, TRUE);
		MoveWindow(hwndB1, wW - 45 - wW2015, 1, 18, 18, TRUE);
		MoveWindow(hwndB2, wW - 26 - wW2015, 1, 18, 9, TRUE);
		MoveWindow(hwndB3, wW - 26 - wW2015, 10, 18, 9, TRUE);
		MoveWindow(hWndES1, 19, 20, wW - 65 - wW2015, 19, TRUE);
		MoveWindow(hwndBUp1, 0, 21, 18, 18, TRUE);
		MoveWindow(hwndBDn1, wW - 26 - wW2015, 21, 18, 18, TRUE);
		MoveWindow(hwndBSr1, wW - 45 - wW2015, 21, 18, 18, TRUE);
		MoveWindow(hWndEB1, 0, 40, wW - 8 - wW2015, (int)(er*wH), TRUE);
		MoveWindow(hWndES2, 19, (int)(er*wH) + 41, wW - 65 - wW2015, 19, TRUE);
		MoveWindow(hwndBUp2, 0, (int)(er*wH) + 41 + 1, 18, 18, TRUE);
		MoveWindow(hwndBDn2, wW - 26 - wW2015, (int)(er*wH) + 41 + 1, 18, 18, TRUE);
		MoveWindow(hwndBSr2, wW - 45 - wW2015, (int)(er*wH) + 41 + 1, 18, 18, TRUE);
		MoveWindow(hWndEB2, 0, (int)(er*wH) + 41 + 1 + 19, wW - 8 - wW2015, wH - ((int)(er*wH) + 41 + 1 + 19) - 27 - wW2015 - wH2015, TRUE);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT APIENTRY EKWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_LBUTTONDBLCLK: {sk = 'k'; InitSearch(); return 0;}; break;
	case WM_KEYDOWN: if (wParam == VK_ESCAPE) PostQuitMessage(0); break;
	case WM_CHAR:
		if (wParam == 13) { sk = 'k'; InitSearch(); }
		if (wParam == 1) SendMessage(hWndEK, EM_SETSEL, (WPARAM)0, (LPARAM)-1);
		break;
	}
	return CallWindowProc(OldWndProc, hWnd, uMsg, wParam, lParam);
}

LRESULT APIENTRY ES1WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_LBUTTONDBLCLK: {sk = '1'; InitSearch(); return 0;}; break;
	case WM_KEYDOWN: if (wParam == VK_ESCAPE) PostQuitMessage(0); break;
	case WM_CHAR: if (wParam == 13) { sk = '1'; InitSearch(); } break;
	}
	return CallWindowProc(OldWndProc, hWnd, uMsg, wParam, lParam);
}

LRESULT APIENTRY ES2WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_LBUTTONDBLCLK: {sk = '2'; InitSearch(); return 0;}; break;
	case WM_KEYDOWN: if (wParam == VK_ESCAPE) PostQuitMessage(0); break;
	case WM_CHAR: if (wParam == 13) { sk = '2'; InitSearch(); } break;
	}
	return CallWindowProc(OldWndProc, hWnd, uMsg, wParam, lParam);
}

LRESULT APIENTRY EBWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		break;
	case WM_CHAR:
		if (wParam == 13)
		{
			SendMessage(hWndEB1, WM_COPY, (WPARAM)NULL, (LPARAM)NULL);
			SendMessage(hWndES2, WM_SETTEXT, (WPARAM)0, (LPARAM)NULL);
			SendMessage(hWndES2, WM_PASTE, (WPARAM)NULL, (LPARAM)NULL);
			sk = '2';
			InitSearch();
			return 0;
		}
		if (wParam == 26)
		{
			SendMessage(hWndEB1, WM_COPY, (WPARAM)NULL, (LPARAM)NULL);
			SendMessage(hWndES1, WM_SETTEXT, (WPARAM)0, (LPARAM)NULL);
			SendMessage(hWndES1, WM_PASTE, (WPARAM)NULL, (LPARAM)NULL);
			sk = '1';
			InitSearch();
			return 0;
		}
		if (wParam == 24)
		{
			SendMessage(hWndEB1, WM_COPY, (WPARAM)NULL, (LPARAM)NULL);
			SendMessage(hWndES2, WM_SETTEXT, (WPARAM)0, (LPARAM)NULL);
			SendMessage(hWndES2, WM_PASTE, (WPARAM)NULL, (LPARAM)NULL);
			sk = '2';
			InitSearch();
			return 0;
		}
		break;
	}
	return CallWindowProc(OldWndProc, hWnd, uMsg, wParam, lParam);
}

void InitSearch()
{
	if (sk == 'k')
	{
		SendMessage(hWndEK, EM_GETLINE, (WPARAM)0, (LPARAM)dWgs);
		LngWgs = SendMessage(hWndEK, EM_LINELENGTH, (WPARAM)0, (LPARAM)0);
		dWgs[LngWgs++] = TEXT(' ');
		sk = '1';
		Set1();
		SearchNorm();
		Set1Back();
		sk = '2';
		Set2();
		SearchNorm();
		Set2Back();
		sk = 'k';
	}
	if (sk == '1')
	{
		SendMessage(hWndES1, EM_GETLINE, (WPARAM)0, (LPARAM)dWgs);
		LngWgs = SendMessage(hWndES1, EM_LINELENGTH, (WPARAM)0, (LPARAM)0);
		dWgs[LngWgs++] = TEXT(' ');
		Set1();
		SearchNorm();
		Set1Back();
	}
	if (sk == '2')
	{
		SendMessage(hWndES2, EM_GETLINE, (WPARAM)0, (LPARAM)dWgs);
		LngWgs = SendMessage(hWndES2, EM_LINELENGTH, (WPARAM)0, (LPARAM)0);
		dWgs[LngWgs++] = TEXT(' ');
		Set2();
		SearchNorm();
		Set2Back();
	}
}

void EndSearch(void)
{
	dWgf[LngWgf] = 0;
	dBgf[LngBgf] = 0;
	if (sk == '1')
	{
		SendMessage(hWndES1, WM_SETTEXT, (WPARAM)0, (LPARAM)dWgf);
		SendMessage(hWndEB1, WM_SETTEXT, (WPARAM)0, (LPARAM)dBgf);
	}
	if (sk == '2')
	{
		SendMessage(hWndES2, WM_SETTEXT, (WPARAM)0, (LPARAM)dWgf);
		SendMessage(hWndEB2, WM_SETTEXT, (WPARAM)0, (LPARAM)dBgf);
	}
}

void Set1()
{
	hf = hf1;
	dp = dp1;
	for (int bf = 0; bf < 4096; bf++) buffer[bf] = buffer1[bf];
	HshMin = HshMin1;
	HshMax = HshMax1;
	iCurPos = iCurPos1;
	iCurBufPos = iCurBufPos1;
}
void Set1Back()
{
	dp1 = dp;
	for (int bf = 0; bf < 4096; bf++) buffer1[bf] = buffer[bf];
	iCurPos1 = iCurPos;
	iCurBufPos1 = iCurBufPos;
}
void Set2()
{
	hf = hf2;
	dp = dp2;
	for (int bf = 0; bf < 4096; bf++) buffer[bf] = buffer2[bf];
	HshMin = HshMin2;
	HshMax = HshMax2;
	iCurPos = iCurPos2;
	iCurBufPos = iCurBufPos2;
}
void Set2Back()
{
	dp2 = dp;
	for (int bf = 0; bf < 4096; bf++) buffer2[bf] = buffer[bf];
	iCurPos2 = iCurPos;
	iCurBufPos2 = iCurBufPos;
}
