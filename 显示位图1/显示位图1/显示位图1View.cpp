
// 显示位图1View.cpp : C显示位图1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "显示位图1.h"
#endif

#include "显示位图1Doc.h"
#include "显示位图1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C显示位图1View

IMPLEMENT_DYNCREATE(C显示位图1View, CView)

BEGIN_MESSAGE_MAP(C显示位图1View, CView)
END_MESSAGE_MAP()

// C显示位图1View 构造/析构

C显示位图1View::C显示位图1View()
{
	// TODO: 在此处添加构造代码
	
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

C显示位图1View::~C显示位图1View()
{
}

BOOL C显示位图1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C显示位图1View 绘制

void C显示位图1View::OnDraw(CDC* pDC)
{
	C显示位图1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);

	// TODO: 在此处为本机数据添加绘制代码
}


// C显示位图1View 诊断

#ifdef _DEBUG
void C显示位图1View::AssertValid() const
{
	CView::AssertValid();
}

void C显示位图1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C显示位图1Doc* C显示位图1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C显示位图1Doc)));
	return (C显示位图1Doc*)m_pDocument;
}
#endif //_DEBUG


// C显示位图1View 消息处理程序
