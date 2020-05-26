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
	, a(0)
	, b(0)
	, result(0)
	, daoshu(0)
	, sqrt_result(0)

	
{

}

diag::~diag()
{  
}

void diag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Control(pDX, IDC_COMBO1, combox);
	DDX_Text(pDX, IDC_EDIT3, result);
	DDX_Text(pDX, IDC_EDIT4, daoshu);
	DDX_Text(pDX, IDC_EDIT5, sqrt_result);
}


BEGIN_MESSAGE_MAP(diag, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &diag::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &diag::结果等于)
	ON_BN_CLICKED(IDC_BUTTON1, &diag::求倒数)
	ON_BN_CLICKED(IDC_BUTTON3, &diag::开平方)
	ON_BN_CLICKED(IDC_BUTTON2, &diag::等于)
END_MESSAGE_MAP()


// diag 消息处理程序


void diag::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void diag::结果等于()
{
	
	UpdateData(true);
	if (a == 0)
		daoshu = 0;
    daoshu= 1/a;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void diag::求倒数()
{

	// TODO: 在此添加控件通知处理程序代码
}


void diag::开平方()
{
	UpdateData(true);

	sqrt_result = sqrt(a) ;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


BOOL diag::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	combox.AddString(_T("+"));
	combox.AddString(_T("-"));
	combox.AddString(_T("*"));
	combox.AddString(_T("/"));
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void diag::等于()
{
	UpdateData(true);


	int nIndex = combox.GetCurSel();

	CString strCBText;
	combox.GetLBText(nIndex, strCBText);

	if (strCBText == _T("+"))
	{

		result = a + b;


	}
	else if (strCBText == _T("-"))
	{

		result = a - b;

	}
	else if (strCBText == _T("*"))
	{


		result = a * b;

	}
	else if (strCBText == _T("/"))
	{

		if (b == 0)
			MessageBox(_T("分母不能为零"));
		else
		{
			result = a / b;

		}

	}
	UpdateData(false);// TODO: 在此添加控件通知处理程序代码
}
