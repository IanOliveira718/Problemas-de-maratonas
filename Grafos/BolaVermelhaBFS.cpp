#include <bits/stdc++.h>
#include <queue>
using namespace std;
int x,y;
int x1,x2,y11,y2;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int mat[1000][1000];
int visited[1000][1000];
int t,n;
queue<int> rq,cq;
int move_count = 0;
int nodes_left_in_layer = 1;
int nodes_in_next_layer = 0;
bool reached = false;


void visit(void){
    for(int i=0;i<4;i++){
        int xx = x+dx[i];
        int yy = y+dy[i];

        if (xx < 0 || yy < 0)continue;
        if (xx >= n || yy >= n)continue;
        if(visited[xx][yy])continue;
        if(mat[xx][yy] == 1)continue;

        rq.push(xx);
        cq.push(yy);
        visited[xx][yy] = 1;
        nodes_in_next_layer++;

    }
}

int main() {
    
    cin >> t;

    for (int i = 0; i<t; i++){
        move_count = 0;
        nodes_left_in_layer = 1;
        nodes_in_next_layer = 0;
        reached = false;

        memset(visited,0,sizeof(visited));
        memset(mat,0,sizeof(mat));
        while (!rq.empty()) {
        rq.pop();
        }
        while (!cq.empty()) {
        cq.pop();
        }

        cin >> n;

        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                cin >> mat[j][k];
            }
        }
        cin >> x1 >> y11;// y1 eh reservado, por isso usei y11
        cin >> x2 >> y2;

        if( mat[x1][y11]==1|| mat[x2] [y2]==1){ 

            cout << "-1"<<"\n"; // Se começar em cima de móveis


        }else{  //  iniciando BFS//

            rq.push(x1);
            cq.push(y11);
            visited[x1][y11] = 1;

            while(rq.size()>0){

                x = rq.front();
                rq.pop();
                y = cq.front();
                cq.pop();

                if(x == x2 && y == y2){
                    reached = true;
                    break;
                }

                visit();

                nodes_left_in_layer--;

                if(nodes_left_in_layer==0){

                    nodes_left_in_layer = nodes_in_next_layer;
                    nodes_in_next_layer = 0;
                    move_count++;

                }
                //if(rq.size()>0) cout<< "!";




            }

            if(reached){
                cout << move_count <<"\n";
            }else{
                cout << "-1"<<"\n";
            } 
            



        }// fim BFS//////////////




        

        
    }


    return 0;
}
