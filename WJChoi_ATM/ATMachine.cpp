//ATM ��迡 ���� ����

#include <iostream>
#include <string>
using namespace std;

#include "ATMachine.h"	//����� ���� ������� 
#define MAX_STRING_SIZE 100	//���ڿ� �ִ� 

ATMachine::ATMachine() {	//������ ����, ������� �ʱ�ȭ
	nMachineBalance = 0;	
	nMaxAccountNum = 0;
	nCurrentAccountNum = 0;
	strManagerPassword = "admin";
}

void ATMachine::displayMenu() {	//ȭ�鿡 �޴� ���,��ɼ��� ȭ��
	cout << '\n';
	cout << "--------------------------" << endl;
	cout << "-        KPU bank        -" << endl;
	cout << "--------------------------" << endl;
	cout << " 1. ���� ����" << endl;
	cout << " 2. ���� ��ȸ" << endl;
	cout << " 3. ���� �Ա�" << endl;
	cout << " 4. ���� ���" << endl;
	cout << " 5. �� ����" << endl;
	cout << " 9. ���� ����" << endl;
	cout << "\n\n";
}

// ���� �迭ũ��, ATM �ܰ�, ������ ��ȣ �ʱ�ȭ 
void ATMachine::initialize(int nSize, int nBalance, string password) {
	pAcctArray = new Account[nSize];	//���� ����ŭ ��ü�迭 �����Ҵ�
	nMachineBalance = nBalance;	//�Է¹��� ����ŭ ATM �ܰ� �ʱ�ȭ
	strManagerPassword = password;	//������ ��ȣ �ʱ�ȭ
}

void ATMachine::createAccount() {	//����
		// ������ Account �迭 ������ pAcctArray
	string name;	//�Է¹��� �� �̸�
	string pwd;	//�Է¹��� �� ���
	Account* p = pAcctArray;	//������ ��ü, ������� ������ ���� 

	cout << " ------ ���� ------" << endl;
	getchar();
	cout << " �̸� �Է�: ";	//�̸� �Է�
	getline(cin, name, '\n');
	
	//getchar();
	cout << " ��ȣ �Է�: ";	//��ȣ �Է�
	getline(cin, pwd, '\n');

	nCurrentAccountNum++;	//������ �������� �� 1�� ����
	int index = nCurrentAccountNum - 1;	//���� ���� ��ü �迭 �ε��� ��ȣ

	//���� ����
	(p+index)->create(nCurrentAccountNum, 0, name, pwd);
	int id = (p+index)->getAcctID();
	cout << name << "�� " << id << "�� ���¹�ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�" << endl;
	//delete [] p;
}
void ATMachine::checkMoney() {	//���� ��ȸ
	int id;	//���¹�ȣ
	int index;	//���� �ε��� ��ȣ
	string pwd;	//��й�ȣ
	bool check;	//���� ���� ��� 

	//���¹�ȣ �Է�
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;
	
	getchar();	//���鹮�� ����

	//��й�ȣ �Է�
	cout << " ��й�ȣ �Է�: ";
	getline(cin, pwd, '\n');

	//�Է��� ������ ���� �˻�
	//���¹�ȣ�� ���¹�ȣ ���۹�ȣ���� ���� �ϸ�
	//(���� ������ ����� �� + �⺻ ���¹�ȣ)���� ���� �Ǿ���.
	//���¹�ȣ�� ������ ����� 1�� �̻��� �� ���¹�ȣ�� �����Ѵ�.
	if (id >= BASE_ACCOUNT_ID && id <= (nCurrentAccountNum + BASE_ACCOUNT_ID) && nCurrentAccountNum > 0) {
		//�ε��� ��ȣ�� �Է¹��� ���¹�ȣ���� ���¹�ȣ ���� ��ȣ�� �� ���� ����
		index = id - BASE_ACCOUNT_ID;
		check = (pAcctArray + index)->check(id, pwd);	//�Է¹��� ������ ��ġ���� �˻��Ѵ�, �� ���� �����Ѵ�.

		if (check == AUTHENTIFICATION_SUCCESS) {	//�������� ������ ����
			cout << " ���� �ܾ� :" << (pAcctArray + index)->getBalance() << endl;
		}
		else {	//�������� ���н� ����
			cout << " Ȯ�� ���" << endl;
			return;
		}
	}
	else	//�� ���ǿ� �ش����� �ʴ� ��� => ������� ���� ���¹�ȣ
	{
		cout << " �Է��Ͻ� ���´� ���� ���¹�ȣ�Դϴ�." << endl;
	}


}

//����
void ATMachine::depositMoney() {
	int id;	//���¹�ȣ
	string pwd;	//��й�ȣ
	int money;	//��
	int index;	//�ε��� ��ȣ
	bool check;	//���� Ȯ�� �� ����
	int balance;	//�ܾ�

	//���¹�ȣ �Է�
	getchar();	//���鹮��
	cout << " ------ �Ա� ------" << endl;
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;

	//��й�ȣ �Է�
	getchar();	//���鹮��
	cout << " ��й�ȣ �Է�: ";
	getline(cin, pwd, '\n');

	//�Ա��� �ݾ� �Է�
	cout << " �Աݾ�   �Է�: ";
	cin >> money;
	
	//�ε��� ��ȣ ���
	index = id - BASE_ACCOUNT_ID;
	check = (pAcctArray + index)->check(id, pwd);	//���� ���� Ȯ��

	if (check == AUTHENTIFICATION_SUCCESS) {	//���Ͻ� ����
		balance = (pAcctArray + index)->deposite(id, pwd, money);	//�ܾ� = ������ ������ �ݾ�
		nMachineBalance += balance;	//ATM�⿡ �����ִ� �ݾ� 
		//�ܾ�ǥ��, �Ա��� �Ϸ�Ǿ��ٰ� ǥ��
		cout << " ���� �ܾ� :" << (pAcctArray + index)->getBalance() << endl;
		cout << " �Ա� �Ϸ�" << endl;
	}
	else {	//����Ȯ�ν� �Էµ� ������ ������ �� ����
		cout << " �Ա� ���" << endl;	//�Ա��� ��ҵǾ��ٰ� ���� �� ����
		return;
	}
}

//���
void ATMachine::widrawMoney() { 
	int id;	//���¹�ȣ
	string pwd;	//��й�ȣ
	int money;	//��
	int index;	//�ε��� ��ȣ
	bool check;	//����Ȯ�� �� ����
	int balance;	//�ܾ�
	
	//���¹�ȣ �Է�
	cout << " ------ ��� ------" << endl;
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;

	//��й�ȣ �Է�
	getchar();	//���鹮��
	cout << " ��й�ȣ �Է�: ";
	getline(cin, pwd, '\n');

	//����� �ݾ� �Է�
	cout << " ��ݾ�   �Է�: ";
	cin >> money;

	//�ε��� ��ȣ ���
	index = id - BASE_ACCOUNT_ID;
	check = (pAcctArray + index)->check(id, pwd);	//�Է��� ������ �´��� Ȯ��

	if (money > (pAcctArray + index)->getBalance()) {
		cout << " �ܾ��� �����մϴ�.";
		return;
	}

	else if (check == AUTHENTIFICATION_SUCCESS) {	//������ ���� �� ����
		balance = (pAcctArray + index)->widraw(id, pwd, money);	//�ܾ� = ����ϰ� ������ �ݾ�
		nMachineBalance -= balance;	//ATM�⿡ ���� �ݾ�
		//���� �ܾװ� ��� �Ϸ�Ǿ��ٴ� ������ ���
		cout << " ���� �ܾ� :" << (pAcctArray + index)->getBalance() << endl;
		cout << " ��� �Ϸ�" << endl;
	}
	else {	//������ ������ �� ����
		cout << " ��� ���" << endl;
		return;
	}
}

bool ATMachine::isManager(string password){ // �Ŵ��� ��ȣ Ȯ�� 
	if ( strManagerPassword == password) {	//���¹�ȣ�� ��й�ȣ�� ���� ��
		cout << " �������Դϴ�.\n" << endl;
		return AUTHENTIFICATION_SUCCESS;	//���� ���� ������ ����
	}
	else {	//���� ���� ���н� ����
		return 0;
	}
}

void ATMachine::displayReport() { // ��� ȭ�� ó�� 
	
	Statistics balance;	//�ܾ׿� ���� ����
	nMaxAccountNum = nCurrentAccountNum ;	//�迭�� ���� == ���� ��

	int sum = balance.sum(pAcctArray, nMaxAccountNum);	//���� �� �ܾ�
	int best = balance.max(pAcctArray, nMaxAccountNum);	//���� ������ ���� ū �ܾ�
	int average = balance.average(pAcctArray, nMaxAccountNum);	//���� �Ա��� �ݾ��� ���

	//������ ����� ����� ���
	cout << "ATM ���� �ܰ�:" << '\t' << nMachineBalance << endl;
	cout << "�� �ܰ� ���:" << '\t' << sum << "(��" << nCurrentAccountNum << "��)" << endl;
	cout << "�� �ܰ� ���:" << '\t' << average<< endl;
	cout << "�� �ܰ� �ְ�:" << '\t' <<  best << endl;
	cout << '\n';
	
	//���� ��Ȳ ���
	cout << "---------������Ȳ---------" << endl;
	cout << "--------------------------" << endl;
	//�ε��� ��ȣ�� �����ϸ鼭 ����� �ٲ�
	for (int i = 0; i < nCurrentAccountNum; i++) {	//���� ����ŭ �ݺ�
		string name = (pAcctArray + i)->getAccountName();	//�̸� ����
		int id = (pAcctArray + i)->getAcctID();	//���¹�ȣ ����
		int check = (pAcctArray + i)->getBalance();	//���� �ݾ�
		cout << name << '\t' << id << "\t" << check << endl;	//��� ���

	}
	cout << "\n\n";
}

void ATMachine::managerMode() {	//�Ŵ��� ��� ����
	string pwd;		//��й�ȣ
	//��й�ȣ �Է�
	cout << " ������ ��й�ȣ �Է�: ";
	getchar();	//���鹮�� ó��
	getline(cin, pwd, '\n');
	//�Ŵ��� ���� Ȯ��
	bool check = isManager(pwd);

	if (nCurrentAccountNum == 0) {	//������ ���°� ���� ���
		cout << " ������ ���°� �����ϴ�." << endl;
	}

	else if (check == AUTHENTIFICATION_SUCCESS) {	//���� �� ����
		displayReport();	//�Ŵ��� ���� ���â ���
	}
	else {	//������ �� ����
		cout << " ������ ��ȣ�� Ʋ�Ƚ��ϴ�." << endl;
	}
}

ATMachine::~ATMachine() {	//�Ҹ���
	delete[] pAcctArray;	//�����Ҵ��� �迭�� �޸� ����
}