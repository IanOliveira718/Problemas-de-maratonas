#include<bits/stdc++.h>
//problema: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2737

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
    cin>>t;
	for(int t0=0;t0<t;t0++){
	    b=true;
	    cin >>n>>m;
	    
	    if (!n) break;
    	    for(int i=1; i<=n; i++){
    	        cin >>pai[i].d;
    	        pai[i].p = i;
    	    }	    
    	    //maxi = -1;
    	    
    	    for(int i=1; i<=m; i++){
    	        cin >>u>>v;
    	        Uniao(u+1, v+1);
    	    }
    	    
    	    //for(int i=1; i<=n; i++)
    	   //     cout << pai[i].d << " ";
    	   //cout<<endl;
    	   
    	   //for(int i=1; i<=n; i++)
    	   //     cout << pai[i].p << " ";
    	   //cout<<endl;
    	    
    	    
            for(int i=1; i<=n; i++){
                if(pai[i].p==i){
                    
                    if(pai[i].d>0){
                        b=false;
                        break;
                    }
                }
            }
                
            if(b){
                cout<<"POSSIBLE"<<"\n";
            }else{
                cout<<"IMPOSSIBLE"<<"\n";
            }    
        	
        	
	    
	    	
    	
    }
	return 0;
}
