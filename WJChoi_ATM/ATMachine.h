#ifndef ATMACHINE_H 
#define ATMACHINE_H

using std::string;

#include "Account.h"
#include "Statistics.h"

#define NEGATIVE_ATM_BALANCE -10 // ATM �ܾ� ����
class ATMachine {
private: 
	Account * pAcctArray; // ���� ������ ������ �迭������ 
	int nMachineBalance; // ATM �ܰ� 
	int nMaxAccountNum; // ���� ������ ������ �迭ũ�� 
	int nCurrentAccountNum; // ������ ������ �� 
	string strManagerPassword; // ������ ��й�ȣ
	bool isManager(string password);  // �Ŵ��� ��ȣ Ȯ�� 
	void displayReport(); // ��� ȭ�� ó�� 

public:
	ATMachine(); 
	~ATMachine();
	
	void displayMenu(); // ATM ��� ���� ȭ�� 
						// ���� �迭ũ��, ATM �ܰ�, ������ ��ȣ �ʱ�ȭ 
	void initialize(int nSize, int nBalance, string password); 
	void createAccount(); // ���� ���� 
	void checkMoney(); // ���� ��ȸ
	void depositMoney();	//���� �Ա�
	void widrawMoney(); // ���� ���
	void managerMode();                 // �� ����
};
#endif
