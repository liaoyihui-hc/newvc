
// ��ͼ��ʾ�˳��Ի���View.cpp : C��ͼ��ʾ�˳��Ի���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ͼ��ʾ�˳��Ի���.h"
#endif

#include "��ͼ��ʾ�˳��Ի���Doc.h"
#include "��ͼ��ʾ�˳��Ի���View.h"
#include "diag.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ͼ��ʾ�˳��Ի���View

IMPLEMENT_DYNCREATE(C��ͼ��ʾ�˳��Ի���View, CView)

BEGIN_MESSAGE_MAP(C��ͼ��ʾ�˳��Ի���View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C��ͼ��ʾ�˳��Ի���View ����/����

C��ͼ��ʾ�˳��Ի���View::C��ͼ��ʾ�˳��Ի���View()
{
	// TODO: �ڴ˴���ӹ������

}

C��ͼ��ʾ�˳��Ի���View::~C��ͼ��ʾ�˳��Ի���View()
{
}

BOOL C��ͼ��ʾ�˳��Ի���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ͼ��ʾ�˳��Ի���View ����

void C��ͼ��ʾ�˳��Ի���View::OnDraw(CDC* pDC)
{
	C��ͼ��ʾ�˳��Ի���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	diag dc;
	CString s;
	s = _T("�Ի������˳�");
	int result = dc.DoModal();
	if (result = IDOK)
	{
		pDC->TextOutW(20,20,s);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ͼ��ʾ�˳��Ի���View ��ӡ

BOOL C��ͼ��ʾ�˳��Ի���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ͼ��ʾ�˳��Ի���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ͼ��ʾ�˳��Ի���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��ͼ��ʾ�˳��Ի���View ���

#ifdef _DEBUG
void C��ͼ��ʾ�˳��Ի���View::AssertValid() const
{
	CView::AssertValid();
}

void C��ͼ��ʾ�˳��Ի���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ͼ��ʾ�˳��Ի���Doc* C��ͼ��ʾ�˳��Ի���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ͼ��ʾ�˳��Ի���Doc)));
	return (C��ͼ��ʾ�˳��Ի���Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ͼ��ʾ�˳��Ի���View ��Ϣ�������
