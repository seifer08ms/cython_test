#ifndef TOOLKIT_INCLUDE_H
#define TOOLKIT_INCLUDE_H

#include "PyGISCore/exports.h"
#include "PyGISCore/def.h"

//! \breif 工具类
class GISCORE_API Toolkit
{
public:
	//! \breif 构造函数
	Toolkit();

	//! \breif 析构函数
	~Toolkit();

	//! \breif 字符串转换为UGC数据源类型
	static int ToUGDataSourceType(const PyString &strType); 

	//! \breif UGC数据源类型转换为字符串
	static PyString FromDataSourceType(int nType);

	//! \breif 字符串转换为UGC像素格式
	static int ToPixelFormat(const PyString& strPixelFormat);

	//! \breif 字符串转换为UGC像素格式
	static PyString FromPixelFormat(int nPixelFormat);

	//! \breif 字符串转换为UGC字符集
	static int  ToUGCharset(const PyString& strCharset);

	//! \breif 字符串转换为UGC字段类型
	static int ToUGFieldType(const PyString& strType);

	//! \breif UGC字段类型转换为字符串
	static PyString FromUGFieldType(int nType);

	//! \breif 字符串转换为UGC特殊系统字段标识
	static int ToUGFieldSign(const PyString& strFieldSign);

	//! \breif UGC特殊系统字段标识转换为字符串
	static PyString FromUFieldSign(int nType);
};

#endif // !TOOLKIT_INCLUDE_H
