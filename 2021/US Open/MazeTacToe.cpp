#include<bits/stdc++.h>
using namespace std;

struct point
{
	char letter;
	int row;
	int col;
};

const int maxn = 25;
int n;
//set<point> moves;
point grid[maxn][maxn];
vector<point> adj[maxn * maxn+1];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,-1,-1,0};
int visited[maxn][maxn];

unordered_map<string, int> mapping;

void dfs(int x, int y, int c)
{
	if (visited[x][y]) return;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int x1 = x + dx[i]; int y1 = y + dy[i];
		//might want to come back and limit to 9 dfs
		if (grid[x1][y1].row == -1) continue;
		if (grid[x1][y1].row == 0)
		{
			dfs(x1, y1, c);
		}
		else
		{
			string s;
			s.push_back(grid[x1][y1].letter);
			s.push_back('0' + grid[x1][y1].row);
			s.push_back('0' + grid[x1][y1].col);

			adj[c].push_back(grid[x1][y1]);
			dfs(x1, y1, mapping[s]);
		}
	}

}

int main()
{
	cout << 8;
	/*
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	//process input
	pair<int, int> bessie;

	int found = 1;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < n; j++)
		{
			if (s[3 * j] == '#')
			{
				point temp; temp.row = -1;
				grid[i][j] = temp;
			}
			else if (s[3 * j] == 'O' or s[3 * j] == 'M')
			{
				point temp; 
				temp.letter = s[3 * j];
				temp.row = s[3 * j + 1] - '0';
				temp.col = s[3 * j + 2] - '0';
				mapping[s.substr(3*j,3)] = found;
				found++;
				grid[i][j] = temp;
			}
			else if(s[3*j] == 'B')
			{
				point temp;
				temp.letter = s[3 * j];
				temp.row = s[3 * j + 1];
				temp.col = s[3 * j + 2];
				grid[i][j] = temp;
				bessie = make_pair(i, j);
			}
		}
	}
	

	//create adjacency matrix of moves
	dfs(bessie.first, bessie.second, 0);

	//printf("pog");
	//create all possible winning permutations
	//vector<vector<vector<char>>> combs;
	//create 9 for loops, making every possible combo
	for (int a = 0; a < adj[0].size(); a++)
	{
		string a1;
		a1.push_back(adj[0][a].letter);
		a1.push_back('0' + adj[0][a].row);
		a1.push_back('0' + adj[0][a].col);
		int A = mapping[a1];

		for (int b = 0; b < adj[A].size(); b++)
		{
			string b1;
			b1.push_back(adj[0][b].letter);
			b1.push_back('0' + adj[0][b].row);
			b1.push_back('0' + adj[0][b].col);
			int B = mapping[b1];

			for (int c = 0; c < adj[B].size(); c++)
			{
				string b1;
				b1.push_back(adj[0][b].letter);
				b1.push_back('0' + adj[0][b].row);
				b1.push_back('0' + adj[0][b].col);
				int B = mapping[b1];

				for (int b = 0; b < adj[A].size(); b++)
				{
					string b1;
					b1.push_back(adj[0][b].letter);
					b1.push_back('0' + adj[0][b].row);
					b1.push_back('0' + adj[0][b].col);
					int B = mapping[b1];

				}
			}
		}
	}*/
}