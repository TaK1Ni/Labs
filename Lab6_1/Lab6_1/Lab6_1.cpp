#include <iostream>
#include <stack>

bool stk(char* arr)
{
	std::stack <char> st;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == '[' or arr[i] == '{' or arr[i] == '(')
		{
			st.push(arr[i]);
		}
		else if (st.empty() and (arr[i] == ']' or arr[i] == '}' or arr[i] == ')'))
		{
			return false;
		}
		else if (arr[i] == ']' or arr[i] == '}' or arr[i] == ')')
		{
			if (st.top() == '[' and arr[i] == ']')
			{
				st.pop();
			}
			else if (st.top() == '(' and arr[i] == ')')
			{
				st.pop();
			}
			else if (st.top() == '{' and arr[i] == '}')
			{
				st.pop();
			}
		}
	}
	if (st.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char arr[1024];
	std::cin.getline(arr, 1024, ';');
	if (stk(arr))
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
}