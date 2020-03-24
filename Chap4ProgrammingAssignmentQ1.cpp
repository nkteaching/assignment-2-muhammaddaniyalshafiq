#include <iostream>
using namespace std;

struct Node
{
	char val;
	Node *next, *prev;
	
	Node(char value)
	{
		val = value;
		next = NULL;
		prev = NULL;
	}
};

class Stack
{	
	Node *top = NULL, *back = NULL;
	int size = 0;
	
	public:
		void push(char value)
		{
			if(top == NULL)
			{
				top = new Node(value);
				back = top;
				size++;
			}
			
			else
			{
				back->next = new Node(value);
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
			
			int n;
			
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
			Node *temp = top;
			
			while(top != NULL)
			{
				cout << top->val << " ";
				top = top->next;
			}
			
			top = temp;
		}
		
		int getSize()
		{
			return size;
		}
};

int main()
{
	char ch;
	Stack s;
	
	cin.get(ch);
	
	while(ch!='\n')
	{
		s.push(ch);
		cin.get(ch);
	}
	
	int size = s.getSize();
	
	if(size % 2 == 0)
	{
		Stack s2;
		char temp, temp2;
		
		for(int i = 1;i <= size/2;i++)
		{
			s2.push(s.pop());
		}
		
		int i;
		
		for(i = 1;i <= size/2;i++)
		{
			temp = s.pop();
			temp2 = s2.pop();
			
			if(temp != temp2)
			{
				break;
			}
		}
		
		if(i > size/2)
		{
			cout << "Its palindrome";
		}
		
		else
		{
			cout << "Not palindrome";
		}
	}
	
	else
	{
		Stack s2;
		char temp, temp2;
		
		for(int i = 1;i <= size/2;i++)
		{
			s2.push(s.pop());
		}
		
		int i;
		s.pop();
		
		for(i = 1;i <= size/2;i++)
		{
			temp = s.pop();
			temp2 = s2.pop();
			
			if(temp != temp2)
			{
				break;
			}
		}
		
		if(i > size/2)
		{
			cout << "Its palindrome";
		}
		
		else
		{
			cout << "Not palindrome";
		}
	}
}
