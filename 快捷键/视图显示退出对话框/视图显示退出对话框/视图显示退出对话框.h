
// ��ͼ��ʾ�˳��Ի���.h : ��ͼ��ʾ�˳��Ի��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ͼ��ʾ�˳��Ի���App:
// �йش����ʵ�֣������ ��ͼ��ʾ�˳��Ի���.cpp
//

class C��ͼ��ʾ�˳��Ի���App : public CWinAppEx
{
public:
	C��ͼ��ʾ�˳��Ի���App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ͼ��ʾ�˳��Ի���App theApp;
