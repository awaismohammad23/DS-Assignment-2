#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//unimplemented.
// This function create the run time stack of the program file provided 
// Step 1:  Push the passing arguments of the function  into the stack 
// Step 2:  Push the line address of the code line that is calling the function 
// Step 3:  Push EBP to the stack (for first step conside EBP =1004 AS default value )
// Step 4:  Assign the current ESP value to EBP  
// Remember Stack Pointer(ESP) always points at the Top of the Stack and is decreased by 4 bytes whenever a value is inserted into the stack 
//  (  REPEAT THE ABOVE STEPS 1 TO 4 FOR ALL THE RECURSIVE CALLS  )
// write the output to the outputFile if the string is  not isEmpty()
void CreateRunTimeStack(string filename, string outputFile)
{

}

// Start execution from the main function and use outputFile to print the output
// Must use CreateRunTimeStack() for execution of the code 
// write the output to the outputFile if the string is not isEmpty()
void ExecuteCode(string filename, string outputFile)
{

}

// use special stack for converting expressions  
//string infixToPostfix(string expression) {
//	return expression;
//}

// Code should be templatized
//use this node for creating a Run Time Stack
template<class T>
class RuntimeNode
{
	T data;	 //You may modify the above line
	RuntimeNode<T>* nodeAddress; //same will be stored in ESP and EBP						
	RuntimeNode<T>* next;
};



//queue node
template<typename T>
class QueueNode 
{

public:

	T value;
	QueueNode* next;

};

//stack for evaluation of postfix expression
// Add the required functions 
template<typename T>
class Stack 
{

public:

	//templatized stack array
	//n is the size of the array.
	//stack top.
	T* Array = new T[100];
	int top = -1;

	//Default Constructor.
	Stack<T>() 
	{
		//initializing the stack with 0.
		for (int i = 0; i < 100; i++)
		{
			Array[i] = 0;
		}
			
	}

	//Function to return top the the stack.
	T stackTop()
	{
		return Array[top];
	}

	//isEmpty function.
	bool isEmpty() 
	{
		//if top of stack is -1 it is empty.
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
			
	}

	//push function to push the data into the stack.
	void push(T val) 
	{
		//storing the data int the array making it the top and incrementing top.
		if(top < 100)
		{
			top++;
			Array[top] = val;
		}
	}

	//pop function to return the top data value in the stack.
	T pop()
	{
		if (top <= -1)
		{
			return -1;
		}
		else 
		{
			//decrementing top.
			top--;
		}
	}

};


//Creating another stack class to implement postfix manipulation.
template<typename T>
class PostFixManipStack
{

private:

	//stack array and its size.
	T* Array = new T[100];
	int top = -1;
	int stackIndex;

public:

	//Default constructor.
	PostFixManipStack<T>() 
	{
		//initializing the array with 0;
		for (int i = 0; i < 100; i++)
		{
			Array[i] = 0;
			stackIndex = 0;
		}

	}

	//returns top of the stack. 
	T stackTop()
	{
		return Array[stackIndex - 1];
	}

	//empty function if the top of the stack is -1.
	bool isEmpty()
	{
		//if index < 0
		if (stackIndex < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//push function of the stack.
	void push(T data)
	{
		//checking the size of the stack whether it is full or not.
		if (stackIndex < 100)
		{
			//storing the value in the stack
			Array[stackIndex] = data;

			//incrementing the index.
			stackIndex++;
		}
	}

	//popping the data from the stack.
	T pop()
	{
		//checking the index whether the index is invalid or not.
		if (stackIndex < 0)
		{
			return -1;
		}
		else
		{
			//decrementing the index.
			stackIndex--;

			//returning the value from the stack.
			return Array[stackIndex];

		}
	}

};


//use linked list base implementation 
template<class T>
class Queue 
{
	QueueNode<T>* rear;
	QueueNode<T>* front;

public:

	Queue<T>()
	{
		rear = NULL;
		front = NULL;
	}
};

//A linked list of Variables can be use for finding the variable and associated value 
template <typename T>
struct Variables 
{
	T value;
	string Name;

};


//list node of the linked list.
template<typename T>
struct ListNode 
{
	T value;
	ListNode<T>* next;

	//default constructor.
	ListNode <T>()
	{
		value = 0;
		next = NULL;
	}

};

template<typename T>
class LinkedList 
{
	//creating the head of the list.
	ListNode<T>* head;

public:

	LinkedList<T>() 
	{
		head = NULL;
	}

	//insert function.
	void insert(T data)
	{
		//creating a new node and storing the data into the node.
		ListNode<T>* newNode = new ListNode<T>();
		newNode->value = data;
		newNode->next = NULL;

		//if the head is NULL assign the new node to the head.
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			//creating a current node and traversing the list until the list is NULL.
			ListNode<T>* CurrentNode = head;

			//traversing the list.
			while (CurrentNode->next != NULL)
			{
				CurrentNode = CurrentNode->next;
			}

			//storing the node at the end of the list.
			CurrentNode->next = newNode;
		}
	}

};


// Stack used for converting infix expressions to postfix expressions 
template<class T>
class SpecialStack 
{
public:

	Queue<T> queue1;
	Queue<T> queue2;
};


// Simply just read the file
// Use '\n' to sperate each line of code
string readFile(string a = "code.txt") 
{
	//creating an  object and opening the file using the object.
	ifstream readFile;
	readFile.open(a);
	
	//creting a string variable to read the string from the file and
	//string to store the final result after adding '\n'.
	string readString;
	string FinalString;

	//reading the data from the file.
	while (getline(readFile, readString))
	{
		//storing the data from file into the string.
		FinalString = FinalString + readString + '\n';

	}

	//closing the file.
	readFile.close();

	//returning the final string.
	return FinalString;
}

// Remove useless lines so line addressing is done properly
string removeLines(string code)
{
	//creating a string stream variable to read the file.
	stringstream readFile(code);

	//creting a string variable to read the string from the file and
	//string to store the final result after adding '\n'.
	string readString;
	string FinalString;

	

	//reading the data from the file.
	while (getline(readFile, readString, '\n'))
	{
		//creating a bool variable to store the result whether the occurence of \n or space happened or not. 
		bool flag = false;

		//looping to the end of the code in the string.
		int count = 0;
		while (count < readString.size())
		{
			
			if (readString[count] != '\n' && readString[count] != ' ')
			{
				flag = true;
			}
			count++;
		}
		
		//adding \n to the final string.
		if (flag)
		{
			FinalString = FinalString + readString + '\n';
		}
			
	}

	//returning the final string.
	return FinalString;
}

// Use this for checking indentations (function, loops, if conditions, etc.)
//Only check for the brackets in this function 
string checkIndentationErrors(string code)
{

	int openFlowerBrackets = 0;
	int closeFlowerBrackets = 0;
	int openRoundBrackets = 0;
	int closeRoundBrackets = 0;


	for (int i = 0; i < code.length(); i++)
	{
		char symbol = code[i];
		
		switch (symbol)
		{
			//incrementing the number of brackets occured in the string. 
			case '{': openFlowerBrackets++;
			case '}': closeFlowerBrackets++;
			case '(': openRoundBrackets++;
			case ')': closeRoundBrackets++;
			default: break;
		}

	}

	//creating a bool variable.
	bool flag = true;

	//comparing the count of { and } and ( and ) characters. 
	if (openFlowerBrackets == closeFlowerBrackets && openRoundBrackets == closeRoundBrackets)
	{
		flag = false;
	}

	//if the flag is true then return "Indentation error detected" message.
	if (flag)
	{
		string message = "Indentation error detected";
		return  message;
	}
	else
	{
		//if the flag is false then return "Indentation error detected" message.
		string message = "Indentation error not detected";
		return  message;
	}
	
}

// This prepends a line address to every single line in program
string prependLineAddress(string code) 
{
	//initializing the line number from hundred.
	int LineNumber = 100;
	stringstream readFile(code);
	string readString;
	string FinalString;

	//reading the string after it is read from the file.
	while (getline(readFile, readString, '\n'))
	{
		//converting the line number to string.
		string CountString = to_string(LineNumber);

		//adding the final string along with the line number and the data read from the file in the string variable.
		FinalString = FinalString + "C" + CountString + "    " + readString + '\n';

		//incrementing the line number.
		LineNumber++;
	}

	//returning the final string.
	return FinalString;

}

//Check if the function calls itself infinitely
string checkInfiniteLoop(string code)
{
	//creating a boolean variable to check whether the loop is infinite or not.
	bool isInfinite = true;
	string var = code;

	//checking for the code word in the infinite code like if,() and return statements.
	if (var.find("if") != -1)
	{
		isInfinite = false;
	}
	else if (var.find("return") != -1)
	{
		isInfinite = false;
	}
	else if (var.find("()") == 0)
	{
		isInfinite = false;
	}

	//if the code is infinite then return "Infinite loop detected" message.
	if (isInfinite)
	{
		string message = "Infinite loop detected";
		return message;
	}
	else
	{
		string message = "Infinite loop not detected";
		return message;
	}
}


// Use Array based stack for evaluating the expression  
// Values contains the values of the variables used in the postfix expression  for  getting the final result
// You may look at the Test Case for understanding the working of the function   
template<typename T>
T Solving_PostfixExpression(string expression, LinkedList<T> values) 
{
	//creating a stack to evalvate the postfix expression.
	PostFixManipStack<T> stack;

		//
		for (int i = 0; i < expression.size(); i++)
		{
			bool isOperator = true;
		
			//checking where the operators in the string occur. 
			if (expression[i] == '-' || expression[i] == '+' 
			||  expression[i] == '*' || expression[i] == '/')
			{
				//making the presence of the operator.
				isOperator = false;
			}
			
			//if an operator comes in the string push its corresponding value in the stack.
			if (isOperator)
			{
				//pushing the value in the stack.
				stack.push(CharacterNumber(expression[i]));
			}

			else
			{
				//popping the two numbers on which the operation has to be done in the stack.
				int first_value = stack.pop();
				int second_value = stack.pop();

				//checking the expression according to the operator and performing the operation according to the operator.
				switch (expression[i])
				{
					//adding the numbers and pushing the result back to stack.
					case '+': stack.push(second_value + first_value);   break;
					
					//subtracting the numbers and pushing the result back to stack.
					case '-': stack.push(second_value - first_value);  break;

					//multiplying the numbers and pushing the result back to stack.
					case '*': stack.push(second_value * first_value);  break;

					//dividing the numbers and pushing the result back to stack.
					case '/': stack.push(second_value / first_value);  break;
				}
			}

		}

		//return the final value remaining in the stack which will be the final resulr of the expression.
		return stack.stackTop();
	}

//function to return the integer value of the alphabet passed in the function.
int CharacterNumber(char Operator) 
{
	//checking the variable and returning the value according to it.
	switch (Operator)
	{
		case 'A':	return 1;//returning 1 for A
		case 'B':	return 2;//returning 2 for B
		case 'C':	return 3;//returning 3 for C
		case 'D':	return 4;//returning 4 for D
		case 'E':	return 5;//returning 5 for E
		case 'F':	return 6;//returning 6 for F
		default:	break;
	}

}

//checking the precedence of the operators and returning the numbers according to their precedence.
int CheckPrecedence(char Operator) 
{
	//checking the operator and returning its precedence.
	switch (Operator)
	{
		case '^':	return 3;//returning 3 for ^ operator. 
		case '/':	return 2;//returning 2 for / operator.
		case '*':	return 2;//returning 2 for * operator.
		case '+':	return 1;//returning 1 for + operator.
		case '-':	return 1;//returning 1 for - operator.
		default:return -1;	 //returning if any other operator comes.
	}

}

//infixtopostfix function.
string infixToPostfix(string str)
{
	//creating a stack.
	Stack<char> stack;

	//creating final postfix string.
	string postFixString = "";
	string finalString;

		for (int i = 0; i < str.length(); i++) 
		{
			char stringCharacter = str[i];

			// If the scanned character is an operand, add it to output string.
			if ((stringCharacter >= 65 && stringCharacter <= 90) ||
				(stringCharacter >= 97 && stringCharacter <= 122) ||
				(stringCharacter >= '0' && stringCharacter <= '9'))
			{
				finalString += stringCharacter;
			}

			// If the scanned character is an ‘(‘, push it to the stack.
			else if (stringCharacter == '(')
			{
				stack.push('(');
			}
				
			// If the scanned character is an ‘)’ pop and to output string from the stack until an ‘(‘ is encountered.
			else if (stringCharacter == ')')
			{
				//popping the stack until the '(' is occured.
				while (stack.stackTop() != '(')
				{
					//adding the string in the final string.
					finalString += stack.stackTop();

					//popping the operators from the stack.
					stack.pop();
				}

				//popping the '(' character remained in the stack.
				stack.pop();
			}
		
			//If an operator is scanned
			else 
			{	
				//if stackis not empty.
				if (!stack.isEmpty())
				{
					//comparing the precedence of the operators in the stack. 
					while (CheckPrecedence(str[i]) <= CheckPrecedence(stack.stackTop()))
					{
						//adding the operator in the final string.
						finalString += stack.stackTop();

						//popping the operators from the stack.
						stack.pop();
					}
				}
				
				//pushing the character in the stack. 
				stack.push(stringCharacter);
			}
		}

		// Pop all the remaining elements from the stack
		while (!stack.isEmpty())
		{
			//popping all the elements of stack to the final string. 
			finalString += stack.stackTop();

			//popping the stack.
			stack.pop();
		}	

	//returning the final string.
	return finalString;
}
