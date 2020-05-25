#include "stdafx.h"

// CompilersDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Compilers.h"
#include "CompilersDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "abouting.h"
#include "error_no_path.h"
#include "error_no_token.h"
#include "error_wrong_path.h"
#include "error_repeat.h"
#include "error_wrong_token.h"


#include <iostream>
#include "TokenScanner.h"
#include "Parser.h"
#include <vector>


static string 词法类型[100] = { "ENDFILE", "ERRORR" ,
"PROGRAM", "PROCEDURE", "TYPE", "VAR", "IF",
"THEN", "ELSE"," FI", "WHILE", "DO",
"ENDWH", "BEGIN", "END", "READ", "WRITE",
"ARRAY", "OF", "RECORD", "RETURN",
"INTEGER", "CHARR",
/* 多字符单词符号 */
"ID", "INTC","CHARC",
/*特殊符号 */
"ASSIGN", "EQ", "LT", "PLUS", "MINUS",
"TIMES", "OVER"," LPAREN", "RPAREN", "DOT",
"COLON", "SEMI","COMMA"," LMIDPAREN", "RMIDPAREN",
"UNDERANGE"
};



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


/*访问路径，初始设为0*/
CString path = '\0';
/*是否产生token序列，是否产生grammer序列，路径是否发生变化*/
bool token = false, grammer = false, no_change = true;
/*每一次产生的词法分析是否有错误*/
bool TOKEN = true;



// CCompilersDlg 对话框



CCompilersDlg::CCompilersDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMPILERS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCompilersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, ID_PATH);
}

BEGIN_MESSAGE_MAP(CCompilersDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCompilersDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CCompilersDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCompilersDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCompilersDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT3, &CCompilersDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &CCompilersDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON4, &CCompilersDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCompilersDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CCompilersDlg 消息处理程序

BOOL CCompilersDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	/*初始化窗口的大小*/
	CRect temprect(0, 0, 1020, 760);

	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCompilersDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCompilersDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCompilersDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*更改路径*/
void regularization(CString* path) {
	/*当出现第一个\时，赋值为1*/
	int flag = 0;
	/*判定读取两个 \\ key->false*/
	bool key = true;
	for (int i = 0; i < (*path).GetLength(); i++) {
		if ((!flag) && (*path)[i] == '\\') {
			/*出现第一个 \*/
			flag = 1;
		}
		else if (flag == 1 && (*path)[i] == '\\') {
			/*如果任意的一个 \\ 出现，不要修改路径，直接跳出*/
			key = FALSE;
			break;
		}
		else if (flag == 1 && (*path)[i] != '\\') {
			/*只出现一个 \ 恢复初始状态*/
			flag = 0;
		}
	}
	if ((!flag)&&key) {
		/*\ 替换成 \\*/
		(*path).Replace('\\', '\\\\');
	}
}




/*浏览*/
void CCompilersDlg::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE, "Text Files", "*.txt", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"text Files(*.txt)|All Files(*.*)|*.*||");
	if (dlg.DoModal() != IDOK)
	{
		return;
	}
	/*赋值完整路径。*/
	path = dlg.GetPathName();
	GetDlgItem(IDC_EDIT1)->SetWindowText(path);
	/*词法 语法 分析框清空*/
	GetDlgItem(IDC_EDIT2)->SetWindowText(TEXT(""));
	GetDlgItem(IDC_EDIT3)->SetWindowText(TEXT(""));

	no_change = false;
	token = false;
	grammer = false;
}


/*文本框的修改*/
void CCompilersDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	ID_PATH.GetWindowText(path);

	/*文本框只要改变no_change就为false*/
	no_change = FALSE;
}

vector<Token> Tokenlist;						//存储Token序列


void CCompilersDlg::OnBnClickedButton2()
{
	/*词法 语法 分析框清空*/


	if (path == "") {
		/*请先选择源文件*/
		error_no_path Dlg;
		Dlg.DoModal();
	}
	else {
		regularization(&path);
		/*
			根据路径打印token，成功返回true，失败返回false；
			输入token建立成功与否的返回bool值
		*/
		FILE* fp;
		if (fopen_s(&fp,path, "r") == 0 ) {
			/*如果成功*/
			token = TRUE;
			TOKEN = TRUE;
			if (no_change) {
				/*请执行下一步*/
				error_repeat Dlg3;
				Dlg3.DoModal();
			}
			else {
				/*print函数
				更改TOKEN的值，产生正确与否的词法分析序列，用于判断语法分析能够进行
				该路径已经读入，将no_change变为true
				*/
				TokenScanner* TScanner = new TokenScanner();	// 词法分析部分的Scanner
				Tokenlist.clear();					//新一轮分析清空存储Token序列
				Token* newtoken = NULL;
				while (!feof(fp))
				{
					newtoken = TScanner->Scan(fp);
					Tokenlist.push_back(*newtoken);
					newtoken = NULL;
				}
				fclose(fp);
				/*打印新的token序列之前，先清空两个文本框*/
				GetDlgItem(IDC_EDIT2)->SetWindowText("");
				GetDlgItem(IDC_EDIT3)->SetWindowText("");

				CString cstr;
				string str = "";
				if (!TScanner->Error) {
					/*Error为false，词法分析正确*/
					str.append("词法分析无错：Token序列如下：\r\n");
				}
				else {
					/*词法分析错误*/
					str.append("词法分析有错，以ERRORR显示的为错误的Token：\r\n");
					TOKEN = FALSE;
				}
				for (Token t : Tokenlist) {
					str.append("行数: ");
					str.append(to_string(t.line));
					str.append("     ");
					str.append(to_string(t.type));
					str.append("     ");
					if (t.type == ID) {
						/*换行输出 \r\n*/
						str.append(t.content);
						str.append("\r\n");
						cstr = str.c_str();
						GetDlgItem(IDC_EDIT3)->SetWindowTextA(cstr);
					}
					else {

						str.append(词法类型[t.type]);
						str.append("\r\n");
						cstr = str.c_str();
						GetDlgItem(IDC_EDIT3)->SetWindowTextA(cstr);
					}
				}

				token = TRUE;
				no_change = true;
			}
		}
		else {
			/*路径错误 打开失败*/
			error_wrong_path Dlg2;
			Dlg2.DoModal();
		}

	}
}


void CCompilersDlg::OnBnClickedButton3()
{
	if (!token) {
		/*失败不允许进入语法分析
		请先执行词法分析
		*/
		error_no_token Dlg1;
		Dlg1.DoModal();
	}
	else {
		if (TOKEN) {
			/*词法分析正确，正确入口*/
			if (!grammer) {
				/*没有进行过语法分析，正确入口*/
				/*print*/
				/*语法分析成功，标志设为true*/
				Parser* parser = new Parser();
				string str = parser->Parse(Tokenlist);
				str += "语法树表示如下：\r\n";
				str += parser->PrintTree(parser->root);
				GetDlgItem(IDC_EDIT2)->SetWindowTextA(str.c_str());
				grammer = TRUE;
			}
			else {
				/*进行过语法分析
				进行下一步
				*/
				error_repeat Dlg2;
				Dlg2.DoModal();
			}
		}
		else {
			error_wrong_token Dlg3;
			Dlg3.DoModal();
		}

	}
}


void CCompilersDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCompilersDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCompilersDlg::OnBnClickedButton4()
{
	abouting Dlg;
	Dlg.DoModal();
}


void CCompilersDlg::OnBnClickedButton5()
{
	CDialogEx::OnCancel();
}


BOOL CCompilersDlg::PreTranslateMessage(MSG* pMsg)
{
	//重写虚函数PreTranslateMessage() 用于回车键确认
	
	// 屏蔽回车以及exs放着错误的退出
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		// 如果消息是键盘按下事件，且是Esc键，返回
		return TRUE;
	}
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		// 如果消息是键盘按下事件，且是Entert键，返回
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
