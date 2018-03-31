#include<iostream>

using namespace std;

int main()
{
    cout<<"test"<<endl;
    int size;
    cin>>size;

    for(int r=0;r<size;r++){
      for(int c=0;c<size;c++){
        int w;
        cin<<w;
        cout<<w;
      }
      cout<<endl;
    }
    return 0;
}
