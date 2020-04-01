
// 显示位图1View.h : C显示位图1View 类的接口
//

#pragma once


class C显示位图1View : public CView
{
protected: // 仅从序列化创建
	C显示位图1View();
	DECLARE_DYNCREATE(C显示位图1View)

// 特性
public:
	C显示位图1Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C显示位图1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 显示位图1View.cpp 中的调试版本
inline C显示位图1Doc* C显示位图1View::GetDocument() const
   { return reinterpret_cast<C显示位图1Doc*>(m_pDocument); }
#endif

