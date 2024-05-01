#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define SIZE 26

int Time[SIZE][SIZE][SIZE];
int visited[SIZE][SIZE][SIZE];

const int FORBIDDEN = -1;
const int NOT_VISITED = 0;
const int VISITED = 1;

int X[] = {0, 0, 1, 0, 0, -1};
int Y[] = {0, 1, 0, 0, -1, 0};
int Z[] = {1, 0, 0, -1, 0, 0};

struct point
{
    int x;
    int y;
    int z;

    point() {}
    point(int x, int y, int z) : x(x), y(y), z(z) {}
};

int main()
{
    int tc;
    scanf("%d", &tc);

    for (int t = 1; t <= tc; t++)
    {
        string str1, str2, s1, s2, s3;
        int n; // Added initialization for n
        cin >> str1 >> str2 >> n;
        memset(visited, 0, sizeof visited);

        for (int m = 0; m < n; m++)
        {
            cin >> s1 >> s2 >> s3;

            for (int i = 0; i < s1.length(); i++)
                for (int j = 0; j < s2.length(); j++)
                    for (int k = 0; k < s3.length(); k++)
                        visited[s1[i]-'a'][s2[j]-'a'][s3[k]-'a'] = FORBIDDEN;
        }

        if (visited[str1[0]-'a'][str1[1]-'a'][str1[2]-'a'] == FORBIDDEN)
        {
            printf("Case %d: %d\n", t, -1);
            continue;
        }
        Time[str1[0]-'a'][str1[1]-'a'][str1[2]-'a'] = 0;

        queue<point> q;
        q.push(point(str1[0]-'a', str1[1]-'a', str1[2]-'a'));
        bool flag = true;
        while (!q.empty() && flag)
        {
            point p = q.front();
            q.pop();

            if (p.x == str2[0]-'a' && p.y == str2[1]-'a' && p.z == str2[2]-'a')
            {
                flag = false;
                break;
            }

            for (int m = 0; m < 6; m++)
            {
                int a = (p.x + X[m]) % 26;
                int b = (p.y + Y[m]) % 26;
                int c = (p.z + Z[m]) % 26;

                if (a < 0) a += 26;
                if (b < 0) b += 26;
                if (c < 0) c += 26;

                if (visited[a][b][c] == NOT_VISITED)
                {
                    visited[a][b][c] = VISITED;
                    Time[a][b][c] = Time[p.x][p.y][p.z] + 1;
                    q.push(point(a, b, c));
                }
            }
        }

        if (!flag) printf("Case %d: %d\n", t, Time[str2[0]-'a'][str2[1]-'a'][str2[2]-'a']); // Corrected access to Time array
        else printf("Case %d: %d\n", t, -1);
    }
    return 0;
}
