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
	ON_BN_CLICKED(IDC_BUTTON2, &diag::����)
END_MESSAGE_MAP()


// diag ��Ϣ�������


void diag::OnBnClickedButton1()
{  
	CString s3;	
	box.ResetContent();
	UpdateData(true);
	s3 = s2.GetString();
	a[num-1] = s3;

	for (int i = 0; i < 10; i++)
		box.AddString(a[i]);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}








BOOL diag::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	for (int i = 0; i < 10; i++)
	box.AddString(a[i]);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void diag::OnLbnSelchangeList1()
{
	
	CString s1;
	num= box.GetCurSel();//��ȡѡ��ֵ������
box.GetText(num, s1);
s2= s1;
UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void diag::����()
{
	CFileDialog dia(FALSE);
	int result = dia.DoModal();// TODO: �ڴ���ӿؼ�֪ͨ����������
}
