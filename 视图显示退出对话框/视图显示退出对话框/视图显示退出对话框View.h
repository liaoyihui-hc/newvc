
// ��ͼ��ʾ�˳��Ի���View.h : C��ͼ��ʾ�˳��Ի���View ��Ľӿ�
//

#pragma once


class C��ͼ��ʾ�˳��Ի���View : public CView
{
protected: // �������л�����
	C��ͼ��ʾ�˳��Ի���View();
	DECLARE_DYNCREATE(C��ͼ��ʾ�˳��Ի���View)

// ����
public:
	C��ͼ��ʾ�˳��Ի���Doc* GetDocument() const;

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
	virtual ~C��ͼ��ʾ�˳��Ի���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��ͼ��ʾ�˳��Ի���View.cpp �еĵ��԰汾
inline C��ͼ��ʾ�˳��Ի���Doc* C��ͼ��ʾ�˳��Ի���View::GetDocument() const
   { return reinterpret_cast<C��ͼ��ʾ�˳��Ի���Doc*>(m_pDocument); }
#endif

