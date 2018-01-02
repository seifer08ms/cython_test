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

#ifndef RECT_INCLUDE_H
#define RECT_INCLUDE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PyGISCore/Point.h"

//!  \brief 矩形对象类，存储了矩形的左上角点、右下角点的(x,y)坐标，坐标值为int型。
class GISCORE_API Rect  
{
public:
	//! \brief 矩形左上角点的x轴坐标
	int left;
	//! \brief 矩形左上角点的y轴坐标
	int top;
	//! \brief 矩形右下角点的x轴坐标
	int right;
	//! \brief 矩形右下角点的y轴坐标
	int bottom;		

public:

	//! \brief 		缺省构造函数
	Rect();	

	//! \brief 		缺省解析函数
	~Rect();	

	//! \brief 		构造函数一个二维矩形对象
	//! \param 		nLeft	矩形左上角点的x轴坐标
	//! \param 		nTop	矩形左上角点的y轴坐标
	//! \param 		nRight	矩形右下角点的x轴坐标
	//! \param 		nBottom	矩形右下角点的y轴坐标
	//! \remarks 	请确保nLeft<nRight,nTop<nBottom
	Rect(int nLeft,int nTop,int nRight,int nBottom);

	//! \brief 		带参构造函数
	//! \param 		pnt	左上角坐标
	//! \param 		sz	矩形的大小	
	Rect(const Point& pnt,const Size& sz);

	//! \brief 		带参构造函数
	//! \param 		pntTL	左上角坐标点
	//! \param 		pntBR   右下角坐标点	
	Rect(const Point& pntTL,const Point& pntBR);	

	//! \brief 		重载 =
	Rect& operator=(const Rect& rc);

	//! \brief 		设置矩形参数
	//! \param 		nLeft	矩形左上角点的x轴坐标
	//! \param 		nTop	矩形左上角点的y轴坐标
	//! \param 		nRight	矩形右下角点的x轴坐标
	//! \param 		nBottom	矩形右下角点的y轴坐标
	void SetRect(int nLeft,int nTop,int nRight,int nBottom);

	//! \brief 		设置矩形参数
	//! \param 		pntTL	左上角坐标
	//! \param 		pntBR	右下角坐标	
	void SetRect(const Point& pntTL,const Point& pntBR);

	//! \brief 		将矩形置为空
	//! \remarks 	左上角、右下角点坐标都设为0
	void SetEmpty();

	//! \brief 		判断矩形是否为空或是否合法
	//! \return 	矩形为空返回true，矩形不为空返回false
	//! \remarks 	如果不符合left<right,top<bottom规则，返回true，认为矩形为空。
	bool IsEmpty() const;

	//! \brief 		矩形是否为未初始化
	//! \return 	如果符合left==right==top==bottom==0规则，则返回true，否则，返回false
	bool IsNull() const;

	//! \brief 		矩形的宽度
	//! \return 	返回right-left的值(整型)
	int Width() const;

	//! \brief 		矩形的高度
	//! \return 	返回top-bottom的值(整型)
	int  Height() const;

	//! \brief 		获取矩形的左上角点
	Point& TopLeft();

	//! \brief 		获取矩形的左上角点
	//! \remarks 	如果矩形对象为const类型，则将调用本接口
	const Point& TopLeft() const;	

	//! \brief 		获取矩形右下角坐标点
	Point& BottomRight();		

	//! \brief 		获取矩形右下角坐标点
	//! \remarks 	如果矩形对象为const类型，则将调用本接口
	const Point& BottomRight() const;

	//! \brief 		获取矩形的中心点
	Point CenterPoint() const;

	//! \brief 		获取矩形的大小
	Size GetSize() const;

	//! \brief 		交换left与right的值
	void SwapLeftRight();

	//! \brief 		交换top与bottom的值	
	void SwapTopBottom();	

	//! \brief 		判断点是否在矩形中
	//! \param 		pnt	坐标点
	//! \return		若点在矩形中或在矩形边界上，则返回true，否则返回false。
	bool PtInRect(const Point& pnt) const;

	//! \brief 		判断当前矩形是否包含矩形rc
	//! \param 		rc 矩形
	//! \return		若当前矩形包含矩形rc，则返回ture，否则，返回false。
	//! \image html Contains.png
	bool Contains(const Rect& rc) const;

	//! \brief 		判断当前矩形是否被矩形rc包含
	//! \param 		rc	矩形
	//! \return		若当前矩形被矩形rc包含，则返回ture，否则，返回false。
	//! \image html within.png
	bool Withins(const Rect& rc) const;

	//! \brief 		判断当前矩形是否与矩形rc相交
	//! \param 		rc	矩形
	//! \returen	相交返回true，否则，返回false。
	//! \image html Intersect2.png
	bool Intersects(const Rect& rc) const;

	//! \brief 		规范矩形，确保left<=right,top<=bottom	
	void Normalize();

	//! \brief 		对矩形进行偏移
	//! \param 		nX	横坐标偏移量
	//! \param 		nY	纵坐标偏移量	
	void Offset(int nX,int nY);

	//! \brief 		对矩形进行偏移
	//! \param 		sz	横纵坐标偏移量	
	void Offset(const Size& sz);

	//! \brief 		对矩形进行偏移
	//! \param 		pnt	横纵坐标偏移量	
	void Offset(const Point& p);

	//! \brief 		对矩形进行放大
	//! \param 		nMargin	横纵放大比例 	
	void Inflate(int nMargin);

	//! \brief 		对矩形进行放大
	//! \param 		nHormargin	横坐标放大比例
	//! \param 		nVermargin	总坐标放大比例	
	void Inflate(int nHorMargin,int nVerMargin);

	//! \brief 		对矩形进行放大
	//! \param 		nLeftMargin	左上角点沿x轴向左的偏移量
	//! \param 		nTopMargin	左上角点沿y轴向上的偏移量
	//! \param 		nRightMargin    右下角点沿x轴向右的偏移量
	//! \param 		nBottomMargin	右下角点沿y轴向下的偏移量
	void Inflate(int nLeftMargin,int nTopMargin,int nRightMargin,int nBottomMargin);

	//! \brief 		对矩形进行缩小
	//! \param 		nMargin	横纵缩小比例	
	void Deflate(int nMargin);

	//! \brief 		对矩形进行缩小
	//! \param 		nHormargin	横坐标缩小比例
	//! \param 		nVermargin	总坐标缩小比例	
	void Deflate(int nHorMargin,int nVerMargin);

	//! \brief 		对矩形进行缩小
	//! \param 		nLeftMargin	左上角点沿x轴向右的偏移量
	//! \param 		nTopMargin	左上角点沿y轴向下的偏移量
	//! \param 		nRightMargin 右下角点沿x轴向左的偏移量	
	//! \param 		nBottomMargin 右下角点沿y轴向上的偏移量	
	void Deflate(int nLeftMargin,int nTopMargin,int nRightMargin,int nBottomMargin);

	//! \brief 		矩形合并
	//! \param 		pnt	合并的点
	//! \image html union.png
	void Union(const Point& pnt);

	//! \brief 		矩形合并
	//! \param 		rc 用来与原矩形合并的矩形rc	
	//! \image html union2.png
	void Union(const Rect& rc);	

	//! \brief 		矩形求交
	//! \param 		rc 用来与原矩形求交的矩形rc
	//! \image html Intersect2.png
	void Intersection(const Rect& rc);

	//! \brief 		重载 ==
	friend GISCORE_API bool operator==(const Rect& rcStart,const Rect& rcEnd);

	//! \brief 		重载 !=
	friend GISCORE_API bool operator!=(const Rect& rcStart,const Rect& rcEnd);
};

#endif
