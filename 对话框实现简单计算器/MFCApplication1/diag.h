#pragma once
#include "afxwin.h"


// diag �Ի���

class diag : public CDialogEx
{
	DECLARE_DYNAMIC(diag)

public:
	diag(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~diag();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	float a;
	float b;
	CComboBox combox;
	float result;
	float daoshu;
	double sqrt_result;
	afx_msg void �������();
	afx_msg void ����();
	afx_msg void ��ƽ��();
   
	
	virtual BOOL OnInitDialog();
	afx_msg void ����();
};
