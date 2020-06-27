#pragma once
#include "afxwin.h"
#include "MFCApplication1Doc.h"

// diag 对话框

class diag : public CDialogEx
{
	DECLARE_DYNAMIC(diag)

public:
	diag(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~diag();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
	afx_msg void 保存();
};
