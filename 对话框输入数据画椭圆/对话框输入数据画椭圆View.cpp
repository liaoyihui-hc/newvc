
// �Ի����������ݻ���ԲView.cpp : C�Ի����������ݻ���ԲView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�Ի����������ݻ���Բ.h"
#endif

#include "�Ի����������ݻ���ԲDoc.h"
#include "�Ի����������ݻ���ԲView.h"
#include "diag.h"+
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�Ի����������ݻ���ԲView

IMPLEMENT_DYNCREATE(C�Ի����������ݻ���ԲView, CView)

BEGIN_MESSAGE_MAP(C�Ի����������ݻ���ԲView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &C�Ի����������ݻ���ԲView::�е㻭��Բ)
END_MESSAGE_MAP()

// C�Ի����������ݻ���ԲView ����/����

C�Ի����������ݻ���ԲView::C�Ի����������ݻ���ԲView()
{
	// TODO: �ڴ˴���ӹ������

}

C�Ի����������ݻ���ԲView::~C�Ի����������ݻ���ԲView()
{
}

BOOL C�Ի����������ݻ���ԲView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�Ի����������ݻ���ԲView ����

void C�Ի����������ݻ���ԲView::OnDraw(CDC* /*pDC*/)
{
	C�Ի����������ݻ���ԲDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�Ի����������ݻ���ԲView ��ӡ

BOOL C�Ի����������ݻ���ԲView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�Ի����������ݻ���ԲView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�Ի����������ݻ���ԲView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�Ի����������ݻ���ԲView ���

#ifdef _DEBUG
void C�Ի����������ݻ���ԲView::AssertValid() const
{
	CView::AssertValid();
}

void C�Ի����������ݻ���ԲView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�Ի����������ݻ���ԲDoc* C�Ի����������ݻ���ԲView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�Ի����������ݻ���ԲDoc)));
	return (C�Ի����������ݻ���ԲDoc*)m_pDocument;
}
#endif //_DEBUG


// C�Ի����������ݻ���ԲView ��Ϣ�������


void C�Ի����������ݻ���ԲView::�е㻭��Բ()
{
	diag dc;
	int result = dc.DoModal();
	if (result == IDOK)
	{
		UpdateData(TRUE);
		������Բ(dc.x, dc.y, dc.a, dc.b);
	}// TODO: �ڴ���������������
}
void C�Ի����������ݻ���ԲView::������Բ(int xc, int yc, int a, int b)
{
	CDC*pDC=GetDC();
	int x, y, c = 0;
	double d1, d2;
	x = 0;
	y = b;
	d1 = b*b + a*a*(-b + 0.25);
	pDC->SetPixel(x + 300, y + 200, c);
	pDC->SetPixel(-x + 300, y + 200, c);
	pDC->SetPixel(x + 300, -y + 200, c);
	pDC->SetPixel(-x + 300, -y + 200, c);
	while (b*b*(x + 1) < a*a*(y - 0.5))
	{
		if (d1 < 0) {
			d1 += b*b*(2 * x + 3);
			x++;

		}
		else
		{

			d1 += b*b*(2 * x + 3) + a*a*(-2 * y + 2);
			x++;
			y--;

		}
		pDC->SetPixel(x + xc, y + yc, c);
		pDC->SetPixel(-x + xc, y + yc, c);
		pDC->SetPixel(x + xc, -y + yc, c);
		pDC->SetPixel(-x + xc, -y + yc, c);

	}
	d2 = sqrt(b*(x + 0.5)) + a*(y - 1) - a*b;
	while (y > 0)
	{

		if (d2 < 0)
		{
			d2 += b*b*(2 * x + 2) + a*a*(-2 * y + 3);
			x++;
			y--;
		}
		else {
			d2 += a*a*(-2 * y + 3);
			y--;
		}
		pDC->SetPixel(x + xc, y + yc, c);
		pDC->SetPixel(-x + xc, y + yc, c);
		pDC->SetPixel(x + xc, -y + yc, c);
		pDC->SetPixel(-x + xc, -y + yc, c);
	}


}