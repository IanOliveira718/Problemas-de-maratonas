//link para o problema: https://onlinejudge.org/external/123/12324.pdf

#include <bits/stdc++.h>
using namespace std;

int main() {
     int sum;
    int aux;
    int d[1000],time[1000];
    int t;
    priority_queue <int> pq;
    
    cin >> t;
    
    while(t != 0) {
        
        for(int i = 0; i < t; i++) {
            cin >> d[i] >> time[i];
        }
        
        pq.push(d[t-1]);
        
        for(int i = t-2; i >= 0; i--) {
            
           
            for(time[i];time[i]>0;time[i]--){
                aux = pq.top()/2;
                pq.pop();
                sum +=aux;
                if(pq.empty()) break;
                }
            
            
            pq.push(d[i]);

            
        }
        
       
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        
        cout<<sum<<endl;
        sum=0;

        cin >> t;
    }
    
    return 0;
}
