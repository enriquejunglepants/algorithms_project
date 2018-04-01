#include<iostream>
#include <stdlib.h>
#include "graph.cpp"

using namespace std;

int main()
{
    int size;
    cout<<"Input number of vertices: ";
    cin>>size;
    graph g(size);
    g.print();

    for(int r=0;r<g.size;r++){
      for(int c=0;c<g.size;c++){
        cout<<g.edges[r][c]<<"\t";
      }
      cout<<endl;
    }

    /*
    int MAX_WEIGHT = 99;

    cout<<"Input number of vertices: ";
    cin>>size;

    for(int r=0;r<size;r++){
      for(int c=0;c<size;c++){
        int w;
        if(r==c){
          w=0;
        }
        else{
          w=rand() % (MAX_WEIGHT+1);
        }

        cout<<w<<"\t";
      }
      cout<<endl;
    }
    */

    return 0;
}
