#include<iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int size;
    int MAX_WEIGHT = 99;

    cout<<"Input number of vertices: ";
    cin>>size;

    for(int r=0;r<size;r++){
      for(int c=0;c<size;c++){
        int w;
        //cin>>w;
        w=rand() % (MAX_WEIGHT+1);
        cout<<w<<"\t";
      }
      cout<<endl;
    }
    return 0;
}
