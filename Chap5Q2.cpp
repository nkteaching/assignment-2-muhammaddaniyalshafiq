#include<iostream>
#include<stdlib.h> 
using namespace std;

struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  

void push(struct Node** head, int new_data) 
{ 

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  

    new_node->data  = new_data; 
  

    new_node->next = (*head); 
  
    
    (*head) = new_node; 
} 
  

int count(struct Node* head) 
{ 
    
    if (head == NULL) 
        return 0; 
  
    
    return 1 + count(head->next); 
} 
  

int main() 
{ 
  	struct Node* head = NULL;
  	int num, choice;
  	
  	while(true)
	{
		cout << "1. Insert value\n2. Print length of linklist\n3. exit\nWhat operation do you want to perform?\n";
		
		cin >> choice;
		
		if(choice == 1)
		{
			cout << "Enter value: ";
			cin >> num;
			push(&head, num);
			
			system("cls");
		}
		
		else if(choice == 2)
		{
			cout << "Length of linklist: " << count(head) << endl;
		}
		
		else
		{
			break;
		}
	}
}
