#include <vector>

using namespace std;
class Primes
{
private:
	vector<int> _primes;
	vector<bool> _prime_bools;

public:
	Primes(int);
	void sift(int);
	vector<int> getPrimes();
	vector<bool> getPrimeBools();
};

