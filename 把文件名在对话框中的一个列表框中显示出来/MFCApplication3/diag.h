#pragma once
#include "afxwin.h"


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
	CString s;
};
