#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

	int M,N;
	cout << "Input row: ";
	cin >> M;
	cout << "Input column: ";
	cin >> N	;	
	int matrix[M][N];
	
	cout << '\n' << "Original Matrix: "<<endl;
	int i,j;
	//Creat Image
	for(i=0;i<M;i++){
	  for(j=0;j<N;j++){
	    if( (i==M/2&&j==N/4) || (i==M-1&&j==N-1)) matrix[i][j]=0;
	    else matrix[i][j]=rand()%10;
	    cout << matrix[i][j] << " ";
	  }
	  cout << '\n';
	}

	//matrix[0] = {1,3,5,7,9};
	//matrix[1] = {7,0,11,13,17};
	//matrix[2] = {15,19,0,21,13};

	bool zeror[M];
	bool zeroc[N];

	for(i=0;i<M;i++){ zeror[i]=false; }
	for(j=0;j<N;j++){ zeroc[j]=false; }

	for(i=0;i<M;i++){
	 for(j=0;j<N;j++){
	  if(matrix[i][j]==0){
	    zeror[i]=true;
	    zeroc[j]=true;
	  } 
	 }
	}

	for(i=0;i<M;i++){ cout << zeror[i]; }
	cout << '\n';
	for(j=0;j<N;j++){ cout << zeroc[j]; }
	cout << '\n';

	for(i=0;i<M;i++){
	 for(j=0;j<N;j++){
	  if(zeror[i] || zeroc[j]){
	    matrix[i][j]=0;
	  }
	 }
	}

	cout << '\n' << "Output: " << endl;
	for(i=0;i<M;i++){
	  for(j=0;j<N;j++){
	    cout <<matrix[i][j] << " ";
	  }
	  cout << '\n';
	}	

	return 0;



}
