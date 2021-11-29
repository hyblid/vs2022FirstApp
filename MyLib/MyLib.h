#pragma once

#ifndef EXT_MYLIB
  #ifdef DLL_BUILD
     #define EXT_MYLIB __declspec(dllexport)
  #else 
     #pragma comment(lib, "MyLib.lib")
     #define EXT_MYLIB __declspec(dllimport)
  #endif
#endif // !EXT_MYLIB


extern int EXT_MYLIB max_size;
