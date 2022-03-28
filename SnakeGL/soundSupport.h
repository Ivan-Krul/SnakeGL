#pragma once
#include <Windows.h>
#include <string>
#pragma comment(lib, "winmm.lib")

namespace soundSupport {
	void sound(std::wstring dir,DWORD mode) {
		PlaySound(dir.c_str(), NULL,mode);
	}
}
