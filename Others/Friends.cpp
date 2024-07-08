//problema: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1549&mosmsg=Submission+received+with+ID+29615753

/* Primitivas para Union Find*/
#include<bits/stdc++.h>
using namespace std;
 struct no {int d; int p;};
int maxi;
int n, m, i, pp, pq;
int cont[40001];
no pai[40001];

int Busca(int p){
    if (pai[p].p != p)
		pai[p].p = Busca(pai[p].p);
    return pai[p].p;
}


void Uniao(int u, int v){
	int p, q;
	p = Busca(u);  q = Busca(v);
	if(p!=q){ //conectados
	    if (pai[p].p < pai[q].p){   
            pai[pai[p].p].d = pai[pai[p].p].d + pai[pai[q].p].d;//correcao feita (inverti para nao contar repetido)
            if(pai[pai[p].p].d>maxi)
                maxi=pai[pai[p].p].d;
        	pai[pai[q].p].p = pai[p].p;
    	
    	}
        else{
            pai[pai[q].p].d = pai[pai[p].p].d + pai[pai[q].p].d;//correcao feita (inverti para nao contar repetido)
            if(pai[pai[q].p].d>maxi)
                maxi=pai[pai[q].p].d;
    		pai[pai[p].p].p = pai[q].p;
        		
    	}
	}
    
}

int main(){
    int u, v, c, pp, pq;
    int t;
    cin>>t;
	for(int t0=0;t0<t;t0++){
	    cin >>n>>m;
	    if(m == 0){
	        cout<<1<<"\n";
	    }else{
	        if (!n) break;
    	    for(int i=1; i<=n; i++){
    	        pai[i].p = i;  pai[i].d = 1;
    	    }	    
    	    maxi = -1;
    	    
    	    for(int i=1; i<=m; i++){
    	        cin >>u>>v;
    	        Uniao(u, v);
    	    }
    
        	cout<<maxi<<"\n";
	    }
	    	
    	
    }
	return 0;
}
