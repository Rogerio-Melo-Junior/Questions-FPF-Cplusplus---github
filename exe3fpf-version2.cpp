// segunda versão de solução do problema com uso do 'new' e 'delete'.
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;


int exercise3(int a[],int n){ //parâmetros: primeiro endereço de memória do vetor e tamanho do vetor
      int sum=0,i,maior = 1,pos,lim_maior,lim_menor; //declaração das variáveis locais da função
                                              // i é o incrementador, 'maior' é a minha saída, 'pos' é a posição da 
                                              // minha entrada 
                                              // 'lim_maior' e 'lim_menor' são os limites: inferior e superior 
                                              // do intervalo de análise.
 
     for(i=0;i<n;i++){// loop de entrada dos meus 'n' elementos do array.
        if(i==0)
             lim_maior = lim_menor = a[i]; // definindo meus limites no primeiro elemento.
        
        pos = a[i];
        if(pos > 0){
                 if(pos > lim_maior)
                     lim_maior = pos; // redefinindo meu limite superior do intervalo.
                 if(pos < lim_menor)
                     lim_menor = pos; // redefinindo meu limite inferior do intervalo.
         }
   }
   
   int *A = new int[lim_maior+1];
   
    if(!A){
        cout << "Memoria insuficiente em A!" << endl;
        return 0; //sai do programa
     }
    for(i=0;i<n;i++){
         pos = a[i];
         if(pos>0){
            A[pos] = 1; // setando em '1' valores maiores que zero na posição do vetor 'A'.
            sum++;
         }
    }
    
    if(sum==0){ //verificação para o caso de todos os números serem menores ou iguais a zero.
             maior = 1;
             delete[] A; //libera o array alocado dentro dessa função
        return maior;    // sai da função e retorna um valor pra função main().
    }
    else{
      for(i=lim_menor;i<=lim_maior;i++){ // percorrendo o intervalo com os limites traçados.
        if(A[i] == 0)                    // como o vetor inicialmente estava zerado 
            maior = i;                   // valores pertencentes ao intervalo mas não mencionados na entrada terão valor 0.
      }
    
       if(maior == 1 && lim_maior>0) // se no intervalo percorrido o valor de 'A[i]' for sempre '1', significa que 
          maior = lim_maior+1;       // o valor de saída está fora do intervalo, sendo o resultado uma unidade fora do intervalo.           
       
       delete[] A; //libera o array alocado dentro dessa função
       return maior; // sai da função e retorna um valor pra função main().
    }
    
}
   
int main(){_
   int i,n;
   cin >> n;  // números de elementos que será lido no vetor 
   cin.ignore();
   
   int *P = new (nothrow) int[n];
     if(!P){
        cout << "Memoria insuficiente em P!" << endl;
        return 0; //sai do programa.
     }
    
   for(i=0;i<n;i++)// loop de entrada dos meus 'n' elementos do array.
        cin >> P[i];

    cout << exercise3(P,n) << endl;
    
    delete[] P;
   return 0;
}