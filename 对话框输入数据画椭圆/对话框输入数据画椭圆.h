
// �Ի����������ݻ���Բ.h : �Ի����������ݻ���Բ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�Ի����������ݻ���ԲApp:
// �йش����ʵ�֣������ �Ի����������ݻ���Բ.cpp
//

class C�Ի����������ݻ���ԲApp : public CWinAppEx
{
public:
	C�Ի����������ݻ���ԲApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�Ի����������ݻ���ԲApp theApp;
