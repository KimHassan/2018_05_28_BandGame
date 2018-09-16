#include "stdafx.h"

int main(int argc, char* argv[])
{
	//DEVMODE devmode;
	//int w, h;
	//w = (int)GetSystemMetrics(SM_CXSCREEN);
	//h = (int)GetSystemMetrics(SM_CXSCREEN);

	//ZeroMemory(&devmode, sizeof(DEVMODE));
	//devmode.dmSize = sizeof(DEVMODE);
	//devmode.dmBitsPerPel = 32;
	//devmode.dmPelsWidth = 1280;
	//devmode.dmPelsHeight = 720;
	//devmode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
	//ChangeDisplaySettings(&devmode, CDS_FULLSCREEN);

	CSystem* pSystem = new CSystem;

	pSystem->Initialize();

	pSystem->Run();

	pSystem->Terminate();

	delete pSystem;

	return 0;
}

