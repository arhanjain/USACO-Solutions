#include<bits/stdc++.h>
#include<set>
using namespace std;

int n;



int main()
{
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);

	cin >> n;

	int fencePosts[n][2];

	for (int i = 0; i < n; i++)
	{
		cin >> fencePosts[i][0];
		cin >> fencePosts[i][1];
	}

	int sameX[n][2];
	int sameY[n][2];

	int xRow = 0;
	int yRow = 0;

	//finding same X points
	std::set<int> alreadyDoneX;
	for (int i = 0; i < n; i++)
	{
		if (alreadyDoneX.count(fencePosts[i][0]) == 0)
		{
			alreadyDoneX.insert(fencePosts[i][0]);
			for (int j = i + 1; j < n; j++)
			{
				if (fencePosts[i][0] == fencePosts[j][0])
				{
					if (j = i + 1)
					{
						sameX[xRow][0] = fencePosts[i][0];
						sameX[xRow][1] = fencePosts[i][1];
						xRow++;
					}

					sameX[xRow][0] = fencePosts[j][0];
					sameX[xRow][1] = fencePosts[j][1];
					xRow++;
				}
			}
		}	
	}

	//finding same Y points
	std::set<int> alreadyDoneY;
	for (int i = 0; i < n; i++)
	{
		if (alreadyDoneY.count(fencePosts[i][1]) == 0)
		{
			alreadyDoneY.insert(fencePosts[i][1]);
			for (int j = i + 1; j < n; j++)
			{
				if (fencePosts[i][1] == fencePosts[j][1])
				{
					if (j = i + 1)
					{
						sameY[yRow][0] = fencePosts[i][0];
						sameY[yRow][1] = fencePosts[i][1];
						yRow++;
					}

					sameY[yRow][0] = fencePosts[j][0];
					sameY[yRow][1] = fencePosts[j][1];
					yRow++;
				}
			}
		}
	}

	for (int i = 0; i <n ; i++)
	{
		cout << sameY[i][0];
		cout << sameY[i][1];
		cout << "\n";
	}
}

