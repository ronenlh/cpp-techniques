#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "Primes.h"

using namespace std;

Primes::Primes(int n) : _prime_bools(n), _primes() {
	sift(n);
}

void Primes::sift(int max) {
	/*
	 * Input: an integer n>1
	 *
	 * Let A be an array of Boolean values, indexed by integers 2 to n,
	 * initially all set to true.
	 *
	 * for i = 2,3,4... not exceeding sqrt(n):
	 * 	if A[i] is true:
	 * 		for j=i^2, i^2+i, i^2+2i, i^2+3i... not exceeding n:
	 * 			A[j] := false.
	 *
	 * Output: all i such that A[i] is true.
	 */
		
	fill(_prime_bools.begin(),_prime_bools.end(),true);

	_prime_bools[0] = _prime_bools[1] = false;

	for(auto i=2;i<=sqrt(max);++i)
		for(auto j=0;pow(i,2)+j*i<=max;++j) {
			int k=pow(i,2)+j*i;
			_prime_bools[k]=false;
		}

	for(auto i=0;i!=max;++i)
		if (_prime_bools[i]) 
			_primes.push_back(i);
	}

vector<int> Primes::getPrimes() {
	return _primes;
}

vector<bool> Primes::getPrimeBools() {
	return _prime_bools;
}
/*
int main(int argn, char* argv[]) 
{
	int amount=0;
	
	cout << "Enter limit for primes to generate:";
	cin >> amount;
	Primes primes(amount);
	vector<int> pv = primes.getPrimes();
	for (int prime : pv)
		cout << prime << ", ";

	cout << endl;
	return 0;
}
*/
