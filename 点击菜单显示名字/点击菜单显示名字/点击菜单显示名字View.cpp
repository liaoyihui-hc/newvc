
// 点击菜单显示名字View.cpp : C点击菜单显示名字View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "点击菜单显示名字.h"
#endif

#include "点击菜单显示名字Doc.h"
#include "点击菜单显示名字View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C点击菜单显示名字View

IMPLEMENT_DYNCREATE(C点击菜单显示名字View, CView)

BEGIN_MESSAGE_MAP(C点击菜单显示名字View, CView)
	ON_COMMAND(ID_32771, &C点击菜单显示名字View::On32771)
END_MESSAGE_MAP()

// C点击菜单显示名字View 构造/析构

C点击菜单显示名字View::C点击菜单显示名字View()
{
	// TODO: 在此处添加构造代码

}

C点击菜单显示名字View::~C点击菜单显示名字View()
{
}

BOOL C点击菜单显示名字View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C点击菜单显示名字View 绘制

void C点击菜单显示名字View::OnDraw(CDC* /*pDC*/)
{
	C点击菜单显示名字Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C点击菜单显示名字View 诊断

#ifdef _DEBUG
void C点击菜单显示名字View::AssertValid() const
{
	CView::AssertValid();
}

void C点击菜单显示名字View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C点击菜单显示名字Doc* C点击菜单显示名字View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C点击菜单显示名字Doc)));
	return (C点击菜单显示名字Doc*)m_pDocument;
}
#endif //_DEBUG


// C点击菜单显示名字View 消息处理程序


void C点击菜单显示名字View::On32771()
{
	CString  c;
	c = _T("巨魔奥利给");
	CClientDC dc(this);
	dc.TextOutW(200, 200, c);

	// TODO: 在此添加命令处理程序代码
}
