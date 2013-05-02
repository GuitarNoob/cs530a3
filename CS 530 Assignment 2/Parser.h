#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;


#define READ "r"
#define MAX_RECORD_SIZE 68

char* error = new char[100];
std::list<char> SS;
std::list<char> charsOnly;
std::list<char> Ops;
std::list<string> GoodLines;
std::list<string> BadLines;

void MakeList();
void WriteResults();
void ParseFile(string Path);
bool ParseLine(string line);
bool GetAssignment(string line);
bool GetExpression(string line);
bool CheckID(string line);
bool CheckOp(string line);
bool CheckCharOnly(char c);
bool CheckChar(char c);

struct ParensIndex
{	
	int start;
	int end;
	ParensIndex::ParensIndex(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
};