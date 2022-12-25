// primeira versão estática de solução do problema com limite de 1000 elementos.
#include <bits/stdc++.h> 
#define _ ios_base::sync_with_stdio(0); // uso de macro para reduzir o tempo de execução.

using namespace std;

int main(){_ 
   int i,n,pos; //declaração das variáveis. A variável 'i' é o índice do loop, 
                //a variável 'n' é a qtd de elementos do vetor, a variável 'pos' é a posição que será usada nos vetores 'A' e 'B'
                // no momento de virar(setar em '1') as cartas.  
   int P[1001],A[1001] = {},B[1001] = {};
      // os vetores 'A' e 'B' serão usados como cartas viradas para baixo, sendo indicadas pelo valor 0.
      // o vet
   cin >> n; // leitura da qtd de elementos a serem lidos pelo vetor.
   cin.ignore(); 
   if(n%2==1){    // o número de elementos tem que ser par.
   for(i=0;i<n;i++){
        cin >> P[i];
        pos = P[i];
        if(A[pos] == 0){
           A[pos] = 1; // Virou a primeira carta.
        }
        else{
             if(B[pos] == 0)
                B[pos] = 1; // Virou a carta 'par' correspondente.
        }
   }
   for(i=0;i<n;i++){
      pos = P[i];
      if(B[pos] == 0){  // Verificando a existência de uma carta sem seu 'par'.
         cout << P[i] << endl; // Saída com a carta sem seu 'par'.
         return 0;
      }
   }
   }
   else{
      cout << "necessario numero impar de elementos" << endl;
   }
   return 0;
}