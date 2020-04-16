#include<iostream>
#include<cmath>
#include<list>
using namespace std;

/*
	----------------------------------
	https://projecteuler.net/problem=5
	----------------------------------
	-----------------------------------------------------------------------------------------------------------
	Problem #5.
	Statement:
	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
	What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
	-----------------------------------------------------------------------------------------------------------
	Solution:
*/

list<unsigned int> GetPrimeNumbers(int upperLimit);
unsigned int GetPrimeAt(list<unsigned int> primeList, int index);
unsigned long long int EvenlyDivisibleNumberUpTo(int divisibleUpto);

int main() {
	cout << EvenlyDivisibleNumberUpTo(20) << endl;
	return 0;
}

unsigned long long int EvenlyDivisibleNumberUpTo(int divisibleUpto) {
	unsigned int result = 1;
	int i = 0;
	bool check = true;
	int limit = sqrt(divisibleUpto);
	int powers[divisibleUpto];
	list<unsigned int> prime = GetPrimeNumbers(divisibleUpto);
	while(GetPrimeAt(prime, i) < divisibleUpto) {
		powers[i] = 1;
		if (check) {
			if (GetPrimeAt(prime, i) <= limit) {
				powers[i] = floor(log(divisibleUpto) / log(GetPrimeAt(prime, i)));
			} else {
				check = false;
			}
		}
		result = result * pow(GetPrimeAt(prime, i), powers[i]);
		i = i + 1;
	}
	return (result);
}
unsigned int GetPrimeAt(list<unsigned int> primeList, int index) {
	list<unsigned int>::iterator it;
	it = primeList.begin();
	int i = 0;
	while(i < index) {
		++it;
		i++;
	}
	return(*it);
}
list<unsigned int> GetPrimeNumbers(int upperLimit) {
	
	list<unsigned int> primeNumbers = list<unsigned int>();
	list<unsigned int>::iterator it;
	
	// Sieve algorithm for collecting prime numbers.
	primeNumbers.push_back(2);
	for (int i = 3; i < upperLimit; i+=2) {
		bool flag = true;
		for (it = primeNumbers.begin(); it != primeNumbers.end(); ++it) {
			if (i % *it == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			primeNumbers.push_back(i);
		}
	}
	return (primeNumbers);
}

