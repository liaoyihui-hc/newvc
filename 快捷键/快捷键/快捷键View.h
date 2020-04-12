
// 快捷键View.h : C快捷键View 类的接口
//

#pragma once


class C快捷键View : public CView
{
protected: // 仅从序列化创建
	C快捷键View();
	DECLARE_DYNCREATE(C快捷键View)

// 特性
public:
	C快捷键Doc* GetDocument() const;

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
	virtual ~C快捷键View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 快捷键View.cpp 中的调试版本
inline C快捷键Doc* C快捷键View::GetDocument() const
   { return reinterpret_cast<C快捷键Doc*>(m_pDocument); }
#endif

