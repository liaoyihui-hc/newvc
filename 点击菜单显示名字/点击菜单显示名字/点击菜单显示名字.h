
// ����˵���ʾ����.h : ����˵���ʾ���� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C����˵���ʾ����App:
// �йش����ʵ�֣������ ����˵���ʾ����.cpp
//

class C����˵���ʾ����App : public CWinApp
{
public:
	C����˵���ʾ����App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C����˵���ʾ����App theApp;
