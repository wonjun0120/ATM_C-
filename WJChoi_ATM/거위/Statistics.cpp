#include <iostream>

using namespace std;

#include "Statistics.h"

//���� ���� �� �ݾ�
int Statistics::sum(Account * pArray, int size) {
	int sumBalance = 0;	//�� �ݾ�

	for (int i = 0; i < size; i++) {	//������� ����ŭ �ݺ�
		sumBalance += ((pArray + i)->getBalance());	//�� �ݾ׿� �ܾ׵��� ���ؼ� �� �ݾ����� ����
	}
	return sumBalance;	//����� ��ȯ
}

//���� ���� �ݾ��� ���
int Statistics::average(Account * pArray, int size) {
	int s = sum(pArray, size);	//���� ���� �� �ݾ� ���, ����
	return (s / size);	//������ ����� ���� ����� ���� ������ �� ���� ��ȯ
}

//���� ���� �ݾ��� �ְ� 
int Statistics::max(Account * pArray, int size) {
	int best = 0;	//�ְ�, �ʱ갪 =0

	for (int i = 0; i < size; i++) {	//���� ����ŭ �ݺ�
		if (best < (pArray + i)->getBalance()) {	//�ְ����� ����� �ݾ��� ���� ���� ���� �ݾ׺��� �������
			best = (pArray + i)->getBalance();	//�� ���� ���� ���� �ݾ����� �ְ� ����
		}
	}
	return best;	//�ְ� ��ȯ
}