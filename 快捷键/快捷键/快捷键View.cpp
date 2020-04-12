
// ��ݼ�View.cpp : C��ݼ�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ݼ�.h"
#endif

#include "��ݼ�Doc.h"
#include "��ݼ�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ݼ�View

IMPLEMENT_DYNCREATE(C��ݼ�View, CView)

BEGIN_MESSAGE_MAP(C��ݼ�View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C��ݼ�View ����/����

C��ݼ�View::C��ݼ�View()
{
	// TODO: �ڴ˴���ӹ������

}

C��ݼ�View::~C��ݼ�View()
{
}

BOOL C��ݼ�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ݼ�View ����

void C��ݼ�View::OnDraw(CDC* pDC)
{
	C��ݼ�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->rc);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ݼ�View ��ӡ

BOOL C��ݼ�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ݼ�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ݼ�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��ݼ�View ���

#ifdef _DEBUG
void C��ݼ�View::AssertValid() const
{
	CView::AssertValid();
}

void C��ݼ�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ݼ�Doc* C��ݼ�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ݼ�Doc)));
	return (C��ݼ�Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ݼ�View ��Ϣ�������


void C��ݼ�View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	C��ݼ�Doc* pDoc = GetDocument();
	switch (nChar)
	{
	case VK_LEFT:
	{pDoc->rc.left += 10;
	pDoc->rc.right += 10;

	}
	break;
	case VK_RIGHT:
	{
		pDoc->rc.left -= 10;
		pDoc->rc.right -= 10;
	}
	break;
	case VK_UP:
	{
		pDoc->rc.top += 10;
		pDoc->rc.bottom += 10;
	}
	break;
	case VK_DOWN:
	{
		pDoc->rc.top -= 10;
		pDoc->rc.bottom -= 10;
	}
	break;
	case VK_HOME:
	{
		pDoc->rc.top -= 10;
		pDoc->rc.left -= 10;
	}

	break;
	case VK_END:
	{
		pDoc->rc.top += 10;
		pDoc->rc.left += 10;
	}

	break;
	default:
		break;
	}
	InvalidateRect(NULL, true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void C��ݼ�View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	C��ݼ�Doc* pDoc = GetDocument();
	pDoc->rc.left = 30;
	pDoc->rc.right = 80;
	pDoc->rc.top = 30;
	pDoc->rc.bottom = 80;
	
	InvalidateRect(NULL, true);
	CView::OnLButtonDown(nFlags, point);
}
