#include <bits/stdc++.h>
using namespace std;

template<class T>
class Graph{
    map<T,vector<T>>um;
public:
    void addEdge(T x,T y){
        um[x].push_back(y);
        um[y].push_back(x);
    }
    void bfs(T src){
        map<T,bool>visited;
        queue<T>Q;
        Q.push(src);
        visited[src]=true;
        while(!Q.empty()){
            T f=Q.front();
            Q.pop();
            cout<<f<<" ";
            for(auto x:um[f]){
                if(visited[x]==false)
                    Q.push(x);
                    visited[x]=true;
            }
        }
    }
};

int main() {
	// your code goes here
	Graph<char>g;
	g.addEdge('A','B');
	g.addEdge('A','D');
	g.addEdge('A','C');
	g.addEdge('C','D');
	g.addEdge('E','D');
	g.addEdge('E','F');
	g.bfs('A');
	return 0;
}
