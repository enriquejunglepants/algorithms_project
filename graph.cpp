#include<vector>
#include <stdlib.h>
#include<iostream>
#include <time.h>

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
      srand (time(NULL));
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

    clock_t dijkstra(){
      clock_t t=clock();

      for(int i=0;i<size;i++){
        dijkstra(i);
      }
      t = clock() - t;
      reset_dist();
      return t;
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
            }

            if(min==-1 || dist[start][i]<dist[start][min]){
              min=i;
            }
          }
        }
      }
    }



    clock_t floyd_warshall(){
      clock_t t=clock();
      for(int start=0;start<size;start++){
        for(int end=0;end<size;end++){
          if(start!=end){
            for(int mid=0;mid<size;mid++){
              if(start!=mid && end!=mid){
                int new_dist=dist[start][mid]+dist[mid][end];
                if(new_dist<dist[start][end]){
                  dist[start][end]=new_dist;
                }
              }
            }
          }
        }
      }
      t = clock() - t;
      reset_dist();
      return t;
    }

    void reset_dist(){
      dist=edges;
    }
};
