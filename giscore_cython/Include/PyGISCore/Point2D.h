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

#ifndef POINT2D_INCLUDE_H
#define POINT2D_INCLUDE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PyGISCore/Size2D.h"
#include "PyGISCore/Point.h"

class GISCORE_API Point2D
{
public:
	//! \brief 点的横坐标
	double x;
	//! \brief 点的纵坐标
	double y;

public:

	//! \brief  	缺省构造函数
	Point2D();

	//! \brief  	默认析造函数
	~Point2D();

	//! \brief 		带参构造函数	
	//! \param 		dX			横坐标
	//! \param 		dY			纵坐标
	Point2D(double dX,double dY);

	//! \brief 		拷贝构造函数	
	//! \param 		sz			
	Point2D(const Size2D& sz);

	//! \brief 		拷贝构造函数	
	//! \param 		sz			
	Point2D(const Point2D& pnt);

	//! \brief 		绕点旋转
	//! \param 		pntAnchor	中心点
	//! \param 		dRadian		旋转角度(弧度)	
	void Rotate(const Point2D& pntAnchor, double dRadian);

	//! \brief 		绕点旋转
	//! \param 		pntAnchor	中心点
	//! \param 		dCos		余弦值
	//! \param 		dSin		正弦值
	void Rotate(const Point2D& pntAnchor, double dCos, double dSin);

	//! \brief 		点偏移
	//! \return 	void
	//! \param 		szValue		偏移量 
	void Offset(const Size2D &szValue);

	//! \brief 		点偏移
	//! \param 		nOffsetX	横坐标偏移
	//! \param 		nOffsetY	纵坐标偏移
	void Offset(double dOffsetX, double dOffsetY);

	//! \brief 		判断和当前点是否相等
	//! \param 		pntAnchor	要判断的点
	//! \param 		dTolerance	判断容限
	bool EQ(const Point2D& pntAnchor, double dTolerance)const;

	//! \brief 		重载 = 	
	Point2D& operator=(const Size2D& sz);

	//! \brief 		重载 = 	
	Point2D& operator=(const Point2D& pnt2);

	//! \brief 		重载 = 
	Point2D& operator=(const Point& pnt);

	//! \brief 		重载 += 
	Point2D& operator+=(const Point2D& pnt);

	//! \brief 		重载 += 
	Point2D& operator+=(const Size2D& sz);

	//! \brief 		重载 -= 
	Point2D& operator-=(const Point2D& pnt);

	//! \brief 		重载 -= 
	Point2D& operator-=(const Size2D& sz);	

	//! \brief 		重载 - 负号 
	Point2D operator-() const;		

	//! \brief 		重载 == 
	//! \return 	返回是否相等
	friend GISCORE_API bool operator==(const Point2D& pntStart,const Point2D& pntEnd);

	//! \brief 		重载 !=		
	//! \return 	返回是否不相等
	friend GISCORE_API bool operator!=(const Point2D& pntStart,const Point2D& pntEnd);

	//! \brief 		重载 + 
	friend GISCORE_API Point2D operator+(const Point2D& pntStart,const Point2D& pntEnd);

	//! \brief 		重载 + 
	friend GISCORE_API Point2D operator+(const Point2D& pntStart,const Size2D& pntEnd);

	//! \brief 		重载 + 
	friend GISCORE_API Point2D operator+(const Size2D& sz,const Point2D& pnt);	

	//! \brief 		重载 - 
	friend GISCORE_API Point2D operator-(const Point2D& pntStart,const Point2D& pntEnd);

	//! \brief 		重载 - 
	friend GISCORE_API Point2D operator-(const Point2D& pntStart,const Size2D& sz);

	//! \brief 		重载 - 
	friend GISCORE_API Point2D operator-(const Size2D& sz,const Point2D& pnt);	

	//! \brief 		重载 < 
	friend GISCORE_API bool operator<(const Point2D& pntStart,const Point2D& pntEnd);
};

typedef vector<Point2D> Point2Ds;

#endif
