// abouting.cpp: 实现文件
//

#include "pch.h"
#include "Compilers.h"
#include "abouting.h"
#include "afxdialogex.h"


// abouting 对话框

IMPLEMENT_DYNAMIC(abouting, CDialogEx)

abouting::abouting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

abouting::~abouting()
{
}

void abouting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(abouting, CDialogEx)
END_MESSAGE_MAP()


// abouting 消息处理程序


BOOL abouting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*设置窗口大小*/
	CRect temprect(0, 0, 500, 380);
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
