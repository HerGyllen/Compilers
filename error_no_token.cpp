// error_no_token.cpp: 实现文件
//

#include "pch.h"
#include "Compilers.h"
#include "error_no_token.h"
#include "afxdialogex.h"


// error_no_token 对话框

IMPLEMENT_DYNAMIC(error_no_token, CDialogEx)

error_no_token::error_no_token(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

error_no_token::~error_no_token()
{
}

void error_no_token::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(error_no_token, CDialogEx)
END_MESSAGE_MAP()


// error_no_token 消息处理程序


BOOL error_no_token::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*设置窗口大小*/
	CRect temprect(0, 0, 500, 380);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
