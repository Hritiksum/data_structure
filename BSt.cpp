#include<bits/stdc++.h>
using namespace std;

//tree node
class node{
public:
    int data;
    node* left;
    node* right;
    node(int d):data(d),right(NULL),left(NULL){}
};

//check whether two tree are identical or not
bool identical(node* t1,node *t2){
    if(t1==NULL && t2==NULL){
        return true;
    }
    else if(t1!=NULL && t2==NULL){
        return false;
    }
    else if(t1==NULL && t2!=NULL){
        return false;
    }
    else{
        if(t1->data==t2->data && identical(t1->left,t2->left) && identical(t1->right,t2->right)){
            return true;
        }else{
            return false;
        }
    }
}

//count number of leaf node
int countLeafnode(node* temp){
    if(temp==NULL){
        return 0;
    }
    if(temp->left==NULL && temp->right==NULL){
        return 1;
    }
    return countLeafnode(temp->left)+countLeafnode(temp->right);
}

//create an mirror of tree
node* mirror(node* root1,node* &root2){
    if(root1==NULL){
        return NULL;
    }
    if(root2==NULL){
        node* temp=new node(root1->data);
        temp->left=root1->right;
        temp->right=root1->left;
        return temp;
    }
    mirror(root1->left,root2);
    mirror(root1->right,root2);
    return root2;
}

//return min value
node* MinValueInTree(node* temp){
    node* Cache= temp;
    while(Cache && Cache->left!=NULL){
        Cache=Cache->left;
    }
    return Cache;
}

//to delete node
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

//to balance tree using vector
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

//to import tree into vector
void TreeIntoVector(node* temp, vector <node*> &v){
    if(temp==NULL){
        return;
    }
    TreeIntoVector(temp->left,v);
    v.push_back(temp);
    TreeIntoVector(temp->right,v);
}

//call to balance tree
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

//to check whether tree is balance or not and also return its height,diameter
Pair IsBalance(node* temp){
    Pair p;
    if(temp==NULL){
        p.height=0;
        p.diameter=0;
        p.balance=true;
        return p;
    }

    Pair left=IsBalance(temp->left);
    Pair right=IsBalance(temp->right);

    p.height=max(left.height,right.height)+1;

    int op1=left.height+right.height+1;
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

//print tree in inorder
void Inorder(node* temp){
    if(temp==NULL){
        return;
    }
    Inorder(temp->left);
    cout<<temp->data<<" ";
    Inorder(temp->right);
}

//print in lever order
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

//insert value in tree
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

//to create tree
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

    node* root1=NULL;
    node* root2=NULL;
    cout<<"Input data in first tree 'root1'"<<endl;
    CreateTree(root1);
    cout<<"1st tree Inorder print"<<endl;
    Inorder(root1);
    cout<<endl;
    cout<<"1st tree LevelOrder print"<<endl;
    LevelOrder(root1);
    Pair p1;
    p1=IsBalance(root1);
    if(p1.balance){
        cout<<"1st tree is balanced ,height= "<<p1.height<<" ,diameter= "<<p1.diameter<<endl;
    }
    else{
        cout<<"1st tree is not balanced ,height= "<<p1.height<<" ,diameter= "<<p1.diameter<<endl;
        cout<<endl<<"BALANCING TREE...."<<endl;
        root1=DoBalance(root1);
        p1=IsBalance(root1);
        LevelOrder(root1);
        cout<<"1st tree is balanced now,height= "<<p1.height<<" ,diameter= "<<p1.diameter<<endl;
    }
    int leaf=countLeafnode(root1);
    cout<<endl<<"Number of leaf node in tree is "<<leaf<<endl;

    root2=mirror(root1,root2);
    cout<<"mirror of 1st tree and store it in another node 'root2'"<<endl;
    LevelOrder(root2);
    cout<<endl<<"to check tree are same or not"<<endl;
    bool idt=identical(root1,root1);
    if(idt){
        cout<<"yes, both tree are true";
    }
    else{
        cout<<"No, tree are not identical";
    }


//    cout<<"Input data in second tree 'root1'"<<endl;
//    CreateTree(root2);
//    cout<<"2st tree Inorder print"<<endl;;
//    Inorder(root2);
//    cout<<"2st tree LevelOrder print"<<endl;
//    LevelOrder(root2);
//    Pair p2=IsBalance(root2 );
//    if(p2.balance){
//        cout<<"2st tree is balanced ,height= "<<p2.height<<" ,diameter= "<<p2.diameter<<endl;
//    }
//    else{
//        cout<<"2st tree is not balanced ,height= "<<p2.height<<" ,diameter= "<<p2.diameter<<endl;
//        cout<<endl<<"BALANCING TREE...."<<endl;
//        root2=IsBalance(root2);
//        cout<<"2st tree is balanced now,height= "<<p2.height<<" ,diameter= "<<p2.diameter<<endl;
//    }


//    node* root=NULL;
//    cout<<"Input Data"<<endl;
//    CreateTree(root);
//    cout<<endl<<"Inorder"<<endl;
//    Inorder(root);
//    cout<<endl<<endl<<"LevelOrder"<<endl;
//    LevelOrder(root);
//    Pair p=IsBalance(root);
//    if(p.balance){
//        cout<<endl<<"Tree is balance and it's height is "<<p.height<<" and its diameter is "<<p.diameter;
//    }
//    else{
//        cout<<endl<<"Tree is not balanced and it's height is "<<p.height<<" and its diameter is "<<p.diameter<<endl;
//        cout<<endl<<"BALANCING TREE...."<<endl;
//        root=DoBalance(root);
//        LevelOrder(root);
//        p=IsBalance(root);
//        cout<<endl<<"Tree is balanced now and its height is "<<p.height<<" and its diameter is "<<p.diameter;
//    }
//    cout<<endl<<"Want to delete number: if yes-input '1' if no-input '0'";
//    bool v;
//    cin>>v;
//    if(v==true){
//        cout<<endl<<"which number wants to delete"<<endl;
//        int key;
//        cin>>key;cout<<endl;
//        while(v){
//            root=Delete(root,key);
//            LevelOrder(root);
//            cout<<endl<<"Want to delete again: if yes-input '1' if no-input '0'"<<endl;
//            cin>>v;
//            cout<<endl;
//            if(v==false){
//                break;
//            }
//            cout<<endl<<"which number wants to delete"<<endl;
//            cin>>key;
//            cout<<endl;
//        }

//    }
    return 0;
}
