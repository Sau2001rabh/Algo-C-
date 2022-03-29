/*Given n nodes of forest (collection of trees), find the number of trees in the forest.
Example:
    Input :  edges[] = {0, 1}, {0, 2}, {3, 4}
    Output : 2
    Explanation : There are 2 trees
                   0       3
                  / \       \
                 1   2       4
*/

#include <iostream>
#include <vector>
using namespace std;

//functio  to add edge in graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//traversing nodes
void dfsUtils(int u, vector<int>adj[], vector<bool>&visited)
{
    visited[u]=true;
    for(int k=0; k<adj[u].size(); k++)
    {
        if(visited[adj[u][k]]==false)
        {
            dfsUtils(adj[u][k], adj, visited);
        }
    }
}

//dfs modification
int countTrees(vector<int>adj[], int V)
{
    vector<bool> visited(V, false);
    int ans=0;
    
    for(int u=0; u<V; u++)
    {
        if(visited[u]==false)
        {
            dfsUtils(u, adj, visited);
            ans++;
        }
    }
    return ans;
}


int main() {
	int V=5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 3, 4);
	
	cout << countTrees(adj, V) << endl;
	return 0;
}
