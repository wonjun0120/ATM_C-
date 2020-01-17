#ifndef ATMACHINE_H 
#define ATMACHINE_H

using std::string;

#include "Account.h"
#include "Statistics.h"

#define NEGATIVE_ATM_BALANCE -10 // ATM 잔액 부족
class ATMachine {
private: 
	Account * pAcctArray; // 동적 생성된 고객계좌 배열포인터 
	int nMachineBalance; // ATM 잔고 
	int nMaxAccountNum; // 동적 생성된 고객계좌 배열크기 
	int nCurrentAccountNum; // 개설된 고객계좌 수 
	string strManagerPassword; // 관리자 비밀번호
	bool isManager(string password);  // 매니저 암호 확인 
	void displayReport(); // 통계 화면 처리 

public:
	ATMachine(); 
	~ATMachine();
	
	void displayMenu(); // ATM 기능 선택 화면 
						// 계좌 배열크기, ATM 잔고, 관리자 암호 초기화 
	void initialize(int nSize, int nBalance, string password); 
	void createAccount(); // 계좌 개설 
	void checkMoney(); // 계좌 조회
	void depositMoney();	//계좌 입금
	void widrawMoney(); // 계좌 출금
	void managerMode();                 // 고객 관리
};
#endif
