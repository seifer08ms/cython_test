//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file Size.h
//!  \brief Class 。
//!  \details 。
//!  \author liyq。
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef SIZE_INCLUDE_H
#define SIZE_INCLUDE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PyGISCore/exports.h"

class GISCORE_API Size
{
public:
	//! \brief 		长度
	int cx;
	//! \brief 		宽度
	int cy;

public:

	//! \brief 		缺省构造函数
	Size();	

	//! \brief 		缺省析构函数
	~Size();	

	//! \brief 		带参构造函数
	//! \param 		nX		长度
	//! \param 		nY		宽度
	Size(int nX, int nY);

	//! \brief 		重载 +=
	Size& operator+=(const Size& sz);

	//! \brief 		重载 -=
	Size& operator-=(const Size& sz);	

	//! \brief 		重载 -
	Size operator-() const;	

	//! \brief 		重载==
	friend  GISCORE_API bool operator==(const Size& szSrc,const Size& szTag);

	//! \brief 		重载!=
	friend  GISCORE_API bool operator!=(const Size& szSrc,const Size& szTag);

	//! \brief 		重载 +
	friend  GISCORE_API Size operator+(const Size& szSrc,const Size& szTab);

	//! \brief 		重载 -
	friend  GISCORE_API Size operator-(const Size& szSrc,const Size& szTab);
};

#endif
