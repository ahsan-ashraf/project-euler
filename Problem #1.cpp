#include<iostream>
using namespace std;
/*
	Problem #1.
	Statement:
	If we list all the natural numbers below 10 that are multiples of 
	3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23. 
	Find the sum of all the multiples of 3 or 5 below 1000.
	
	Solution:
	
	As we know: 1 + 2 + 3 + ... + n = n(n+1)/2		.....1
	
	3 + 9 + 12 + ... + 3n
	3(1 + 2 + 3 + ... + n)							using eq 1
	3[n(n+1)/2]										.....2
	
	5 + 10 + 15 + ... + 5n
	5(1 + 2 + 3 + ... + n)							using eq 1
	5[n(n+1)/2]										.....3
	
	As 3 X 5 = 15
	Multiples of 15 are common in multiples of 3 and 5.
	
	15 + 30 + 45 + ... + 15n
	15(1 + 2 + 3 + ... + n)							using eq 1
	15[n(n+1)/2]									.....4
	
	For sum of all the multiples of 3 or 5 below 1000:
	A	=	3[n(n+1)/2]		put n = 333 as 3 * 333 = 999 < 1000.
	B	=	5[n(n+1)/2]		put n = 199 as 5 * 199 = 995 < 1000.
	C	=	15[n(n+1)/2]	put n = 66  as 15 * 66 = 990 < 1000.
	
	Result = A + B - C
*/
int MathematicalApproach() {
	return (
		+3 * (333 * (333 + 1) / 2)
	 	+5 * (199 * (199 + 1) / 2)
  	  	-15 * (66 * (66 + 1) / 2)
  	);
}
int BruteForceApproach() {
	int sum = 0;
	for (int i = 1; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	return sum;
}
int main() {
	cout << "1. Mathematical Approach: " << MathematicalApproach() << endl;
	cout << "2. Brute Force Approach:  " << BruteForceApproach() << endl;
	return 0;
}
