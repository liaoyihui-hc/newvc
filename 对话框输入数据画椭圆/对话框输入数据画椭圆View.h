
// �Ի����������ݻ���ԲView.h : C�Ի����������ݻ���ԲView ��Ľӿ�
//

#pragma once


class C�Ի����������ݻ���ԲView : public CView
{
protected: // �������л�����
	C�Ի����������ݻ���ԲView();
	DECLARE_DYNCREATE(C�Ի����������ݻ���ԲView)

// ����
public:
	C�Ի����������ݻ���ԲDoc* GetDocument() const;

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
	virtual ~C�Ի����������ݻ���ԲView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void �е㻭��Բ();
	void ������Բ(int x, int y, int a, int b);
};

#ifndef _DEBUG  // �Ի����������ݻ���ԲView.cpp �еĵ��԰汾
inline C�Ի����������ݻ���ԲDoc* C�Ի����������ݻ���ԲView::GetDocument() const
   { return reinterpret_cast<C�Ի����������ݻ���ԲDoc*>(m_pDocument); }
#endif

