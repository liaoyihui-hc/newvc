
// ��ݼ�.h : ��ݼ� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ݼ�App:
// �йش����ʵ�֣������ ��ݼ�.cpp
//

class C��ݼ�App : public CWinAppEx
{
public:
	C��ݼ�App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ݼ�App theApp;
