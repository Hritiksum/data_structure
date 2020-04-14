#include<bits/stdc++.h>
using namespace std;

//linklist node
class node{
public:
    int data;
    node* next;
    node(int d):data(d),next(NULL){}
};

//lenght of LL
int Lenghtll(node* head){
    if(head==NULL){
        return 0;
    }
    int lenght=0;
    node* temp=head;
    while(temp){
        temp=temp->next;
        lenght++;
    }
    return lenght;
}
//print Linklist
void printLL(node* head){
    if(head==NULL){
        cout<<"END";
        return;
    }
    cout<<head->data<<"-->";
    printLL(head->next);
}

node* InsertFront(node* &head,node* &tail,int data){
    if(head==NULL){
        node* temp=new node(data);
        head=tail=temp;
    }else{
        node* temp=new node(data);
        temp->next=head;
        head=temp;
    }
}

//insert at end of linklist
node* InsertEnd(node* &head,node* &tail,int data){
    if(head==NULL){
        node* temp=new node(data);
        head=tail=temp;
    }
    else{
        node* temp=new node(data);
        tail->next=temp;
        tail=temp;
    }
}


node* InsertMid(node* &head,node* &tail,int pos,int data){
    if(pos==0){
        InsertFront(head,tail,data);
    }
    else if(pos>=Lenghtll(head)){
        InsertEnd(head,tail,data);
    }
    else{
        int jump=1;
        node* Cache=head;
        while(jump<=pos-1){
            Cache=Cache->next;
            jump++;
        }
        node* temp=new node(data);
        temp->next=Cache->next;
        Cache->next=temp;
    }
}




//insert at front
node* Insert(node* &head,node* &tail,int data){
    if(head==NULL){
        node* temp=new node(data);
        head=tail=temp;
    }
    else{
        node* temp=new node(data);
        tail->next=temp;
        tail=temp;
    }
}



//call insert funtion to create linklist
node* Create(node* &head, node* &tail){
    int data;
    cout<<"input data"<<endl;
    cin>>data;
    while(data>0){
        Insert(head,tail,data);
        cin>>data;
    }
//    return head;
    //cout<<head->data<<head->next->data;
}

int main(){
    //linklist head and tail
    node* head=NULL;
    node* tail=NULL;
    //function to create linklist
    Create(head,tail);
//    InsertFront(head,tail,data);
//    InsertEnd(head,tail,data);
//    InsertMid(head,tail,3,100);


    printLL(head);
}
