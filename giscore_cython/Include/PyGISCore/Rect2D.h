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

#ifndef RECT2D_INCLUDE_H
#define RECT2D_INCLUDE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PyGISCore/Point2D.h"
#include "PyGISCore/Size2D.h"

//!  \brief 矩形对象类，存储了矩形的左上角点、右下角点的(x,y)坐标，坐标值为double类型。
class GISCORE_API Rect2D  
{
public:
	//! \brief 矩形左边界
	double left;
	//! \brief 矩形上边界
	double top;
	//! \brief 矩形右边界。left<right
	double right;
	//! \brief 矩形下边界。bottom < top
	double bottom;

public:

	//! \brief 构造函数一个二维矩形对象
	Rect2D();

	// fansc 加一个拷贝构造，发现在GCC编译器下，使用OpenMP时拷贝UGRect2D时会导致编译器内部出错
	//! \brief 拷贝构造函数
	Rect2D(const Rect2D& rc);

	//! \brief 		缺省析造函数
	~Rect2D();

	//! \brief 		构造函数一个二维矩形对象
	//! \param 		nLeft	矩形左上角点的x轴坐标
	//! \param 		nTop	矩形左上角点的y轴坐标
	//! \param 		nRight	矩形右下角点的x轴坐标
	//! \param 		nBottom	矩形右下角点的y轴坐标
	//! \remarks 	请确保nLeft<nRight,nTop<nBottom
	Rect2D(double dLeft,double dTop,double dRight,double dBottom);

	//! \brief 		构造函数一个二维矩形对象
	//! \param 		pnt	左下角坐标
	//! \param 		sz	矩形的大小
	Rect2D(const Point2D& pnt,const Size2D& sz);

	//! \brief 		构造函数一个二维矩形对象
	//! \param 		pntTL	左上角坐标
	//! \param 		pntBR   右下角坐标
	Rect2D(const Point2D& pntTL,const Point2D& pntBR);	

	//! \brief 		重载 =
	Rect2D& operator=(const Rect2D& rc);

	//! \brief 		设置矩形参数
	//! \param 		dLeft	矩形左上角点的x轴坐标
	//! \param 		dTop	矩形左上角点的y轴坐标
	//! \param 		dRight	矩形右下角点的x轴坐标
	//! \param 		dBottom	矩形右下角点的y轴坐标
	void SetRect(double dLeft,double dTop,double dRight,double dBottom);

	//! \brief 		设置矩形参数
	//! \param 		pntTL	左上角坐标
	//! \param 		pntBR	右下角坐标
	void SetRect(const Point2D& pntTL,const Point2D& pntBR);

	//! \brief 		将矩形置为空
	//! \remarks 	左上角、右下角点坐标都设为0
	void SetEmpty();

	//! \brief 		判断矩形是否为空或是否合法
	//! \return 	矩形为空返回true，矩形不为空返回false
	//! \remarks 	如果符合left=right,top=bottom规则，返回true，认为矩形为空。
	bool IsEmpty() const;

	//! \brief 		矩形是否为未初始化
	//! \return 	如果符合left==right==top==bottom==0规则，则返回true，否则，返回false
	bool IsNull() const;

	//! \brief 		矩形的宽度
	//! \return 	返回right-left的值(整型)
	double Width() const;

	//! \brief 		矩形的高度
	//! \return 	返回top-bottom的值(整型)
	double  Height() const;

	//! \brief 		获取矩形的左上角点
	Point2D& TopLeft();

	//! \brief 		获取矩形的左上角点
	//! \remarks 	如果矩形对象为const类型，则将调用本接口
	const Point2D& TopLeft() const;	


	//! \brief 		获取矩形右上角坐标点
	Point2D TopRight() const;

	//! \brief 		获取矩形右下角坐标点
	Point2D& BottomRight();	

	//! \brief 		获取矩形右下角坐标点
	//! \remarks 	如果矩形对象为const类型，则将调用本接口
	const Point2D& BottomRight() const;

	//! \brief 		获取矩形左下角坐标点
	Point2D BottomLeft() const;

	//! \brief 		获取矩形的中心点
	//! \remarks 	矩形对角线的交点
	Point2D CenterPoint() const;

	//! \brief 		获取矩形的大小
	Size2D Size() const;

	//! \brief 		交换left与right的值
	void SwapLeftRight();

	//! \brief 		交换top与bottom的值	
	void SwapTopBottom();	

	//! \brief 		判断点是否在矩形中
	//! \param 		pnt	坐标点
	//! \return		若点在矩形中或在矩形边界上，则返回true，否则返回false。
	bool PtInRect(const Point2D& pnt) const;

	//! \brief 		判断当前矩形是否包含矩形rc
	//! \param 		rc 矩形
	//! \return		若当前矩形包含矩形rc，则返回ture，否则，返回false。
	//! \image html Contains.png
	bool Contains(const Rect2D& rc) const;

	//! \brief 		判断当前矩形是否被矩形rc包含
	//! \param 		rc	矩形
	//! \return		若当前矩形被矩形rc包含，则返回ture，否则，返回false。
	//! \image html within.png
	bool Withins(const Rect2D& rc) const;

	//! \brief 		判断当前矩形是否与矩形rc相交
	//! \param 		rc	矩形
	//! \returen	相交返回true，否则，返回false。
	bool IsIntersect(const Rect2D& rc) const;

	//! \brief 		规范矩形，确保left<=right,top<=bottom	
	void Normalize();

	//! \brief 		对矩形进行偏移
	//! \param 		dX	横坐标偏移量
	//! \param 		dY	纵坐标偏移量
	void Offset(double dX,double dY);

	//! \brief 		对矩形进行偏移
	//! \param 		sz	横纵坐标偏移量
	void Offset(const Size2D& sz);

	//! \brief 		对矩形进行偏移
	//! \param 		pnt	横纵坐标偏移量
	void Offset(const Point2D& pnt);

	//! \brief 		对矩形进行放大
	//! \param 		nMargin	横纵放大比例 	
	void Inflate(double dMargin);

	//! \brief 		对矩形进行放大
	//! \param 		dHormargin	横坐标放大比例
	//! \param 		dVermargin	总坐标放大比例	
	void Inflate(double dHorMargin,double dVerMargin);

	//! \brief 		对矩形进行放大
	//! \param 		nLeftMargin	左上角点沿x轴向左的偏移量
	//! \param 		nTopMargin	左上角点沿y轴向上的偏移量
	//! \param 		nRightMargin    右下角点沿x轴向右的偏移量
	//! \param 		nBottomMargin	右下角点沿y轴向下的偏移量
	void Inflate(double nLeftMargin,double nTopMargin,double nRightMargin,double nBottomMargin);

	//! \brief 		对矩形进行缩小
	//! \param 		dMargin	横纵缩小比例	
	void Deflate(double dMargin);

	//! \brief 		对矩形进行缩小
	//! \param 		dHorMargin	横坐标缩小比例
	//! \param 		dVerMargin	总坐标缩小比例
	void Deflate(double dHorMargin,double dVerMargin);

	//! \brief 		对矩形进行缩小
	//! \param 		dLeftMargin	左上角点沿x轴向右的偏移量
	//! \param 		dTopMargin	左上角点沿y轴向下的偏移量
	//! \param 		dRightMargin 右下角点沿x轴向左的偏移量	
	//! \param 		dBottomMargin 右下角点沿y轴向上的偏移量	
	void Deflate(double dLeftMargin,double dTopMargin,double dRightMargin,double dBottomMargin);

	//! \brief 		矩形合并
	//! \param 		pnt	合并的点
	//! \image html union.png
	void Union(const Point2D& pnt);

	//! \brief 		矩形合并
	//! \param 		rc 用来与原矩形合并的矩形rc
	//! \image html union2.png
	void Union(const Rect2D& rc);	

	//! \brief 		矩形求交
	//! \param 		rc 用来与原矩形求交的矩形rc
	//! \param		当前矩形为与rc求交的结果矩形
	//! \image html Intersect2.png
	bool IntersectRect(const Rect2D& rc);

	//! \brief 		矩形求交
	//! \param 		rc1 用来求交的矩形	
	//! \param 		rc2	用来求交的矩形
	//! \remarks	当前矩形为rc1，与rc2求交后的结构矩形。
	//! \image html Interset.png
	bool IntersectRect(const Rect2D& rc1,const Rect2D& rc2);

	//! \brief 		当前矩形与旋转之后的矩形求并
	//! \param 		pntOrg 中心点
	//! \param 		dbAngle 旋转角度
	//! \image html union3.png
	void UnionRotate(const Point2D &pntOrg, double dbAngle);

	//! \brief 判断Rect2D对象是否有效
	bool IsValid() const;

	void InflateRect(double x, double y);

	//! \brief 		重载 ==
	friend GISCORE_API bool operator==(const Rect2D& rcStart,const Rect2D& rcEnd);

	//! \brief 		重载 !=
	friend GISCORE_API bool operator!=(const Rect2D& rcStart,const Rect2D& rcEnd);
};

#endif
