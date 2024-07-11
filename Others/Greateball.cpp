//RMQ com Tabela Esparsa
//problema: https://www.spoj.com/problems/BYTESE2/

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
	int i,j,k,i0,j0;
	
	int t,t0;
	cin>>t0;
	for(j0=0;j0<t0;j0++){
	    cin>>t;
    	N=0;
    	
    	for(i0=0;i0<t;i0++){
    	    cin >> i >>j;
    	    for(i=i-1;i<=j-1;i++){
    	        A[i]--;
    	        
    	    }
    	    if(j>N) N=j;
    	    
    	}
    	
        tabelaEsparsa();
    
        k = queryAE(0,N-1); 
       
        cout << -A[k] << endl;
        //for(i =0;i<N;i++) cout<<A[i]<<" " ;
        //cout<<endl;
        for(i =0;i<N;i++) A[i]=0;
	}
	
				
	
	return 0;
}
