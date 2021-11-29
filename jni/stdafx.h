// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef WIN32

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#pragma comment(lib,"dbghelp.lib")
#pragma comment(lib,"Psapi.lib")
#endif

#include <string>

#define LOG_HCDNDOWNLOADER			"cube"
#define LOG_HCDNDOWNLOADER_CREATOR		"cube_creator"
#define LOG_HCDNDOWNLOADER_TASK			"cube_task"
#define LOG_HCDNDOWNLOADER_CREATOREX		"cube_creatorex"
#define LOG_HCDNDOWNLOADER_TASKEX		"cube_taskex"
#define LOG_CUBE_CUPID_PLAYER			"cube_cupid_player"
#define LOG_CUBE_CHECKQSV               "cueb_checkqsv_jni"
#define LOG_CUBE_CHECKQSV_CALLBACK      "cueb_checkqsv_callback"
extern std::string g_cube_domain;

#define CUBE_GETPARAM_PRIMELEN              10240

#include <logger/include/InterfaceLogger.h>
using namespace psl::logger;

extern string g_cur_dll_dir;

// TODO: reference additional headers your program requires here
//#define CURL_SUPPORT_QSV