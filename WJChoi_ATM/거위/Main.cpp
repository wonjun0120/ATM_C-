#include <iostream>	
using namespace std;

#include "Account.h"	//���¿� ���� ����
#include "ATMachine.h"	//ATM ���
#include "Statistics.h"	//������

int main() {
	int select;		//����ڰ� ������ ���
	ATMachine atm;	//atm ��ü
	// ����(100��), ATM �ܱ� �ʱ�ȭ, ������ ��ȣ 
	atm.initialize(100, 50000, "admin");
	
	while (1) {	//���� ����� ���� �� ���� �ݺ�
		atm.displayMenu();	//��� �޴�â ���
		
		//����ڰ� ����ϴ� �޴� �Է¹޾� �ش��ϴ� ���� ����
		cout << "�޴��� �����ϼ��� : ";		
		cin >> select; 
		cout << endl;
		
		//�Է¹��� ��ɿ� �ش��ϴ� ���� ����
		switch (select) {
		case 1:		//���� ����
			atm.createAccount(); 
			break; 
		case 2:		//���� ��ȸ
			atm.checkMoney();
			break;
		case 3:		//���� �Ա�
			atm.depositMoney();
			break;
		case 4:		//���� ���
			atm.widrawMoney();
			break;
		case 5:		//������ ��� ����
			atm.managerMode();
			break;
		case 9:		//���� ����
			cout << "�ȳ��� ������" << endl;
			return 0;
		default:	//�޴��� ��µ� ��ȣ�� ���� ���� ������ ��µ� ��� ����
			cout << "��ȣ Ȯ�� �� �ٽ� �Է��ϼ���." << endl;
		}
	} 
	return 0;
}