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
    void detectCycleUtil(T node,map<T,bool>& visited,int& flag){
       if(visited[node]==false && flag==0){
           visited[node]=true;
           for(auto x:um[node])
               detectCycleUtil(x,visited,flag);
           if(flag==0)
               visited[node]=false;
       }
       else
           flag=1;
    }
    void detectCycle(){
        map<T,bool>visited;
        for(auto x:um)
            visited[x.first]=false;
        int flag=0;
        for(auto x:um){
            if(flag==0)
                detectCycleUtil(x.first,visited,flag);
            else
                break;
        }
        if(flag==0)
            cout<<"no cycle detected";
        else{
            cout<<"cycle detected";
        }
    }
};

int main() {
	// your code goes here
	Graph<int>g;
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(5,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,4);
	g.detectCycle();
	return 0;
}