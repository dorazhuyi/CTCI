#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int N;
	cout << "Input image size: ";
	cin >> N;
	int image[N][N];
	
	int i,j;
	//Creat Image
	for(i=0;i<N;i++){
	  for(j=0;j<N;j++){
	    image[i][j]=rand()%256;
	    cout << image[i][j] << " ";
	  }
	  cout << '\n';
	}

	
	for(i=0;i<N/2;i++){
	  int start = i;
	  int end = N-i-1;
	  int tmp;
	  for(j=start;j<end;j++){
	    tmp = image[i][j];
	    cout << i << " " << j << " " << tmp << endl;
	    //move from left to top
	    image[i][j]=image[N-1-j][i];
	    //move from bottom to left
	    image[N-1-j][i]=image[N-1-i][N-1-j];
	    //move from right to bottom
	    image[N-1-i][N-1-j]=image[j][N-1-i];
	    //move from tmp(top) to right
	    image[j][N-1-i]=tmp;		
	  }
	}

	cout << '\n' << "Rotated: " << endl;
	for(i=0;i<N;i++){
	  for(j=0;j<N;j++){
	    cout << image[i][j] << " ";
	  }
	  cout << '\n';
	}	

	return 0;

}
