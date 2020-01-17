#include <iostream>
using namespace std;

#include "Account.h"

//������
Account::Account() {
	nID = BASE_ACCOUNT_ID;	//���¹�ȣ ���� ��ȣ(���)�� �ʱ�ȭ

}

//��������
bool Account::authenticate(int id, string passwd) {
	if (nID == id && strPassword == passwd) {	//���¹�ȣ�� ��й�ȣ�� ���� ��
		return AUTHENTIFICATION_SUCCESS;	//���� ���� ����
	}
	else {
		//return AUTHENTIFICATION_FAIL;	//�������� ����
		return 0;
	}
}

//���� ����
void Account::create(int id, int money, string name, string password) {
	nID = BASE_ACCOUNT_ID + id -1;	//�����Ǵ� ���¹�ȣ�� ���۹�ȣ + ���� ��-1
	nBalance = money;	//�Է��� ������ �ʱ�ȭ
	strAccountName = name;	//�Է��� �̸����� �ʱ�ȭ
	strPassword = password;	//�Է��� ��й�ȣ�� �ʱ�ȭ
}

int Account::check(int id, string password) {
	bool check = authenticate(id, password);	//���������� �������

	if (check == AUTHENTIFICATION_SUCCESS) {	//�������� ������ ����
		return AUTHENTIFICATION_SUCCESS;
	}

	else if(check ==AUTHENTIFICATION_FAIL) { //�������� ���н� ����
		cout << " �������� ����" << endl;
		return 0; 
	}
}

//����
int Account::deposite(int id, string password, int money) {
	nBalance += money;	//���� ����ִ� �ݾ׿� ����
	return nBalance;
}

//���
int Account::widraw(int id, string password, int money) {
	nBalance -= money;	//���� ����ִ� �ݾ׿��� ����
	return nBalance;
}
