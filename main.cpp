#include<iostream>
#include <stdlib.h>
#include "graph.cpp"
#include <time.h>
#include <cstdlib>

using namespace std;
int main()
{
    for(int size=50;size<=500;size+=50){
      graph g(size);
      cout<<size<<","<<g.dijkstra()<<","<<g.floyd_warshall()<<endl;
    }
    return 0;
}
