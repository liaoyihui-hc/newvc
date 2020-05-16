
// 移动矩形View.h : C移动矩形View 类的接口
//

#pragma once


class C移动矩形View : public CView
{
protected: // 仅从序列化创建
	C移动矩形View();
	DECLARE_DYNCREATE(C移动矩形View)

// 特性
public:
	C移动矩形Doc* GetDocument() const;
	CRect dc;
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
	virtual ~C移动矩形View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 移动矩形View.cpp 中的调试版本
inline C移动矩形Doc* C移动矩形View::GetDocument() const
   { return reinterpret_cast<C移动矩形Doc*>(m_pDocument); }
#endif

