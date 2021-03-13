#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> numbers;
	for (int i = 0; i < 7; i++)
	{
		int a; cin >> a;
		numbers.push_back(a);
	}

	sort(numbers.begin(), numbers.end());

	vector<int> answers;
	answers.push_back(numbers[0]);
	answers.push_back(numbers[1]);
	if (numbers[2] == numbers[0] + numbers[1])
	{
		answers.push_back(numbers[3]);
	}
	else
	{
		answers.push_back(numbers[2]);
	}

	cout << answers[0] << " " << answers[1] << " " << answers[2];
}