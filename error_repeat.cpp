// error_repeat.cpp: 实现文件
//

#include "pch.h"
#include "Compilers.h"
#include "error_repeat.h"
#include "afxdialogex.h"


// error_repeat 对话框

IMPLEMENT_DYNAMIC(error_repeat, CDialogEx)

error_repeat::error_repeat(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

error_repeat::~error_repeat()
{
}

void error_repeat::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(error_repeat, CDialogEx)
END_MESSAGE_MAP()


// error_repeat 消息处理程序


BOOL error_repeat::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*设置窗口大小*/
	CRect temprect(0, 0, 500, 380);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
