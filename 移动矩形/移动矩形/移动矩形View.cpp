
// 移动矩形View.cpp : C移动矩形View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "移动矩形.h"
#endif

#include "移动矩形Doc.h"
#include "移动矩形View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C移动矩形View

IMPLEMENT_DYNCREATE(C移动矩形View, CView)

BEGIN_MESSAGE_MAP(C移动矩形View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C移动矩形View 构造/析构
int a, b, c, d;
C移动矩形View::C移动矩形View()
{
	dc.left = 0;
	dc.top = 0;
	dc.right = 100;
	dc.bottom =100;
	// TODO: 在此处添加构造代码

}

C移动矩形View::~C移动矩形View()
{
}

BOOL C移动矩形View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C移动矩形View 绘制

void C移动矩形View::OnDraw(CDC* pDC)
{
	C移动矩形Doc* pDoc = GetDocument();
	pDC->Rectangle(dc);
	ASSERT_VALID(pDoc);
	if (!pDoc)
	
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C移动矩形View 打印

BOOL C移动矩形View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C移动矩形View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C移动矩形View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C移动矩形View 诊断

#ifdef _DEBUG
void C移动矩形View::AssertValid() const
{
	CView::AssertValid();
}

void C移动矩形View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C移动矩形Doc* C移动矩形View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C移动矩形Doc)));
	return (C移动矩形Doc*)m_pDocument;
}
#endif //_DEBUG


// C移动矩形View 消息处理程序


void C移动矩形View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	c = point.x;
	d = point.y;
	c = c - a;
	d = d - b;
	CView::OnMouseMove(nFlags, point);
}


void C移动矩形View::OnLButtonDown(UINT nFlags, CPoint point)
{

	CDC*pDC = GetDC();
	if (point.y > dc.top&&point.y<dc.bottom&&point.x>dc.left&&point.x < dc.right)
	{
		SetCapture();
		a = point.x;
		b = point.y;
	}
	else {
		MessageBox(_T("操作无效"));
	}
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}


void C移动矩形View::OnLButtonUp(UINT nFlags, CPoint point)
{
	CDC*pDC = GetDC();
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
		dc.left = dc.left+(c);
		dc.top = dc.top+(d);
		dc.right = dc.right + (c);
		dc.bottom = dc.bottom + (d );
		Invalidate();
		pDC->Rectangle(dc);
	
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}
