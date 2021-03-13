#include<bits/stdc++.h>
using namespace std;

struct particle {
	int x;
	int y;
};

bool sortParticles(particle a, particle b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main()
{
	int n; cin >> n;
	vector<particle> particles;
	for (int i = 0; i < n; i++)
	{
		particle temp;
		cin >> temp.x >> temp.y;
		particles.push_back(temp);
	
	}

	sort(particles.begin(), particles.end(), sortParticles);
	
	int topXBound = particles[n - 1].x;
	int botXbound = particles[0].x;

	//y bound of top x;
	int topYBound = particles[n - 1].y;

	int pleft = 1;
	for (int i = 0; i < n; i++)
	{
		if (particles[i].x < topXBound)
		{
			if (particles[i].y > topYBound)
			{
				pleft++;
			}
		}
	}

	cout << pleft;
}