#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

static vector<int> getAllDivisors(int number)
{
	vector<int> divisors;

	for (int i = 1; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			divisors.push_back(i);

			if (i != number / i)
			{
				divisors.push_back(number / i);
			}
		}
	}

	sort(divisors.begin(), divisors.end());
	return divisors;
}

static vector<int> removeLastValue(vector<int>& list)
{
	if (!list.empty())
	{
		list.pop_back();
	}

	return list;
}


static int addAllDivisors(const vector<int>& divisors) {
	int sum = 0;
	for (size_t i = 0; i < divisors.size(); i++)
	{
		sum += divisors[i];
	}

	return sum;
}

static int sumOfDivisors(int n) {
	int sum = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			sum += i;
			if (i != n / i) {
				sum += n / i;
			}
		}
	}

	return sum;
}

static void printDivisors(const vector<int>& divisors) {
	for (size_t i = 0; i < divisors.size(); i++) {
		std::cout << divisors[i];
		if (i < divisors.size() - 1) {
			std::cout << ", ";
		}
	}
}

int main()
{
	std::cout << "Recherche des nombres parfaits.\n";
	vector<string> result;
	std::ostringstream sb;
	int finalNumber = 33550336;
	sb << "Liste des nombres parfaits entre 2 et " << finalNumber << " sont: ";
	for (int i = 2; i <= finalNumber; i++)
	{
		// int maxInt = 2 147 483 647;
		int currentNumber = i;
		vector<int> divisors = getAllDivisors(currentNumber);
		int calculatedSum = addAllDivisors(divisors) - currentNumber; // Subtract the number itself from the sum of divisors

		if (currentNumber == calculatedSum)
		{
			std::cout << i << " est un nombre parfait.";
			std::cout << " Ses diviseurs sont: ";
			printDivisors(removeLastValue(divisors));
			std::cout << " et la somme de ses diviseurs est: " << calculatedSum;
			std::cout << endl;
		}
		else
		{
			/*cout << i << " n'est pas un nombre parfait.";
			cout << " Ses diviseurs sont: ";
			printDivisors(removeLastValue(divisors));
			cout << " et la somme de ses diviseurs est: " << calculatedSum;
			cout << endl;*/
		}
	}

	int sortie;
	std::cout << "Appuyez sur une touche pour terminer: ";
	std::cin >> sortie;
	return 0;
}

// Un nombre parfait est la somme de ses diviseurs sauf lui-même
// Chercher tous les nombres parfaits entre 1 et 1000
// Pour cela chercher tous les diviseurs d'un nombre et les additionner
// Les 10 premiers nombres parfaits:
// 6
// 28
// 496
// 8128
// 33 550 336
// 8 589 869 056
// 137 438 691 328
//  2 305 843 008 139 952 128
// 18 446 744 073 709 551 615 unsigned long long max value is not a perfect number
// 2 658 455 991 569 831 744 654 692 615 953 842 176
// 191 561 942 608 236 107 294 793 378 084 303 638 130 997 321 548 169 216

