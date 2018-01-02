#include "PyGISCore/Toolkit.h"
#include "Base/OgdcString.h"
#include "Element/OgdcFieldInfo.h"

using namespace OGDC;

Toolkit::Toolkit()
{

}

Toolkit::~Toolkit()
{

}

int Toolkit::ToUGDataSourceType(const PyString &strType)
{
	OgdcString strUGType(strType.c_str());
	if (strUGType.CompareNoCase(_U("SDE")) == 0)
	{
		return 4;
	}
	else if (strUGType.CompareNoCase(_U("ImagePlugins")) == 0)
	{
		return 5;
	}
	else if (strUGType.CompareNoCase(_U("OracleSpatial")) == 0)
	{
		return 10;
	}
	else if (strUGType.CompareNoCase(_U("OraclePlus")) == 0)
	{
		return 12;
	}
	else if (strUGType.CompareNoCase(_U("SQLPlus")) == 0)
	{
		return 16;
	}
	else if (strUGType.CompareNoCase(_U("UDB")) == 0)
	{
		return 219;
	}
	else if (strUGType.CompareNoCase(_U("MySQL")) == 0)
	{
		return 32;
	}
	else if (strUGType.CompareNoCase(_U("ExtFile")) == 0)
	{
		return 101;
	}
	else if (strUGType.CompareNoCase(_U("MongoDB")) == 0)
	{
		return 401;
	}
	else if (strUGType.CompareNoCase(_U("DMPlus")) == 0)
	{
		return 17;
	}
	else if (strUGType.CompareNoCase(_U("Kingbase")) == 0)
	{
		return 19;
	}
	else if (strUGType.CompareNoCase(_U("Kadb")) == 0)
	{
		return 2010;
	}
	else if (strUGType.CompareNoCase(_U("PostgreSQL")) == 0)
	{
		return 221;
	}
	else 
	{
		return -1;
	}
}

PyString Toolkit::FromDataSourceType(int nType)
{
	switch (nType)
	{
	case 4:
		return _U("SDE");
	case 5:
		return _U("ImagePlugins");
	case 10:
		return _U("OracleSpatial");
	case 12:
		return _U("OraclePlus");
	case 16:
		return _U("SQLPlus");
	case 219:
		return _U("UDB");
	case 32:
		return _U("MySQL");
	case 401:
		return _U("MongoDB");
	case 101:
		return _U("ExtFile");
	case 221:
		return _U("PostgreSQL");
	default:
		return _U("");
	}
}

int Toolkit::ToPixelFormat(const PyString& strPixelFormat)
{
	OgdcString strOGPixelFormat(strPixelFormat.c_str());

	OGDC::PixelFormat ePixelFormat  = IPF_UNKNOWN;
	if (strOGPixelFormat.CompareNoCase(_U("IPF_MONO")) == 0)
	{
		ePixelFormat = IPF_MONO;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_FBIT")) == 0)
	{
		ePixelFormat = IPF_FBIT;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_UBYTE")) == 0)
	{
		ePixelFormat = IPF_UBYTE;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_BYTE")) == 0)
	{
		ePixelFormat = IPF_BYTE;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_RGB")) == 0)
	{
		ePixelFormat = IPF_RGB;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_RGBA")) == 0)
	{
		ePixelFormat = IPF_RGBA;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_TBYTE")) == 0)
	{
		ePixelFormat = IPF_TBYTE;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_TRGB")) == 0)
	{
		ePixelFormat = IPF_TRGB;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_LONGLONG")) == 0)
	{
		ePixelFormat = IPF_LONGLONG;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_LONG")) == 0)
	{
		ePixelFormat = IPF_LONG;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_ULONG")) == 0)
	{
		ePixelFormat = IPF_ULONG;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_FLOAT")) == 0)
	{
		ePixelFormat = IPF_FLOAT;
	}
	else if (strOGPixelFormat.CompareNoCase(_U("IPF_DOUBLE")) == 0)
	{
		ePixelFormat = IPF_DOUBLE;
	}

	return (int)ePixelFormat;
}

PyString Toolkit::FromPixelFormat(int nPixelFormat)
{
	PyString strPixelFormat = _U("IPF_UNKNOWN");

	switch (nPixelFormat)
	{
	case IPF_MONO:
		{
			strPixelFormat = _U("IPF_MONO");
		}
		break;

	case IPF_FBIT:
		{
			strPixelFormat = _U("IPF_MONO");
		}
		break;

	case IPF_UBYTE:
		{
			strPixelFormat = _U("IPF_UBYTE");
		}
		break;

	case IPF_BYTE:
		{
			strPixelFormat = _U("IPF_BYTE");
		}
		break;

	case IPF_RGB:
		{
			strPixelFormat = _U("IPF_RGB");
		}
		break;

	case IPF_RGBA:
		{
			strPixelFormat = _U("IPF_RGBA");
		}
		break;

	case IPF_TBYTE:
		{
			strPixelFormat = _U("IPF_TBYTE");
		}
		break;

	case IPF_UTBYTE:
		{
			strPixelFormat = _U("IPF_UTBYTE");
		}
		break;

	case IPF_TRGB:
		{
			strPixelFormat = _U("IPF_TRGB");
		}
		break;

	case IPF_LONGLONG:
		{
			strPixelFormat = _U("IPF_LONGLONG");
		}
		break;

	case IPF_LONG:
		{
			strPixelFormat = _U("IPF_LONG");
		}
		break;
	case IPF_ULONG:
		{
			strPixelFormat = _U("IPF_ULONG");
		}
		break;

	case IPF_FLOAT:
		{
			strPixelFormat = _U("IPF_FLOAT");
		}
		break;
	case IPF_DOUBLE:
		{
			strPixelFormat = _U("IPF_DOUBLE");
		}
		break;

	default:
		break;
	}

	return strPixelFormat;
}

int Toolkit::ToUGCharset(const PyString& strCharset)
{
	OgdcString strUGCharset(strCharset.c_str());
	OgdcString::Charset charset;

	if (strUGCharset.CompareNoCase(_U("ANSI")) == 0)
	{
		charset = OgdcString::ANSI;
	}
	else if (strUGCharset.CompareNoCase(_U("Default")) == 0)
	{
		charset = OgdcString::Default;
	}
	else if (strUGCharset.CompareNoCase(_U("Symbol")) == 0)
	{
		charset = OgdcString::Symbol;
	}
	else if (strUGCharset.CompareNoCase(_U("MAC")) == 0)
	{
		charset = OgdcString::MAC;
	}
	else if (strUGCharset.CompareNoCase(_U("ISO2022JP2")) == 0)
	{
		charset = OgdcString::ISO2022JP2;
	}
	else if (strUGCharset.CompareNoCase(_U("ShiftJIS")) == 0)
	{
		charset = OgdcString::ShiftJIS;
	}
	else if (strUGCharset.CompareNoCase(_U("Hangeul")) == 0)
	{
		charset = OgdcString::Hangeul;
	}
	else if (strUGCharset.CompareNoCase(_U("Johab")) == 0)
	{
		charset = OgdcString::Johab;
	}
	else if (strUGCharset.CompareNoCase(_U("GB18030")) == 0)
	{
		charset = OgdcString::GB18030;
	}
	else if (strUGCharset.CompareNoCase(_U("ChineseBIG5")) == 0)
	{
		charset = OgdcString::ChineseBIG5;
	}
	else if (strUGCharset.CompareNoCase(_U("Greek")) == 0)
	{
		charset = OgdcString::Greek;
	}
	else if (strUGCharset.CompareNoCase(_U("Turkish")) == 0)
	{
		charset = OgdcString::Turkish;
	}
	else if (strUGCharset.CompareNoCase(_U("Vietnamese")) == 0)
	{
		charset = OgdcString::Vietnamese;
	}
	else if (strUGCharset.CompareNoCase(_U("Hebrew")) == 0)
	{
		charset = OgdcString::Hebrew;
	}
	else if (strUGCharset.CompareNoCase(_U("Arabic")) == 0)
	{
		charset = OgdcString::Arabic;
	}
	else if (strUGCharset.CompareNoCase(_U("Baltic")) == 0)
	{
		charset = OgdcString::Baltic;
	}
	else if (strUGCharset.CompareNoCase(_U("Russian")) == 0)
	{
		charset = OgdcString::Russian;
	}
	else if (strUGCharset.CompareNoCase(_U("Thai")) == 0)
	{
		charset = OgdcString::Thai;
	}
	else if (strUGCharset.CompareNoCase(_U("EastEurope")) == 0)
	{
		charset = OgdcString::EastEurope;
	}
	else if (strUGCharset.CompareNoCase(_U("UTF8")) == 0)
	{
		charset = OgdcString::UTF8;
	}
	else if (strUGCharset.CompareNoCase(_U("UCS2LE")) == 0)
	{
		charset = OgdcString::UCS2LE;
	}
	else if (strUGCharset.CompareNoCase(_U("UCS2BE")) == 0)
	{
		charset = OgdcString::UCS2BE;
	}
	else if (strUGCharset.CompareNoCase(_U("UCS4LE")) == 0)
	{
		charset = OgdcString::UCS4LE;
	}
	else if (strUGCharset.CompareNoCase(_U("UCS4BE")) == 0)
	{
		charset = OgdcString::UCS4BE;
	}
	else if (strUGCharset.CompareNoCase(_U("Unicode")) == 0)
	{
		charset = OgdcString::Unicode;
	}
	else if (strUGCharset.CompareNoCase(_U("OEM")) == 0)
	{
		charset = OgdcString::OEM;
	}
	else if (strUGCharset.CompareNoCase(_U("Windows1252")) == 0)
	{
		charset = OgdcString::Windows1252;
	}
	else if (strUGCharset.CompareNoCase(_U("Korean")) == 0)
	{
		charset = OgdcString::Korean;
	}
	else if (strUGCharset.CompareNoCase(_U("Cyrillic")) == 0)
	{
		charset = OgdcString::Cyrillic;
	}
	else if (strUGCharset.CompareNoCase(_U("xIA5")) == 0)
	{
		charset = OgdcString::xIA5;
	}
	else if (strUGCharset.CompareNoCase(_U("xIA5German")) == 0)
	{
		charset = OgdcString::xIA5German;
	}
	else if (strUGCharset.CompareNoCase(_U("xIA5Swedish")) == 0)
	{
		charset = OgdcString::xIA5Swedish;
	}
	else if (strUGCharset.CompareNoCase(_U("xIA5Norwegian")) == 0)
	{
		charset = OgdcString::xIA5Norwegian;
	}
	else if (strUGCharset.CompareNoCase(_U("UTF7")) == 0)
	{
		charset = OgdcString::UTF7;
	}
	else
	{
		charset = OgdcString::Default;
	}

	return (int)charset;
}

int Toolkit::ToUGFieldType(const PyString& strType)
{
	OgdcString strUGType(strType.c_str());
	OgdcFieldInfo::FieldType ugFiledType = OgdcFieldInfo::UnKnown;
	if (strUGType.CompareNoCase(_U("UnKnown")) == 0)
	{
		ugFiledType = OgdcFieldInfo::UnKnown;
	}
	else if (strUGType.CompareNoCase(_U("Boolean")) == 0)
	{
		ugFiledType = OgdcFieldInfo::Boolean;
	}
	else if (strUGType.CompareNoCase(_U("Byte")) == 0)
	{
		ugFiledType = OgdcFieldInfo::Byte;
	}
	else if (strUGType.CompareNoCase(_U("INT16")) == 0)
	{
		ugFiledType = OgdcFieldInfo::INT16;
	}
	else if (strUGType.CompareNoCase(_U("INT32")) == 0)
	{
		ugFiledType = OgdcFieldInfo::INT32;
	}
	else if (strUGType.CompareNoCase(_U("INT64")) == 0)
	{
		ugFiledType = OgdcFieldInfo::INT64;
	}
	else if (strUGType.CompareNoCase(_U("Float")) == 0)
	{
		ugFiledType = OgdcFieldInfo::Float;
	}
	else if (strUGType.CompareNoCase(_U("Double")) == 0)
	{
		ugFiledType = OgdcFieldInfo::Double;
	}
	else if (strUGType.CompareNoCase(_U("Date")) == 0)
	{
		ugFiledType = OgdcFieldInfo::Date;
	}
	else if (strUGType.CompareNoCase(_U("Binary")) == 0)
	{
		ugFiledType = OgdcFieldInfo::Binary;
	}
	else if (strUGType.CompareNoCase(_U("Text")) == 0)
	{
		ugFiledType = OgdcFieldInfo::Text;
	}
	else if (strUGType.CompareNoCase(_U("LongBinary")) == 0)
	{
		ugFiledType = OgdcFieldInfo::LongBinary;
	}
	else if (strUGType.CompareNoCase(_U("Char")) == 0)
	{
		ugFiledType = OgdcFieldInfo::Char;
	}
	else if (strUGType.CompareNoCase(_U("Time")) == 0)
	{
		ugFiledType = OgdcFieldInfo::Time;
	}
	else if (strUGType.CompareNoCase(_U("TimeStamp")) == 0)
	{
		ugFiledType = OgdcFieldInfo::TimeStamp;
	}
	else if (strUGType.CompareNoCase(_U("NText")) == 0)
	{
		ugFiledType = OgdcFieldInfo::NText;
	}
	else if (strUGType.CompareNoCase(_U("Geometry")) == 0)
	{
		ugFiledType = OgdcFieldInfo::Geometry;
	}

	return int(ugFiledType);
}

PyString Toolkit::FromUGFieldType(int nType)
{
	OgdcFieldInfo::FieldType ugFiledType = OgdcFieldInfo::FieldType(nType);
	PyString strType = _U("UnKnown");

	switch (ugFiledType)
	{
	case OGDC::OgdcFieldInfo::UnKnown:
		strType = _U("UnKnown");
		break;
	case OGDC::OgdcFieldInfo::Boolean:
		strType = _U("Boolean");
		break;
	case OGDC::OgdcFieldInfo::Byte:
		strType = _U("UnKnown");
		break;
	case OGDC::OgdcFieldInfo::INT16:
		strType = _U("INT16");
		break;
	case OGDC::OgdcFieldInfo::INT32:
		strType = _U("INT32");
		break;
	case OGDC::OgdcFieldInfo::INT64:
		strType = _U("UnKnown");
		break;
	case OGDC::OgdcFieldInfo::Float:
		strType = _U("Float");
		break;
	case OGDC::OgdcFieldInfo::Double:
		strType = _U("Double");
		break;
	case OGDC::OgdcFieldInfo::Date:
		strType = _U("Date");
		break;
	case OGDC::OgdcFieldInfo::Binary:
		strType = _U("Binary");
		break;
	case OGDC::OgdcFieldInfo::Text:
		strType = _U("Text");
		break;
	case OGDC::OgdcFieldInfo::LongBinary:
		strType = _U("LongBinary");
		break;
	case OGDC::OgdcFieldInfo::Char:
		strType = _U("Char");
		break;
	case OGDC::OgdcFieldInfo::Time:
		strType = _U("Time");
		break;
	case OGDC::OgdcFieldInfo::TimeStamp:
		strType = _U("TimeStamp");
		break;
	case OGDC::OgdcFieldInfo::NText:
		strType = _U("NText");
		break;
	case OGDC::OgdcFieldInfo::Geometry:
		strType = _U("Geometry");
		break;
	default:
		strType = _U("UnKnown");
		break;
	}

	return strType;
}

int Toolkit::ToUGFieldSign(const PyString& strFieldSign)
{
	OgdcString strUGFieldSign(strFieldSign.c_str());
	OgdcFieldInfo::FieldSign ugFieldSign = OgdcFieldInfo::signNone;
	
	if (strUGFieldSign.CompareNoCase(_U("signNone")) == 0)
	{
		ugFieldSign = OgdcFieldInfo::signNone;
	}
	else if (strUGFieldSign.CompareNoCase(_U("signNodeID")) == 0)
	{
		ugFieldSign = OgdcFieldInfo::signNodeID;
	}
	else if (strUGFieldSign.CompareNoCase(_U("signFNode")) == 0)
	{
		ugFieldSign = OgdcFieldInfo::signFNode;
	}
	else if (strUGFieldSign.CompareNoCase(_U("signTNode")) == 0)
	{
		ugFieldSign = OgdcFieldInfo::signTNode;
	}
	else if (strUGFieldSign.CompareNoCase(_U("signEdgeID")) == 0)
	{
		ugFieldSign = OgdcFieldInfo::signEdgeID;
	}
	else if (strUGFieldSign.CompareNoCase(_U("signRouteID")) == 0)
	{
		ugFieldSign = OgdcFieldInfo::signRouteID;
	}
	else if (strUGFieldSign.CompareNoCase(_U("signID")) == 0)
	{
		ugFieldSign = OgdcFieldInfo::signID;
	}
	else if (strUGFieldSign.CompareNoCase(_U("signGeometry")) == 0)
	{
		ugFieldSign = OgdcFieldInfo::signGeometry;
	}
	else if (strUGFieldSign.CompareNoCase(_U("signStart")) == 0)
	{
		ugFieldSign = OgdcFieldInfo::signStart;
	}

	return int(ugFieldSign);
}

PyString Toolkit::FromUFieldSign(int nType)
{
	OgdcFieldInfo::FieldSign ugFieldSign = OgdcFieldInfo::FieldSign(nType);
	PyString strType = _U("signNone");

	switch (ugFieldSign)
	{
	case OGDC::OgdcFieldInfo::signNone:
		strType = _U("signNone");
		break;
	case OGDC::OgdcFieldInfo::signNodeID:
		strType = _U("signNodeID");
		break;
	case OGDC::OgdcFieldInfo::signFNode:
		strType = _U("signNone");
		break;
	case OGDC::OgdcFieldInfo::signTNode:
		strType = _U("signTNode");
		break;
	case OGDC::OgdcFieldInfo::signEdgeID:
		strType = _U("signEdgeID");
		break;
	case OGDC::OgdcFieldInfo::signRouteID:
		strType = _U("signRouteID");
		break;
	case OGDC::OgdcFieldInfo::signID:
		strType = _U("signID");
		break;
	case OGDC::OgdcFieldInfo::signGeometry:
		strType = _U("signGeometry");
		break;
	case OGDC::OgdcFieldInfo::signStart:
		strType = _U("signStart");
		break;
	default:
		break;
	}

	return strType;
}