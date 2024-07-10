//PROBLEMA: https://www.spoj.com/problems/RMQSQ/

//RMQ com Tabela Esparsa
#include <bits/stdc++.h>
using namespace std;

int N;
int A[1000000], M[25][1000000];

int menor(int a, int b) {
	return (A[b]>A[a]) ? a : b;
}

void tabelaEsparsa() {
	int i, k;
    for (i = 0; i < N; ++i)
		M[0][i] = i;
    for (k = 1; 1<<k <= N; ++k)
        for (i = 0; i+(1<<k)-1 < N; ++i) {
        	M[k][i] = menor(M[k-1][i],M[k-1][i+(1<<(k-1))]);
        }
}

int queryAE(int c, int f) {
	int k = (int) log2(f-c+1);
	return menor(M[k][c], M[k][f-(1<<k)+1]);
}

int main() {
	int t;
	int i,j;
    cin >> N;
    
	//Preenchimento aleat�rio
	//N = 20;
	for (i=0; i<N; i++){
		//A[i] = rand()%N;
		cin>>A[i];
	}
	
	//Pr�-processamento
	tabelaEsparsa();
	
	cin>>t;
	//Leitura das consultas
	for(int k=0;k<t;k++) {
	    //cout<<"."<<endl;
	    cin>>i>>j;
		cout<<A[queryAE(i,j)]<<endl;	
	}

	return 0;
}
