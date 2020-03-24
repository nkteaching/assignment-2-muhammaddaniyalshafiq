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

void sortInAscending(Stack &s) // sort stack in ascending order using additional stack and non-array variabbles
{
	Stack s1;
	
	while(!s.isEmpty())
	{
		s1.push(s.pop());
	}
	
	Node *temp = s1.top;
	Node *temp2 = temp;
		
	while(temp!=NULL)
	{
		while(temp2->next!=NULL)
		{
			if(temp2->val < temp2->next->val)
			{
				swap(temp2->val, temp2->next->val);
			}
						
			temp2 = temp2->next;
		}
		
		temp = temp->next;
		temp2 = s1.top;
	}
	
	while(!s1.isEmpty())
	{
		s.push(s1.pop());
	}
}

int main()
{
	Stack s;
	
	int num, choice;
	
	while(true)
	{
		cout << "1. Insert value\n2. Sort stack in ascending order\n3. Print stack\n4. exit\nWhat operation do you want to perform?\n";
		
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
			sortInAscending(s);
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
