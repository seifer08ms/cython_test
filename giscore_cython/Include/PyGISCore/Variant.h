#ifndef VARIANT_INCLUDE_H
#define VARIANT_INCLUDE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PyGISCore/exports.h"
#include "PyGISCore/def.h"

//! \breif 二进制结构体
class GISCORE_API Binary
{  
public:
	//! \breif 构造函数
	Binary();

	//! \breif 构造函数
	Binary(const Uchar* pData, Uint nSize);
	//! \breif 拷贝构造
	Binary(const Binary& another);

	//! \breif 析构函数
	~Binary();

	//! \brief 拷贝赋值函数
	Binary& operator=(const Binary& tmsSrc);

public:
	//! \brief 存储 Binary 指针或者 String指针
	Uchar* m_pData;	

	//! \brief 存储Binary 数据流的大小 以字节为单位。
	Uint m_nSize;   
};

//! \breif 时间类
class GISCORE_API TimeStamp
{
public:
	//! \breif 构造函数
	TimeStamp();

	//! \breif 构造函数
	TimeStamp(int nYear, int nMonth, int nDay, int nHour, int nMinute, int nSecond);

	//! \breif 析构函数
	~TimeStamp();

	//! \brief 拷贝赋值函数
	const TimeStamp& operator=(const TimeStamp& tmsSrc);

	//! \brief 重载操作符 <
	bool operator<(const TimeStamp &tms) const;

	//! \brief 重载操作符 >
	bool operator>(const TimeStamp &tms) const;

public:
	int   m_nYear;
	int   m_nMonth;
	int   m_nDay;
	int   m_nHour;
	int   m_nMinute;
	int   m_nSecond;   
};

//! \brief 变体类
class GISCORE_API Variant
{
public:
	//! \breif 构造函数
	Variant();

	//! \breif 析构函数
	Variant(Uchar bValue, short sValue, int iValue, Long lValue,float fValue,double dValue, 
		const TimeStamp& tmValue, Binary binValue, const PyString& strValue, const PyString& strType);

	//! \breif 拷贝构造
	Variant(const Variant& fieldValue);
	
	//! \breif 析构函数
	~Variant();

	//! \brief 赋值
	const Variant& operator=(const Variant& fieldValueSrc);

	//! \breif 获取Byte字段值
	Uchar GetByte() const{return m_bVal;}

	//! \breif 设置Byte字段值
	void SetByte(const Uchar& bVal){m_bVal = bVal;}

	//! \breif 获取short字段值
	short GetShort() const{return m_sVal;}

	//! \breif 设置short字段值
	void SetShort(const short& sVal){m_sVal = sVal;}

	//! \breif 获取int字段值
	int GetInt() const{return m_iVal;}

	//! \breif 设置int字段值
	void SetInt(const int& nVal){m_iVal = nVal;}

	//! \breif 获取Long字段值
	Long GetLong() const{return m_lVal;}

	//! \breif 设置Long字段值
	void SetLong(const Long& nVal){m_lVal = nVal;}

	//! \breif 获取Float字段值
	float GetFloat() const{return m_fVal;}

	//! \breif 设置Float字段值
	void SetFloat(const float& fVal){m_fVal = fVal;}

	//! \breif 获取Float字段值
	double GetDouble() const{return m_dVal;}

	//! \breif 设置Float字段值
	void SetDouble(const double& dVal){m_dVal = dVal;}

	//! \breif 获取时间字段的值
	TimeStamp GetTimeStamp() const{return m_tmVal;}

	//! \breif 设置时间字段的值
	void SetTimeStamp(const TimeStamp& tmVal){m_tmVal = tmVal;}

	//! \breif 获取二进制字段值
	Binary GetBinary() const{return m_binVal;}

	//! \breif 设置二进制字段值
	void SetBinary(const Binary& binVal){m_binVal = binVal;}

	//! \breif 获取时间字段的值
	PyString GetString() const{return m_strVal;}

	//! \breif 设置字符串字段值
	void SetString(const PyString& strVal){m_strVal = strVal;}

	//! \breif 获取字符串字段值
	PyString GetType() const{return m_strType;}

	//! \breif 设置字段值类型
	void SetType(const PyString& strType){m_strType = strType;}

private:
	Uchar     m_bVal;
	short     m_sVal;
	int	      m_iVal;
	Long      m_lVal;
	float     m_fVal;
	double    m_dVal;
	TimeStamp m_tmVal; 
	Binary    m_binVal;
	PyString  m_strVal;

	//! \breif 字段值类型
	//	//	-- Null			未定义的类型
	//	//	-- Byte			单字节类型
	//	//	-- Short		双字节整型类型
	//	//	-- Integer		四字节整型类型
	//	//	-- Long			八字节整型类型
	//	//	-- Float		四字节浮点类型
	//	//	-- Double		八字节浮点类型
	//	//	-- Time			时间类型
	//	//	-- Binary		二进制类型 
	//	//	-- String		字符串
	//	//	-- Date			日期类型
	//	//	-- TimeStamp	时间戳类型
	//	//	-- Boolean		布尔类型
	PyString m_strType; 
};

#endif