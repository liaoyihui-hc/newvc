
// �ƶ�����.h : �ƶ����� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ƶ�����App:
// �йش����ʵ�֣������ �ƶ�����.cpp
//

class C�ƶ�����App : public CWinAppEx
{
public:
	C�ƶ�����App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ƶ�����App theApp;
