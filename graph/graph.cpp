#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
// class node{
//     int data;
//     node* next;
// };

class graph{
    private:
    list<int>*l;
    int v;
    public:
    graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    void addedge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);

    }
    void bfs(){
        queue<int> q;
        vector<int>vec(v,false);
        q.push(0);
        vec[0] = true;
        while (q.size()>0)
        {
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            for (int n : l[u])
            {
                if (!vec[n])
                {
                   vec[n]= true;
                   q.push(n);
                }
                
            }
            
        
        }
        
    }
    
    
};


int main(){
    graph test(6);
    test.addedge(0,1);
    test.addedge(1,2);
    test.addedge(1,3);
    test.addedge(2,4);
    test.addedge(3,5);
   
    test.bfs();
    return 0 ;
}