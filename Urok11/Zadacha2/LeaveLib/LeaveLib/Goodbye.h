#pragma once
#include <string>

#ifdef LEAVELIB_EXPORTS 
#define LeavLib_API __declspec(dllexport)
#else 
#define LeavLib_API __declspec(dllimport)
#endif

class Leaver {
public:
	LeavLib_API std::string leave(std::string name);
};
