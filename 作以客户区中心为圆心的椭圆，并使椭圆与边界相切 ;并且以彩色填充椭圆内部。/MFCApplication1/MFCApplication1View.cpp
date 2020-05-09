
// MFCApplication1View.cpp : CMFCApplication1View ���ʵ��
//
#include<math.h>
#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFCApplication1View::��ֵ΢��)
	ON_COMMAND(ID_32772, &CMFCApplication1View::�е㻭��)
	ON_COMMAND(ID_32773, &CMFCApplication1View::Bresenham�㷨)
	ON_COMMAND(ID_32775, &CMFCApplication1View::On32775)
END_MESSAGE_MAP()

// CMFCApplication1View ����/����

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: �ڴ˴���ӹ������

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

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
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


void CMFCApplication1View::��ֵ΢��()
{  

	int xa = 100, ya = 300, xb = 300, yb = 200;
		
	��ֵ΢�ֻ���(xa, ya, xb, yb);
	
	
	// TODO: �ڴ���������������
}
void CMFCApplication1View::��ֵ΢�ֻ���(int xa,int ya,int xb,int yb)
{
	CDC*pDC = GetDC();
	int x, y, c = RGB(80, 255, 30);
	float dx, dy, k;
	dx = (float)(xb - xa),
		dy = (float)(yb - ya);
	k = dy / dx;
	y = ya;
	if (fabs(k) < 1)
	{
		for (x = xa; x <= xb; x++)
		{
			pDC->SetPixel(x, int(y + 0.5), c);
		
		}
	}
	if (fabs(k) >= 1)
	{
		for (y = ya; y <= yb; y++)
		{
			pDC->SetPixel(int(x + 0.5), y, c);
			x = x + 1 / k;
			c += 80;
		}

		ReleaseDC(pDC);
	}
}
void CMFCApplication1View::�е㻭��()
{
	
	int xa = 300, ya = 200, xb = 450, yb= 300;

	for (int i = 0; i <4; i++)
	{
		�е㻭�ߴ���(xa, ya, xb, yb);
		ya -= 10;
		yb += 10;
		
	}

}


void CMFCApplication1View::Bresenham�㷨()
{
// TODO: �ڴ���������������
}
void CMFCApplication1View::�е㻭�ߴ���(int xa, int ya, int xb, int yb)
{
	CDC*pDC = GetDC();
	int c = RGB(0, 255, 0);
	float a, b, d1, d2, d, dx, x, y;
	a = ya - yb, b = xb - xa, d = 2 * a + b;
	d1 = 2 * a, d2 = 2 * (a + b);
	x = xa, y = ya;
	pDC->SetPixel(x, y, c);
	while (x < xb)
	{

		if (d < 0)
		{
			x++,
				y++,
				d += d2;

		}
		else {
			x++, d += d1;
		}
		c = c + 10;
		pDC->SetPixel(x, y, c);
	}
	ReleaseDC(pDC);// TODO: �ڴ���������������
}

void CMFCApplication1View::On32775()
{
	CDC*pDC = GetDC();
	int x1 = 100, y1 = 200, x2 = 350, y2 = 100, c = RGB(0, 0, 255);
	int i, s1, s2, interchange;
	float x, y, deltax, deltay, e, temp, f;
	x = x1;
	y = y1;
	deltax = abs(x2 - x1);
	deltay = abs(y2 - y1);
	if (x2 - x1 >= 0)
		s1 = 1;
	else
		s1 = -1;
	if (y2 - y1 >= 0)
		s2 = 1;
	else
		s2 = -1;
	if (deltay > deltax)
	{
		temp = deltax;
		deltay = temp;
		interchange = 1;
	}
	else
		interchange = 0;
	f = 2 * deltay - deltax;
	pDC->SetPixel(x, y, c);
	for (i = 1; i <= deltax; i++)
	{
		if (f >= 0)
		{
			if (interchange == 1)
				x += s1;
			else
				y += s2;
			pDC->SetPixel(x, y, c);

		}
		else
		{
			if (interchange == 1)
				y += s2;
			else
				x += s1;
			f = f + 2 * deltay;
		}
	}// TODO: �ڴ���������������
}
