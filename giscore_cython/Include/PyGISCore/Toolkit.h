#ifndef TOOLKIT_INCLUDE_H
#define TOOLKIT_INCLUDE_H

#include "PyGISCore/exports.h"
#include "PyGISCore/def.h"

//! \breif ������
class GISCORE_API Toolkit
{
public:
	//! \breif ���캯��
	Toolkit();

	//! \breif ��������
	~Toolkit();

	//! \breif �ַ���ת��ΪUGC����Դ����
	static int ToUGDataSourceType(const PyString &strType); 

	//! \breif UGC����Դ����ת��Ϊ�ַ���
	static PyString FromDataSourceType(int nType);

	//! \breif �ַ���ת��ΪUGC���ظ�ʽ
	static int ToPixelFormat(const PyString& strPixelFormat);

	//! \breif �ַ���ת��ΪUGC���ظ�ʽ
	static PyString FromPixelFormat(int nPixelFormat);

	//! \breif �ַ���ת��ΪUGC�ַ���
	static int  ToUGCharset(const PyString& strCharset);

	//! \breif �ַ���ת��ΪUGC�ֶ�����
	static int ToUGFieldType(const PyString& strType);

	//! \breif UGC�ֶ�����ת��Ϊ�ַ���
	static PyString FromUGFieldType(int nType);

	//! \breif �ַ���ת��ΪUGC����ϵͳ�ֶα�ʶ
	static int ToUGFieldSign(const PyString& strFieldSign);

	//! \breif UGC����ϵͳ�ֶα�ʶת��Ϊ�ַ���
	static PyString FromUFieldSign(int nType);
};

#endif // !TOOLKIT_INCLUDE_H
