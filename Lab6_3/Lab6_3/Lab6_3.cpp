#include <iostream>
#include <queue>



int main()
{
	std::queue <int> q;
	int n,k=2,t;
	std::cin >> n;
	while (q.size()<n)
	{
		t = k;//сделать через три очереди апмсер снизу
		while (t % 2 == 0)
		{
			t = t / 2;
		}
		while (t % 3 == 0)
		{
			t = t / 3;
		}
		while (t % 5 == 0)
		{
			t = t / 5;
		}
		if (t==1)
		{
			q.push(k); std::cout << k;
		}
		k++;
	}

	/*	q2  *	*	12	24
		q3	*	6	18	
		q5	5	10	30
		res	2	3	4

		*/
	for (int i = 0; i < n; i++)
	{
		std::cout << q.front()<<" "; q.pop();
	}
}