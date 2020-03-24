#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *next, *prev;
	
	Node(int value)
	{
		val = value;
		next = NULL;
		prev = NULL;
	}
};

class Stack
{	
	public:
		Node *top = NULL, *back = NULL;
		
		void push(int value)
		{
			if(top == NULL)
			{
				top = new Node(value);
				back = top;
			}
			
			else
			{
				back->next = new Node(value);
				back->next->prev = back;
				back = back->next;
			}
		}
		
		int pop()
		{
			if(top == NULL)
			{
				cout << "Stack is empty";
				
				return -1;
			}
			
			int n;
			
			if(back != top)
			{
				n = back->val;
				back = back->prev;
				delete back->next;
				
				return n;
			}
			
			else
			{
				n = back->val;
				delete back;
				top = NULL;
				
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
			Node *temp = top;
			
			while(top != NULL)
			{
				cout << top->val << " ";
				top = top->next;
			}
			
			top = temp;
		}
};

void transfer(Stack &s1, Stack &s2) // reverse using only one stack and non-array variables
{
	Stack s;
	
	while(!s1.isEmpty())
	{
		s.push(s1.pop());
	}
	
	int n;
		
	while(!s.isEmpty())
	{
		n = s.pop();
		s1.push(n);
		s2.push(n);
	}
}

int main()
{
	Stack s1, s2;
	
	int num, choice;
	
	cout << "For stack 1:\n\n";
	
	while(true)
	{
		cout << "1. Insert value\n2. Transfer to stack 2\n3. Print stack 1\n4. Print stack 2\n5. exit\nWhat operation do you want to perform?\n";
		
		cin >> choice;
		
		if(choice == 1)
		{
			cout << "Enter value: ";
			cin >> num;
			s1.push(num);
			
			system("cls");
		}
		
		else if(choice == 2)
		{
			transfer(s1, s2);
			system("cls");
		}
		
		else if(choice == 3)
		{
			s1.print();
			cout << endl;
		}
		
		else if(choice == 4)
		{
			s2.print();
			cout << endl;
		}
		
		else
		{
			break;
		}
	}
}
