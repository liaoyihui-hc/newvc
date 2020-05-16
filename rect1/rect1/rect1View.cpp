
// rect1View.cpp : Crect1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "rect1.h"
#endif

#include "rect1Doc.h"
#include "rect1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int a = 0, b = 0, c = 0;

// Crect1View

IMPLEMENT_DYNCREATE(Crect1View, CView)

BEGIN_MESSAGE_MAP(Crect1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Crect1View ����/����

Crect1View::Crect1View()
{
	rect.SetSize(256);
	for (int i = 0; i < 4; i++)
	{
		rect[i].bottom = 150;
		rect[i].left = 0;
		rect[i].top = 0;
		rect[i].right = 150;
	}


	// TODO: �ڴ˴���ӹ������

}

Crect1View::~Crect1View()
{
}

BOOL Crect1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Crect1View ����

void Crect1View::OnDraw(CDC* pDC)
{
	Crect1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(rect[0]);
	for (int i = 1; i < 4; i++)
	{
		
		rect[i].left= rect[i-1].left+200;

		rect[i].right = rect[i-1].right+200;
		pDC->Rectangle(rect[i]);
		
	}
		

	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Crect1View ��ӡ

BOOL Crect1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Crect1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Crect1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Crect1View ���

#ifdef _DEBUG
void Crect1View::AssertValid() const
{
	CView::AssertValid();
}

void Crect1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Crect1Doc* Crect1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Crect1Doc)));
	return (Crect1Doc*)m_pDocument;
}
#endif //_DEBUG


// Crect1View ��Ϣ�������


void Crect1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC*pDC = GetDC();
	
	CString s;

	
	

	CView::OnLButtonDown(nFlags, point);
	if (point.x > rect[0].left&&point.x<rect[0].right&&point.y>rect[0].top&&point.y < rect[0].bottom)
	{
		a = rand() % 50;
		s.Format(_T("%d"), a);
		pDC->TextOutW(50, 50, s);
	}
	else	if (point.x > rect[1].left&&point.x<rect[1].right&&point.y>rect[1].top&&point.y < rect[1].bottom)

	{
		b = rand() % 50;
		s.Format(_T("%d"), b);
		pDC->TextOutW(250, 50, s);

	}
	else	if (point.x > rect[2].left&&point.x<rect[2].right&&point.y>rect[2].top&&point.y < rect[2].bottom)

	{
		c = a + b;
		s.Format(_T("%d"), c);
		pDC->TextOutW(450, 50, s);

	}
	else
	{
		MessageBox(_T("�����Ч"));
	}
}
