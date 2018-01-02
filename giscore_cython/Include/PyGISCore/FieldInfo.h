#ifndef FIELDINFO_INCLUDE_H
#define FIELDINFO_INCLUDE_H

#include "PyGISCore/exports.h"
#include "PyGISCore/def.h"
#include <vector>

//! \breif �ֶ���
class GISCORE_API FieldInfo
{
public:
	//! \breif ���캯��
	FieldInfo();

	//! \breif ���캯��
	FieldInfo(const PyString& strName, const PyString& strType, int nSize);

	//! \breif ��������
	FieldInfo(const FieldInfo& fieldInfo);

	//! \breif ��������
	~FieldInfo();

	//! \brief ���� = 
	const FieldInfo& operator =(const FieldInfo& fieldInfo);

	//! \brief ���� ==
	bool operator ==(const FieldInfo& fieldInfo);

	//! \brief ���� != 
	bool operator !=(const FieldInfo& fieldInfo);

	//! \brief  �ж��ֶ��Ƿ�ɸ��¡�
	//! \return �Ƿ���Ը��£����Է���TRUE�������Է���FALSE��
	bool CanUpdate();	

	//! \brief �ж��Ƿ���ϵͳ�ֶ�
	//! \return �Ƿ���ϵͳ�ֶΣ��Ƿ���TRUE�����Ƿ���FALSE��
	bool IsSystemField();

	//! \brief �ж��Ƿ��Ǽ��ζ����ֶ�
	//! \return �Ƿ��Ǽ��ζ����ֶΣ��Ƿ���TRUE�����Ƿ���FALSE��
	bool IsGeoField();

	//! \brief �ж��Ƿ��������
	//! \return �Ƿ�����������Ƿ���TRUE�����Ƿ���FALSE��
	bool IsContainIndex();

	//! \brief �ж��ֶ��Ƿ�ΪUUID
	bool IsUUIDField();

	//! \brief ����Ĭ��ֵ
	void SetDefaultValue(const PyString& strDefaultValue);

	//! \brief ��ȡĬ��ֵ
	//! \return Ĭ��ֵ���ַ�����ʽ
	PyString & GetDefaultValue();

public:	
	//! \brief �Ƿ���ϵͳUUID�ֶ�
	bool m_bUUID;

	//! \brief �Ƿ���ϵͳ�ֶΡ�
	bool m_bSystem;

	//! \brief �Ƿ��Ǳ����ֶΡ�
	bool m_bRequired;

	//! \brief �ֶγ����Ƿ������㳤�ȡ�
	bool m_bAllowZeroLength;

	//! \brief �̶�
	int m_nScale;

	//! \brief ����
	int m_nPrecision;

	//! \brief �ֶγ��ȡ�
	int m_nSize;

	//! \brief �ֶ����ԡ�
	int m_nAttributes;

	//! \brief �ֶ����λ�á�
	int m_nOrdinalPosition;

	//! \brief �Ƚ�����
	int m_nCollatingOrder;

	//! \brief �ֶ����͡�
	//	--UnKnown		��ʶ�������
	//	--Boolean		����ֵ�����ֽڣ�TRUE,FALSE
	//	--Byte			�޷��ŵ����0-255
	//	--INT16			�����ͣ�2�ֽ�
	//	--INT32			�����ͣ�4�ֽ�
	//	--INT64			�����ͣ�8�ֽ�, 
	//	--Float			�����ȸ����ͣ�4�ֽ�
	//	--Double		˫���ȸ����ͣ�8�ֽ�
	//	--Date			�����ͣ��ꡢ�¡��գ�����ʱ��
	//	--Binary		�̶����ȶ������ͣ���ָ������
	//	--Text			�������ַ�����
	//	--LongBinary	����������������
	//	--Char			�����ַ����ͣ���ָ������ 
	//	--Time			ʱ���ͣ�Сʱ���֡��룬��������
	//	--TimeStamp		ʱ����ͣ��ꡢ�¡��ա�Сʱ���֡���
	//	--NText			���ֽڲ������ַ�������
	//	--Geometry		������������
	PyString m_strType;

	//! \brief �ֶα�ʶ��
	//	--signNone	    Ĭ��
	//	--signNodeID	�������ݼ��Ľڵ�ID��Ĭ����SmNodeID�ֶ� 
	//	--signFNode		�������ݼ�����ֶ�, Ĭ����SmFNode 
	//	--signTNode		�������ݼ��յ��ֶ�, Ĭ����SmTNode
	//	--signEdgeID	�������ݼ��ߵ�ID�ֶ�
	//	--signRouteID	·�����ݼ���RouteID�ֶ�	
	//	--signID		����ID�ֶ�			
	//	--signGeometry	���ζ����ֶΡ�
	//	--signStart		�û��Զ����ֶα�ʶ��ʼֵ 
	PyString  m_strFieldSign;

	//! \brief �ֶ����ơ�
	PyString m_strName;

	//! \brief �ֶε��������
	PyString m_strForeignName;

	//! \brief Դ�ֶ���
	PyString m_strSourceField;

	//! \brief Դ����
	PyString m_strSourceTable;

	//! \brief ��֤����
	PyString m_strValidationRule;

	//! \brief ��֤����
	PyString m_strValidationText;

	//! \brief ��ʽ
	PyString m_strFormat;

	//! \brief ������Ϣ
	PyString m_strDomain;

	//! \brief �Ƿ�ɱ༭
	bool m_bUpdatable;

	//! \brief ����������
	PyString m_strIndexTab;

private:
	//! \brief �ֶ�Ĭ��ֵ
	PyString m_strDefaultValue;
};

typedef std::vector<FieldInfo> FieldInfos;

#endif // !FIELDINFO_INCLUDE_H