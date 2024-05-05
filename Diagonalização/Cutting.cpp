//link do problema: https://onlinejudge.org/external/100/10003.pdf

#include <bits/stdc++.h>

using namespace std;

int tam;
int Ncuts;
int CutPts[51];
int CutSizes[51];
int MatDiag[51][51];

int Bestcut() {
    int coluna;
    long long  min;
    int cut;

    for (int k = 0; k < Ncuts + 1; k++) {
        for (int linha = 0; linha < Ncuts + 1 - k; linha++) {
            coluna = linha + k;

            if (linha == coluna) {
                MatDiag[linha][coluna] = 0;
            } else {
                if (coluna - linha == 1) {
                    MatDiag[linha][coluna] = CutSizes[linha] + CutSizes[coluna];
                } else {
                    // primeira tentativa de corte
                    min = LLONG_MAX;
                    for (int i = linha; i < coluna; i++) { // quantidade de tentativas de cortes
                        if (i == coluna -1) {
                            
                            if (min > MatDiag[linha][coluna-1]) min = MatDiag[linha][coluna-1];
                            
                        } else if(i==linha){
                            
                            if (min > MatDiag[linha+1][coluna]) min = MatDiag[linha+1][coluna];
                            
                        }else{
                            
                            if (min > MatDiag[linha][i] + MatDiag[i + 1][coluna]) min = MatDiag[linha][i] + MatDiag[i + 1][coluna];
                        }
                    }
                    cut=0;
                    for (int i = linha; i <= coluna; i++) {
                        cut += CutSizes[i];
                    }
                    MatDiag[linha][coluna] = min + cut; // +tamanho
                }
            }
        }
    }
    return MatDiag[0][Ncuts];
}


int main(void) {
    
    
    while(true){
        cin>> tam;

        if(tam == 0 ) break;
        
        cin>> Ncuts;
        
        for(int i = 0; i<Ncuts;i++) cin>>CutPts[i];
        
        CutPts[Ncuts] = tam; 
        
        CutSizes[0] = CutPts[0];
        
        for(int i = 1; i<Ncuts + 1;i++) CutSizes[i] = CutPts[i] - CutPts[i-1];
        
        int p = Bestcut();
        //cout<<tam;
        //for(int i = 0; i<Ncuts+1;i++) cout << CutPts[i];
        //cout << endl;
        //for(int i = 0; i<Ncuts + 1;i++) cout << CutSizes[i];
        //cout << endl;
        
        //for(int i=0;i<Ncuts+1;i++){
        //    for (int j=0;j<Ncuts+1;j++) cout<<MatDiag[i][j]<< " ";
        //    cout << endl;
        //}
        cout <<"The minimum cutting is "<< p <<"."<< endl;
        
    }
    

    return 0;
}
