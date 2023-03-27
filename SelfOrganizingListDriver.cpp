// CSCN215 - Lab 4 - Jeremiah Carter

// includes statements
#include "Count.h"
#include "Transpose.h"
#include "MoveToFront.h"
#include <fstream>

using namespace std;

int main()
{
	// intro
	//cout << "CSCN215 - Lab 4: Self-Organizing Lists - Jeremiah Carter" << endl << endl;
	cout << "Homework 2 - Problem #5 - Jeremiah Carter" << endl << endl;

	// count 
	Count<char> count;
	Count<string> count2;

	// transpose
	Transpose<char> transp;
	Transpose<string> transp2;

	// move-to-front
	MoveToFront<char> mtf;
	MoveToFront<string> mtf2;

	string word;
	ifstream input;

	char base[] = { 'A','B','C','D','E','F','G','H' };
	char addThese[] = {'D','H','H','G','H','E','G','H','G','H','E','C','E','H','G'};

	// count: char test

	// loading up the arrays
	for(int i = 0; i < 8; i++)
	{
		count.add(base[i]);
		transp.add(base[i]);
		mtf.add(base[i]);
	}

	cout << "Here is the starting list of characters: ";
	for (int i = 0; i < 15; i++)
		cout << addThese[i] << " ";
	cout << endl << endl;

	// finding all the values
	for (int i = 0; i < 14; i++)
	{
		count.find(addThese[i]);
		transp.find(addThese[i]);
		mtf.find(addThese[i]);
	}

	cout << "Count Heuristic:" << endl;
	count.printlist();
	cout << endl;

	cout << "Transpose Heuristic:" << endl;
	transp.printlist();
	cout << endl;

	cout << "Move-TO-Front Heuristic:" << endl;
	mtf.printlist();
	cout << endl;



	//cout << endl << endl << "----------- file test -------------" << endl << endl;

	//input.open("test.txt");

	//// count: file test
	//while (input >> word) {
	//	count2.find(word);
	//	transp2.find(word);
	//	mtf2.find(word);
	//}

	//cout << "Count Heuristic:" << endl;
	//count2.printlist(10);
	//cout << endl << endl;

	//cout << "Transpose Heuristic:" << endl;
	//transp2.printlist(10);
	//cout << endl << endl;

	//cout << "Move-TO-Front Heuristic:" << endl;
	//mtf2.printlist(10);
	//cout << endl << endl;

	// transpose: char test



	// end
	input.close();
	system("pause");
	return 0;
}
