#include<iostream>
#include<set>
using namespace std;
struct path{
    int v;
    path * p;
};

path* Adj_List[51];
int dfn[51],low[51];
int num=0;
void dfnlow(int child ,int parent);
set<int> AP;

int main(void){
    for(int i=0;i<50;i++){
        dfn[i]=-1;
        low[i]=-1;
    }

    int a,b;
    while((cin>>a>>b)){
        path * input1=new path;
        input1->v=a;
        input1->p=NULL;

        path * input2=new path;
        input2->v=b;
        input2->p=NULL;

        //cout<<input1->v<<" "<<input2->v<<endl;

        path * now1=Adj_List[a];
        if(!now1){
            Adj_List[a]=input2;
        }
        else{
            while(now1->p){
                now1=now1->p;
            }
            now1->p=input2;
        }

        path * now2=Adj_List[b];
        if(!now2){
            Adj_List[b]=input1;
        }
        else{
            while(now2->p){
                now2=now2->p;
            }
            now2->p=input1;
        }
    }

    // for(int i=0;i<50;i++){
    //     path * ptr=Adj_List[i];
    //     if(ptr){
    //         while(ptr){
    //             cout<<ptr->v<<" ";
    //             ptr=ptr->p;
    //             }
    //         cout<<endl;
    //     }   
    //     else{
    //         break;
    //     }
    // }
    
    for (int i = 0; i < 50; i++) {
        if (dfn[i] < 0) {
            dfnlow(i, -1);
        }
    }
    // for(int i=0;i<50;i++){
    //     cout<<dfn[i]<<" "<<low[i]<<endl;
    // }
    if(AP.empty()){
        cout<<"true";
    }
    else{
        cout<<"false\n";
        for(auto i:AP){
            cout<<i<<" ";
        }
    }
    
}

void dfnlow(int child, int parent) {
    path * ptr;
    int w;
    dfn[child] = low[child] = num++;
    int childCount = 0;  // 計算子節點數量
    for(ptr = Adj_List[child]; ptr; ptr = ptr->p) {
        w = ptr->v;
        if(dfn[w] < 0) {
            childCount++;
            dfnlow(w, child);
            low[child] = min(low[child], low[w]);

            // Check for articulation point
            if(low[w] >= dfn[child]) {
                if(parent >= 0 || childCount > 1) {
                    AP.insert(child);
                }
            }
        } 
        else if(w != parent) {
            low[child] = min(low[child], dfn[w]);
        }
    }
}