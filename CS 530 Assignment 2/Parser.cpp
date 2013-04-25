#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include "Parser.h"

string IntToHex(int num);

int main(int argc, char* argv[])
{
	MakeList();
	std::string filePath;
	//filePath = argv[1];
	/*if(argc > 1)
		std::string filePath(argv[1]);
	else
	{
		cout << "Please type in the file path of a SIC Basic or XE source code" << endl;
		getline(cin, filePath);
	}*/

	cout << ParseLine("first = one1 + two2 - three3 / four4 ;") << "\n";

	cout << ParseLine("second = one1 * ( ( two2 * three3 ) + ( two2 * three3 ) );") << "\n";
	cout << ParseLine("third = ONE + twenty - three3 ;") << "\n";
	cout << ParseLine("third = old * thirty2 / b567 ;") << "\n";
	cout << ParseLine("one1 * i8766e98e + bignum") << "\n";
	cout << ParseLine("third = ONE + twenty - three3 ;") << "\n";
	cout << ParseLine("third = ONE + twenty - three3 ;") << "\n";
	cout << ParseLine("first = = one1 + two2 - three3 / four4 ;") << "\n";
	cout << ParseLine("first = one1 + two2 - three3 / four4") << "\n";
	cout << ParseLine("first = 1 + - two2 - three3 / four4 ;") << "\n";
	cout << ParseLine("first = one1 + two2 ? three3 / four4 ;") << "\n";
	cout << ParseLine("second = 4 + ( one1 * two2 ) * ( three3 + four4 ;") << "\n";
	cout << ParseLine("third = one1 + 24 - three3 ;") << "\n";
	cout << ParseLine("one1 + - delta") << "\n";
	cout << ParseLine("sixty6 / min = fourth ;") << "\n";

	filePath = ".\\SICTEST.asm";
	
	system("PAUSE");
}

void MakeList()
{
	Ops.push_back('+');
	Ops.push_back('-');
	Ops.push_back('/');
	Ops.push_back('*');
	Ops.push_back('%');

	SS.push_back('a');
	SS.push_back('b');
	SS.push_back('c');
	SS.push_back('d');
	SS.push_back('e');
	SS.push_back('f');
	SS.push_back('g');
	SS.push_back('h');
	SS.push_back('i');
	SS.push_back('j');
	SS.push_back('k');
	SS.push_back('l');
	SS.push_back('m');
	SS.push_back('n');
	SS.push_back('o');
	SS.push_back('p');
	SS.push_back('q');
	SS.push_back('r');
	SS.push_back('s');
	SS.push_back('t');
	SS.push_back('u');
	SS.push_back('v');
	SS.push_back('w');
	SS.push_back('x');
	SS.push_back('y');
	SS.push_back('z');

	SS.push_back('A');
	SS.push_back('B');
	SS.push_back('C');
	SS.push_back('D');
	SS.push_back('E');
	SS.push_back('F');
	SS.push_back('G');
	SS.push_back('H');
	SS.push_back('I');
	SS.push_back('J');
	SS.push_back('K');
	SS.push_back('L');
	SS.push_back('M');
	SS.push_back('N');
	SS.push_back('O');
	SS.push_back('P');
	SS.push_back('Q');
	SS.push_back('R');
	SS.push_back('S');
	SS.push_back('T');
	SS.push_back('U');
	SS.push_back('V');
	SS.push_back('W');
	SS.push_back('X');
	SS.push_back('Y');
	SS.push_back('Z');

	SS.push_back('0');
	SS.push_back('1');
	SS.push_back('2');
	SS.push_back('3');
	SS.push_back('4');
	SS.push_back('5');
	SS.push_back('6');
	SS.push_back('7');
	SS.push_back('8');
	SS.push_back('9');

	charsOnly.push_back('a');
	charsOnly.push_back('b');
	charsOnly.push_back('c');
	charsOnly.push_back('d');
	charsOnly.push_back('e');
	charsOnly.push_back('f');
	charsOnly.push_back('g');
	charsOnly.push_back('h');
	charsOnly.push_back('i');
	charsOnly.push_back('j');
	charsOnly.push_back('k');
	charsOnly.push_back('l');
	charsOnly.push_back('m');
	charsOnly.push_back('n');
	charsOnly.push_back('o');
	charsOnly.push_back('p');
	charsOnly.push_back('q');
	charsOnly.push_back('r');
	charsOnly.push_back('s');
	charsOnly.push_back('t');
	charsOnly.push_back('u');
	charsOnly.push_back('v');
	charsOnly.push_back('w');
	charsOnly.push_back('x');
	charsOnly.push_back('y');
	charsOnly.push_back('z');

	charsOnly.push_back('A');
	charsOnly.push_back('B');
	charsOnly.push_back('C');
	charsOnly.push_back('D');
	charsOnly.push_back('E');
	charsOnly.push_back('F');
	charsOnly.push_back('G');
	charsOnly.push_back('H');
	charsOnly.push_back('I');
	charsOnly.push_back('J');
	charsOnly.push_back('K');
	charsOnly.push_back('L');
	charsOnly.push_back('M');
	charsOnly.push_back('N');
	charsOnly.push_back('O');
	charsOnly.push_back('P');
	charsOnly.push_back('Q');
	charsOnly.push_back('R');
	charsOnly.push_back('S');
	charsOnly.push_back('T');
	charsOnly.push_back('U');
	charsOnly.push_back('V');
	charsOnly.push_back('W');
	charsOnly.push_back('X');
	charsOnly.push_back('Y');
	charsOnly.push_back('Z');
}

void ParseFile(std::string Path)
{
	FILE *localFP;
	if ((localFP = fopen(Path.c_str(), READ)) == NULL)
	{
		error  = "File does not exist: ";
		
	}
	char line[MAX_RECORD_SIZE];
	//get each line
	while(fgets(line, sizeof(line), localFP) != NULL)
	{
		ParseLine(std::string(line));		
	}
}

bool ParseLine(std::string line)
{
	if (line.find(";") != string::npos)
	{
		return GetAssignment(line);
	}
	else
	{
		return GetExpression(line);
	}
}

bool GetAssignment(std::string line)
{
	if (line.find(";") != string::npos)
	{
		//check for characters after the ;
		std::string lineS = line.substr(line.find_first_of(";"), line.length() - line.find_first_of("="));
		for (int i = 0; i < lineS.length(); i++)
		{
			if (CheckChar(lineS[i]))
			{
				error = "charaters after semicolon!";
				return false;
			}
		}
		line = line.substr(0, line.find_first_of(";"));
		//
		lineS = line.substr(0, line.find_first_of("="));
		//check if line contains white space
		if (lineS.find(" ") != string::npos)
		{
			int indexOfWhiteSpace = lineS.find_first_of(" ");
			if (indexOfWhiteSpace == lineS.length() - 1)
				lineS = lineS.substr(0, indexOfWhiteSpace);
			else if (indexOfWhiteSpace == 0)
				lineS = lineS.substr(1);
			else 
			{
				error = "incorrent space in id";
				return false;
			}
		}
		if (!CheckID(lineS))
			return false;
		if (!GetExpression(line.substr(line.find_first_of("=") + 1, (line.length() - line.find_first_of("=") - 1))))
			return false;		
		return true;
	}
	error = "No semicolon in the assignment!";
	return false;
}

bool GetExpression(std::string line)
{
	bool op = false;
	int parens = 0;
	while (line.length() > 0)
	{
		//first count the parens
		for (int i = 0; i < line.length(); i ++)
		{
			if (line[i] == '(')
			{				
				parens++;
			}
			else if (line[i] == ')')
			{
				parens--;
			}
		}
		if (parens != 0)
		{
			error = "parenthesis do not match";
			return false;
		}
		while (line[0] == ' ' && line[0] != NULL)
		{
			if (line.length() == 1)
				goto Finish;
			else
				line = line.substr(1); 
		}
		if (line[0] == '(')
		{
			if (!op)
			{
				//first count the parens
				for (int i = 0; i < line.length(); i ++)
				{
					if (line[i] == '(')
					{				
						parens++;
					}
					else if (line[i] == ')')
					{
						parens--;
						if (parens == 0)
						{
							if (!GetExpression(line.substr(1).substr(0, i - 1)))
								return false;				
							line = line.substr(i + 1, line.length() - i);	
							op = true;
							break;
						}
					}
				}				
			}
			else
			{
				error = "incorrect use of parenthesis";
				return false;
			}
		}
		else if (line.find(' ') != string::npos)
		{
			if (op)
			{
				if (!CheckOp(line.substr(0, line.find_first_of(' '))))
				{
					error = "invalid expression";
					return false;
				}
				op = false;
				line = line.substr(line.find_first_of(' '), line.length() - line.find_first_of(' '));
			}
			else
			{
				if (!CheckID(line.substr(0, line.find_first_of(' '))))
				{
					error = "invalid expression";
					return false;
				}
				op = true;
				line = line.substr(line.find_first_of(' '), line.length() - line.find_first_of(' '));
			}
		}
		else
		{
			if (!op)
			{
				if (!CheckID(line))
				{
					error = "invalid expression";
					return false;
				}
				op = true;
				line = line.substr(line.length());
			}
			else
			{
				error = "cannot end expression in a op";
				return false;
			}
		}
	}
	Finish:
	return op;
}

bool CheckID(std::string line)
{
	for (int i = 0; i < line.length(); i++)
	{
		if (i == 0)
		{
			if (!CheckCharOnly(line[i]))
			{
				error = "incorrect character in ID";
				return false;
			}
		}
		else
		{
			if (!CheckChar(line[i]))
			{
				error = "incorrect character in ID";
				return false;
			}
		}
	}
	return true;
}

bool CheckOp(std::string line)
{
	bool passed = false;
	for (int i = 0; i < line.length(); i ++)
	{
		std::list<char>::iterator findIter = std::find(Ops.begin(), Ops.end(), line[i]);
		if (findIter != Ops.end())
		{
			if (passed)
			{
				error = "incorrect op";
				return false;
			}
			passed = true;
		}
	}
	return passed;
}

bool CheckCharOnly(char c)
{
	std::list<char>::iterator findIter = std::find(charsOnly.begin(), charsOnly.end(), c);
	if (findIter == charsOnly.end())
		return false;
	return true;
}

bool CheckChar(char c)
{
	
	std::list<char>::iterator findIter = std::find(SS.begin(), SS.end(), c);
	if (findIter == SS.end())
		return false;
	return true;
}