
// ��ʾλͼ1View.cpp : C��ʾλͼ1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʾλͼ1.h"
#endif

#include "��ʾλͼ1Doc.h"
#include "��ʾλͼ1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʾλͼ1View

IMPLEMENT_DYNCREATE(C��ʾλͼ1View, CView)

BEGIN_MESSAGE_MAP(C��ʾλͼ1View, CView)
END_MESSAGE_MAP()

// C��ʾλͼ1View ����/����

C��ʾλͼ1View::C��ʾλͼ1View()
{
	// TODO: �ڴ˴���ӹ������
	
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

C��ʾλͼ1View::~C��ʾλͼ1View()
{
}

BOOL C��ʾλͼ1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ʾλͼ1View ����

void C��ʾλͼ1View::OnDraw(CDC* pDC)
{
	C��ʾλͼ1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ʾλͼ1View ���

#ifdef _DEBUG
void C��ʾλͼ1View::AssertValid() const
{
	CView::AssertValid();
}

void C��ʾλͼ1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ʾλͼ1Doc* C��ʾλͼ1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʾλͼ1Doc)));
	return (C��ʾλͼ1Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ʾλͼ1View ��Ϣ�������
