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

class Queue
{
	Node *top = NULL, *back = NULL;
	
	public:
		void enqueue(int value)
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
		
		int dequeue()
		{
			if(back == NULL)
			{
				cout << "Stack is empty";
				
				return -1;
			}
			
			int n;
			
			if(top != back)
			{
				n = top->val;
				top = top->next;
				delete top->prev;
				top->prev = NULL;
				
				return n;
			}
			
			else
			{
				n = back->val;
				delete back;
				back = NULL;
				
				return n;
			}
		}
		
		bool isEmpty()
		{
			if(back == NULL)
			{
				return true;
			}
			
			else
			{
				return false;
			}
		}
		
		Node* getTop()
		{
			return top;
		}
};

class Stack // stack implemented in terms of queue made above
{
	Node *top = NULL, *back = NULL;
	Queue q;
		
	public:
		void push(int value)
		{
			q.enqueue(value);
		}
		
		int pop()
		{
			q.dequeue();
		}
		
		bool isEmpty()
		{
			return q.isEmpty();
		}
		
		void print()
		{
			Node *temp = q.getTop();
			
			while(temp != NULL)
			{
				cout << temp->val << " ";
				temp = temp->next;
			}
			
		}
};

int main()
{
	Stack s;
	
	int num, choice;
	
	while(true)
	{
		cout << "1. Insert value\n2. Print stack\n3. exit\nWhat operation do you want to perform?\n";
		
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
			s.print();
			cout << endl;
		}
		
		else
		{
			break;
		}
	}
}
