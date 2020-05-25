
// MFCApplication1View.cpp : CMFCApplication1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include "diag.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int color=RGB(255, 255, 255);

// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONUP()

	ON_COMMAND(ID_32771, &CMFCApplication1View::On32771)
END_MESSAGE_MAP()

// CMFCApplication1View ����/����

CMFCApplication1View::CMFCApplication1View()
{
	rc.top = 50;
	rc.bottom = 300;
	rc.left = 100;
	rc.right = 500;// TODO: �ڴ˴���ӹ������

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View ����

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	pDC->Ellipse(rc);
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	
		return;
	

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCApplication1View ��ӡ

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCApplication1View ���

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View ��Ϣ�������


void CMFCApplication1View::OnMButtonDown(UINT nFlags, CPoint point)
{


	CView::OnMButtonDown(nFlags, point);
}


void CMFCApplication1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	CDC*pDC = GetDC();
	CClientDC dc(this);
	
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ


	if (point.x >=rc.left&&point.x <=rc.right&&point.y <= rc.bottom&&point.y >=rc.top)
	{
		CPen newPen(PS_DOT, 1, color);
	CPen*oldPen = dc.SelectObject(&newPen);
	
		dc.Rectangle(rc);
		dc.SelectObject(oldPen);
		Sleep(100);
		CBrush newBrush(color);
		CBrush*oldBrush = dc.SelectObject(&newBrush);
		dc.Ellipse(rc);
	
	
		
	
	
	
	}// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CView::OnLButtonUp(nFlags, point);
}





void CMFCApplication1View::On32771()
{
	
		



		diag dc;
		int result = dc.DoModal();
		if (result == IDOK)
		{
			UpdateData(true);
		color = RGB(dc.R, dc.G, dc.Y);


		}// TODO: �ڴ���������������
	
}
