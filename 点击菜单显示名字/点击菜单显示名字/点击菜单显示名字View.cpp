
// ����˵���ʾ����View.cpp : C����˵���ʾ����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����˵���ʾ����.h"
#endif

#include "����˵���ʾ����Doc.h"
#include "����˵���ʾ����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����˵���ʾ����View

IMPLEMENT_DYNCREATE(C����˵���ʾ����View, CView)

BEGIN_MESSAGE_MAP(C����˵���ʾ����View, CView)
	ON_COMMAND(ID_32771, &C����˵���ʾ����View::On32771)
END_MESSAGE_MAP()

// C����˵���ʾ����View ����/����

C����˵���ʾ����View::C����˵���ʾ����View()
{
	// TODO: �ڴ˴���ӹ������

}

C����˵���ʾ����View::~C����˵���ʾ����View()
{
}

BOOL C����˵���ʾ����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����˵���ʾ����View ����

void C����˵���ʾ����View::OnDraw(CDC* /*pDC*/)
{
	C����˵���ʾ����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C����˵���ʾ����View ���

#ifdef _DEBUG
void C����˵���ʾ����View::AssertValid() const
{
	CView::AssertValid();
}

void C����˵���ʾ����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����˵���ʾ����Doc* C����˵���ʾ����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����˵���ʾ����Doc)));
	return (C����˵���ʾ����Doc*)m_pDocument;
}
#endif //_DEBUG


// C����˵���ʾ����View ��Ϣ�������


void C����˵���ʾ����View::On32771()
{
	CString  c;
	c = _T("��ħ������");
	CClientDC dc(this);
	dc.TextOutW(200, 200, c);

	// TODO: �ڴ���������������
}
