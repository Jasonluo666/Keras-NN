#include <windows.h>
#include <shellapi.h>
#include <stdio.h>
#include <tchar.h>

void main()
{
	SHELLEXECUTEINFO shExecInfo = { 0 };
	shExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	shExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	shExecInfo.hwnd = NULL;
	shExecInfo.lpVerb = _T("open");
	shExecInfo.lpFile = _T("C:/Users/ljsPC/Desktop/AI project/Skat-Game/Skat/x64/Debug/Skat.exe");
	shExecInfo.lpParameters = NULL;
	shExecInfo.lpDirectory = NULL;
	shExecInfo.nShow = SW_SHOW;
	shExecInfo.hInstApp = NULL;


	for (int count = 0; count < 100; count++) {
		ShellExecuteEx(&shExecInfo);
		WaitForSingleObject(shExecInfo.hProcess, INFINITE);
		printf("turn %d finished\n", count + 1);
	}

	system("pause");
}