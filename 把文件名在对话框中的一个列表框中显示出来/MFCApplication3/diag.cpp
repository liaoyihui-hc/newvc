// diag.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "diag.h"
#include "afxdialogex.h"


// diag 对话框

IMPLEMENT_DYNAMIC(diag, CDialogEx)

diag::diag(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
{
	
}

diag::~diag()
{
	
}

void diag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, box);

	DDX_Text(pDX, IDC_EDIT1, s);
	box.AddString(s);
}


BEGIN_MESSAGE_MAP(diag, CDialogEx)
END_MESSAGE_MAP()


// diag 消息处理程序
