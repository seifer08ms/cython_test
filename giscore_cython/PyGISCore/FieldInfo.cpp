#include "PyGISCore/FieldInfo.h"
#include "Base/OgdcString.h"

using namespace OGDC;

FieldInfo::FieldInfo()
{
	m_nSize				= 0;
	m_nAttributes		= 0;
	m_nOrdinalPosition	= 0;
	m_nCollatingOrder	= 0;
	m_bRequired			= false;
	m_bAllowZeroLength	= true;
	m_nScale			= -1;
	m_nPrecision		= -1;
	m_bUpdatable		= true;
	m_bUUID				= false;
	m_bSystem			= false;
	m_strType			= _U("UnKnown");
	m_strFieldSign		= _U("signNone");
}

FieldInfo::FieldInfo(const PyString& strName, const PyString& strType, int nSize)
{
	m_strName           = strName;
	m_strType			= strType;
	m_nSize				= nSize;
	m_nAttributes		= 0;
	m_bRequired			= false;
	m_bAllowZeroLength	= true;
	m_strIndexTab		= _U("");
	m_nOrdinalPosition	= 0;
	m_nCollatingOrder	= 0;
	m_nScale			= -1;
	m_nPrecision		= -1;
	m_bUpdatable		= true;
	m_bUUID				= false;
	m_bSystem			= false;
	m_strFieldSign		= _U("signNone");
}

FieldInfo::FieldInfo(const FieldInfo& fieldInfo)
{
	*this = fieldInfo;
}

FieldInfo::~FieldInfo()
{

}

const FieldInfo& FieldInfo::operator =(const FieldInfo& fieldInfo)
{
	m_strName			= fieldInfo.m_strName;
	m_strType			= fieldInfo.m_strType;
	m_nSize				= fieldInfo.m_nSize;
	m_nAttributes		= fieldInfo.m_nAttributes;
	m_nOrdinalPosition	= fieldInfo.m_nOrdinalPosition;
	m_nCollatingOrder	= fieldInfo.m_nCollatingOrder;
	m_bSystem			= fieldInfo.m_bSystem;
	m_bUUID				= fieldInfo.m_bUUID;
	m_bRequired			= fieldInfo.m_bRequired;
	m_bAllowZeroLength  = fieldInfo.m_bAllowZeroLength;
	m_strForeignName    = fieldInfo.m_strForeignName;
	m_strSourceField    = fieldInfo.m_strSourceField;
	m_strSourceTable    = fieldInfo.m_strSourceTable;
	m_strValidationRule = fieldInfo.m_strValidationRule;
	m_strValidationText = fieldInfo.m_strValidationText;
	m_strDefaultValue   = fieldInfo.m_strDefaultValue;
	m_nScale			= fieldInfo.m_nScale;
	m_nPrecision		= fieldInfo.m_nPrecision;
	m_strFormat			= fieldInfo.m_strFormat;
	m_strDomain			= fieldInfo.m_strDomain;
	m_bUpdatable		= fieldInfo.m_bUpdatable;
	m_strIndexTab		= fieldInfo.m_strIndexTab;
	m_strFieldSign		= fieldInfo.m_strFieldSign;

	return *this;
}

bool FieldInfo::operator ==(const FieldInfo& fieldInfo)
{
	if (m_strName == fieldInfo.m_strName && \
		m_strType == fieldInfo.m_strType && \
		m_nSize == fieldInfo.m_nSize && \
		m_nAttributes == fieldInfo.m_nAttributes && \
		m_nOrdinalPosition == fieldInfo.m_nOrdinalPosition && \
		m_nCollatingOrder == fieldInfo.m_nCollatingOrder && \
		m_bSystem == fieldInfo.m_bSystem && \
		m_bUUID == fieldInfo.m_bUUID&& \
		m_bRequired == fieldInfo.m_bRequired && \
		m_bAllowZeroLength == fieldInfo.m_bAllowZeroLength && \
		m_strForeignName == fieldInfo.m_strForeignName && \
		m_strSourceField == fieldInfo.m_strSourceField && \
		m_strSourceTable == fieldInfo.m_strSourceTable && \
		m_strValidationRule == fieldInfo.m_strValidationRule && \
		m_strValidationText == fieldInfo.m_strValidationText && \
		m_strDefaultValue == fieldInfo.m_strDefaultValue && \
		m_nScale == fieldInfo.m_nScale && \
		m_nPrecision == fieldInfo.m_nPrecision && \
		m_strFormat == fieldInfo.m_strFormat && \
		m_strDomain == fieldInfo.m_strDomain && \
		m_bUpdatable == fieldInfo.m_bUpdatable && \
		m_strIndexTab == fieldInfo.m_strIndexTab && \
		m_strFieldSign == fieldInfo.m_strFieldSign)
	{
		return true;
	}

	return false;
}

bool FieldInfo::operator !=(const FieldInfo& fieldInfo)
{
	return !operator==(fieldInfo);
}

bool FieldInfo::CanUpdate()
{
	return m_bUpdatable;	
}

bool FieldInfo::IsSystemField()
{
	OgdcString  strName(m_strName.c_str());
	int nPos = strName.Find((_U(".")));

	OgdcString strUGFieldSign(m_strFieldSign.c_str());

	if ( nPos > 0 )
	{
		strName = strName.Right(strName.GetLength() - nPos - 1);
	}

	if(strName.Left(2).CompareNoCase(_U("Sm"))==0)
	{
		if(strName.CompareNoCase(_U("SmUserID"))==0)
		{
			return FALSE;
		}
		else if ( strName.CompareNoCase(_U("SmID")) == 0 ||
			strName.CompareNoCase(_U("SmSdriN")) == 0	||
			strName.CompareNoCase(_U("SmSdriS")) == 0 ||
			strName.CompareNoCase(_U("SmSdriW")) == 0 ||
			strName.CompareNoCase(_U("SmSdriE")) == 0 ||
			strName.CompareNoCase(_U("SmGeometry")) == 0 ||
			strName.CompareNoCase(_U("SmX")) == 0 ||
			strName.CompareNoCase(_U("SmY")) == 0 ||
			strName.CompareNoCase(_U("SmZ")) == 0 ||
			strName.CompareNoCase(_U("SmKey")) == 0 ||
			strName.CompareNoCase(_U("SmGranule")) == 0 ||
			strName.CompareNoCase(_U("SmLength")) == 0 ||
			strName.CompareNoCase(_U("SmArea")) == 0 ||
			strName.CompareNoCase(_U("SmPerimeter")) == 0 ||
			strName.CompareNoCase(_U("SmLibTileID")) == 0 ||
			strName.CompareNoCase(_U("SmEdgeID")) == 0 ||
			strName.CompareNoCase(_U("SmFNode")) == 0 ||
			strName.CompareNoCase(_U("SmTNode")) == 0 ||
			strName.CompareNoCase(_U("SmResistanceA")) == 0 ||
			strName.CompareNoCase(_U("SmResistanceB")) == 0 ||
			strName.CompareNoCase(_U("SmTopoError")) == 0 ||
			strName.CompareNoCase(_U("SmNodeID")) == 0 ||
			strName.CompareNoCase(_U("SmGeoType")) == 0 ||
			strName.CompareNoCase(_U("SmRouteID")) == 0 ||
			strName.CompareNoCase(_U("SMMAXMEASURE")) == 0 ||  
			strName.CompareNoCase(_U("SMMINMEASURE")) == 0 ||  
			strName.CompareNoCase(_U("SmGeometrySize")) == 0 ||
			strName.CompareNoCase(_U("SmVertexSeq")) == 0||		
			strName.CompareNoCase(_U("SmHashCode")) == 0 ||
			strName.CompareNoCase(_U("SmGeoPosition")) == 0)		
		{
			return TRUE;
		}
	}
	else if(strUGFieldSign.CompareNoCase(_U("signID")) == 0   || 
		strUGFieldSign.CompareNoCase(_U("signGeometry")) == 0 ||
		m_bSystem)
	{
		return TRUE;
	}

	return FALSE;
}

bool FieldInfo::IsGeoField()
{
	OgdcString  strName(m_strName.c_str());
	strName.MakeUpper();
	if((strName.Find(_U("SMGEOMETRYID"))==-1&&(strName.Find(_U("SMGEOMETRY")) == 0 ||
		strName.Find(_U(".SMGEOMETRY")) > 0 ||
		strName.Find(_U("SMX")) == 0 ||
		strName.Find(_U(".SMX")) > 0 ||
		strName.Find(_U("SMY")) == 0 ||
		strName.Find(_U(".SMY")) > 0 ||
		strName.Find(_U("SMZ")) == 0 ||
		strName.Find(_U(".SMZ")) > 0) && strName.CompareNoCase(_U("SMGEOMETRYSIZE")) != 0 ))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

	return FALSE;
}

bool FieldInfo::IsUUIDField()
{
	OgdcString  strName(m_strName.c_str());
	OgdcInt nPos = strName.Find((_U(".")));

	if ( nPos > 0 )
	{
		strName = strName.Right(strName.GetLength() - nPos - 1);
	}
	if(strName.Left(2).CompareNoCase(_U("sm"))==0)
	{
		if ( strName.CompareNoCase(_U("SmUUID")) == 0 )
		{
			return TRUE;
		}
	}

	return FALSE;
}

bool FieldInfo::IsContainIndex()
{
	return !m_strIndexTab.empty(); 	
}

void FieldInfo::SetDefaultValue(const PyString& strDefaultValue)
{
	m_strDefaultValue = strDefaultValue;
}


PyString & FieldInfo::GetDefaultValue()
{
	return m_strDefaultValue;
}