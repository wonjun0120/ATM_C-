//ATM 기계에 관한 내용

#include <iostream>
#include <string>
using namespace std;

#include "ATMachine.h"	//사용자 지정 헤더파일 
#define MAX_STRING_SIZE 100	//문자열 최대 

ATMachine::ATMachine() {	//생성자 실행, 멤버변수 초기화
	nMachineBalance = 0;	
	nMaxAccountNum = 0;
	nCurrentAccountNum = 0;
	strManagerPassword = "admin";
}

void ATMachine::displayMenu() {	//화면에 메뉴 출력,기능선택 화면
	cout << '\n';
	cout << "--------------------------" << endl;
	cout << "-        KPU bank        -" << endl;
	cout << "--------------------------" << endl;
	cout << " 1. 계좌 개설" << endl;
	cout << " 2. 계좌 조회" << endl;
	cout << " 3. 계좌 입금" << endl;
	cout << " 4. 계좌 출금" << endl;
	cout << " 5. 고객 관리" << endl;
	cout << " 9. 업무 종료" << endl;
	cout << "\n\n";
}

// 계좌 배열크기, ATM 잔고, 관리자 암호 초기화 
void ATMachine::initialize(int nSize, int nBalance, string password) {
	pAcctArray = new Account[nSize];	//고객의 수만큼 객체배열 동적할당
	nMachineBalance = nBalance;	//입력받은 수만큼 ATM 잔고 초기화
	strManagerPassword = password;	//관리자 암호 초기화
}

void ATMachine::createAccount() {	//개설
		// 고객정보 Account 배열 포인터 pAcctArray
	string name;	//입력받은 고객 이름
	string pwd;	//입력받은 고객 비번
	Account* p = pAcctArray;	//포인터 객체, 사용자의 정보를 저장 

	cout << " ------ 개설 ------" << endl;
	getchar();
	cout << " 이름 입력: ";	//이름 입력
	getline(cin, name, '\n');
	
	//getchar();
	cout << " 암호 입력: ";	//암호 입력
	getline(cin, pwd, '\n');

	nCurrentAccountNum++;	//개설된 고객계좌의 수 1명 증가
	int index = nCurrentAccountNum - 1;	//현재 고객의 객체 배열 인덱스 번호

	//계좌 생성
	(p+index)->create(nCurrentAccountNum, 0, name, pwd);
	int id = (p+index)->getAcctID();
	cout << name << "님 " << id << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다" << endl;
	//delete [] p;
}
void ATMachine::checkMoney() {	//계좌 조회
	int id;	//계좌번호
	int index;	//고객의 인덱스 번호
	string pwd;	//비밀번호
	bool check;	//본인 인증 결과 

	//계좌번호 입력
	cout << " 계좌번호 입력: ";
	cin >> id;
	
	getchar();	//공백문자 제거

	//비밀번호 입력
	cout << " 비밀번호 입력: ";
	getline(cin, pwd, '\n');

	//입력한 계좌의 유무 검색
	//계좌번호는 계좌번호 시작번호부터 시작 하며
	//(현재 생성된 사람의 수 + 기본 계좌번호)까지 생성 되었다.
	//계좌번호는 생성한 사람이 1명 이상일 때 계좌번호가 존재한다.
	if (id >= BASE_ACCOUNT_ID && id <= (nCurrentAccountNum + BASE_ACCOUNT_ID) && nCurrentAccountNum > 0) {
		//인덱스 번호는 입력받은 계좌번호에서 계좌번호 시작 번호를 뺀 값과 같다
		index = id - BASE_ACCOUNT_ID;
		check = (pAcctArray + index)->check(id, pwd);	//입력받은 정보가 일치한지 검사한다, 그 값을 저장한다.

		if (check == AUTHENTIFICATION_SUCCESS) {	//본인인증 성공시 실행
			cout << " 현재 잔액 :" << (pAcctArray + index)->getBalance() << endl;
		}
		else {	//본인인증 실패시 실행
			cout << " 확인 취소" << endl;
			return;
		}
	}
	else	//위 조건에 해당하지 않는 경우 => 저장되지 않은 계좌번호
	{
		cout << " 입력하신 계좌는 없는 계좌번호입니다." << endl;
	}


}

//예금
void ATMachine::depositMoney() {
	int id;	//계좌번호
	string pwd;	//비밀번호
	int money;	//돈
	int index;	//인덱스 번호
	bool check;	//본인 확인 참 거짓
	int balance;	//잔액

	//계좌번호 입력
	getchar();	//공백문자
	cout << " ------ 입금 ------" << endl;
	cout << " 계좌번호 입력: ";
	cin >> id;

	//비밀번호 입력
	getchar();	//공백문자
	cout << " 비밀번호 입력: ";
	getline(cin, pwd, '\n');

	//입금할 금액 입력
	cout << " 입금액   입력: ";
	cin >> money;
	
	//인덱스 번호 계산
	index = id - BASE_ACCOUNT_ID;
	check = (pAcctArray + index)->check(id, pwd);	//본인 정보 확인

	if (check == AUTHENTIFICATION_SUCCESS) {	//참일시 실행
		balance = (pAcctArray + index)->deposite(id, pwd, money);	//잔액 = 예금후 변동된 금액
		nMachineBalance += balance;	//ATM기에 남아있는 금액 
		//잔액표시, 입금이 완료되었다고 표시
		cout << " 현재 잔액 :" << (pAcctArray + index)->getBalance() << endl;
		cout << " 입금 완료" << endl;
	}
	else {	//본인확인시 입력된 정보가 거짓일 시 실행
		cout << " 입금 취소" << endl;	//입금이 취소되었다고 전달 후 종료
		return;
	}
}

//출금
void ATMachine::widrawMoney() { 
	int id;	//계좌번호
	string pwd;	//비밀번호
	int money;	//돈
	int index;	//인덱스 번호
	bool check;	//본인확인 참 거짓
	int balance;	//잔액
	
	//계좌번호 입력
	cout << " ------ 출금 ------" << endl;
	cout << " 계좌번호 입력: ";
	cin >> id;

	//비밀번호 입력
	getchar();	//공백문자
	cout << " 비밀번호 입력: ";
	getline(cin, pwd, '\n');

	//출금할 금액 입력
	cout << " 출금액   입력: ";
	cin >> money;

	//인덱스 번호 계산
	index = id - BASE_ACCOUNT_ID;
	check = (pAcctArray + index)->check(id, pwd);	//입력한 정보가 맞는지 확인

	if (money > (pAcctArray + index)->getBalance()) {
		cout << " 잔액이 부족합니다.";
		return;
	}

	else if (check == AUTHENTIFICATION_SUCCESS) {	//정보가 참일 시 실행
		balance = (pAcctArray + index)->widraw(id, pwd, money);	//잔액 = 출금하고 변동된 금액
		nMachineBalance -= balance;	//ATM기에 남은 금액
		//현재 잔액과 출금 완료되었다는 정보를 출력
		cout << " 현재 잔액 :" << (pAcctArray + index)->getBalance() << endl;
		cout << " 출금 완료" << endl;
	}
	else {	//정보가 거짓일 시 실행
		cout << " 출금 취소" << endl;
		return;
	}
}

bool ATMachine::isManager(string password){ // 매니저 암호 확인 
	if ( strManagerPassword == password) {	//계좌번호와 비밀번호가 같을 때
		cout << " 관리자입니다.\n" << endl;
		return AUTHENTIFICATION_SUCCESS;	//계정 인증 성공시 실행
	}
	else {	//계정 인증 실패시 실행
		return 0;
	}
}

void ATMachine::displayReport() { // 통계 화면 처리 
	
	Statistics balance;	//잔액에 관한 정보
	nMaxAccountNum = nCurrentAccountNum ;	//배열의 길이 == 고객의 수

	int sum = balance.sum(pAcctArray, nMaxAccountNum);	//고객의 총 잔액
	int best = balance.max(pAcctArray, nMaxAccountNum);	//고객이 예금한 가장 큰 잔액
	int average = balance.average(pAcctArray, nMaxAccountNum);	//고객이 입금한 금액의 평균

	//위에서 계산한 결과값 출력
	cout << "ATM 현금 잔고:" << '\t' << nMachineBalance << endl;
	cout << "고객 잔고 통액:" << '\t' << sum << "(총" << nCurrentAccountNum << "명)" << endl;
	cout << "고객 잔고 평균:" << '\t' << average<< endl;
	cout << "고객 잔고 최고:" << '\t' <<  best << endl;
	cout << '\n';
	
	//계좌 현황 출력
	cout << "---------계좌현황---------" << endl;
	cout << "--------------------------" << endl;
	//인덱스 번호가 증가하면서 사람을 바꿈
	for (int i = 0; i < nCurrentAccountNum; i++) {	//고객의 수만큼 반복
		string name = (pAcctArray + i)->getAccountName();	//이름 저장
		int id = (pAcctArray + i)->getAcctID();	//계좌번호 저장
		int check = (pAcctArray + i)->getBalance();	//예금 금액
		cout << name << '\t' << id << "\t" << check << endl;	//결과 출력

	}
	cout << "\n\n";
}

void ATMachine::managerMode() {	//매니저 모드 실행
	string pwd;		//비밀번호
	//비밀번호 입력
	cout << " 관리자 비밀번호 입력: ";
	getchar();	//공백문자 처리
	getline(cin, pwd, '\n');
	//매니저 계정 확인
	bool check = isManager(pwd);

	if (nCurrentAccountNum == 0) {	//생성된 계좌가 없을 경우
		cout << " 생성된 계좌가 없습니다." << endl;
	}

	else if (check == AUTHENTIFICATION_SUCCESS) {	//참일 시 실행
		displayReport();	//매니저 전용 결과창 출력
	}
	else {	//거짓일 시 실행
		cout << " 관리자 암호가 틀렸습니다." << endl;
	}
}

ATMachine::~ATMachine() {	//소멸자
	delete[] pAcctArray;	//동적할당한 배열의 메모리 삭제
}