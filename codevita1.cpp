#include <iostream>
#include <vector>
#include <climits>

using namespace std;
struct Race
{
    int x, y, day;
};
int N;
vector<Race> races;
vector<vector<int>> graph;
vector<int> matchRight;
vector<bool> visited;
bool canMatch(int u)
{
    for (int v : graph[u])
    {
        if (visited[v])
            continue;
        visited[v] = true;
        if (matchRight[v] == -1 || canMatch(matchRight[v]))
        {
            matchRight[v] = u;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> N;
    races.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> races[i].x >> races[i].y >> races[i].day;
    }
    sort(races.begin(), races.end(), [](const Race &a, const Race &b)
         { return a.day < b.day; });
    graph.assign(N, {});
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int dist = abs(races[i].x - races[j].x) + abs(races[i].y - races[j].y);
            if (races[j].day - races[i].day >= dist)
            {
                graph[i].push_back(j);
            }
        }
    }
    matchRight.assign(N, -1);
    int maxMatching = 0;

    for (int i = 0; i < N; i++)
    {
        visited.assign(N, false);
        if (canMatch(i))
        {
            maxMatching++;
        }
    }
    int minCars = N - maxMatching;
    cout << minCars << endl;

    return 0;
}