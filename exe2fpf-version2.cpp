    // segunda versão com alocação dinâmica, usando o 'new' e o 'delete'.
    #include <bits/stdc++.h> 
    #define _ ios_base::sync_with_stdio(0); // uso de macro para reduzir o tempo de execução.

    using namespace std;

    int main(){_ 
    int i; //percorre como índice
    int N,pos,maior_pos=0; //declaração das variáveis.
                    //a variável 'n' é a qtd de elementos do vetor, a variável 'pos' é a posição que será usada nos vetores 'A' e 'B'
                    // no momento de virar(setar em '1') as cartas.  
    int *P, *A, *B; //Declaração de ponteiros
        // os vetores 'A' e 'B' serão usados como cartas viradas para baixo, sendo indicadas pelo valor 0.
        // o vet
    cin >> N; // leitura da qtd de elementos a serem lidos pelo vetor.
    cin.ignore(); 
    if(N%2==1){    // o número de elementos tem que ser ímpar.
      P = new (nothrow) int[N](); //tornando o ponteiro '*P', um vetor P de N posições.
       
      for(i=0;i<N;i++){
            cin >> P[i]; 
            pos = P[i];
            if(pos>maior_pos)
                maior_pos = pos;
      }
    
      A = new (nothrow) int[maior_pos](); //tornando o ponteiro '*A', um vetor 'A' de 'maior_pos' posições.
                                // O uso de '()' ao final da linha é para setar os valores nas posições do vetor 'A' em '0'.
      B = new (nothrow) int[maior_pos](); //tornando o ponteiro '*A', um vetor 'B' de 'maior_pos' posições.
                                // O uso de '()' ao final da linha é para setar os valores nas posições do vetor 'B' em '0'.
    
      if(!A || !B){  //profilaxia para caso haja problema com as memórias de A ou B no momento da alocação. 
         cout << "Erro: Memória Insuficiente!"<< endl;   
          return 0; //Sai do programa.
      }
      else{
         for(i=0 ; i<N ; i++){
            pos = P[i];
            if(A[pos] == 0){
            A[pos] = 1; // Virou a primeira carta.
            }
            else{
                if(B[pos] == 0)
                       B[pos] = 1; // Virou a carta 'par' correspondente.
            }
         } 

         for(i=0 ; i<N ; i++){
           pos = P[i];
            if(B[pos] == 0){  // Verificando a existência de uma carta sem seu 'par'.
                  cout << pos << endl; // Saída com a carta sem seu 'par'.
                return 0;
            }
         }
       delete[] P; // libera o array alocado previamente;
       delete[] A;  
       delete[] B; 
      }
    }
    else{ // caso o valor N digitado pelo usuário seja par, o programa apresentará essa msg
        cout << "Necessario numero impar de elementos" << endl;
    }
    return 0;
}