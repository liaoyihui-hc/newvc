
// ����˵���ʾ����View.h : C����˵���ʾ����View ��Ľӿ�
//

#pragma once


class C����˵���ʾ����View : public CView
{
protected: // �������л�����
	C����˵���ʾ����View();
	DECLARE_DYNCREATE(C����˵���ʾ����View)

// ����
public:
	C����˵���ʾ����Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C����˵���ʾ����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
};

#ifndef _DEBUG  // ����˵���ʾ����View.cpp �еĵ��԰汾
inline C����˵���ʾ����Doc* C����˵���ʾ����View::GetDocument() const
   { return reinterpret_cast<C����˵���ʾ����Doc*>(m_pDocument); }
#endif

