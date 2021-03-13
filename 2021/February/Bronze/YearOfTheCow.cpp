#include<bits/stdc++.h>
using namespace std;

struct info {
	int order; //-1 or 1, p or n
	int year; 
	string connectedCow;
};
int diff = 0;	
int n;
int main()
{
	cin >> n;
	unordered_map<string, int> calendar;
	calendar["Ox"] = 1;
	calendar["Tiger"] = 2;
	calendar["Rabbit"] = 3;
	calendar["Dragon"] = 4;
	calendar["Snake"] = 5;
	calendar["Horse"] = 6;
	calendar["Goat"] = 7;
	calendar["Monkey"] = 8;
	calendar["Rooster"] = 9;
	calendar["Dog"] = 10;
	calendar["Pig"] = 11;
	calendar["Rat"] = 12;

	string name;
	string waste;
	string order;
	string year;
	string person;
	int sum = 0;

	unordered_map<string, info> infos; // 
	info temp;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> waste >> waste >> order >> year >> waste >> waste >> person;
		if (order.compare("previous") == 0)
		{
			temp.order = -1;
		}
		else {
			temp.order = 1;
		}
		temp.year = calendar[year];
		temp.connectedCow = person;
		infos.insert({ name, temp });
	}
	info currCow = infos["Elsie"];
	vector<string> cowChain;
	cowChain.push_back("Elsie");
	while (currCow.connectedCow.compare("Bessie") != 0)
	{
		cowChain.push_back(currCow.connectedCow);
		currCow = infos[currCow.connectedCow];
	}

	int lastYear = 1;
	for (int i = cowChain.size() - 1; i >= 0; i--)
	{
		if (infos[cowChain[i]].order == -1) // if its previous
		{
			if (lastYear - infos[cowChain[i]].year > 0)
			{
				diff -= lastYear - infos[cowChain[i]].year;

			}
			else
			{
				diff -= lastYear + (12 - infos[cowChain[i]].year);
			}
		}
		else
		{
			if (infos[cowChain[i]].year - lastYear > 0)
			{
				diff += infos[cowChain[i]].year - lastYear;
			}
			else
			{
				diff += (12 - lastYear) + infos[cowChain[i]].year;
			}
		}

		lastYear = infos[cowChain[i]].year;
	}
	
	cout << abs(diff);
}