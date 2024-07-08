#include<bits/stdc++.h>
//PROBLEM LINK: https://onlinejudge.org/external/11/1197.pdf
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
            //if(pai[pai[p].p].d>maxi)
            //    maxi=pai[pai[p].p].d;
        	pai[pai[q].p].p = pai[p].p;
    	
    	}
        else{
            pai[pai[q].p].d = pai[pai[p].p].d + pai[pai[q].p].d;//correcao feita (inverti para nao contar repetido)
            //if(pai[pai[q].p].d>maxi)
            //    maxi=pai[pai[q].p].d;
    		pai[pai[p].p].p = pai[q].p;
        		
    	}
	}
    
}

int main(){
    bool b;
    int u, v, c, pp, pq;
    int t;
    //cin>>t;
	while(true){
	    b=true;
	    cin >>n>>m;
	    
	    if (!n) break;
    	    for(int i=1; i<=n; i++){
    	        pai[i].d = 1;
    	        pai[i].p = i;
    	    }	    
    	    //maxi = -1;
    	    
    	    for(int i=1; i<=m; i++){
    	        int k;
    	        cin >> k;
    	        cin >>u;
    	        for(int j=1; j<=k-1; j++){
    	            cin >>v;
    	            Uniao(u+1,v+1);
    	        }
    	        
    	    }
    	   //for(int i=1; i<=n; i++)
    	   //     cout << pai[i].d << " ";
    	   //cout<<endl;
    	   
    	   //for(int i=1; i<=n; i++)
    	   //     cout << pai[i].p << " ";
    	   //cout<<endl;
                
            
            cout<<pai[1].d<<"\n";
           
        	
        	
	    
	    	
    	
    }
	return 0;
}
