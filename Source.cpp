#include<fstream>
#include<iostream>
#include<string>
using std::ifstream;
using std::string;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	ifstream inFile;
	string fileName;
	do
	{
		cout << "Please enter File Name" << endl;
		getline(cin, fileName);
		inFile.open(fileName);

		if (!inFile)
		{
			cerr << "Could not open input file name: " << fileName << endl;
			inFile.clear();
			inFile.close();
		}

	} while (!inFile);

	int counter(0);
	double first1(0), first2(0), last1(0), last2(0);


	while (!inFile.eof() && !inFile.fail())
	{
		if (counter == 0)
		{
			inFile >> first1;
			last1 = first1;
		}
		if (counter == 1)
		{
			inFile >> first2;
			last2 = last1;
			last1 = first2;
		}
		if (counter > 1)
		{
			last2 = last1;
			inFile >> last1;
		}

		counter++;
	}
	if (counter >= 2)
	{
		cout << "The first two numbers are " << first1 << " & " << first2 << endl;
		cout << "The last two numbers are " << last2 << " & " << last1 << endl;
		cout << "The number of numbers is " << counter << endl;
	}
	else if (counter == 1)
	{
		cout << "The only number in the file is " << first1 << endl;
	}

	else
	{
		cout << "File is empty" << endl;
	}



	inFile.close();
}


