#include <iostream>
//link do problema https://judge.beecrowd.com/pt/runs/code/40277172 


using namespace std;
int n = 1000000007;
int t, T, M, N;
 int mat[100002][52];

int SM(int a, int b){
		long long int la, lb;
		la = a; lb = b;
	    return (la+lb)%n;
}


long long int bike(void){
    int i,j;
    long long int r = 0;
    for ( i = 0 ; i < 100001; i++){
        if (M<=i && i<=N){
            mat[i][1]=1;
            mat[i][0]=0;
        }else{
            for ( j = 0 ; j < T+1; j++){
                mat[i][j]=0;
            } 
        }
    }

    for (j = 2 ; j < T+1; j++){
            for ( i = M ; i < N+1; i++){
                mat[i][j]=SM(mat[i-1][j-1],mat[i+1][j-1]);
            }
    }

    for ( i = M ; i < N+1; i++){
        r = SM(r,mat[i][T]);
    }
    
    return r;

}
 
int main() {
  

    
        cin >> T >> M >> N; 
        cout << bike()<< "\n";
    
    
 
    return 0;
}
