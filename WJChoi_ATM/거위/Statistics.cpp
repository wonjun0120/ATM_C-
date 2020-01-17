#include <iostream>

using namespace std;

#include "Statistics.h"

//고객이 넣은 총 금액
int Statistics::sum(Account * pArray, int size) {
	int sumBalance = 0;	//총 금액

	for (int i = 0; i < size; i++) {	//사용자의 수만큼 반복
		sumBalance += ((pArray + i)->getBalance());	//총 금액에 잔액들을 더해서 총 금액으로 저장
	}
	return sumBalance;	//결과값 반환
}

//고객이 넣은 금액의 평균
int Statistics::average(Account * pArray, int size) {
	int s = sum(pArray, size);	//고객이 넣은 총 금액 계산, 저장
	return (s / size);	//위에서 계산한 값은 사람의 수로 나누고 그 값을 반환
}

//고객이 넣은 금액중 최고값 
int Statistics::max(Account * pArray, int size) {
	int best = 0;	//최고값, 초깃값 =0

	for (int i = 0; i < size; i++) {	//고객의 수만큼 반복
		if (best < (pArray + i)->getBalance()) {	//최고값으로 저장된 금액이 현재 고객이 넣은 금액보다 적은경우
			best = (pArray + i)->getBalance();	//그 현재 고객이 넣은 금액으로 최고값 갱신
		}
	}
	return best;	//최고값 반환
}