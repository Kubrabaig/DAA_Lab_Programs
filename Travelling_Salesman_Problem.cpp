#include <iostream>
#include <climits>
using namespace std;

#define N 4

int tsp(int graph[N][N], bool visited[], int curr, int count, int cost, int ans)
{
    if (count == N && graph[curr][0]) {
        ans = min(ans, cost + graph[curr][0]);
        return ans;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && graph[curr][i]) {
            visited[i] = true;
            ans = tsp(graph, visited, i, count + 1,
                      cost + graph[curr][i], ans);
            visited[i] = false;
        }
    }
    return ans;
}

int main()
{
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    bool visited[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    visited[0] = true;

    int ans = INT_MAX;

    cout << "Minimum travelling cost = "
         << tsp(graph, visited, 0, 1, 0, ans);

    return 0;
}