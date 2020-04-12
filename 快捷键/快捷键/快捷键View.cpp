
// 快捷键View.cpp : C快捷键View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "快捷键.h"
#endif

#include "快捷键Doc.h"
#include "快捷键View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C快捷键View

IMPLEMENT_DYNCREATE(C快捷键View, CView)

BEGIN_MESSAGE_MAP(C快捷键View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C快捷键View 构造/析构

C快捷键View::C快捷键View()
{
	// TODO: 在此处添加构造代码

}

C快捷键View::~C快捷键View()
{
}

BOOL C快捷键View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C快捷键View 绘制

void C快捷键View::OnDraw(CDC* pDC)
{
	C快捷键Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->rc);
	// TODO: 在此处为本机数据添加绘制代码
}


// C快捷键View 打印

BOOL C快捷键View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C快捷键View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C快捷键View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C快捷键View 诊断

#ifdef _DEBUG
void C快捷键View::AssertValid() const
{
	CView::AssertValid();
}

void C快捷键View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C快捷键Doc* C快捷键View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C快捷键Doc)));
	return (C快捷键Doc*)m_pDocument;
}
#endif //_DEBUG


// C快捷键View 消息处理程序


void C快捷键View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	C快捷键Doc* pDoc = GetDocument();
	switch (nChar)
	{
	case VK_LEFT:
	{pDoc->rc.left += 10;
	pDoc->rc.right += 10;

	}
	break;
	case VK_RIGHT:
	{
		pDoc->rc.left -= 10;
		pDoc->rc.right -= 10;
	}
	break;
	case VK_UP:
	{
		pDoc->rc.top += 10;
		pDoc->rc.bottom += 10;
	}
	break;
	case VK_DOWN:
	{
		pDoc->rc.top -= 10;
		pDoc->rc.bottom -= 10;
	}
	break;
	case VK_HOME:
	{
		pDoc->rc.top -= 10;
		pDoc->rc.left -= 10;
	}

	break;
	case VK_END:
	{
		pDoc->rc.top += 10;
		pDoc->rc.left += 10;
	}

	break;
	default:
		break;
	}
	InvalidateRect(NULL, true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void C快捷键View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	C快捷键Doc* pDoc = GetDocument();
	pDoc->rc.left = 30;
	pDoc->rc.right = 80;
	pDoc->rc.top = 30;
	pDoc->rc.bottom = 80;
	
	InvalidateRect(NULL, true);
	CView::OnLButtonDown(nFlags, point);
}
