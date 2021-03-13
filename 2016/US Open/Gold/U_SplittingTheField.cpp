#include<bits/stdc++.h>
using namespace std;

struct cow {
	int x;
	int y;
};

bool cowYSort(cow a, cow b)
{
	return a.y < b.y;
}

bool cowXSort(cow a, cow b)
{
	return a.x < b.x;
}

vector<cow> cowsY;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a; int b;
		cin >> a >> b;

		cow temp;
		temp.x = a;
		temp.y = b;

		cowsY.push_back(temp);
	}
	
	vector<cow> cowsX = cowsY;
	sort (cowsX.begin(), cowsX.end(), cowXSort);
	sort(cowsY.begin(), cowsY.end(), cowYSort);

	//One Pen
	int x1 = cowsX[0].x;
	int x2 = cowsX[n - 1].x;
	int y1 = cowsY[0].y;
	int y2 = cowsY[n - 1].y;

	int onePen = (x2 - x1) * (y2 - y1);

	//Two Pens
	int areaEnclosed = 0;
	for (int j = 0; j < n-1; j++)
	{
		int currArea = 0;
		//Bottom Cow
		int lowestx1 = -1;
		int lowestx2 = -1;
		for (int i = 0; i < n; i++)
		{
			if (cowsX[i].y <= cowsY[j].y and lowestx1 == -1)
			{
				lowestx1 = cowsX[i].y;
			}
			if (cowsX[n-1 - i].y <= cowsY[i].y and lowestx2 == -1)
			{
				lowestx2 = cowsX[i].y;
			}
			if(lowestx1!=-1 and lowestx2!=-1) break;
		}
		currArea += (cowsY[j].y - cowsY[0].y) * (lowestx2 - lowestx1);
			 
		//Top Cow
		lowestx1 = -1;
		lowestx2 = -1;
		for (int i = 0; i < n; i++)
		{
			if (cowsX[i].y >= cowsY[j+1].y and lowestx1 == -1)
			{
				lowestx1 = cowsX[i].y;
			}
			if (cowsX[n - 1 - i].y >= cowsY[j+1].y and lowestx2 == -1)
			{
				lowestx2 = cowsX[i].y;
			}
			if (lowestx1 != -1 and lowestx2 != -1) break;
		}
		currArea += (cowsY[j+1].y - cowsY[n-1].y) * (lowestx2 - lowestx1);

		if (currArea > areaEnclosed)
		{
			areaEnclosed = currArea;
		}
	}

	cout << onePen - areaEnclosed;
}