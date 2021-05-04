
// mfc-dialogDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfc-dialog.h"
#include "mfc-dialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CmfcdialogDlg 대화 상자



CmfcdialogDlg::CmfcdialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCDIALOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcdialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcdialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CmfcdialogDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_MOVEJ1, &CmfcdialogDlg::OnBnClickedButtonMovej1)
	ON_BN_CLICKED(IDC_BUTTON_MOVEJ2, &CmfcdialogDlg::OnBnClickedButtonMovej2)
	ON_BN_CLICKED(IDC_BUTTON_MOVEJ3, &CmfcdialogDlg::OnBnClickedButtonMovej3)
	ON_BN_CLICKED(IDC_BUTTON_SIMUL, &CmfcdialogDlg::OnBnClickedButtonSimul)
END_MESSAGE_MAP()


// CmfcdialogDlg 메시지 처리기

BOOL CmfcdialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	GetDlgItem(IDC_BUTTON_SIMUL)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_MOVEJ1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_MOVEJ2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_MOVEJ3)->EnableWindow(FALSE);
	SetDlgItemText(IDC_STATIC_TEXT_STATUS, L"상태");

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcdialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcdialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcdialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CmfcdialogDlg::OnBnClickedButtonConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (cobot_.ConnectToCB()) {
		GetDlgItem(IDC_BUTTON_SIMUL)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_MOVEJ1)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_MOVEJ2)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_MOVEJ3)->EnableWindow(TRUE);
		SetDlgItemText(IDC_STATIC_TEXT_STATUS, L"연결 완료");
	}
	else {
		GetDlgItem(IDC_BUTTON_SIMUL)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_MOVEJ1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_MOVEJ2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_MOVEJ3)->EnableWindow(FALSE);
		SetDlgItemText(IDC_STATIC_TEXT_STATUS, L"제어반 IP를 확인하세요");
	}

	
	
}


void CmfcdialogDlg::OnBnClickedButtonMovej1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	rb::Joint j1(90, -90, 90, 45, -45, 45);
	cobot_.MoveJ(j1, 0.5, 0.5);
	SetDlgItemText(IDC_STATIC_TEXT_STATUS, L"J1");
}


void CmfcdialogDlg::OnBnClickedButtonMovej2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	rb::Joint j2(45, 45, 45, 90, 0, -90);
	cobot_.MoveJ(j2, 0.5, 0.5);
	SetDlgItemText(IDC_STATIC_TEXT_STATUS, L"J2");
}


void CmfcdialogDlg::OnBnClickedButtonMovej3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	rb::Joint j1(90, -90, 90, 45, -45, 45);
	rb::Joint j2(45, 45, 45, 90, 0, -90);
	rb::Joint j3 = j1 + j2;
	cobot_.MoveJ(j3, 0.5, 0.5);
	SetDlgItemText(IDC_STATIC_TEXT_STATUS, L"J3");
}



void CmfcdialogDlg::OnBnClickedButtonSimul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	cobot_.SetProgramMode(rb::PG_MODE::SIMULATION);
	SetDlgItemText(IDC_STATIC_TEXT_STATUS, L"시뮬레이션 모드");
}
