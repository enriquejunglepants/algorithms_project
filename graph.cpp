#include<vector>
#include <stdlib.h>
#include<iostream>
#include <time.h>
#include <fstream>

using namespace std;

const int INF = 9999999;

class graph{
  public:
    int MAX_WEIGHT;
    int** edges;
    int**  dist1;
    int**  dist2;
    bool**  hit;
    int size;

    graph(int s){
      size=s;
    }

    void print(){
      int max_print = 5;
      for(int r=0;r<size;r++){
        for(int c=0;c<size;c++){

          cout<<edges[r][c]<<"\t";
        }
        cout<<endl;
      }
      cout<<endl;
    }

    void print_dist(){
      ofstream out_file;
      out_file.open("solution.txt");
      for(int r=0;r<size;r++){
        for(int c=0;c<size;c++){
          out_file<<dist2[r][c]<<"\t";
        }
        out_file<<"\n";
      }
      out_file<<"\n";
    }

    string print_dist2(){
      string s="";
      for(int r=0;r<size;r++){
        for(int c=0;c<size;c++){
          s+=dist2[r][c]+"\t";
        }
        s+="\n";
      }
      s+="\n";
      //cout<<s<<endl;
      return s;
    }

    clock_t dijkstra(){
      clock_t t=clock();

      for(int i=0;i<size;i++){
        dijkstra(i);
      }
      t = clock() - t;
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
            int new_dist = dist1[start][v] + edges[v][i];

            if(new_dist < dist1[start][i]){
              dist1[start][i] = new_dist;
            }

            if(min==-1 || dist1[start][i]<dist1[start][min]){
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
                int new_dist=dist2[start][mid]+dist2[mid][end];
                if(new_dist<dist2[start][end]){
                  dist2[start][end]=new_dist;
                }
              }
            }
          }
        }
      }
      t = clock() - t;
      print_dist();
      return t;
    }
};
