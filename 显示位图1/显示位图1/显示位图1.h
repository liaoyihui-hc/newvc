
// ��ʾλͼ1.h : ��ʾλͼ1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ʾλͼ1App:
// �йش����ʵ�֣������ ��ʾλͼ1.cpp
//

class C��ʾλͼ1App : public CWinApp
{
public:
	C��ʾλͼ1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ʾλͼ1App theApp;
