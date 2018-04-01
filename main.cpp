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
    for(int i=0;i<size;i++){
      g.dijkstra(i);
    }
    g.print_dist();
    g.dist=g.edges;
    g.floyd_warshall();
    g.print_dist();

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
