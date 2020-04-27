// diag.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "diag.h"
#include "afxdialogex.h"


// diag 对话框

IMPLEMENT_DYNAMIC(diag, CDialogEx)

diag::diag(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(_T(""))
	, b(0)
	, c(_T(""))
{

}

diag::~diag()
{
}

void diag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, a);
	DDX_Text(pDX, IDC_EDIT1, b);
	DDX_Text(pDX, IDC_EDIT2, c);
}


BEGIN_MESSAGE_MAP(diag, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &diag::OnBnClickedButton1)
END_MESSAGE_MAP()


// diag 消息处理程序


void diag::OnBnClickedButton1()
{
	CString s;
	UpdateData(true);
	s.Format(_T("%d"), b);
	c = a + s;
	UpdateData(false);	// TODO: 在此添加控件通知处理程序代码
}
