#include<vector>
#include <stdlib.h>
#include<iostream>

using namespace std;

const int INF = 9999999;

class graph{
  public:
    int MAX_WEIGHT;
    int** edges;
    int**  dist;
    bool**  hit;

    int size;
    graph(){

    }

    graph(int num_vertices){
      MAX_WEIGHT=99;
      size=num_vertices;
      edges= new int*[size];
      dist= new int*[size];
      hit=new bool*[size];

      for(int r=0;r<size;r++){
        edges[r]=new int[size];
        dist[r]=new int[size];
        hit[r]=new bool[size];
        for(int c=0;c<size;c++){
          if(r==c){
            edges[r][c]=0;
            dist[r][c]=0;
            hit[r][c]=true;
          }
          else{
            edges[r][c]=rand() % (MAX_WEIGHT+1);
            dist[r][c]=INF;
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
      cout<<endl;
    }

    void print_dist(){
      for(int r=0;r<size;r++){
        for(int c=0;c<size;c++){
          cout<<dist[r][c]<<"\t";
        }
        cout<<endl;
      }
      cout<<endl;
    }

    void dijkstra(int start){
      int v=start;
      int min=start;
      while(min!=-1){
        v=min;
        hit[start][v]=true;
        min=-1;
        for(int i=0;i<size;i++){
          if(!hit[start][i]){
            int new_dist = dist[start][v] + edges[v][i];
            if(new_dist < dist[start][i]){
              dist[start][i] = new_dist;
              if(min==-1 || new_dist<dist[start][min]){
                min=i;
              }
            }
          }
        }
      }
    }


};
