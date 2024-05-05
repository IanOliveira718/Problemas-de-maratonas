//link para o problema: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&category=11&page=show_problem&problem=851

#include <bits/stdc++.h>


char Mtranzicao[26][3];
int Mmem[26][50];
int Nletras;
int Nmoves;
bool final[26];
char c1,c2,c0,c;

//setar Mtranzicao como -1 em toda template


int TvGame (char L, int jogada)
{ if(Nmoves==0){if(final[L-65] == true)return 1;}

  if (jogada == Nmoves)
	{   int wins = 0;
	
	    if(final[Mtranzicao[L-65][1]-65]){
	        wins++;
	    }
	    if(final[Mtranzicao[L-65][2]-65]){
	        wins++;
	    }
	    Mmem[L-65][jogada-1] = wins;
	    return wins;
	}
  else
	{
	  if (Mmem[L-65][jogada-1] == -1)
		{   if(L == Mtranzicao[L-65][1] && L == Mtranzicao[L-65][2]){
		        if(final[L-65]){
		            //Retornar 2^nmoves - jogada + 1
		            Mmem[L-65][jogada-1] = pow(2,Nmoves - jogada + 1);
		            return Mmem[L-65][jogada-1];
		            
		        }else{
		            Mmem[L-65][jogada-1] = 0;
		            return Mmem[L-65][jogada-1];
		        }
		    
		    }else{
		       Mmem[L-65][jogada-1] = TvGame (Mtranzicao[L-65][1], jogada + 1) + TvGame (Mtranzicao[L-65][2], jogada + 1);
		       return Mmem[L-65][jogada-1];
		    }
		    
		    
		}else{
		    return Mmem[L-65][jogada-1];
		}


	}

}



int main ()
{

while(std::cin >> Nletras){
	  for (int i = 0; i < Nletras; i++)
	{

	  std::cin >> c0>>c1>>c2>>c;
	  Mtranzicao[c0-65][0] = c0; Mtranzicao[c0-65][1]=c1;  Mtranzicao[c0-65][2]=c2;

	  if (c == 'x')
		{
		  final[c0-65] = true;
		}
	  else{final[c0-65] = false;}

	}
  std::cin >> Nmoves;
  
  for(int i = 0; i< 26; i++){
      for(int j = 0; j< 50; j++)
        Mmem [i][j] = -1;
  }

  std::cout << TvGame('A',1)<<"\n";

}
  //std::cin >> Nletras;


  return 0;
}
