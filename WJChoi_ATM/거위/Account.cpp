#include <iostream>
using namespace std;

#include "Account.h"

//생성자
Account::Account() {
	nID = BASE_ACCOUNT_ID;	//계좌번호 시작 번호(상수)로 초기화

}

//본인인증
bool Account::authenticate(int id, string passwd) {
	if (nID == id && strPassword == passwd) {	//계좌번호와 비밀번호가 같을 때
		return AUTHENTIFICATION_SUCCESS;	//계정 인증 성공
	}
	else {
		//return AUTHENTIFICATION_FAIL;	//계정인증 실패
		return 0;
	}
}

//계좌 개설
void Account::create(int id, int money, string name, string password) {
	nID = BASE_ACCOUNT_ID + id -1;	//생성되는 계좌번호는 시작번호 + 고객의 수-1
	nBalance = money;	//입력한 돈으로 초기화
	strAccountName = name;	//입력한 이름으로 초기화
	strPassword = password;	//입력한 비밀번호로 초기화
}

int Account::check(int id, string password) {
	bool check = authenticate(id, password);	//본인인증후 결과저장

	if (check == AUTHENTIFICATION_SUCCESS) {	//본인인증 성공시 실행
		return AUTHENTIFICATION_SUCCESS;
	}

	else if(check ==AUTHENTIFICATION_FAIL) { //본인인증 실패시 실행
		cout << " 본인인증 실패" << endl;
		return 0; 
	}
}

//예금
int Account::deposite(int id, string password, int money) {
	nBalance += money;	//현재 들어있는 금액에 더함
	return nBalance;
}

//출금
int Account::widraw(int id, string password, int money) {
	nBalance -= money;	//현재 들어있는 금액에서 감함
	return nBalance;
}
