// error_wrong_token.cpp: 实现文件
//

#include "pch.h"
#include "Compilers.h"
#include "error_wrong_token.h"
#include "afxdialogex.h"


// error_wrong_token 对话框

IMPLEMENT_DYNAMIC(error_wrong_token, CDialogEx)

error_wrong_token::error_wrong_token(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

error_wrong_token::~error_wrong_token()
{
}

void error_wrong_token::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(error_wrong_token, CDialogEx)
END_MESSAGE_MAP()


// error_wrong_token 消息处理程序


BOOL error_wrong_token::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*设置窗口大小*/
	CRect temprect(0, 0, 500, 380);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
