#include <iostream>
#include <stack>

using namespace std;


int main()
{
	int n = 0; 
	stack<int> first, temp;
	int task = 0, number = 0;
	
	cin >> n;

	for (int i = n; i > 0; i--) {
		cin >> task;

		switch (task)
		{
		case 1:
			cin >> number;
			first.push(number);
			break;

		case 2:
			if (temp.size() == 0)
				while (!first.empty())
				{
					temp.push(first.top());
					first.pop();
				}

			temp.pop();
			break;

		case 3:
			if (temp.size() == 0)
				while (!first.empty())
				{
					temp.push(first.top());
					first.pop();
				}
			cout << temp.top() << endl;
		default:
			break;
		}
	}

	return 0;
}