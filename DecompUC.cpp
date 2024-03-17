// FlatOut Ultimate Carnage Decompilation

// This is a decompilation of the Steam version of FlatOut Ultimate Carnage

// The way the new updates were done was by modifying the files around the game. Does this mean the Steam version could have been decompiled this whole time?

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// D3D9.DLL
#include <d3d9.h>

// Uses a newer version of Direct X, I don't know the NuGet command for it yet
// D3DX9_37.DLL

// GDI32.DLL
#include <wingdi.h>

// WINMM.DLL
// USER32.DLL
// SHELL32.DLL
// KERNEL32.DLL
#include <windows.h>

// XINPUT1_3.DLL
#include <xinput.h>

// I don't know where you'd get a Games for Windows Live DLL these days.
// XLIVE.DLL



/////////////////////////////////////////////////
//
// ROMU
// 
/////////////////////////////////////////////////
// The functions that are also found in FlatOut 2

// Something I found out that was a bit funny is that some data paths, including the cars, are still under FlatOut2

void CreateErrorMessageAndDie(const char* message, ...)
{
	char temp[1024];
	char body[1024];
	
	va_list list;
	va_start(list, message);
	vsprintf(temp, message, list);
	sprintf(body, "%s", temp);
	MessageBoxA(NULL, (LPCSTR)body, "Fatal error", MB_ICONERROR);
	ExitProcess(0);
}

// Change the value at 0x6F3DD0 to 0x5B2FB0 to force this function to be called.
void DoNotCallEver(void (**jmpTable)())
{
	// Normal jumptable that I think is a default value
	*jmpTable = LiteDb::vftable;
	CreateErrorMessageAndDie("Must not be called - ever");
	// They actually removed all code after that line, even the return op code that would have brought you back from calling this. If you were to bypass this error message who knows what would happen.
}

