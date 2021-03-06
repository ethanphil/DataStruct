#include "Recursion.h"
#include <stack>
#include <stdbool.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1

bool PalindromeByRecursion::IsPalindrome(string s)
{
	if (s == Reverse(s) || s.size() < 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string PalindromeByRecursion::Reverse(string s, int i)
{
	if (i < 0)
	{
		return "";
	}
	//Get the element from the back of the string, offset by the index given
	return s.at(s.size() - 1 - i) + Reverse(s, i+1);
}

bool PalindromeByStack::IsPalindrome(string s)
{
	if (s == Reverse(s) || s.size() < 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string PalindromeByStack::Reverse(string s)
{
	string reverseString = "";
	while (s.size() > 0)
	{
		reverseString = s.at(s.size() - 1);
		s.pop_back();
	}
	return reverseString;
}

int FactorialByRecursion::CalculateFactorial(int num) {

	if (num <= 1)
	{
		return 1;
	}

	else 
	{
		return num * CalculateFactorial(num - 1);  
	}
}


int FactorialByStack::CalculateFactorial(int num) {

	int answer = 1;

	if (num <= 1) { return 1; }

	while (num > 1) {
		s.push(num);
		num--;
	}
	while (!s.empty()) {
		answer = answer * s.top();
		s.pop();
	}
	return answer;
}

bool ChessBoard::Solve(ChessBoard chessBoard, int col) {

	if (col >= 8) {
		return true;
	}


	for (int i = 0; i < 8; ++i) {

		if (CheckSafeQueens(chessBoard, i, col)) {
			m_board[i][col] = 1;


			if (Solve(chessBoard, col + 1) == true)
				return true;

			m_board[i][col] = 0;

		}
	}
	return false;
}


bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) 
{
	for (int i = 0; i < col; i++)
	{
		int takenRow = GetQueenInCol(i);
		if (takenRow > -1)
		{
			//Check if the row is taken, or if the queen in another column is diagonal of the given coordinate
			if (takenRow == row || (abs(row - takenRow) == col - i))
			{
				return false;
			}
		}
	}
    return true;
}


string ChessBoard::ToString() {

	string answer = "";
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int temp = m_board[i][j];
			stringstream ss;
			ss << temp;
			string str = ss.str();
			answer = answer + str;
		}
		answer = answer + "\n";
	}
	return answer;
}

int ChessBoard::GetQueenInCol(int col)
{
	for (int i = 0; i < 8; i++)
	{
		if (m_board[i][col] == 1)
		{
			return i;
		}
	}
	return -1;
}

int Queen::GetRow()
{
	return m_y;
}

int Queen::GetColumn()
{
	return m_x;
}

extern std::string CallSimpleExceptionMethod(int i)
{    
    // TODO:
    // Note this is starter code that is not safe.  
    // As Simple exceptin method will throw an exception
    // which will not be handled, and we will also leak resources.
    // Make this method safer and handle all possible exceptions 
    // And also return a string of the exception recieved
    // The tests will tell you what to string to return.


	std::string retVal;
	MyFakeClass* resourceThatNeedsToBeCleanedup = nullptr;

	resourceThatNeedsToBeCleanedup = new MyFakeClass();

	SimpleExceptionMethod(1);

	delete resourceThatNeedsToBeCleanedup;

	return retVal;
}

// NOTE this function should not be editted.
extern void SimpleExceptionMethod(int i)
{
	int retVal = 0;

	if (i == 1)
	{
		throw MyException1();
	}
	else if (i == 2)
	{
		throw MyException2();

	}
	else if (i == 3)
	{
        // TODO uncomment line below, as you need to have all three exceptions working here
		//throw MyException3();
	}
	else
	{
		retVal = 20;
	}

	return;

}



char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "MyException1";
}
char const* MyException2::what() const throw() {
	return "MyException2";
}
// TODO make a MyException3::what
