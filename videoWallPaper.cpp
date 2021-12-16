#ifndef UNICODE
#define UNICODE
#define UNICODE_WAS_UNDEFINED
#endif

#include <Windows.h>

#ifdef UNICODE_WAS_UNDEFINED
#undef UNICODE
#endif
#include <stdio.h>

BOOL CALLBACK EnumWindowsProc(_In_ HWND hwnd, _In_ HWND Lparam){
	HWND hDefView = FindWindowExW(hwnd,0,L"SHELLDLL_DefView",0);
	if(hDefView!=0){
		HWND hWorkerw = FindWindowExW(0,hwnd,L"WorkerW",0);
		ShowWindow(hWorkerw,SW_HIDE);
		return FALSE;
	}
	return TRUE;
}

int main(int argc, char **argv){
	/*
	//获取屏幕高度，使用ffplay可以设置视频的高宽,
	//也可以用-fs参数设置全屏，这个全屏参数指的大概是按照视频的分辨率，而不是屏幕的分辨率，不好用
	//替换为其他播放程序可能会方便使用
    int cx = GetSystemMetrics(SM_CXSCREEN);
    int cy = GetSystemMetrics(SM_CYSCREEN);
    printf("screen %d %d\n",cx,cy);
	*/
	LPWSTR lpBuffer = L" C:\\Users\\hello\\Desktop\\ED.wmv  -noborder -x 1920 -y 1080 -loop 0";
    LPCWSTR lpAppName = L"D:\\ffmpeg-2021-09-11\\bin\\ffplay.exe";
	STARTUPINFO si {0};
	PROCESS_INFORMATION pi {0};
	
	if(CreateProcess(lpAppName,lpBuffer,0,0,0,0,0,0,&si,&pi)){
		Sleep(200);
		HWND hProgman = FindWindowEx(0,0,L"Progman",0);
		SendMessageTimeout(hProgman,0x52c,0,0,0,100,0);
		HWND hffplay = FindWindowEx(0,0,L"SDL_app",0);
		SetParent(hffplay,hProgman);
		EnumWindows(EnumWindowsProc,0);
	}
	return 0;
}