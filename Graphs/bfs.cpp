#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<bool> visited; // vistied track
vector<vector<int> > adj; // Adjecency List

void edge(int a, int b)
{
	adj[a].pb(b);  //  Made it for Directed graph

}

void bfs(int u)
{
	queue<int> q;  //queue


	q.push(u);
	visited[u] = true;

	while (!q.empty()) {

		int f = q.front();
		q.pop();

		cout << f << " ";

		// Enqueue all adjacent of f and mark them visited
		for (auto i = adj[f].begin(); i != adj[f].end(); i++) {
			if (!visited[*i]) {
				q.push(*i);
				visited[*i] = true;
			}
		}
	}
}

/*
      0
    /   \
  2   -  3
   \    /   \
      1     4
*/

int main()
{
	int n, e;
  cout<<"Enter Vertices and Edges: ";
	cin >> n >> e;

	visited.assign(n, false);
	adj.assign(n, vector<int>());

  cout<<"Enter U -> V: "<<endl;
	int a, b;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		edge(a, b);
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i])
			bfs(i);
	}

	return 0;
}
