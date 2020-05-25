
// MFCApplication3Set.cpp : CMFCApplication3Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3Set ʵ��

// ���������� 2020��5��25��, 16:50

IMPLEMENT_DYNAMIC(CMFCApplication3Set, CRecordset)

CMFCApplication3Set::CMFCApplication3Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication3Set::GetDefaultConnect()
{
	return _T("DSN=shujuyan;DBQ=C:\\Users\\liaoy\\Documents\\shujukun1.mdb;DefaultDir=C:\\Users\\liaoy\\Documents;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication3Set::GetDefaultSQL()
{
	return _T("[��1]");
}

void CMFCApplication3Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication3Set ���

#ifdef _DEBUG
void CMFCApplication3Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication3Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

