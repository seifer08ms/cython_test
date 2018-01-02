#include "PyGISCore/Variant.h"
#include "Base/OgdcString.h"
#include "Base/OgdcTime.h"

using namespace OGDC;

////////////////////////////二进制结构类/////////////////////////////////////
//计数器用于释放非外界传入的二进制数据
static int m_nCout = 0; 

Binary::Binary()
{
	m_pData = NULL;
	m_nSize = 0;
}

Binary::Binary(const Binary& another)
{
	m_nSize = another.m_nSize;
	m_pData = new Uchar[m_nSize];
	memcpy(m_pData, another.m_pData, m_nSize);
	m_nCout++;
}

Binary::~Binary()
{
	if (NULL != m_pData && m_nCout > 0)
	{
		delete[] m_pData;
		m_pData = NULL;
		m_nCout--;
	}
}

Binary::Binary(const Uchar* pData, Uint nSize)
{
	if (NULL != pData && nSize > 0)
	{
		m_pData = new Uchar[nSize];
		if (NULL != m_pData)
		{
			memcpy(m_pData, pData, nSize);
			m_nCout++;
		}

		m_nSize = nSize;
	}
	else
	{
		m_pData = NULL;
		m_nSize = 0;
	}
}

Binary& Binary::operator=(const Binary& tmpSrc)
{
	if (&tmpSrc == this)
	{
		return *this;
	}
	m_nSize = tmpSrc.m_nSize;

	if (m_pData != NULL)
	{
		delete m_pData;
	}
	m_pData = new Uchar[m_nSize];
	memcpy(m_pData, tmpSrc.m_pData, m_nSize);
	m_nCout++;

	return *this;
}

///////////////////////////时间//////////////////////////////////////
TimeStamp::TimeStamp()
{
	m_nYear		= 0;
	m_nMonth	= 0;
	m_nDay		= 0;
	m_nHour		= 0;
	m_nMinute	= 0;
	m_nSecond	= 0; 
}

TimeStamp::TimeStamp(int nYear, int nMonth, int nDay, int nHour, int nMinute, int nSecond)
{
	m_nYear		= nYear;
	m_nMonth	= nMonth;
	m_nDay		= nDay;
	m_nHour		= nHour;
	m_nMinute	= nMinute;
	m_nSecond	= nSecond; 
}

TimeStamp::~TimeStamp()
{

}

const TimeStamp& TimeStamp::operator=(const TimeStamp& tmsSrc)
{
	m_nYear		= tmsSrc.m_nYear;
	m_nMonth	= tmsSrc.m_nMonth;
	m_nDay		= tmsSrc.m_nDay;
	m_nHour		= tmsSrc.m_nHour;
	m_nMinute	= tmsSrc.m_nMinute;
	m_nSecond	= tmsSrc.m_nSecond; 

	return *this;
}

bool TimeStamp::operator<(const TimeStamp &tms) const
{
	OgdcTime tTime1(m_nYear, m_nMonth, m_nDay, m_nHour, m_nMinute, m_nSecond);
	OgdcTime tTime2(tms.m_nYear, tms.m_nMonth, tms.m_nDay, tms.m_nHour, 
		tms.m_nMinute, tms.m_nSecond);

	return tTime1 < tTime2;
}

bool TimeStamp::operator>(const TimeStamp &tms) const
{
	OgdcTime tTime1(m_nYear, m_nMonth, m_nDay, m_nHour, m_nMinute, m_nSecond);
	OgdcTime tTime2(tms.m_nYear, tms.m_nMonth, tms.m_nDay, tms.m_nHour, 
		tms.m_nMinute, tms.m_nSecond);

	return tTime1 > tTime2;
}

/////////////////////////////字段类/////////////////////////////
Variant::Variant()
{
	m_bVal = ' ';
	m_sVal  = 0;
	m_iVal  = 0;
	m_lVal  = 0;
	m_fVal  = 0.0;
	m_dVal  = 0.0;
	m_strVal = _U("");
	m_strType = _U("Null");
}

Variant::~Variant()
{

}

Variant::Variant(const Variant& fieldValue)
{
	m_bVal    = fieldValue.m_bVal;
	m_sVal    = fieldValue.m_sVal;
	m_iVal    = fieldValue.m_iVal;
	m_lVal    = fieldValue.m_lVal;
	m_fVal    = fieldValue.m_fVal;
	m_dVal    = fieldValue.m_dVal;
	m_tmVal   = fieldValue.m_tmVal;
	m_binVal  = fieldValue.m_binVal;
	m_strVal  = fieldValue.m_strVal;
	m_strType = fieldValue.m_strType;
}

Variant::Variant(Uchar bValue, short sValue, int iValue, Long lValue,float fValue, 
					   double dValue, const TimeStamp& tmValue, Binary binValue, 
					   const PyString& strValue, const PyString& strType)
{
	m_bVal   = bValue;
	m_sVal   = sValue;
	m_iVal   = iValue;
	m_lVal   = lValue;
	m_fVal   = fValue;
	m_dVal   = dValue;
	m_tmVal  = tmValue;
	m_strVal = strValue;
	m_binVal = Binary(binValue.m_pData, binValue.m_nSize);
	m_strType = strType;
}

const Variant& Variant::operator=(const Variant& fieldValueSrc)
{
	m_bVal    = fieldValueSrc.m_bVal;
	m_sVal    = fieldValueSrc.m_sVal;
	m_iVal    = fieldValueSrc.m_iVal;
	m_lVal    = fieldValueSrc.m_lVal;
	m_fVal    = fieldValueSrc.m_fVal;
	m_dVal    = fieldValueSrc.m_dVal;
	m_tmVal   = fieldValueSrc.m_tmVal;
	m_binVal  = fieldValueSrc.m_binVal;
	m_strVal  = fieldValueSrc.m_strVal;
	m_strType = fieldValueSrc.m_strType;

	return *this;
}