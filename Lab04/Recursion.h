#include <vector>

#include <stack>
#include <string>
#include <iostream>

using namespace std;

class IPalindromeComputer
{
public:
	virtual bool IsPalindrome(string stringToComputer) = 0;
};

class PalindromeByRecursion : public IPalindromeComputer
{
public:
	bool IsPalindrome(string s);
	std::string Reverse(string s, int index = 0);
};

class PalindromeByStack : public IPalindromeComputer
{
public:
	bool IsPalindrome(string s);
	string Reverse(string s);
};

class  IFactorialComputer
{
public:
	IFactorialComputer() {};
	virtual int CalculateFactorial(int numberToComputer) = 0;
};


class  FactorialByRecursion : public IFactorialComputer
{
public:
	FactorialByRecursion() {};
	int CalculateFactorial(int num);
};
class  FactorialByStack : public IFactorialComputer
{
public:
	FactorialByStack() {};
	
	int CalculateFactorial(int num);

private:
	std::stack <int> s;
};

class  MyFakeClass
{
public:
	MyFakeClass() {std::cout << "Constructor for MyFakeClass was called" << std::endl;}
	~MyFakeClass() { std::cout << "Destructor for MyFakeClass was called" << std::endl; }

};

class  MyBaseException : public std::exception
{
public:

	virtual char const* what() const throw();
};

class  MyException1 : MyBaseException
{
public:
	
	virtual char const* what() const throw();
};


class  MyException2 : MyBaseException
{
public:
	
	virtual char const* what() const throw();
};

// TODO make a MyException3


extern  std::string CallSimpleExceptionMethod(int i);
extern  void SimpleExceptionMethod(int i);

class Queen
{
public:
	Queen() = delete;
	Queen(int x, int y);
	int GetRow();
	int GetColumn();
private:
	int m_x;
	int m_y;
};

// This class is exported from the RecursionList.dll
class  ChessBoard {
public:
	ChessBoard() 
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				m_board[i][j] = 0;
			}
		}
	}

	ChessBoard(stack<Queen*> queens)
	{
		for (int i = 0; i < queens.size(); i++)
		{
			
		}
	}

	std::string ToString();
	
	bool Solve(ChessBoard chessboard, int col);

	

private:
    bool CheckSafeQueens(ChessBoard chessBoard, int i, int col);
	stack<Queen*> m_queens;
	//zero is free, while 1 is a placed queen
	// TODO: add your methods here.
	int GetQueenInCol(int col);
};

