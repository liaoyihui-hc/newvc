
// ����ƶ�������View.h : C����ƶ�������View ��Ľӿ�
//

#pragma once


class C����ƶ�������View : public CView
{
protected: // �������л�����
	C����ƶ�������View();
	DECLARE_DYNCREATE(C����ƶ�������View)

// ����
public:
	C����ƶ�������Doc* GetDocument() const;

// ����
public:
	int a, b, c, d;
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
	virtual ~C����ƶ�������View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ����ƶ�������View.cpp �еĵ��԰汾
inline C����ƶ�������Doc* C����ƶ�������View::GetDocument() const
   { return reinterpret_cast<C����ƶ�������Doc*>(m_pDocument); }
#endif

