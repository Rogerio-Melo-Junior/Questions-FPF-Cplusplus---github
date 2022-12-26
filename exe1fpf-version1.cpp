// Versão 1 da questão 1. Versão final.
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

int countSetBits(int X){
    if(X == 0) // Caso base
       return 0;
    else  
      return (X & 1) + countSetBits(X >> 1); // Soma o bit recursivamente e desloca o bit menos significativo para a direita 
}
int exercise1(int a, int b){ // parâmetros de entrada da função
    int P;   //variáveis locais da função
    P = a*b; //produto das entradas da função
    return countSetBits(P); // função que retorna a soma dos bits
}

int main(){_ //uso da macro '_'.
    int *A = new (nothrow) int; // Declaração dos ponteiros de inteiros e alocação de inteiros.
    int *B = new (nothrow) int; 
    
    if(!A || !B) // verifica se há problema com a memória após a alocação.
        return 0;
    
    cin >> *A >> *B; // Entrada dos números a serem multiplicados.
    
    if((*A)<0 || (*B)<0){ 
        cout << "Apenas inteiros positivos!!" << endl;
    }
    else{
        cout << exercise1(*A,*B) << endl; // Chamada da função e saída do resultado.
    }
    delete A; // libera a alocação;
    delete B; // libera a alocação;
    return 0;   
}