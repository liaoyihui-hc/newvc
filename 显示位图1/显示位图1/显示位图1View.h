
// ��ʾλͼ1View.h : C��ʾλͼ1View ��Ľӿ�
//

#pragma once


class C��ʾλͼ1View : public CView
{
protected: // �������л�����
	C��ʾλͼ1View();
	DECLARE_DYNCREATE(C��ʾλͼ1View)

// ����
public:
	C��ʾλͼ1Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C��ʾλͼ1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��ʾλͼ1View.cpp �еĵ��԰汾
inline C��ʾλͼ1Doc* C��ʾλͼ1View::GetDocument() const
   { return reinterpret_cast<C��ʾλͼ1Doc*>(m_pDocument); }
#endif

