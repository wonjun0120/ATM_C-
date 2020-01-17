#ifndef ACCOUNT_H 
#define ACCOUNT_H

using std::string;

#define AUTHENTIFICATION_FAIL -1   // ���� ���� ���� 
#define AUTHENTIFICATION_SUCCESS 1   // ���� ���� ���� 
#define BASE_ACCOUNT_ID 100     // ���¹�ȣ�� 100�� ����

class Account {
private: 
	int nID;      // ���� ��ȣ 
	int nBalance; // �ܰ� 
	string strAccountName;      // �� �� 
	string strPassword;         // ���� ��й�ȣ
private:
	inline bool authenticate(int id, string passwd);     //  ���� ���� : true(1), ���� ���� : false(0)
public:
	Account(); 
	void create(int id, int money, string name, string password);   // ���� ���� 
	int check(int id, string password);      //  return �� : nBalance (�ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
	int getAcctID() { return nID; }            // ���� ��ȣ �о����
	int deposite(int id, string password, int money);	//�Ա�
	int widraw(int id, string password, int money);	//���
	int getBalance() { return nBalance; }	//�ܱ� ��ȯ
	string getAccountName() { return strAccountName; }	//������ �̸� ��ȯ
	
};
#endif
