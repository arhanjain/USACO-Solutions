#include<bits/stdc++.h>

using namespace std;

int N = 0;
vector<vector<int>> switches;


int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    
    cin >> N;
    vector<int> temp{0, 0, 0};
    int temporary = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> temp[0] >> temp[1] >> temp[2];
        switches.push_back(temp);
    }
    
    int startOne = 0;
    int startTwo = 0;
    int startThree = 0;
    
    int pos = 1;
    
    for(int i = 0; i<N; i++)
    {
        if(switches[i][0] == pos)
        {
            pos = switches[i][1];
        }
        else if(switches[i][1] == pos)
        {
            pos = switches[i][0];
        }
        
        if(pos == switches[i][2])
        {
            startOne++;
        }
    }
    
    pos = 2;
    
    for(int i = 0; i<N; i++)
    {
        if(switches[i][0] == pos)
        {
            pos = switches[i][1];
        }
        else if(switches[i][1] == pos)
        {
            pos = switches[i][0];
        }
        
        if(pos == switches[i][2])
        {
            startTwo++;
        }
    }
    
    pos = 3;
    
    for(int i = 0; i<N; i++)
    {
        if(switches[i][0] == pos)
        {
            pos = switches[i][1];
        }
        else if(switches[i][1] == pos)
        {
            pos = switches[i][0];
        }
        
        if(pos == switches[i][2])
        {
            startThree++;
        }
    }
    
    vector<int> useless;
    useless.push_back(startOne);
    useless.push_back(startTwo);
    useless.push_back(startThree);

    int max = 0;
    for(int i =0; i < 3; i++)
    {
        if(i==0 || max<useless[i])
        {
            max = useless[i];
        }
    }
    
    cout << max;
    return 0;
}
