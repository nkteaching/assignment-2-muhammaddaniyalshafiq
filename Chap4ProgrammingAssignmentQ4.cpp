#include <iostream>
using namespace std;

template<class T>
struct Node
{
	T val;
	Node *next, *prev;
	
	Node(T value)
	{
		val = value;
		next = NULL;
		prev = NULL;
	}
};

template<class T>
class Stack
{
	int size = 0;
	
	public:
		Node<T> *top = NULL, *back = NULL;
		
		void push(T value)
		{
			if(top == NULL)
			{
				top = new Node<T>(value);
				back = top;
				size++;
			}
			
			else
			{
				back->next = new Node<T>(value);
				back->next->prev = back;
				back = back->next;
				size++;
			}
		}
		
		int pop()
		{
			if(top == NULL)
			{
				cout << "Stack is empty";
				
				return -1;
			}
			
			T n;
			
			if(back != top)
			{
				n = back->val;
				back = back->prev;
				delete back->next;
				size--;
				
				return n;
			}
			
			else
			{
				n = back->val;
				delete back;
				top = NULL;
				size--;
				
				return n;
			}
		}
		
		bool isEmpty()
		{
			if(top == NULL)
			{
				return true;
			}
			
			else
			{
				return false;
			}
		}
		
		void print()
		{
			Node<T> *temp = back;
			
			while(temp != NULL)
			{
				cout << temp->val;
				temp = temp->prev;
			}
		}
		
		int getSize()
		{
			return size;
		}
};

void addingLargeNum(Stack<char> &s1, Stack<char> &s2, Stack<int> &finalSum)
{
	int num1, num2, sum;
	int carry = 0;
	int size1 = s1.getSize();
	int size2 = s2.getSize();
	int diff;
	
	if(size1 < size2)
	{
		diff = size2 - size1;
	}
	
	else if(size2 < size1)
	{
		diff = size1 - size2;
	}
	
	else
	{
		while(!s1.isEmpty())
		{
			num1 = s1.pop() - 48;
			num2 = s2.pop() - 48;
			sum = num1 + num2 + carry;
			
			if(sum >= 10)
			{
				carry = 1;
				finalSum.push(sum%10);
			}
			
			else
			{
				carry = 0;
				finalSum.push(sum);
			}
		}
		
		if(carry == 1)
		{
			finalSum.push(carry);
		}
	}
}

int main()
{
	Stack <char>s1; 
	Stack <char>s2;
	
	cout << "Enter first number: ";
	
	char ch;
	
	cin.get(ch);
	
	while(ch != '\n')
	{
		s1.push(ch);
		cin.get(ch);
	}
	
	cout << "Enter second number: ";
	cin.get(ch);
	
	while(ch != '\n')
	{
		s2.push(ch);
		cin.get(ch);
	}
	
	Stack <int>sum;
	
	addingLargeNum(s1, s2, sum);
	
	cout << "Sum is: ";
	sum.print();
} 
