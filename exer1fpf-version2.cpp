// Versão 2 da questão 1, simplificadamente sem o uso da recursividade e sem usar o operador '&'
#include <iostream>

using namespace std;

int exercise1(int a, int b){ // parâmetros de entrada da função
    int P,sum=0;
    P = a*b;
    while(P>0){ // Loop que soma os bits do número 'produto'
         if(P%2==1) // Verifica a paridade do número. Como um número ímpar tem sempre o bit menos significativo setado em '1',
                    //  esse bit é contabilizado a cada iteração.
          sum = sum+1; // Contabiliza a soma os 'bits'.
        cout << P <<endl;
        P = P>>1; // Desloca um bit para a direita o valor de P a cada iteração
    } 
    return sum; // função que retorna a soma dos bits
}

int main(){
    int A,B; // Declaração das variáveis.
    int X,sum=0; 
    cin >> A >> B; // Entrada dos números a serem multiplicados.
    cout << exercise1(A,B) << endl; // Chamada da função e saída do resultado.
    return 0;   
}