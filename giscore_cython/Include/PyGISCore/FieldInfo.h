#ifndef FIELDINFO_INCLUDE_H
#define FIELDINFO_INCLUDE_H

#include "PyGISCore/exports.h"
#include "PyGISCore/def.h"
#include <vector>

//! \breif 字段类
class GISCORE_API FieldInfo
{
public:
	//! \breif 构造函数
	FieldInfo();

	//! \breif 构造函数
	FieldInfo(const PyString& strName, const PyString& strType, int nSize);

	//! \breif 拷贝构造
	FieldInfo(const FieldInfo& fieldInfo);

	//! \breif 析构函数
	~FieldInfo();

	//! \brief 重载 = 
	const FieldInfo& operator =(const FieldInfo& fieldInfo);

	//! \brief 重载 ==
	bool operator ==(const FieldInfo& fieldInfo);

	//! \brief 重载 != 
	bool operator !=(const FieldInfo& fieldInfo);

	//! \brief  判断字段是否可更新。
	//! \return 是否可以更新，可以返回TRUE，不可以返回FALSE。
	bool CanUpdate();	

	//! \brief 判断是否是系统字段
	//! \return 是否是系统字段，是返回TRUE，不是返回FALSE。
	bool IsSystemField();

	//! \brief 判断是否是几何对象字段
	//! \return 是否是几何对象字段，是返回TRUE，不是返回FALSE。
	bool IsGeoField();

	//! \brief 判断是否包含索引
	//! \return 是否包含索引，是返回TRUE，不是返回FALSE。
	bool IsContainIndex();

	//! \brief 判断字段是否为UUID
	bool IsUUIDField();

	//! \brief 设置默认值
	void SetDefaultValue(const PyString& strDefaultValue);

	//! \brief 读取默认值
	//! \return 默认值，字符串格式
	PyString & GetDefaultValue();

public:	
	//! \brief 是否是系统UUID字段
	bool m_bUUID;

	//! \brief 是否是系统字段。
	bool m_bSystem;

	//! \brief 是否是必填字段。
	bool m_bRequired;

	//! \brief 字段长度是否允许零长度。
	bool m_bAllowZeroLength;

	//! \brief 刻度
	int m_nScale;

	//! \brief 精度
	int m_nPrecision;

	//! \brief 字段长度。
	int m_nSize;

	//! \brief 字段属性。
	int m_nAttributes;

	//! \brief 字段序号位置。
	int m_nOrdinalPosition;

	//! \brief 比较序列
	int m_nCollatingOrder;

	//! \brief 字段类型。
	//	--UnKnown		不识别的类型
	//	--Boolean		布尔值，单字节，TRUE,FALSE
	//	--Byte			无符号单字李，0-255
	//	--INT16			短整型，2字节
	//	--INT32			长整型，4字节
	//	--INT64			长整型，8字节, 
	//	--Float			单精度浮点型，4字节
	//	--Double		双精度浮点型，8字节
	//	--Date			日期型，年、月、日，不带时间
	//	--Binary		固定长度二进制型，需指定长度
	//	--Text			不定长字符串型
	//	--LongBinary	不定长二进制类型
	//	--Char			定长字符串型，需指定长度 
	//	--Time			时间型，小时、分、秒，不带日期
	//	--TimeStamp		时间戳型，年、月、日、小时、分、秒
	//	--NText			宽字节不定长字符串类型
	//	--Geometry		几何数据类型
	PyString m_strType;

	//! \brief 字段标识。
	//	--signNone	    默认
	//	--signNodeID	网络数据集的节点ID，默认是SmNodeID字段 
	//	--signFNode		网络数据集起点字段, 默认是SmFNode 
	//	--signTNode		网络数据集终点字段, 默认是SmTNode
	//	--signEdgeID	网络数据集边的ID字段
	//	--signRouteID	路线数据集的RouteID字段	
	//	--signID		对象ID字段			
	//	--signGeometry	几何对象字段。
	//	--signStart		用户自定义字段标识起始值 
	PyString  m_strFieldSign;

	//! \brief 字段名称。
	PyString m_strName;

	//! \brief 字段的外键名。
	PyString m_strForeignName;

	//! \brief 源字段名
	PyString m_strSourceField;

	//! \brief 源表名
	PyString m_strSourceTable;

	//! \brief 验证规则
	PyString m_strValidationRule;

	//! \brief 验证条件
	PyString m_strValidationText;

	//! \brief 格式
	PyString m_strFormat;

	//! \brief 限制信息
	PyString m_strDomain;

	//! \brief 是否可编辑
	bool m_bUpdatable;

	//! \brief 索引表名称
	PyString m_strIndexTab;

private:
	//! \brief 字段默认值
	PyString m_strDefaultValue;
};

typedef std::vector<FieldInfo> FieldInfos;

#endif // !FIELDINFO_INCLUDE_H