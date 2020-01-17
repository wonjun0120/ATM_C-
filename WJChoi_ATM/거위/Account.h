#ifndef ACCOUNT_H 
#define ACCOUNT_H

using std::string;

#define AUTHENTIFICATION_FAIL -1   // 계정 인증 실패 
#define AUTHENTIFICATION_SUCCESS 1   // 계정 인증 성공 
#define BASE_ACCOUNT_ID 100     // 계좌번호는 100번 부터

class Account {
private: 
	int nID;      // 계좌 번호 
	int nBalance; // 잔고 
	string strAccountName;      // 고객 명 
	string strPassword;         // 계좌 비밀번호
private:
	inline bool authenticate(int id, string passwd);     //  인증 성공 : true(1), 인증 실패 : false(0)
public:
	Account(); 
	void create(int id, int money, string name, string password);   // 계좌 개설 
	int check(int id, string password);      //  return 값 : nBalance (잔고) or 인증 실패(AUTHENTIFICATION_FAIL)
	int getAcctID() { return nID; }            // 계좌 번호 읽어오기
	int deposite(int id, string password, int money);	//입금
	int widraw(int id, string password, int money);	//출금
	int getBalance() { return nBalance; }	//잔금 반환
	string getAccountName() { return strAccountName; }	//예금주 이름 반환
	
};
#endif
