#include <iostream>

using namespace std;

int main() {
  unsigned long long moedas[22];
  unsigned long long solucoes[10001];
  for (int i=0; i<10001; i++)
    solucoes[i] = 0;
  solucoes[0] = 1;

  for (int i=1; i<=21; i++)
    moedas[i] = i*i*i;

  for (int i=1; i<=21; i++) {
    for (unsigned long long j=moedas[i]; j<10002; j++) { 
      if (solucoes[j - moedas[i]])
        solucoes[j] += solucoes[j - moedas[i]];
    }
  }

  unsigned long long n;
  while (cin >> n) {
    cout << solucoes[n] << endl;
  }  

  return 0;
}