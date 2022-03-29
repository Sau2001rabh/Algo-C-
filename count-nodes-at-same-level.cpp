/*Given a tree represented as undirected graph. Count the number of nodes at given level l. It may be asssumed that vertex 0 is the root of the tree.*/

#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
  // adjacency list representation of graph
    list<int>* adj;
    
    public:
    Graph(int V);
    void addEdge(int u, int v);
    int countNode(int s, int l);
};


Graph :: Graph(int V)
{
    this->V=V;
    adj=new list<int> [V];
}

//add the edges
void Graph:: addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


//returns count of nodes at level l from given source s using BFS
int Graph :: countNode(int s, int l)
{
    bool* visited = new bool[V];
    int level[V];
    
    for(int i=0; i<V; i++)
    {
        visited[i]=false;
        level[i]=0;
    }
    
    list<int>queue;
    
    visited[s]=true;
    queue.push_back(s);
    level[s]=0;
    
    while(!queue.empty())
    {
        s=queue.front();
        queue.pop_front();
        
        for(auto it=adj[s].begin(); it!=adj[s].end(); it++)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                level[*it]=level[s]+1;
                queue.push_back(*it);
            }
        }
    }
    int count=0;
    for(int i=0; i<V; i++)
    {
        if(level[i]==l) count++;
    }
    return count;
}

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    
    int level=2;
    cout << g.countNode(0, level) <<endl;
    
    return 0;
}


/*
output : 3
*/
