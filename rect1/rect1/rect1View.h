
// rect1View.h : Crect1View 类的接口
//

#pragma once


class Crect1View : public CView
{
protected: // 仅从序列化创建
	Crect1View();
	DECLARE_DYNCREATE(Crect1View)

// 特性
public:
	Crect1Doc* GetDocument() const;
	CArray<CRect, CRect&> rect;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Crect1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // rect1View.cpp 中的调试版本
inline Crect1Doc* Crect1View::GetDocument() const
   { return reinterpret_cast<Crect1Doc*>(m_pDocument); }
#endif

