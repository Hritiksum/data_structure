#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d):data(d),right(NULL),left(NULL){}
};

int countLeafnode(node* temp){
    if(temp==NULL){
        return 0;
    }
    if(temp->left==NULL && temp->right==NULL){
        return 1;
    }
    return countLeafnode(temp->left)+countLeafnode(temp->right);
}



node* MinValueInTree(node* temp){
    node* Cache= temp;
    while(Cache && Cache->left!=NULL){
        Cache=Cache->left;
    }
    return Cache;
}

node* Delete(node* &temp, int data){
    if(temp==NULL){
        return NULL;
    }
    if(temp->data>data){
        temp->left=Delete(temp->left,data);
    }
    else if(temp->data<data){
        temp->right=Delete(temp->right,data);
    }
    else{
        if(temp->left==NULL){
            node* Cache=temp->right;
            free(temp);
            return Cache;
        }
        else if(temp->right==NULL){
            node* Cache=temp->left;
            free(temp);
            return Cache;
        }
        node* Cache=MinValueInTree(temp->right);
        temp->data=Cache->data;
        temp->right=Delete(temp->right,Cache->data);
    }
    return temp;
}

node* BalancedTree(vector <node*> v, int Start,int End){
    if(Start>End){
        return NULL;
    }
    int mid=(Start+End)/2;
    node* temp=v[mid];
    temp->left=BalancedTree(v,Start,mid-1);
    temp->right=BalancedTree(v,mid+1,End);
    return temp;
}

void TreeIntoVector(node* temp, vector <node*> &v){
    if(temp==NULL){
        return;
    }
    TreeIntoVector(temp->left,v);
    v.push_back(temp);
    TreeIntoVector(temp->right,v);
}

node* DoBalance(node* &root){
    vector <node*> v;
    TreeIntoVector(root,v);
    int s=v.size();
    return BalancedTree(v,0,s-1);
}

class Pair{
public:
    int height;
    int diameter;
    bool balance;
};

Pair IsBalance(node* temp){
    Pair p;
    if(temp==NULL){
        p.height=0;
        p.diameter=1;
        p.balance=true;
        return p;
    }

    Pair left=IsBalance(temp->left);
    Pair right=IsBalance(temp->right);

    p.height=max(left.height,right.height)+1;

    int op1=left.height+right.height;
    int op2=left.diameter;
    int op3=right.diameter;
    p.diameter=max(op1,max(op2,op3));

    if(left.balance && right.balance && abs(left.height-right.height)<=1){
        p.balance=true;
    }
    else{
        p.balance=false;
    }
    return p;
}

void Inorder(node* temp){
    if(temp==NULL){
        return;
    }
    Inorder(temp->left);
    cout<<temp->data<<" ";
    Inorder(temp->right);
}

void LevelOrder(node* temp){
    queue <node*> q;
    q.push(temp);
    q.push(NULL);
    while(!q.empty()){
        node* cache=q.front();
        q.pop();
        if(cache!=NULL){
            cout<<cache->data<<" ";
            if(cache->left){
                q.push(cache->left);
            }
            if(cache->right){
                q.push(cache->right);
            }
        }
        else{
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }

}

node* InsertValue(node* &temp,int data){
    if(temp==NULL){
        temp=new node(data);
        return temp;
    }
    if(temp->data>data){
        temp->left=InsertValue(temp->left,data);
    }
    else{
        temp->right=InsertValue(temp->right,data);
    }
    return temp;
}

void CreateTree(node* &root){
    int data;
    node* temp=NULL;
    cin>>data;
    while(data>0){
        temp=InsertValue(temp,data);
        cin>>data;
    }
    root=temp;
}

int main(){
    node* root=NULL;
    cout<<"Input Data"<<endl;
    CreateTree(root);
    cout<<endl<<"Inorder"<<endl;
    Inorder(root);
    cout<<endl<<endl<<"LevelOrder"<<endl;
    LevelOrder(root);
    Pair p=IsBalance(root);
    if(p.balance){
        cout<<endl<<"Tree is balance and it's height is "<<p.height<<" and its diameter is "<<p.diameter;
    }
    else{
        cout<<endl<<"Tree is not balanced and it's height is "<<p.height<<" and its diameter is "<<p.diameter<<endl;
        cout<<endl<<"BALANCING TREE...."<<endl;
        root=DoBalance(root);
        LevelOrder(root);
        p=IsBalance(root);
        cout<<endl<<"Tree is balanced now and its height is "<<p.height<<" and its diameter is "<<p.diameter;
    }
    cout<<endl<<"Want to delete number: if yes-input '1' if no-input '0'";
    bool v;
    cin>>v;
    if(v==true){
        cout<<endl<<"which number wants to delete"<<endl;
        int key;
        cin>>key;cout<<endl;
        while(v){
            root=Delete(root,key);
            LevelOrder(root);
            cout<<endl<<"Want to delete again: if yes-input '1' if no-input '0'"<<endl;
            cin>>v;
            cout<<endl;
            if(v==false){
                break;
            }
            cout<<endl<<"which number wants to delete"<<endl;
            cin>>key;
            cout<<endl;
        }
        int leaf=countLeafnode(root);
        cout<<"Number of leaf node in tree is "<<leaf;
    }
    return 0;
}
