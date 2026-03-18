#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,c;
  cout<<"Enter no of rows and no of columns:";
  cin>>r>>c;
  vector<vector<int>> data(r, vector<int>(c));
  int total=0;
  
  cout<<"Enter data:";
  for(int i=0; i<r; i++){
     for(int j=0; j<c; j++){
        cin>>data[i][j];
        total+=data[i][j];
        total=total%2;
     }
  }



 int row_cnt=0, col_cnt=0;
 for(int i=0; i<r; i++){
     row_cnt=0;
     for(int j=0; j<c; j++){
        if(data[i][j] == 1) row_cnt++;
     }
     if(row_cnt % 2 == 0) data[i].push_back(0);
     else data[i].push_back(1);
  }
  
  
  vector<int> last_row(c+1, 0);
  for(int i=0; i<c; i++){
     col_cnt=0;
     for(int j=0; j<r; j++){
        if(data[j][i] == 1) col_cnt++;
     }
      
     if(col_cnt % 2 == 0) {
       last_row[i] = 0;
     }
     else last_row[i] = 1;
  }
   
  data.push_back(last_row);
  
  data[r][c]=total;
  
  cout<<"Data with parity bit:"<<endl;
  for(int i=0; i<=r; i++){
     for(int j=0; j<=c; j++){
        cout<<data[i][j]<<" ";
     }
     cout<<endl;
  }
  cout<<endl;


return 0;
}
