#pragma once
#include "afxwin.h"
#include "MFCApplication1Doc.h"

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
	CListBox box;
	CEdit s;
	CString a[10] ;
	int num;
	afx_msg void OnBnClickedButton1();

	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeList1();
	CString s2;
	afx_msg void ����();
};
