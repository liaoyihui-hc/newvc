
// 视图显示退出对话框View.cpp : C视图显示退出对话框View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "视图显示退出对话框.h"
#endif

#include "视图显示退出对话框Doc.h"
#include "视图显示退出对话框View.h"
#include "diag.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C视图显示退出对话框View

IMPLEMENT_DYNCREATE(C视图显示退出对话框View, CView)

BEGIN_MESSAGE_MAP(C视图显示退出对话框View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C视图显示退出对话框View 构造/析构

C视图显示退出对话框View::C视图显示退出对话框View()
{
	// TODO: 在此处添加构造代码

}

C视图显示退出对话框View::~C视图显示退出对话框View()
{
}

BOOL C视图显示退出对话框View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C视图显示退出对话框View 绘制

void C视图显示退出对话框View::OnDraw(CDC* pDC)
{
	C视图显示退出对话框Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	diag dc;
	CString s;
	s = _T("对话框已退出");
	int result = dc.DoModal();
	if (result = IDOK)
	{
		pDC->TextOutW(20,20,s);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// C视图显示退出对话框View 打印

BOOL C视图显示退出对话框View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C视图显示退出对话框View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C视图显示退出对话框View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C视图显示退出对话框View 诊断

#ifdef _DEBUG
void C视图显示退出对话框View::AssertValid() const
{
	CView::AssertValid();
}

void C视图显示退出对话框View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C视图显示退出对话框Doc* C视图显示退出对话框View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C视图显示退出对话框Doc)));
	return (C视图显示退出对话框Doc*)m_pDocument;
}
#endif //_DEBUG


// C视图显示退出对话框View 消息处理程序
