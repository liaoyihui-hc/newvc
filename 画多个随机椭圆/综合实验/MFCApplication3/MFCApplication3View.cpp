
// MFCApplication3View.cpp : CMFCApplication3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Set.h"
#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3View

IMPLEMENT_DYNCREATE(CMFCApplication3View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication3View, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCApplication3View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication3View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication3View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCApplication3View::OnRecordLast)
END_MESSAGE_MAP()

// CMFCApplication3View ����/����

CMFCApplication3View::CMFCApplication3View()
	: CRecordView(IDD_MFCAPPLICATION3_FORM)
	, s(_T(""))
{
	m_pSet = NULL;
	path = _T("E:\\HTML\\image\\");
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication3View::~CMFCApplication3View()
{
}

void CMFCApplication3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication3Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication3View ��ӡ

BOOL CMFCApplication3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCApplication3View ���

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View ���ݿ�֧��
CRecordset* CMFCApplication3View::OnGetRecordset()
{
	return m_pSet;
}

void CMFCApplication3View::draw(CString file)
{
	CClientDC dc(this);
	CImage img;
	img.Load(file);
	CDC*pDC = GetDlgItem(IDC_STATIC)->GetDC();
	CRect rect;
	int sx, sy, w, h;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_radio = 1.0*rect.Width() / rect.Height();
	float img_radio = 1.0*img.GetWidth() / img.GetWidth();
	if (rect_radio > img_radio)
	{
		h = rect.Height();
		w = img_radio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;

	}
	img.Draw(dc.m_hDC, sx, sy, w, h);
}
// CMFCApplication3View ��Ϣ�������



void CMFCApplication3View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: �ڴ���������������
	CString filename, s,s1;
	s1 = _T(".jpg");
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s+s1;
	draw(filename);
}


void CMFCApplication3View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}// TODO: �ڴ���������������
	UpdateData(false);
	CString filename, s, s1;
	s1 = _T(".jpg");
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s + s1;
	draw(filename);
}


void CMFCApplication3View::OnRecordNext()
{

	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveLast();
	}// TODO: �ڴ���������������
	UpdateData(false);// TODO: �ڴ���������������
	CString filename, s, s1;
	s1 = _T(".jpg");
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s + s1;
	draw(filename);
}


void CMFCApplication3View::OnRecordLast()
{
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s, s1;
	s1 = _T(".jpg");
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s + s1;
	draw(filename);
}
