
// exp23View.h : Cexp23View ��Ľӿ�
//

#pragma once


class Cexp23View : public CView
{
protected: // �������л�����
	Cexp23View();
	DECLARE_DYNCREATE(Cexp23View)

// ����
public:
	Cexp23Doc* GetDocument() const;

// ����
public:
	CRect mes;
	CString str1, str2;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // exp23View.cpp �еĵ��԰汾
inline Cexp23Doc* Cexp23View::GetDocument() const
   { return reinterpret_cast<Cexp23Doc*>(m_pDocument); }
#endif

