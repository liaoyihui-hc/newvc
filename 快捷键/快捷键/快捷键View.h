
// ��ݼ�View.h : C��ݼ�View ��Ľӿ�
//

#pragma once


class C��ݼ�View : public CView
{
protected: // �������л�����
	C��ݼ�View();
	DECLARE_DYNCREATE(C��ݼ�View)

// ����
public:
	C��ݼ�Doc* GetDocument() const;

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
	virtual ~C��ݼ�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ��ݼ�View.cpp �еĵ��԰汾
inline C��ݼ�Doc* C��ݼ�View::GetDocument() const
   { return reinterpret_cast<C��ݼ�Doc*>(m_pDocument); }
#endif

