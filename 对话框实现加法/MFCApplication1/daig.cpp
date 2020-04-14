// daig.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "daig.h"
#include "afxdialogex.h"


// daig 对话框

IMPLEMENT_DYNAMIC(daig, CDialogEx)

daig::daig(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(0)
	, b(0)
	, c(0)
{

}

daig::~daig()
{
}

void daig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT3, b);
	DDX_Text(pDX, IDC_EDIT2, c);
}


BEGIN_MESSAGE_MAP(daig, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &daig::OnBnClickedButton1)
END_MESSAGE_MAP()


// daig 消息处理程序


void daig::OnBnClickedButton1()
{
	this->UpdateData(true);
c = a + b;// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(false);// TODO: 在此添加控件通知处理程序代码
}
