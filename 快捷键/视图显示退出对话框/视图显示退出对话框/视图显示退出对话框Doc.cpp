
// ��ͼ��ʾ�˳��Ի���Doc.cpp : C��ͼ��ʾ�˳��Ի���Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ͼ��ʾ�˳��Ի���.h"
#endif

#include "��ͼ��ʾ�˳��Ի���Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��ͼ��ʾ�˳��Ի���Doc

IMPLEMENT_DYNCREATE(C��ͼ��ʾ�˳��Ի���Doc, CDocument)

BEGIN_MESSAGE_MAP(C��ͼ��ʾ�˳��Ի���Doc, CDocument)
END_MESSAGE_MAP()


// C��ͼ��ʾ�˳��Ի���Doc ����/����

C��ͼ��ʾ�˳��Ի���Doc::C��ͼ��ʾ�˳��Ի���Doc()
{
	// TODO: �ڴ����һ���Թ������

}

C��ͼ��ʾ�˳��Ի���Doc::~C��ͼ��ʾ�˳��Ի���Doc()
{
}

BOOL C��ͼ��ʾ�˳��Ի���Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C��ͼ��ʾ�˳��Ի���Doc ���л�

void C��ͼ��ʾ�˳��Ի���Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C��ͼ��ʾ�˳��Ի���Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void C��ͼ��ʾ�˳��Ի���Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C��ͼ��ʾ�˳��Ի���Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C��ͼ��ʾ�˳��Ի���Doc ���

#ifdef _DEBUG
void C��ͼ��ʾ�˳��Ի���Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C��ͼ��ʾ�˳��Ի���Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C��ͼ��ʾ�˳��Ի���Doc ����
