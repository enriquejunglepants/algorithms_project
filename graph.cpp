#include<vector>
#include <stdlib.h>
#include<iostream>

using namespace std;

class graph{
  public:
    int MAX_WEIGHT;
    int** edges;
    int size;
    graph(){

    }

    graph(int num_vertices){
      MAX_WEIGHT=99;
      size=num_vertices;
      edges= new int*[size];

      for(int r=0;r<size;r++){
        edges[r]=new int[size];
        for(int c=0;c<size;c++){
          if(r==c){
            edges[r][c]=0;
          }
          else{
            edges[r][c]=rand() % (MAX_WEIGHT+1);
          }
        }
      }
    }

    void print(){
      for(int r=0;r<size;r++){
        for(int c=0;c<size;c++){
          cout<<edges[r][c]<<"\t";
        }
        cout<<endl;
      }
    }


};
