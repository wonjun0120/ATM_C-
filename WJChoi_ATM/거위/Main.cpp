#include <iostream>	
using namespace std;

#include "Account.h"	//계좌에 관한 정보
#include "ATMachine.h"	//ATM 기계
#include "Statistics.h"	//관리자

int main() {
	int select;		//사용자가 선택한 명령
	ATMachine atm;	//atm 객체
	// 고객수(100명), ATM 잔금 초기화, 관리자 암호 
	atm.initialize(100, 50000, "admin");
	
	while (1) {	//종료 명령이 나올 때 까지 반복
		atm.displayMenu();	//명령 메뉴창 출력
		
		//사용자가 사용하는 메뉴 입력받아 해당하는 내용 실행
		cout << "메뉴를 선택하세요 : ";		
		cin >> select; 
		cout << endl;
		
		//입력받은 명령에 해당하는 내용 실행
		switch (select) {
		case 1:		//계좌 개설
			atm.createAccount(); 
			break; 
		case 2:		//계좌 조회
			atm.checkMoney();
			break;
		case 3:		//계좌 입금
			atm.depositMoney();
			break;
		case 4:		//계좌 출금
			atm.widrawMoney();
			break;
		case 5:		//관리자 모드 실행
			atm.managerMode();
			break;
		case 9:		//업무 종료
			cout << "안녕히 가세요" << endl;
			return 0;
		default:	//메뉴에 출력된 번호와 맞지 않은 내용이 출력된 경우 실행
			cout << "번호 확인 후 다시 입력하세요." << endl;
		}
	} 
	return 0;
}