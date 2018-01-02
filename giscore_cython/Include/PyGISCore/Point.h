//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     6.0           
//                                                           
//!  \file Point.h
//!  \brief Class 。
//!  \details 。
//!  \author liyq。
//!  \attention 
//!   Copyright (c) 1996-2010 SuperMap Software Limited Company.  <br> 
//!   All Rights Reserved.
//!  \version 6.0
//////////////////////////////////////////////////////////////////////////

#ifndef POINT_INCLUDE_H
#define POINT_INCLUDE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PyGISCore/Size.h"
#include <vector>

using namespace std;

class Size;
//!  \brief 二维坐标点，int型，常用来表达屏幕坐标点或设备坐标点
class GISCORE_API Point  
{
public:
	//! \brief 点的横坐标
	int x;
	//! \brief 点的纵坐标
	int y;
public:

	//! \brief 		缺省构造函数
	Point();

	//! \brief 		默认析构函数
	~Point();

	//! \brief 		带参构造函数	
	//! \param 		nX			横坐标
	//! \param 		nY			纵坐标		
	Point(int nX, int nY);	

	//! \brief 		拷贝构造函数	
	//! \param 		sz					
	Point(const Size& sz);

	//! \brief 		绕点旋转
	//! \param 		pntAnchor	中心点
	//! \param 		dRadian		顺时针旋转角度(弧度)	
	void Rotate(const Point& pntAnchor, double dRadian);

	//! \brief 		绕点旋转
	//! \param 		pntAnchor	中心点
	//! \param 		dCos		余弦值
	//! \param 		dSin		正弦值	
	void Rotate(const Point& pntAnchor, double dCos, double dSin);

	//! \brief 		点偏移
	//! \param 		szValue		偏移量	
	void Offset(const Size &szValue);

	//! \brief 		点偏移
	//! \param 		nOffsetX	横坐标偏移
	//! \param 		nOffsetY	纵坐标偏移	
	void Offset(int nOffsetX, int nOffsetY);

	//! \brief 		重载 == 
	//! \return 	返回pntStart与pntEnd的比较结果，相等返回true，不等返回false。
	friend GISCORE_API bool operator==(const Point& pntStart,const Point& pntEnd);

	//! \brief 		重载 != 
	//! \return 	返回pntStart与pntEnd的比较结果，不等返回true，相等返回false。	
	friend GISCORE_API bool operator!=(const Point& pntStart,const Point& pntEnd);			

	//! \brief 		重载 = 	
	Point& operator=(const Size& sz);

	//! \brief 		重载 = 	
	Point& operator=(const Point& pnt);

	//! \brief 		重载 += 
	Point& operator+=(const Point& pnt);

	//! \brief 		重载 += 	
	Point& operator+=(const Size& sz);

	//! \brief 		重载 -= 	
	Point& operator-=(const Point& pnt);

	//! \brief 		重载 -= 
	Point& operator-=(const Size& sz);	

	//! \brief 		重载 -(取相反数) 
	//! \return 	Point
	//! \remarks 	
	Point operator-() const;		

	//! \brief 重载 <
	bool operator<(const Point& pt) const;

	//! \brief 		重载 +
	friend GISCORE_API Point operator+(const Point& pntStart,const Point& pntEnd);

	//! \brief 		重载 +	
	friend GISCORE_API Point operator+(const Point& pnt,const Size& sz);

	//! \brief 		重载 +	
	friend GISCORE_API Point operator+(const Size& sz,const Point& pnt);	

	//! \brief 		重载 -	
	friend GISCORE_API Point operator-(const Point& pntStart,const Point& pntEnd);

	//! \brief 		重载 -
	friend GISCORE_API Point operator-(const Point& pnt,const Size& sz);

	//! \brief 		重载 -
	friend GISCORE_API Point operator-(const Size& sz,const Point& pnt);
};

typedef vector<Point> Points;

#endif
