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
	Node *top = NULL, *back = NULL;
	
	public:
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

void reverse(Stack &s)
{
	Stack s1, s2;
	
	while(!s.isEmpty())
	{
		s1.push(s.pop());
	}
	
	while(!s1.isEmpty())
	{
		s2.push(s1.pop());
	}
	
	while(!s2.isEmpty())
	{
		s.push(s2.pop());
	}
}

int main()
{
	Stack s;
	
	int num, choice;
	
	while(true)
	{
		cout << "1. Insert value\n2. Reverse stack\n3. Print stack\n4. exit\nWhat operation do you want to perform?\n";
		
		cin >> choice;
		
		if(choice == 1)
		{
			cout << "Enter value: ";
			cin >> num;
			s.push(num);
			
			system("cls");
		}
		
		else if(choice == 2)
		{
			reverse(s);
			system("cls");
		}
		
		else if(choice == 3)
		{
			s.print();
			cout << endl;
		}
		
		else
		{
			break;
		}
	}
} 
