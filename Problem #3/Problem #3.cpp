#include<iostream>
#include<list>
#include<iterator>
using namespace std;
/*
	The prime factors of 13195 are 5, 7, 13 and 29.
	What is the largest prime factor of the number 600851475143 ?
*/
int main() {
	unsigned long long int inputNumber = 600851475143;
	
	list<int> primeFactors = list<int>();
	list<int>::iterator it;
	
	// Sieve algorithm for collecting prime numbers.
	primeFactors.push_back(2);
	for (int i = 3; i < inputNumber; i+=2) {
		bool flag = true;
		for (it = primeFactors.begin(); it != primeFactors.end(); ++it) {
			if (i % *it == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			primeFactors.push_back(i);
		}
	}
	cout << "Prime numbers collected now searching for largest prime factor..." << endl;
	unsigned long long int largestPrimeFactor;
	for (it = primeFactors.begin(); it != primeFactors.end(); it++) {
		if (inputNumber % *it == 0) {
			largestPrimeFactor = *it;
		}
	}
	cout << largestPrimeFactor << endl;
	
	
//	int i = 0;
//	for (it = primeFactors.begin(); it != primeFactors.end(); it++) {
//		cout << ++i << "==> "<< *it << endl;
//	}
	return 0;
}
