#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    unordered_map<string,vector<pair<string,int>>>um;
    
    void addEdge(string a,string b,int cost){
        um[a].push_back(make_pair(b,cost));
        //since graph is bidirectional//
        um[b].push_back(make_pair(a,cost));
    }
    
    void djikistraSSSP(string src){
        // set all distances to infinity //
        unordered_map<string,int>dist;
        unordered_map<string,vector<string>>path;
        for(auto city:um)
            dist[city.first]=INT_MAX;
            
        // make a set to select the node with minimum distance //
        set<pair<int,string>>grejik;
        grejik.insert(make_pair(0,src));
        dist[src]=0;
        
        while(!grejik.empty()){
            //pop out first pair in set//
            auto p=*(grejik.begin());
            //current city//
            string city=p.second;
            //current distance//
            int shDist=p.first;
            
            grejik.erase(grejik.begin());
            
            // iterate over neighbours of current city//
            for(auto nbr:um[city]){
                int nbrcost=nbr.second;
                if(shDist+nbrcost<dist[nbr.first]){
                    int newDist=shDist+nbrcost;
                    string dest=nbr.first;
                    auto f=grejik.find(make_pair(dist[dest],dest));
                    if(f!=grejik.end())
                        grejik.erase(f);
                    dist[dest]=newDist;
                    path[dest].clear();
                    path[dest].insert(path[dest].end(),city);
                    for(int i=0;i<path[city].size();i++)
                        path[dest].insert(path[dest].end(),path[city][i]);
                    grejik.insert(make_pair(newDist,dest));
                }
            }
        }
        //printing shortest distances//
        for(auto city:dist){
                cout<<"Amritsar->";
                cout<<city.first<<" "<<city.second<<"kms"<<endl;
        }
        cout<<endl;
        //printing shortest paths//
        for(auto city:path){
                cout<<city.first<<"<--";
                for(auto s:city.second)
                    cout<<s<<" ";
                cout<<endl;
        }
    }
    
    void printMap(){
        for(auto city:um){
            cout<<city.first<<"->";
            for(auto conn:um[city.first]){
                cout<<conn.first<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
	// your code goes here
	Graph India;
	India.addEdge("Amritsar","Delhi",1);
	India.addEdge("Delhi","Agra",1);
	India.addEdge("Agra","Bhopal",2);
	India.addEdge("Bhopal","Mumbai",3);
	India.addEdge("Mumbai","Jaipur",8);
	India.addEdge("Jaipur","Delhi",2);
	India.addEdge("Jaipur","Amritsar",4);
	India.djikistraSSSP("Amritsar");
}
