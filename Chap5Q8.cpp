#include <iostream> 
using namespace std; 
  
int product(int x, int y) 
{ 
   if(x == 1)
   {
   		return y;
   }
   
   else
   {
   		return y + product(x-1, y);
   }
} 

int main() 
{ 
    int x, y; 
    
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    
    cout << product(x, y);
}
