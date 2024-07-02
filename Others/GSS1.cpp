//Soma M�xima no Intervalo (SIMX) com �rvore de Segmentos e Atualiza��o
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

struct nost{int soma; int smax; int prfm;  int sufm;};

int N, A[10000001], pos, nv;

char op;

nost SST[30000002];

//GERAL
nost Combina(nost p1, nost p2){
	nost p3;
	p3.soma = p1.soma + p2.soma;
	p3.smax = max(max(p1.smax, p2.smax), p1.sufm + p2.prfm);
	p3.prfm = max(p1.prfm, p1.soma + p2.prfm);
	p3.sufm = max(p2.sufm, p1.sufm + p2.soma);
	return p3;
}

int segmentTree(int no, int c, int f) {
	int ne=2*no, nd=2*no+1;
	if (c==f){	
		SST[no].soma = SST[no].smax = SST[no].prfm = SST[no].sufm = A[c];
	}
	else {
		int k = (c+f)/2;
		segmentTree(ne,c,k);
		segmentTree(nd,k+1,f);
		SST[no] = Combina(SST[ne], SST[nd]);
	}
	return 0;
}

int Atualiza(int no, int c, int f, int pos, int nv) {
	int ne=2*no, nd=2*no+1;	
	if (c==f)
		SST[no].soma = SST[no].smax = SST[no].prfm = SST[no].sufm = nv;
	else {
		int k = (c+f)/2;
		if (pos <= k)
			Atualiza(ne,c,k, pos, nv);
		else
			Atualiza(nd,k+1,f, pos, nv);
		SST[no] = Combina(SST[ne], SST[nd]);
	}
	return 0;
}

nost querySST(int no, int c, int f, int i, int j) {
	nost p1, p2, p3;
	if (c >= i && f <= j)
		return SST[no];
	else if (i > f || j < c){
		p3.soma = 0;
		p3.smax = p3.prfm = p3.sufm = -INF;
		return p3;
	}
	else {
		int k;
		k=(c+f)/2;
		p1 = querySST(2*no, c, k, i, j);
		p2 = querySST(2*no+1, k+1, f, i, j);
		p3 = Combina(p1, p2);	
		return p3;
	}
}


int main() {
	int i,j,k;
	nost kn;

	//Preenchimento aleat�rio
	cin >> N;

	//N = 20;
	for (i=0; i<N; i++){
	    cin>>A[i];
		//A[i] = rand()%N - rand()%N;
		//cout<<A[i]<<" ";
	}
	//cout<<endl;
	
	//Pr�-processamento
    segmentTree(1,0,N-1); 
	int t;
	cin>>t;
	//Leitura das consultas ou atualiza��es
	for(int k = 0; k<t; k++){
		cin>>i>>j;
		kn = querySST(1, 0, N-1, i-1, j-1); 
		cout<<kn.smax<<"\n";
	}
	
	return 0;
}
