#pragma once


// diag �Ի���

class diag : public CDialogEx
{
	DECLARE_DYNAMIC(diag)

public:
	diag(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~diag();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	int a;
	int b;
};
