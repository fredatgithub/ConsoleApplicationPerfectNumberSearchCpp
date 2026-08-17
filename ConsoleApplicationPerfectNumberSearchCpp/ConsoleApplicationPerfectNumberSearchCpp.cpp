#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>

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
		cout << divisors[i];
		if (i < divisors.size() - 1) {
			cout << ", ";
		}
	}
}

int main()
{
	cout << "Recherche des nombres parfaits.\n";
	vector<string> result;
	ostringstream sb;
  const int startNumber = 33550337; // 33 550 336; 
	constexpr int finalNumber = numeric_limits<int>::max(); //8589869057; // 8 589 869 056;
	sb << "Liste des nombres parfaits entre " << startNumber << " et " << finalNumber << " sont: ";
	vector<string> perfectNumbers;
	perfectNumbers.push_back("Les nombres parfaits sont des nombres qui sont égaux à la somme de leurs diviseurs propres.");

	for (int i = startNumber; i <= finalNumber; i++)
	{
		// int maxInt = 2 147 483 647;
		int currentNumber = i;
		vector<int> divisors = getAllDivisors(currentNumber);
		int calculatedSum = addAllDivisors(divisors) - currentNumber; // Subtract the number itself from the sum of divisors

		if (currentNumber == calculatedSum)
		{
			cout << i << " est un nombre parfait.";
			cout << " Ses diviseurs sont : ";
			printDivisors(removeLastValue(divisors));
			cout << " et la somme de ses diviseurs est : " << calculatedSum;
			cout << endl;
			perfectNumbers.push_back(to_string(currentNumber));
		}
		else
		{
			cout << i << " n'est pas un nombre parfait.";
			/*cout << " Ses diviseurs sont: ";
			printDivisors(removeLastValue(divisors));
			cout << " et la somme de ses diviseurs est: " << calculatedSum;*/
			cout << endl;
		}
	}

	// Print the list of perfect numbers found
	for (const auto& num : perfectNumbers) {
		cout << num << endl;
	}

	// on sauvegarde le résultat dans un fichier texte
  const int fileNumber = 2;
	string fileName = "perfect_numbers" + to_string(fileNumber) + ".txt";
	ofstream outputFile(fileName);
  cout << "Les nombres parfaits trouvés ont été sauvegardés dans le fichier: " << fileName << endl;

	// on affiche si pas de résultat
	if (perfectNumbers.empty())
	{
		cout << " Pas de resultat" << endl;
	}

	for (const auto& num : perfectNumbers) {
		outputFile << num << endl;
	}

	int sortie;
	cout << "Appuyez sur une touche pour terminer: ";
	cin >> sortie;
	return 0;
}

// Un nombre parfait est la somme de ses diviseurs sauf lui-même
// Pour cela chercher tous les diviseurs d'un nombre et les additionner
// Les 10 premiers nombres parfaits:
// 6
// 28
// 496
// 8128
// 33 550 336
// 8 589 869 056
// 137 438 691 328
// 2 305 843 008 139 952 128
// 18 446 744 073 709 551 615 unsigned long long max value is not a perfect number
// 2 658 455 991 569 831 744 654 692 615 953 842 176
// 191 561 942 608 236 107 294 793 378 084 303 638 130 997 321 548 169 216

