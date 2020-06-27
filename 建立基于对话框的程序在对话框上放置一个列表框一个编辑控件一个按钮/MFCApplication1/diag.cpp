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
	, s2(_T(""))
{

}

diag::~diag()
{
}

void diag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, box);
	DDX_Control(pDX, IDC_EDIT1, s);
	DDX_Text(pDX, IDC_EDIT1, s2);
}


BEGIN_MESSAGE_MAP(diag, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &diag::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &diag::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON2, &diag::保存)
END_MESSAGE_MAP()


// diag 消息处理程序


void diag::OnBnClickedButton1()
{  
	CString s3;	
	box.ResetContent();
	UpdateData(true);
	s3 = s2.GetString();
	a[num-1] = s3;

	for (int i = 0; i < 10; i++)
		box.AddString(a[i]);

	// TODO: 在此添加控件通知处理程序代码
}








BOOL diag::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	for (int i = 0; i < 10; i++)
	box.AddString(a[i]);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void diag::OnLbnSelchangeList1()
{
	
	CString s1;
	num= box.GetCurSel();//获取选中值的索引
box.GetText(num, s1);
s2= s1;
UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void diag::保存()
{
	CFileDialog dia(FALSE);
	int result = dia.DoModal();// TODO: 在此添加控件通知处理程序代码
}
