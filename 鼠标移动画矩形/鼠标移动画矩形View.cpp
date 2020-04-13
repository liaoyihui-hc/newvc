
// ����ƶ�������View.cpp : C����ƶ�������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����ƶ�������.h"
#endif

#include "����ƶ�������Doc.h"
#include "����ƶ�������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ƶ�������View

IMPLEMENT_DYNCREATE(C����ƶ�������View, CView)

BEGIN_MESSAGE_MAP(C����ƶ�������View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C����ƶ�������View ����/����

C����ƶ�������View::C����ƶ�������View()
{
	// TODO: �ڴ˴���ӹ������

}

C����ƶ�������View::~C����ƶ�������View()
{
}

BOOL C����ƶ�������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����ƶ�������View ����

void C����ƶ�������View::OnDraw(CDC* pDC)
{
	C����ƶ�������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->rc);
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C����ƶ�������View ��ӡ

BOOL C����ƶ�������View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C����ƶ�������View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C����ƶ�������View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C����ƶ�������View ���

#ifdef _DEBUG
void C����ƶ�������View::AssertValid() const
{
	CView::AssertValid();
}

void C����ƶ�������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����ƶ�������Doc* C����ƶ�������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ƶ�������Doc)));
	return (C����ƶ�������Doc*)m_pDocument;
}
#endif //_DEBUG


// C����ƶ�������View ��Ϣ�������






void C����ƶ�������View::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C����ƶ�������Doc* pDoc = GetDocument();
	CView::OnLButtonDown(nFlags, point);
	pDoc->rc.left = point.x;
	pDoc->rc.top = point.y;
}


void C����ƶ�������View::OnMouseMove(UINT nFlags, CPoint point)
{
	SetCapture();
	C����ƶ�������Doc* pDoc = GetDocument();
	pDoc->rc.right = point.x;
	pDoc->rc.bottom = point.y;// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnMouseMove(nFlags, point);
}


void C����ƶ�������View::OnLButtonUp(UINT nFlags, CPoint point)
{
	
		// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C����ƶ�������Doc* pDoc = GetDocument();

	InvalidateRect(NULL, true);
	
	CView::OnLButtonUp(nFlags, point);
}
