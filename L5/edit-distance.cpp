#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string pal1, pal2;
  cin >> pal1 >> pal2;

  vector<vector<int>> pd(pal1.size()+1, vector<int>(pal2.size()+1));
  for (int i=0; i<=pal1.size(); i++)
    pd[i][0] = i;
  for (int j=0; j<=pal2.size(); j++)
    pd[0][j] = j;

  for (int i=1; i<=pal1.size(); i++) {
    for (int j=1; j<=pal2.size(); j++) {
      if (pal1[i-1] == pal2[j-1])
        pd[i][j] = pd[i-1][j-1];
      else
        pd[i][j] = 1 + min(min(pd[i-1][j-1],pd[i][j-1]),pd[i-1][j]);
    }
  }
  
  cout << pd[pal1.size()][pal2.size()];

  return 0;
}