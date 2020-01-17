#ifndef STATISTCIS_H 
#define STATISTCIS_H

#include "Account.h"

class Statistics {
public: 
	int sum(Account * pArray, int size);        // °èÁÂ ÀÜ°í ÃÑÇÕ 
	int average(Account * pArray, int size);   // °èÁÂ ÀÜ°í Æò±Õ 
	int max(Account * pArray, int size);        // °èÁÂ ÃÖ°í °ª 
};
#endif