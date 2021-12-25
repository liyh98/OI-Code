#include <iostream>
#include <vector>
using namespace std;

int N, K, V[3005];
int DP[3005][3005], P[3005], C[3005];
vector<pair<int, int> > adjList[3005];

void root(int node, int parent) {
    for (auto E: adjList[node]) if (E.first != parent) {
        P[E.first] = node;
        C[E.first] = E.second;
        root(E.first, node);
    }
}

void dfs(int node, int parent) {
    for (int a = C[node]; a <= K; ++a)
        DP[node][a] = DP[P[node]][a - C[node]] + V[node];
    for (auto E: adjList[node]) if (E.first != parent)
        dfs(E.first, node);
    for (int a = 0; a <= K; ++a)
        DP[P[node]][a] = max(DP[P[node]][a], DP[node][a]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int a = 0; a < N; ++a) cin >> V[a];
    int N1, N2, E;
    for (int a = 0; a < N - 1; ++a) {
        cin >> N1 >> N2 >> E;
        adjList[N1].emplace_back(N2, E);
        adjList[N2].emplace_back(N1, E);
    }
    // Root
    root(0, -1);
    // Knapsack
    for (int a = 0; a <= K; ++a) DP[0][a] = V[0];
    for (auto E: adjList[0]) dfs(E.first, 0);
    cout << DP[0][K] << "\n";
    return 0;
}