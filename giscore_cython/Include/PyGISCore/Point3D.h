//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file headerfile.h
//!  \brief Class 。
//!  \details 。
//!  \author liyq。
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef POINT3D_INCLUDE_H
#define POINT3D_INCLUDE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PyGISCore/Point.h"

class GISCORE_API Point3D  
{
public:
	//! \brief 点的x轴坐标
	double x;
	//! \brief 点的y轴坐标
	double y;
	//! \brief 点的z轴坐标
	double z;

public:
	//! \brief  	默认构造函数
	Point3D();

	//! \brief  	缺省析构函数
	~Point3D();

	//! \brief  带参数构造函数
	Point3D(double xx, double yy, double zz);	

public:	
	//! \brief 		重载 = 
	Point3D& operator=(const Point3D& s);

	//! \brief 		重载 += 
	Point3D& operator+=(const Point3D& p);

	//! \brief 		重载 -= 
	Point3D& operator-=(const Point3D& p);

	//! \brief 		重载 *= 
	Point3D& operator*=(double c);

	//! \brief 		重载 /= 
	Point3D& operator/=(double c);

	//! \brief 		重载 - 负号
	Point3D operator-() const;

	//! \brief 		重载 == 
	friend GISCORE_API bool operator==(const Point3D& p,const Point3D& q);

	//! \brief 		重载 !=
	friend GISCORE_API bool operator!=(const Point3D& p,const Point3D& q);			

};

typedef vector<Point3D> Point3Ds;

#endif
