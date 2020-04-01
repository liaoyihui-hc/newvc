
// 点击菜单显示名字View.h : C点击菜单显示名字View 类的接口
//

#pragma once


class C点击菜单显示名字View : public CView
{
protected: // 仅从序列化创建
	C点击菜单显示名字View();
	DECLARE_DYNCREATE(C点击菜单显示名字View)

// 特性
public:
	C点击菜单显示名字Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C点击菜单显示名字View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
};

#ifndef _DEBUG  // 点击菜单显示名字View.cpp 中的调试版本
inline C点击菜单显示名字Doc* C点击菜单显示名字View::GetDocument() const
   { return reinterpret_cast<C点击菜单显示名字Doc*>(m_pDocument); }
#endif

