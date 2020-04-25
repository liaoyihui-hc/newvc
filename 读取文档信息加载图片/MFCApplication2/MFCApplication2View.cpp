
// MFCApplication2View.cpp : CMFCApplication2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif
#include "diag.h"
#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMFCApplication2View::ѡ�����ͼƬ)
	ON_COMMAND(ID_32771, &CMFCApplication2View::ͼƬѡ��)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMFCApplication2View ����/����

CMFCApplication2View::CMFCApplication2View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View ����

void CMFCApplication2View::OnDraw(CDC* /*pDC*/)
{CMFCApplication2Doc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCApplication2View ��ӡ

BOOL CMFCApplication2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCApplication2View ���

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View ��Ϣ�������


void CMFCApplication2View::ѡ�����ͼƬ()
{
	CMFCApplication2Doc* pDoc = GetDocument();
	CFileDialog diag(true);
	int result = diag.DoModal();
	if(result==IDOK)
	{ 
		pDoc->s= diag.GetFileName();
	
	}
	// TODO: �ڴ���������������
}


void CMFCApplication2View::ͼƬѡ��()
{
	diag dc;
	int result = dc.DoModal();
	// TODO: �ڴ���������������
}


void CMFCApplication2View::OnBnClickedButton1()
{
	CMFCApplication2Doc* pDoc = GetDocument();

	CImage img;
	img.Load(pDoc->s);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());  	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
