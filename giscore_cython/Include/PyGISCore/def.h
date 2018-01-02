#ifndef DEF_INCLUDE_H
#define DEF_INCLUDE_H

#ifdef WIN32
#pragma warning(disable: 4251)
#pragma warning(disable: 4800)
#pragma warning(disable: 4018)
#endif

#include <string>

#ifdef _UGUNICODE
typedef std::wstring PyString;
typedef wchar_t Char;
#define _U(x)  L ## x
#else
typedef std::string PyString;
typedef char Char;
#define _U(x)	x
#endif

typedef unsigned short   Ushort;
typedef unsigned int     Uint;
typedef unsigned char    Uchar;

#ifdef WIN32
typedef unsigned __int64  Ulong;
typedef __int64           Long;
#else
typedef unsigned long long int Ulong;	
typedef long long int          Long;	
#endif 

#endif