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
	ON_BN_CLICKED(IDC_BUTTON1, &diag::�������)
	ON_BN_CLICKED(IDC_BUTTON1, &diag::����)
	ON_BN_CLICKED(IDC_BUTTON3, &diag::��ƽ��)
	ON_BN_CLICKED(IDC_BUTTON2, &diag::����)
END_MESSAGE_MAP()


// diag ��Ϣ�������


void diag::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void diag::�������()
{
	
	UpdateData(true);
	if (a == 0)
		daoshu = 0;
    daoshu= 1/a;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void diag::����()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void diag::��ƽ��()
{
	UpdateData(true);

	sqrt_result = sqrt(a) ;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL diag::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	combox.AddString(_T("+"));
	combox.AddString(_T("-"));
	combox.AddString(_T("*"));
	combox.AddString(_T("/"));
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void diag::����()
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
			MessageBox(_T("��ĸ����Ϊ��"));
		else
		{
			result = a / b;

		}

	}
	UpdateData(false);// TODO: �ڴ���ӿؼ�֪ͨ����������
}
