#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Projeto {
  long long inicio, fim, peso;
};

bool comparaProjetos(const Projeto& a, const Projeto& b) {
  return a.fim < b.fim;
}

int main() {
  long long n;
  cin >> n;

  vector<Projeto> projetos(n+1);
  projetos[0].inicio = 0; projetos[0].fim = 0; projetos[0].peso = 0;
  for (int i=1; i<=n; i++)
    cin >> projetos[i].inicio >> projetos[i].fim >> projetos[i].peso;
  sort(projetos.begin(), projetos.end(), comparaProjetos);

  vector<long long> p(n+1);
  p[0] = 0;
  for (long long i=1; i<=n; i++) {
    for (long long j=i-1; j>0; j--) {
      if (projetos[j].fim <= projetos[i].inicio) {
        p[i] = j;
        break;
      }
    }
  }

  vector<long long> pd(n+1);
  pd[0] = 0;
  for (long long i=1; i<=n; i++)
    pd[i] = max(projetos[i].peso + pd[p[i]], pd[i-1]);

  cout << pd[n] << endl;

  return 0;
}
