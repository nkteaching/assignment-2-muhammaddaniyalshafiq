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
	public:
		Node<T> *top = NULL, *back = NULL;
	
		void push(T value)
		{
			if(top == NULL)
			{
				top = new Node<T>(value);
				back = top;
			}
			
			else
			{
				back->next = new Node<T>(value);
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
			Node<T> *temp = top;
			
			while(top != NULL)
			{
				cout << top->val << " ";
				top = top->next;
			}
			
			top = temp;
		}
};

struct MyStruct
{
	int a, b;
	int arr[20];
	
	MyStruct()
	{
		a = 0;
		b = 0;
		
		arr[20] = {0};
	}
};

int main()
{
	Stack<int> s1;
	Stack<MyStruct> s2;
}
