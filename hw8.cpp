#include<bits/stdc++.h>
using namespace std;

struct path{
    int from;
    int to;
    int weight;
    int visited=0;
};

int unionset[10000];
int num[10000];
int findParent(int a);
bool cmp(path a,path b){
  return a.weight < b.weight; 
}

int main(void){
    int cityNum,caseNum;
    cin>>cityNum>>caseNum;
    
    for(int i=0;i<cityNum;i++){
        unionset[i]=i;
        num[i]=1;
    }
    path input[caseNum];
    for(int i=0;i<caseNum;i++){
        path p;
        cin>>p.from>>p.to>>p.weight;
        if(p.from>p.to){
            int temp=p.from;
            p.from=p.to;
            p.to=temp;
        }
        input[i]=p;
    }

    for(int i=0;i<caseNum;i++){
        for(int j=0;j<caseNum;j++){
            if((input[i].weight<input[j].weight)){
                path p=input[j];
                input[j]=input[i];
                input[i]=p;
            }
        }
    }
    //sort(input, input + caseNum, cmp);
    

    // for(int i=0;i<caseNum;i++){
    //     cout<<input[i].from<<" "<<input[i].to<<" "<<input[i].weight<<" "<<input[i].visited<<endl;
    // }

    int totalCost=0;
    int edge=0;
    for(int i=0;i<caseNum && edge<cityNum;i++){
        int a=findParent(input[i].from);
        int b=findParent(input[i].to);
        if(a!=b){
            if (num[a]>num[b]){ 
                unionset[b]=a;
                num[a]+=num[b];                   
            } 
            else {
                unionset[a]=b;
                num[b]+=num[a];                   
            }
            input[i].visited=1;
            totalCost+=input[i].weight;
            edge++;
            //cout<<input[i].from<<" "<<input[i].to<<" "<<input[i].weight<<" "<<input[i].visited<<endl;
        }
        else{
            input[i].visited=0;
        }
    }

    for(int i=0;i<caseNum-1;i++){
        for(int j=0;j<caseNum;j++){
            if(input[i].from<input[j].from){
                path p=input[j];
                input[j]=input[i];
                input[i]=p;
            }
            else if(input[i].from==input[j].from){
                if(input[i].to<input[j].to){
                    path p=input[j];
                    input[j]=input[i];
                    input[i]=p;
                }
            }
        }
    }

    cout<<totalCost<<endl;
    for(int i=0;i<caseNum;i++){
        if(input[i].visited==1){
            cout<<"city"<<input[i].from<<" - city"<<input[i].to<<"\n";
        }
    }
}

int findParent(int a){ 
  while(a!=unionset[a]){
    a=unionset[a];                  
  }    
  return a;   
}