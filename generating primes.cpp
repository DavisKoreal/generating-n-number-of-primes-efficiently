
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

std::vector <long double> primes;

void getprimes(int& maximumnumber) {
	std::string last = "odd";
	for (int i = 2; i < maximumnumber; i++) {
		if (last == "odd") {
			long double prime = 1 + pow(i, 2);
			primes.push_back(prime);
			last = "even";
		}
		else {
			long double prime = 4 + pow(i, 2);
			primes.push_back(prime);
			last = "odd";
		}
	}
	std::cout << "We have managed to collect " << primes.size() << " primes. " << std::endl;
	std::cout << "We are now writing to an external file " << std::endl;
	std::fstream outfile;
	outfile.open("PRIMES.txt", std::fstream::out | std::fstream::app);
	for (int i = 0; i < primes.size(); i++) {
		outfile << std::setprecision(70) << primes[i] << std::endl;
	}
	std::cout << "We are now done outputting primes to the output file " << std::endl;
}


int main() {
	std::cout << "What is the number of primes that you want to get? " << std::endl;
	int numberofprimes;
	std::cin >> numberofprimes;
	std::cout << "We are going to put the number of primes " << std::endl;
	long double firstprime = 2;
	primes.push_back(firstprime);
	getprimes(numberofprimes);
}