#include <bits/stdc++.h>
using namespace std;

class solution{
  public:
    vector<int> bellman(int v, int e, vector<vector<int>>& edge, int s){
    	vector<int> dist(v, 1e8);
    	dist[s]=0;
    	
    	for(int i=0; i < v-1; i++){
    	  for(int j=0; j<e; j++){
    	     int u = edge[j][0];
    	     int v = edge[j][1];
    	     int wt = edge[j][2];
    	    
    	     if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
    	         dist[v] = dist[u] + wt;
    	     }
    	   } 
    	  }
    	  
    	   for(int j=0; j<e; j++){
    	     int u = edge[j][0];
    	     int v = edge[j][1];
    	     int wt = edge[j][2];
    	    
    	     if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
    	         cout<< "Negative cycle detected";
    	         return {};
    	     }
    	   }
    	  
        return dist;
    }
};


int main(){

  int v,e,s;
  cout<<"Enter no of vertices, edges and source:";
  cin>>v>>e>>s;
  vector<vector<int>> edge(e, vector<int>(3));
  cout<<"Enter u, v, w:\n";
  for(int i=0; i < e; i++){
  	cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
  }
  
  solution obj;
  vector<int> dist = obj.bellman(v, e, edge, s);
  
 
    if (!dist.empty()) {
        cout << "Shortest distances from source to all other vertices:\n";
        for (int i = 0; i < v; i++) {
            if (dist[i] == 1e8)
                cout << "Path not exist";  
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }
  
return 0;
}
