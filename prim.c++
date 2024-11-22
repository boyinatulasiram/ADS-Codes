#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class vertex{
    public:
    int v;
    int key;
    int parent;
};
class qvertex{
    public:
    int v;
    int key;
    qvertex(int v,int key)
    {
        this->v=v;
        this->key=key;
    }
    friend bool operator < (qvertex v1,qvertex v2);
};
bool operator < (qvertex v1,qvertex v2){
    return v1.key>v2.key;
}
void print(vector<vertex>& vertices){
    int mincost=0;
    cout<<"vertices  ";
    for(auto i: vertices){
        mincost+=i.key;
        cout<<i.v<<"  ";
    }
    cout<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"parent   ";
    for(auto i:vertices){
        cout<<i.parent<<"  ";
    }
    cout<<endl;
    cout<<"key       ";
    for(auto i:vertices){
        cout<<i.key<<"  ";
    }
    cout<<endl;
    cout<<"minimum cost of spanning tree is "<<mincost<<endl;
}
int main(){
    int n,sr;
    cout<<"enter no of vertices";
    cin>>n;
    cout<<"enter source vertex";
    cin>>sr;
    int w[9][9]={{0, 4, 0, 0, 0, 0, 0, 8,0},
               {4, 0, 8, 0,	0, 0, 0, 11, 0},
               {0, 8, 0, 7,	0, 4, 0, 0, 2},
               {0, 0, 7, 0,	9, 14,0, 0, 0},
               {0, 0, 0, 9, 0, 10, 0, 0, 0},
               {0, 0, 4, 14,10, 0, 2, 0, 0},
               {0, 0, 0, 0, 0, 2, 0, 1, 6},
               {8, 11, 0, 0, 0, 0, 1, 0, 7},
               {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    // vector to maintain vertices -parent and key
    vector<vertex> vertices(n);
    // initialization
    for(int i=0;i<n;i++){
            vertices[i].v=i;
            vertices[i].key=INT32_MAX;
            vertices[i].parent=-1;
    }
    // initialize source vertex 
    vertices[sr].key=0;
    // create a priority queue and push the data
    priority_queue<qvertex> pq;
    for(auto vr:vertices){
        qvertex q(vr.v,vr.key);
        pq.push(q);
    }
    // vector to check whether vertex is present in priority queue or not
    vector<bool> isPresent(n,false);
    while(!pq.empty()){
        qvertex u=pq.top();
        pq.pop();
        isPresent[u.v]=true;
        for(int i=0;i<n;i++)
        {
            if(w[u.v][i]!=0 && isPresent[i]==false && w[u.v][i]<vertices[i].key)
            {
                    vertices[i].parent=u.v;
                    vertices[i].key=w[u.v][i];
                    // it is equivalent to decrease-key operation on priority queue 
                    qvertex q(i,w[u.v][i]);
                    pq.push(q);
            }
        }
    }
    print(vertices);
    return 0;
}