//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file Size2D.h
//!  \brief Class 。
//!  \details 。
//!  \author liyq。
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef SIZE2D_INCLUDE_H
#define SIZE2D_INCLUDE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PyGISCore/exports.h"

//!  \brief 二维矩形大小类。该类存储了矩形的长度cx和宽度cy，类型为double型。
class GISCORE_API Size2D  
{
public:

	//! \brief 		缺省构造函数
	Size2D();

	//! \brief 		缺省构造函数
	~Size2D();

	//! \brief 		带参构造函数
	//! \param 		cx		长度
	//! \param 		cy		宽度
	Size2D(double dX, double dY);

	//! \brief 		重载==
	friend GISCORE_API bool operator==(const Size2D& szSrc, const Size2D& sztag);

	//! \brief 		重载!=
	friend GISCORE_API bool operator!=(const Size2D& szSrc, const Size2D& szTag);	

	//! \brief 		重载 +=
	Size2D& operator+=(const Size2D& sz);

	//! \brief 		重载 -=
	Size2D& operator-=(const Size2D& sz);	

	//! \brief 		重载 -
	Size2D operator-() const;	

	//! \brief 		重载 +
	friend GISCORE_API Size2D operator+(const Size2D& szSrc, const Size2D& szTag);

	//! \brief 		重载 -
	friend GISCORE_API Size2D operator-(const Size2D& szSrc,const Size2D& szTag);	

public:
	//! \brief 		长度
	double cx;
	//! \brief 		宽度
	double cy;
};

#endif
