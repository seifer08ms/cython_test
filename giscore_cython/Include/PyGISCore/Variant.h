#ifndef VARIANT_INCLUDE_H
#define VARIANT_INCLUDE_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PyGISCore/exports.h"
#include "PyGISCore/def.h"

//! \breif �����ƽṹ��
class GISCORE_API Binary
{  
public:
	//! \breif ���캯��
	Binary();

	//! \breif ���캯��
	Binary(const Uchar* pData, Uint nSize);
	//! \breif ��������
	Binary(const Binary& another);

	//! \breif ��������
	~Binary();

	//! \brief ������ֵ����
	Binary& operator=(const Binary& tmsSrc);

public:
	//! \brief �洢 Binary ָ����� Stringָ��
	Uchar* m_pData;	

	//! \brief �洢Binary �������Ĵ�С ���ֽ�Ϊ��λ��
	Uint m_nSize;   
};

//! \breif ʱ����
class GISCORE_API TimeStamp
{
public:
	//! \breif ���캯��
	TimeStamp();

	//! \breif ���캯��
	TimeStamp(int nYear, int nMonth, int nDay, int nHour, int nMinute, int nSecond);

	//! \breif ��������
	~TimeStamp();

	//! \brief ������ֵ����
	const TimeStamp& operator=(const TimeStamp& tmsSrc);

	//! \brief ���ز����� <
	bool operator<(const TimeStamp &tms) const;

	//! \brief ���ز����� >
	bool operator>(const TimeStamp &tms) const;

public:
	int   m_nYear;
	int   m_nMonth;
	int   m_nDay;
	int   m_nHour;
	int   m_nMinute;
	int   m_nSecond;   
};

//! \brief ������
class GISCORE_API Variant
{
public:
	//! \breif ���캯��
	Variant();

	//! \breif ��������
	Variant(Uchar bValue, short sValue, int iValue, Long lValue,float fValue,double dValue, 
		const TimeStamp& tmValue, Binary binValue, const PyString& strValue, const PyString& strType);

	//! \breif ��������
	Variant(const Variant& fieldValue);
	
	//! \breif ��������
	~Variant();

	//! \brief ��ֵ
	const Variant& operator=(const Variant& fieldValueSrc);

	//! \breif ��ȡByte�ֶ�ֵ
	Uchar GetByte() const{return m_bVal;}

	//! \breif ����Byte�ֶ�ֵ
	void SetByte(const Uchar& bVal){m_bVal = bVal;}

	//! \breif ��ȡshort�ֶ�ֵ
	short GetShort() const{return m_sVal;}

	//! \breif ����short�ֶ�ֵ
	void SetShort(const short& sVal){m_sVal = sVal;}

	//! \breif ��ȡint�ֶ�ֵ
	int GetInt() const{return m_iVal;}

	//! \breif ����int�ֶ�ֵ
	void SetInt(const int& nVal){m_iVal = nVal;}

	//! \breif ��ȡLong�ֶ�ֵ
	Long GetLong() const{return m_lVal;}

	//! \breif ����Long�ֶ�ֵ
	void SetLong(const Long& nVal){m_lVal = nVal;}

	//! \breif ��ȡFloat�ֶ�ֵ
	float GetFloat() const{return m_fVal;}

	//! \breif ����Float�ֶ�ֵ
	void SetFloat(const float& fVal){m_fVal = fVal;}

	//! \breif ��ȡFloat�ֶ�ֵ
	double GetDouble() const{return m_dVal;}

	//! \breif ����Float�ֶ�ֵ
	void SetDouble(const double& dVal){m_dVal = dVal;}

	//! \breif ��ȡʱ���ֶε�ֵ
	TimeStamp GetTimeStamp() const{return m_tmVal;}

	//! \breif ����ʱ���ֶε�ֵ
	void SetTimeStamp(const TimeStamp& tmVal){m_tmVal = tmVal;}

	//! \breif ��ȡ�������ֶ�ֵ
	Binary GetBinary() const{return m_binVal;}

	//! \breif ���ö������ֶ�ֵ
	void SetBinary(const Binary& binVal){m_binVal = binVal;}

	//! \breif ��ȡʱ���ֶε�ֵ
	PyString GetString() const{return m_strVal;}

	//! \breif �����ַ����ֶ�ֵ
	void SetString(const PyString& strVal){m_strVal = strVal;}

	//! \breif ��ȡ�ַ����ֶ�ֵ
	PyString GetType() const{return m_strType;}

	//! \breif �����ֶ�ֵ����
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

	//! \breif �ֶ�ֵ����
	//	//	-- Null			δ���������
	//	//	-- Byte			���ֽ�����
	//	//	-- Short		˫�ֽ���������
	//	//	-- Integer		���ֽ���������
	//	//	-- Long			���ֽ���������
	//	//	-- Float		���ֽڸ�������
	//	//	-- Double		���ֽڸ�������
	//	//	-- Time			ʱ������
	//	//	-- Binary		���������� 
	//	//	-- String		�ַ���
	//	//	-- Date			��������
	//	//	-- TimeStamp	ʱ�������
	//	//	-- Boolean		��������
	PyString m_strType; 
};

#endif