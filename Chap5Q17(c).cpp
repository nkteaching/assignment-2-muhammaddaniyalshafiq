#include<iostream>
using namespace std;

void check(int a, string s, char ch)
{
	if(a == s.size())
	{
	   for(int k = 0;k < s.size();k++)
	   {
	   	    cout << s[k];
	   }	
	}
	
	else
	{
		if(s[a] == ch)
		{
			s[a] =* ("");
			a++;
		}
		
		else
		{
			a++;	
		}
		
		return check(a, s, ch);
	}
}

int main()
{
	string s;
	char c;
	
	cout << "Enter word:";
	cin >> s;
	cout << "Enter character you want to delete:";
	cin >> c;
	
	check(0, s, c);
}
