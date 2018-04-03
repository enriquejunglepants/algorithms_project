#include<iostream>
#include <fstream>
#include <stdlib.h>
#include "graph.cpp"
#include "edge.cpp"
#include <time.h>
#include <cstdlib>
#include <queue>

using namespace std;

void generate_graphs(){
  int num_graphs;
  int size;
  int min_w;
  int max_w;
  int gen_type;

  cout<<"how many graphs do you want? ";
  cin>>num_graphs;
  cout<<"how many vertices on each graph? ";
  cin>>size;
  cout<<"choose an edge strategy:\n0) give all edges random weights in a range\n1) give all edges increasing weights\n2) give all edges decreasing weights\n? ";
  cin>>gen_type;
  if(gen_type==0){
    cout<<"what should the minimum edge weight be? ";
    cin>>min_w;
    cout<<"what should the maximum edge weight be? ";
    cin>>max_w;
  }

  ofstream out_file;
  out_file.open("generated_graphs.txt");
  out_file<<num_graphs<<endl;
  out_file<<size<<endl;
  for(int g=0;g<num_graphs;g++){
    int i=1;
    for(int r=0;r<size;r++){
      for(int c=0;c<size;c++){
        if(r==c){
          out_file<<0<<"\t";
        }
        else{
          switch (gen_type) {
            case 0:out_file<< (rand() % (max_w-min_w))+min_w<<"\t";break;
            case 1:out_file<< i++; break;
            case 2:out_file<< size*(size-1) - i++; break;
          }
        }
      }
      out_file<<endl;
    }
  }
}

int main(int argc, char* argv[])
{
    if(argc==1){
      generate_graphs();
    }
    else{

      ifstream in_file;
      in_file.open(argv[1]);

      int num_graphs;
      int size;
      in_file>>num_graphs;
      in_file>>size;

      for(int i=0;i<num_graphs;i++){
        graph g(size);

        g.edges= new int*[size];
        g.dist1= new int*[size];
        g.dist2= new int*[size];
        g.hit=new bool*[size];

        for(int r=0;r<size;r++){
          g.edges[r]=new int[size];
          g.dist1[r]=new int[size];
          g.dist2[r]=new int[size];
          g.hit[r]=new bool[size];
          for(int c=0;c<size;c++){
            in_file>>g.edges[r][c];
            g.dist1[r][c]=INF;
            g.dist2[r][c]=INF;
          }
        }
        g.print();

        //g.input_graph(in_file);
        cout<<"Dijkstra: "<<g.dijkstra()<<" microseconds | F-W: "<<g.floyd_warshall()<<" microseconds"<<endl;
      }

    }

    return 0;
}
