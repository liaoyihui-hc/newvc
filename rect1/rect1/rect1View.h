
// rect1View.h : Crect1View ��Ľӿ�
//

#pragma once


class Crect1View : public CView
{
protected: // �������л�����
	Crect1View();
	DECLARE_DYNCREATE(Crect1View)

// ����
public:
	Crect1Doc* GetDocument() const;
	CArray<CRect, CRect&> rect;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Crect1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // rect1View.cpp �еĵ��԰汾
inline Crect1Doc* Crect1View::GetDocument() const
   { return reinterpret_cast<Crect1Doc*>(m_pDocument); }
#endif

