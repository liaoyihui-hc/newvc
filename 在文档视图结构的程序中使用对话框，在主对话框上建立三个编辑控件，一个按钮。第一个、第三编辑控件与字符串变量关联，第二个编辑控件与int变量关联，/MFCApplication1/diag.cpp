// diag.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "diag.h"
#include "afxdialogex.h"


// diag �Ի���

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


// diag ��Ϣ�������


void diag::OnBnClickedButton1()
{
	CString s;
	UpdateData(true);
	s.Format(_T("%d"), b);
	c = a + s;
	UpdateData(false);	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
