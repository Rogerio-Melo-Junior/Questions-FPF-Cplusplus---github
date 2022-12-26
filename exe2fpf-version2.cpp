// segunda versão com alocação dinâmica, usando o 'new' e o 'delete'. Versão final.
    #include <bits/stdc++.h> 
    #define _ ios_base::sync_with_stdio(0); // uso de macro para reduzir o tempo de execução.

    using namespace std;

  int exercise2(int a[],int N){
  
    int i; //percorre como índice
    int pos,maior_pos=0,maior_pos_neg=0; //declaração das variáveis.
                    //a variável 'N' é a qtd de elementos do vetor, a variável 'pos' é a posição que será usada nos vetores 'A' e 'B'
                    // no momento de virar(setar em '1') as cartas.  
        for(i=0;i<N;i++){  // esse loop percorre o vetor apenas para encontrar o maior valor em módulo tanto para os positivos quanto para os negativos.
                pos = a[i];
                if(pos>maior_pos)
                    maior_pos = pos; //pega o maior valor encontrado. 
                else
                    if(abs(pos)>maior_pos_neg)
                        maior_pos_neg = abs(pos); //pega o maior valor encontrado em módulo.
            
        }
        
      int  *A = new (nothrow) int[maior_pos+1](); //tornando o ponteiro '*A', um vetor 'A' de 'maior_pos' posições.
                                    // O uso de '()' ao final da linha é para setar os valores nas posições do vetor 'A' em '0'.
      int *B = new (nothrow) int[maior_pos+1](); //tornando o ponteiro '*A', um vetor 'B' de 'maior_pos' posições.
                                    // O uso de '()' ao final da linha é para setar os valores nas posições do vetor 'B' em '0'.
      int *A_negativos = new (nothrow) int[maior_pos_neg+1](); //tornando o ponteiro '*A', um vetor 'A' de 'maior_pos' posições.
                                    // O uso de '()' ao final da linha é para setar os valores nas posições do vetor 'A' em '0'.
      int *B_negativos = new (nothrow) int[maior_pos_neg+1](); //tornando o ponteiro '*A', um vetor 'B' de 'maior_pos' posições.
                                    // O uso de '()' ao final da linha é para setar os valores nas posições do vetor 'B' em '0'.
        
        if(!A || !B || !A_negativos || !B_negativos){  //profilaxia para caso haja problema com as memórias de A ou B no momento da alocação. 
            cout << "Erro: Memória Insuficiente!"<< endl;   
            pos = 0;
            return pos; //Sai da função e retorna um valor para a função 'main()'.
        }
        else{
            for(i=0 ; i<N ; i++){ // loop para realizar as viradas das cartas nos vetores espelhos 'A' e 'B'
                pos = a[i];
                if(pos>0){
                    if(A[pos] == 0){
                    A[pos] = 1; // Virou a primeira carta.
                    }   
                    else{
                        if(B[pos] == 0)
                            B[pos] = 1; // Virou a carta 'par' correspondente.
                    }
                }
                else{
                    pos = abs(pos);
                    if(A_negativos[pos] == 0){
                    A_negativos[pos] = 1; // Virou a primeira carta.
                    }   
                    else{
                        if(B_negativos[pos] == 0)
                            B_negativos[pos] = 1; // Virou a carta 'par' correspondente.
                    }  
                }
            } 
        
            for(i=0 ; i<N ; i++){
                  pos = a[i];
                    if(pos>0){ 
                     if(B[pos] == 0){  // Verificando a existência de uma carta sem seu 'par'.
                       delete[] A; // libera o array alocado previamente.
                       delete[] B; // libera o array alocado previamente.
                       break; //saída do loop e retorno do valor de 'pos' 'atual'.
                     }
                    }
                    else{
                    pos = abs(pos); 
                    if(B_negativos[pos] == 0){  // Verificando a existência de uma carta sem seu 'par'.
                        delete[] A_negativos; // libera o array alocado previamente.
                        delete[] B_negativos; // libera o array alocado previamente.
                        pos = (-1)*pos; // pega o módulo de 'pos'. 
                        break; //saída do loop e retorno de valor pra função main().
                     }  
                    }
            }
           return pos; //Sai da função e retorna um valor para a função 'main()'.
        }
}
    int main(){_ //uso da macro com o '_'.
    int i; //percorre como índice.
    int n; //variável de número.
    int *P; //declaração de um ponteiro.
    cin >> n; // leitura da qtd de elementos a serem lidos pelo vetor.
    cin.ignore(); //limpa o buffer de leitura.
    if(n%2==1){    // o número de elementos tem que ser ímpar.
      P = new (nothrow) int[n](); //tornando o ponteiro '*P', um vetor P de N posições.
        
        for(i=0;i<n;i++)
                cin >> P[i]; //leitura dos elementos do vetor alocado. 
            
       cout << exercise2(P,n) << endl; //saída do programa e chamada da função.
       delete[] P; // libera o array alocado previamente.
      
    }
    else{ // caso o valor 'n' digitado pelo usuário seja par, o programa apresentará essa msg
        cout << "Necessario numero impar de elementos" << endl;
    }
    return 0;
}