
// �ƶ�����View.cpp : C�ƶ�����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ƶ�����.h"
#endif

#include "�ƶ�����Doc.h"
#include "�ƶ�����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ƶ�����View

IMPLEMENT_DYNCREATE(C�ƶ�����View, CView)

BEGIN_MESSAGE_MAP(C�ƶ�����View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C�ƶ�����View ����/����
int a, b, c, d;
C�ƶ�����View::C�ƶ�����View()
{
	dc.left = 0;
	dc.top = 0;
	dc.right = 100;
	dc.bottom =100;
	// TODO: �ڴ˴���ӹ������

}

C�ƶ�����View::~C�ƶ�����View()
{
}

BOOL C�ƶ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ƶ�����View ����

void C�ƶ�����View::OnDraw(CDC* pDC)
{
	C�ƶ�����Doc* pDoc = GetDocument();
	pDC->Rectangle(dc);
	ASSERT_VALID(pDoc);
	if (!pDoc)
	
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ƶ�����View ��ӡ

BOOL C�ƶ�����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ƶ�����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ƶ�����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ƶ�����View ���

#ifdef _DEBUG
void C�ƶ�����View::AssertValid() const
{
	CView::AssertValid();
}

void C�ƶ�����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ƶ�����Doc* C�ƶ�����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ƶ�����Doc)));
	return (C�ƶ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ƶ�����View ��Ϣ�������


void C�ƶ�����View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	c = point.x;
	d = point.y;
	c = c - a;
	d = d - b;
	CView::OnMouseMove(nFlags, point);
}


void C�ƶ�����View::OnLButtonDown(UINT nFlags, CPoint point)
{

	CDC*pDC = GetDC();
	if (point.y > dc.top&&point.y<dc.bottom&&point.x>dc.left&&point.x < dc.right)
	{
		SetCapture();
		a = point.x;
		b = point.y;
	}
	else {
		MessageBox(_T("������Ч"));
	}
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);
}


void C�ƶ�����View::OnLButtonUp(UINT nFlags, CPoint point)
{
	CDC*pDC = GetDC();
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
		dc.left = dc.left+(c);
		dc.top = dc.top+(d);
		dc.right = dc.right + (c);
		dc.bottom = dc.bottom + (d );
		Invalidate();
		pDC->Rectangle(dc);
	
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}
