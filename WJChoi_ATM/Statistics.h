#ifndef STATISTCIS_H 
#define STATISTCIS_H

#include "Account.h"

class Statistics {
public: 
	int sum(Account * pArray, int size);        // ���� �ܰ� ���� 
	int average(Account * pArray, int size);   // ���� �ܰ� ��� 
	int max(Account * pArray, int size);        // ���� �ְ� �� 
};
#endif