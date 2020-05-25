// diag.cpp : 实现文件
//

#include "stdafx.h"
#include "对话框输入数据画椭圆.h"
#include "diag.h"
#include "afxdialogex.h"


// diag 对话框

IMPLEMENT_DYNAMIC(diag, CDialogEx)

diag::diag(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, a(0)
	, b(0)
{

}

diag::~diag()
{
}

void diag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, x);
	DDX_Text(pDX, IDC_EDIT1, y);
	DDX_Text(pDX, IDC_EDIT3, a);
	DDX_Text(pDX, IDC_EDIT4, b);
}


BEGIN_MESSAGE_MAP(diag, CDialogEx)
END_MESSAGE_MAP()


// diag 消息处理程序
