#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

int countSetBits(int n){
     // caso base
    if (n == 0)
        return 0;
  
    else
        // se o último 'bit' está 'setado' adicionar 1 senão adicionar 0
        return (n & 1) + countSetBits(n >> 1); //com o operador '&' verificamos o resultado bit a bit do 'AND', 
                                 // como eu pego o número inteiro  e comparo com o inteiro 1, que em binário é -01-
                                 // ele me retorna o AND do bit menos significativo, em outras palavras,
                                 // se o bit menos significativo for 1 ele soma recursivamente na função.
                                     
                                 // o operador '>>' desloca-se um bit a cada iteração e para no caso base em que 
                                 // o inteiro n é 0, isto é,  a cada iteração é retirado o último bit(menos significativo),
                                 // dando lugar ao próximo.
}

int exercise1(int A,int B){ 
    int P;
    P = A*B; // P é o produto das entradas do programa
    return countSetBits(P); // é chamada a função de contagem dos bits setados em '1'
}

int main(){_
   int A,B; //declaração das variáveis de entrada.
   int P; //declaração da variável de saída.
   cin >> A; // leitura da variável A.
   cin >> B; // leitura da variável B.
   if(A>0 && B>0)
     cout << exercise1(A,B); // saída do programa.
   else
     cout << "Apenas inteiros positivos!!"; // saída do programa.
   return 0;
}