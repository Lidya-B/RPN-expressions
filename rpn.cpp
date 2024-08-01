//*****************************************************************************************************
//
//		File:					rpn.cpp
//
//		This program evaluates RPN exepresions that contain integers and integer oprations.
//	
//		Other files required: 
//			1.	stack.h
//			2.	expression.txt
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include<cstdlib>
using namespace std;
#include"stack.h"

//*****************************************************************************************************

void outputToken(char token[], ofstream& resultsFile);
void processNumber(char token[], Stack<int>& stack1, ofstream& resultsFile);
bool processOperator(char token[], Stack<int>& stack1, ofstream& resultsFile);
void displayResult(ofstream& resultsFile, Stack<int>& stack1, bool& isvalid);
void resetFlagStack(Stack<int>& stack1, bool& isValid);

//*****************************************************************************************************

int main()
{
	Stack<int>stack1;
	char token[80];
	bool isvalid;
	isvalid = true;

	ifstream expressions;
	expressions.open("expressions.txt");

	ofstream resultsFile;
	resultsFile.open("results.txt");

	while (expressions >> token)
	{
		outputToken(token, resultsFile);

		if (token[0] == ';')
		{
			displayResult(resultsFile, stack1, isvalid);
			resetFlagStack(stack1, isvalid);
		}
		else if ((isvalid) && (isdigit(token[0])))
		{
			processNumber(token, stack1, resultsFile);
		}
		else if ((isvalid) && (ispunct(token[0])))
		{
			isvalid = processOperator(token, stack1, resultsFile);
		}

	}

	expressions.close();
	resultsFile.close();

	return 0;
}

//*****************************************************************************************************

void outputToken(char token[], ofstream& resultsFile)
{
	resultsFile << endl << "( Token:  " << token << ") \t\t";

	if (token[0] != ';')
		cout << token << " ";
}

//*****************************************************************************************************

void processNumber(char token[], Stack<int>& stack1, ofstream& resultsFile)
{
	int num;

	num = atoi(token);
	stack1.push(num);
	resultsFile << "push" << num;
}

//*****************************************************************************************************

bool processOperator(char token[], Stack<int>& stack1, ofstream& resultsFile)
{
	bool valid = true;

	if (stack1.getNumValues() >= 2)
	{
		int num1;
		int num2;
		int result;

		stack1.pop(num1);
		stack1.pop(num2);

		if (token[0] == '+')
		{
			result = num2 + num1;
			stack1.push(result);
			resultsFile << "pop " << num1 << "\t\t" << " pop " << num2 << "\t\t" << " push " << result << " ";

		}
		else if (token[0] == '-')
		{
			result = num2 - num1;
			stack1.push(result);
			resultsFile << "pop " << num1 << "\t\t" << " pop " << num2 << "\t\t" << " push " << result << " ";
		}
		else if (token[0] == '*')
		{
			result = num2 * num1;
			stack1.push(result);
			resultsFile << "pop " << num1 << "\t\t" << " pop " << num2 << "\t\t" << " push " << result << " ";
		}
		else if (token[0] == '/')
		{
			if (num1 != 0)
			{
				result = num2 / num1;
				stack1.push(result);
				resultsFile << "pop " << num1 << "\t\t" << " pop " << num2 << "\t\t" << " push " << result << " ";
			}

		}
		else if (token[0] == '%')
		{
			if (num1 != 0)
			{
				result = num2 % num1;
				stack1.push(result);
				resultsFile << "pop " << num1 << "\t\t" << " pop " << num2 << "\t\t" << " push " << result << " ";
			}

		}

	}
	else if (stack1.getNumValues() < 2)
	{
		valid = false;
	}

	return valid;
}

//*****************************************************************************************************

void displayResult(ofstream& resultsFile, Stack<int>& stack1, bool& isvalid)
{
	int result;

	if (isvalid)
	{
		stack1.pop(result);
		cout << "= " << result << endl;
		resultsFile << "pop " << result << "\n" << "\t\t valid: Result: " << result << endl << endl;
	}
	else
	{
		cout << "\t Invalid " << endl;
		resultsFile << "\n \t\t Invalid RPN Expression - not enough oprandes" << endl << endl;
	}
}

//*****************************************************************************************************

void resetFlagStack(Stack<int>& Stack1, bool& isValid)
{
	isValid = true;

	int del;
	while (Stack1.pop(del))
	{
		del = 0;
	}

}

//*****************************************************************************************************


