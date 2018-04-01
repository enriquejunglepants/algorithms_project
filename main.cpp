#include<iostream>
#include <stdlib.h>
#include "graph.cpp"
#include <time.h>
#include <cstdlib>

using namespace std;
//typedef chrono::high_resolution_clock Clock;

int main()
{
    clock_t t;

    int size;
    cout<<"Input number of vertices: ";
    cin>>size;
    graph g(size);
    //g.print();


    cout<<"Dijkstra's Algorithm: ";
    t=clock();

    for(int i=0;i<size;i++){
      g.dijkstra(i);
    }

    t = clock() - t;  //end point of clock
    cout << t<<" microseconds"<< endl;

    //g.print_dist();
    g.dist=g.edges;

    cout<<"Floyd-Warshall Algorithm: ";
    t = clock();

    g.floyd_warshall();

    t = clock() - t;  //end point of clock
    cout << t<<" microseconds"<< endl;

    //g.print_dist();

    return 0;
}
