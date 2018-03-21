#define UNICODE
#include <windows.h>

extern	HANDLE	hf;
extern	char	sk;

extern	int	LngWgs;
int	LngWgsN;
extern	int	LngWgf;
int	LngWgfN;
extern	int	LngBgf;

extern	WCHAR	dWgs[64];
WCHAR	dWgsN[64];
extern	WCHAR	dWgf[64];
WCHAR	dWgfN[64];
extern	WCHAR	dBgf[8192];

extern	long HshMin;
extern	long HshMax;

extern	long	iCurPos;
extern	int		iCurBufPos;

void	ByteEToUnicode(byte smbl, char wb);
void	ByteRToUnicode(byte smbl, char wb);

void	SearchNormHsh(void);
void	SearchNormBin(void);
void	SearchNormSmpW(void);
void	SearchNormSmpB(void);
int		SearchNormBufNr(int sym, bool lsn);
int		SearchNormBufJd(int sym, bool lsn);
void	EndSearch(void);

extern int dp;
extern byte buffer[4096];
extern DWORD lpNumberOfBytesRead;


void SearchNorm(void)
{
	SearchNormHsh();
	SearchNormBin();
}

void SearchNormHsh()
{
	iCurPos = (LONG)((HshMax + HshMin) / 2);
	SetFilePointer(hf, iCurPos, NULL, FILE_BEGIN);
}

void Normalisieren()
{
	int n = 0;
	LngWgsN = LngWgs;
	for (int m = 0; m <= LngWgs; m++)
	{
		dWgsN[m + n] = dWgs[m];
		if (dWgs[m] == 0xE4) dWgsN[m + n] = 0x61;
		if (dWgs[m] == 0xF6) dWgsN[m + n] = 0x6F;
		if (dWgs[m] == 0xFC) dWgsN[m + n] = 0x75;
		if (dWgs[m] == 0xC4) dWgsN[m + n] = 0x61;
		if (dWgs[m] == 0xD6) dWgsN[m + n] = 0x6F;
		if (dWgs[m] == 0xDC) dWgsN[m + n] = 0x75;
		if ((dWgs[m] >= 0x41) && (dWgs[m] <= 0x5A)) dWgsN[m + n] = dWgs[m] + 0x20;
		if (dWgs[m] == 0xDF)
		{
			dWgsN[m + n] = 0x73;
			dWgsN[m + (++n)] = 0x73;
			LngWgsN++;
		}
		if (dWgs[m] == 0x2D)
		{
			n--;
			LngWgsN--;
		}
	}
}

void SearchNormBin()
{

	int n = 0;
	LngWgsN = LngWgs;
	for (int m = 0; m <= LngWgs; m++)
	{
		dWgsN[m + n] = dWgs[m];
		if (dWgs[m] == 0xE4) dWgsN[m + n] = 0x61;
		if (dWgs[m] == 0xF6) dWgsN[m + n] = 0x6F;
		if (dWgs[m] == 0xFC) dWgsN[m + n] = 0x75;
		if (dWgs[m] == 0xC4) dWgsN[m + n] = 0x61;
		if (dWgs[m] == 0xD6) dWgsN[m + n] = 0x6F;
		if (dWgs[m] == 0xDC) dWgsN[m + n] = 0x75;
		if ((dWgs[m] >= 0x41) && (dWgs[m] <= 0x5A)) dWgsN[m + n] = dWgs[m] + 0x20;
		if (dWgs[m] == 0xDF)
		{
			dWgsN[m + n] = 0x73;
			dWgsN[m + (++n)] = 0x73;
			LngWgsN++;
		}
		if (dWgs[m] == 0x2D)
		{
			n--;
			LngWgsN--;
		}
	}

	while (true)
	{
		SearchNormSmpW();

		dWgf[LngWgf++] = TEXT(' ');

		int n = 0;
		LngWgfN = LngWgf;
		for (int m = 0; m <= LngWgf; m++)
		{
			dWgfN[m + n] = dWgf[m];
			if (dWgf[m] == 0xE4) dWgfN[m + n] = 0x61;
			if (dWgf[m] == 0xF6) dWgfN[m + n] = 0x6F;
			if (dWgf[m] == 0xFC) dWgfN[m + n] = 0x75;
			if (dWgf[m] == 0xC4) dWgfN[m + n] = 0x61;
			if (dWgf[m] == 0xD6) dWgfN[m + n] = 0x6F;
			if (dWgf[m] == 0xDC) dWgfN[m + n] = 0x75;
			if ((dWgf[m] >= 0x41) && (dWgf[m] <= 0x5A)) dWgfN[m + n] = dWgf[m] + 0x20;
			if (dWgf[m] == 0xDF)
			{
				dWgfN[m + n++] = 0x73;
				dWgfN[m + n] = 0x73;
				LngWgfN++;
			}
			if (dWgf[m] == 0x2D)
			{
				n--;
				LngWgfN--;
			}
		}
		//MessageBox(NULL, (LPCTSTR)dWgfN, TEXT("b"), MB_OK);

		if ((HshMax - HshMin) <= 1) break;

		int	b = 0;
		for (int pp = 0; pp < ((LngWgfN < LngWgsN) ? LngWgfN : LngWgsN); pp++)
		{
			if (dWgfN[pp] < dWgsN[pp]) b = -1;
			if (dWgfN[pp] > dWgsN[pp]) b = 1;
			if (b != 0) break;
		}

		if (b == 0) break;
		if (b == -1) HshMin = iCurPos;
		if (b == 1) HshMax = iCurPos;

		iCurPos = (LONG)((HshMax + HshMin) / 2);
		SetFilePointer(hf, iCurPos, NULL, FILE_BEGIN);
	}
	SearchNormSmpB();
	EndSearch();
}

void SearchNormSmpW()
{
	dp = 1;

	LngWgf = 0;
	LngBgf = 0;

	while (dp < 3)
	{
		ReadFile(hf, &buffer, 4096, &lpNumberOfBytesRead, NULL);
		iCurBufPos = 0;
		if (dp == 1) dp = dp + SearchNormBufNr(0x5C, false);
		if (dp == 2) dp = dp + SearchNormBufNr(0x5D, true);
	}
}

void SearchNormSmpB()
{
	dp = dp + SearchNormBufNr(0x5C, true);

	while (dp < 4)
	{
		ReadFile(hf, &buffer, 4096, &lpNumberOfBytesRead, NULL);
		iCurBufPos = 0;
		dp = dp + SearchNormBufNr(0x5C, true);
	}
}

void SearchNext()
{
	LngWgf = 0;
	LngBgf = 0;

	dp = 2 + SearchNormBufNr(0x5D, true);

	while (dp < 3)
	{
		ReadFile(hf, &buffer, 4096, &lpNumberOfBytesRead, NULL);
		iCurBufPos = 0;
		dp = dp + SearchNormBufNr(0x5D, true);
	}

	SearchNormSmpB();
	EndSearch();
}

void SearchPrev()
{
	LngWgf = 0;
	LngBgf = 0;

	iCurBufPos = iCurBufPos - 2;

	for (int n = 0; n <= 1; n++)
	{
		dp = 2 + SearchNormBufJd(0x5C, false);

		while (dp < 3)
		{
			SetFilePointer(hf, -8192, NULL, FILE_CURRENT);
			ReadFile(hf, &buffer, 4096, &lpNumberOfBytesRead, NULL);
			iCurBufPos = 4095;
			dp = dp + SearchNormBufJd(0x5C, false);
		}
	}

	iCurBufPos = iCurBufPos + 2;

	SearchNext();
	EndSearch();
}

int SearchNormBufNr(int sym, bool lsn)
{
	for (int i = iCurBufPos; i < 4096; i++)
	{
		if (buffer[i] == sym)
		{
			if (sym == 0x5D && lsn == true)	if (sk == '1') dBgf[LngBgf++] = 0x20;
			iCurBufPos = i + 1;
			return 1;
		}
		if (sym == 0x5D && lsn == true)
		{
			if (sk == '1')
			{
				ByteEToUnicode(buffer[i], 'w');
				ByteEToUnicode(buffer[i], 'b');
			}
			if (sk == '2')
			{
				ByteRToUnicode(buffer[i], 'w');
			}
		}
		if (sym == 0x5C && lsn == true)
		{
			if (sk == '1')
			{
				ByteEToUnicode(buffer[i], 'b');
			}
			if (sk == '2')
			{
				ByteRToUnicode(buffer[i], 'b');
			}
		}
	}
	return 0;
}

int SearchNormBufJd(int sym, bool lsn)
{
	for (int i = iCurBufPos; i >= 0; i--)
	{
		if (buffer[i] == sym)
		{
			iCurBufPos = i - 1;
			return 1;
		}
	}
	return 0;
}