// diag.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
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
	ON_BN_CLICKED(IDC_BUTTON1, &diag::读取文件名加载图片)
END_MESSAGE_MAP()


// diag 消息处理程序


void diag::读取文件名加载图片()
{
 // TODO: 在此添加控件通知处理程序代码
}
