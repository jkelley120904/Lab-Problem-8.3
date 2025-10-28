#include <iostream>
#include <string>
using namespace std; 

int romanCharValue(char r);
int convertRomanToInt(string s);

int main(void)
{
	string input;

	while (true)
	{
		cout << "Enter roman number or Q to quit: ";
		getline(cin, input);
		if (input == "q" || input == "Q") break;
		cout << input << " = " << convertRomanToInt(input) << endl;
	}
}

int romanCharValue(char r)
{
	char input;
	if (r == 'I')
	{
		return 1;
	}
	if (r == 'V')
	{
		return 5;
	}
	if (r == 'X')
	{
		return 10;
	}
	if (r == 'L')
	{
		return 50;
	}
	if (r == 'C')
	{
		return 100;
	}
	if (r == 'D')
	{
		return 500;
	}
	if (r == 'M')
	{
		return 1000;
	}
}

int convertRomanToInt(string s)
{
	int total = 0;
	while (s.length() != 0)
	{
		char firstCharacter = s[0];
		char scendond = s[1];
		
		if (romanCharValue(firstCharacter) >= romanCharValue(scendond) || s.length() == 1)
		{
			total += romanCharValue(firstCharacter);
			s = s.substr(1);
		}
		else
		{
			total += romanCharValue(scendond) - romanCharValue(firstCharacter);
			s = s.substr(2);
		}
	}
	return total;
}