// diag.cpp : 实现文件
//

#include "stdafx.h"
#include "视图显示退出对话框.h"
#include "diag.h"
#include "afxdialogex.h"


// diag 对话框

IMPLEMENT_DYNAMIC(diag, CDialogEx)

diag::diag(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

diag::~diag()
{
}

void diag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(diag, CDialogEx)
END_MESSAGE_MAP()


// diag 消息处理程序
