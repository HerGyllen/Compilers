// error_no_path.cpp: 实现文件
//

#include "pch.h"
#include "Compilers.h"
#include "error_no_path.h"
#include "afxdialogex.h"


// error_no_path 对话框

IMPLEMENT_DYNAMIC(error_no_path, CDialogEx)

error_no_path::error_no_path(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	
}

error_no_path::~error_no_path()
{
}

void error_no_path::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(error_no_path, CDialogEx)
END_MESSAGE_MAP()


// error_no_path 消息处理程序


BOOL error_no_path::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*设置窗口大小*/
	CRect temprect(0, 0, 500, 380);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
