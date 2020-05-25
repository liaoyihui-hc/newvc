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
	, R(0)
	, G(0)
	, Y(0)
{

}

diag::~diag()
{
}

void diag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, R);
	DDX_Text(pDX, IDC_EDIT2, G);
	DDX_Text(pDX, IDC_EDIT3, Y);
}


BEGIN_MESSAGE_MAP(diag, CDialogEx)
END_MESSAGE_MAP()


// diag 消息处理程序
