#include<bits/stdc++.h>
using namespace std;

struct item{
    int p;
    string name;
};

void insert_heap(item t,item* heap,int n);
item delete_heap(item* heap,int *n);

int main(void){
    int num;
    cin>>num;
    item heap[num+1];
    int p=0;
    string name="";
    item t;
    for(int i=1;i<=num;i++){
        cin>>name>>p;
        t.name=name;
        t.p=p;
        insert_heap(t,heap,i);
    }
    // for(int i=1;i<=num;i++){
    //     cout<<heap[i].name<<" "<<heap[i].p<<endl;
    // }
    cout<<"First three things to do:\n";
    for(int i=0;i<3;i++){
        cout<<delete_heap(heap,&num).name<<endl;
    }
}

void insert_heap(item t,item* heap,int n){
    int i=n;
    while((i!=1) && (t.p > heap[i/2].p)){
        heap[i]=heap[i/2];
        i/=2;
    }
    heap[i]=t;
}

item delete_heap(item* heap,int* n){
    item max=heap[1];
    item last=heap[(*n)--];
    int p=1,c=2;
    while(c<=*n){
        if(c<*n && heap[c].p<heap[c+1].p){
            c++;
        }
        if(last.p>=heap[c].p){
            break;
        }
        heap[p]=heap[c];
        p=c;
        c*=2;
    }
    heap[p]=last;
    return max;
}
// struct item {
//     string name;
//     int priority;

//     bool operator<(const item& other) const {
//         return other.priority < priority;
//     }
// };

// int main(void){
//     set <item> input;
//     int num=0;
//     cin>>num;
//     for(int i=0;i<num;i++){
//         string a="";
//         int p=0;
//         cin>>a>>p;
//         item t;
//         t.name=a;
//         t.priority=p;
//         input.insert(t);
//     }
//     int count=0;
//     cout<<"First three things to do:"<<endl;
//     for(auto i : input){
//         if(count<3){
//             cout<<i.name<<endl;
//             count++;
//         }
//         else{
//             break;
//         }
//     }
//     return 0;
// }