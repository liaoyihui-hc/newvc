#pragma once


// daig �Ի���

class daig : public CDialogEx
{
	DECLARE_DYNAMIC(daig)

public:
	daig(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~daig();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int a;
	int b;
	int c;
	afx_msg void OnBnClickedButton1();
};
