
// mfc-dialogDlg.h: 헤더 파일
//

#pragma once
#include "../rb-api/include/rb-world.h"

//debug
#pragma comment(lib, "../rb-api/x64/debug/rb-apid.lib")

// CmfcdialogDlg 대화 상자
class CmfcdialogDlg : public CDialogEx
{
// 생성입니다.
public:
	CmfcdialogDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCDIALOG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonSimul();
	afx_msg void OnBnClickedButtonMovej1();
	afx_msg void OnBnClickedButtonMovej2();
	afx_msg void OnBnClickedButtonMovej3();

private:
	rb::Cobot cobot_;

	
};
