#include<iostream>
#include <vector>

class DoubleLink{
private:
struct Node{
    struct Node *fwd;
    struct Node *bwd;
    int vlaue;    
};
public:
 int dll_insert(Node * rootp,int value);
};

int DoubleLink::dll_insert(Node* rootp, int value){
    Node * fd;
    Node * current;
    Node * next;

    for(int fd=rootp;(next=fd->fwd)!=nullptr;fd=next){
        if(next->vlaue==value){
            return 0;
        }
        if(next->vlaue>value){
            break;
        }
    }

    Node * newNode=new Node();
    if(newNode==nullptr){
        return -1;
    }
    newNode->vlaue=value;

    if(next!=nullptr){
        if(fd!=rootp){
            newNode->fwd=next;
            fd->fwd=newNode;
            newNode->bwd=fd;
            next->bwd=newNode;
        }else{
            newNode->fwd =next;
            rootp->fwd =newNode;
            newNode->bwd=nullptr;
            next->bwd=newNode;

        }
    }else{
        if(fd!=rootp){
            newNode->fwd=nullptr;
            fd->fwd=newNode;
            newNode->bwd=fd;
            rootp->bwd=newNode;
        }
        else{
            newNode->fwd=nullptr;
            rootp->fwd=newNode;
            newNode->bwd=nullptr;
            rootp->bwd=newNode;
        }
    }

}

//通过判断可知，双链表指针需要移动四个指针，插入数值的位置不同，链表中、链表头、链表尾、以及空指针四种形式。
//对其进行抽象简化，即可以得到下面的部分；

//变形一：
if(next!=nullptr){

         newNode->fwd=next;
        if(fd!=rootp){          
            fd->fwd=newNode;
            newNode->bwd=fd;
        }else{
            rootp->fwd =newNode;
            newNode->bwd=nullptr;
        }
        next->bwd=newNode;
    }else{
        newNode->fwd=nullptr;
        if(fd!=rootp){

            fd->fwd=newNode;
            newNode->bwd=fd;

        }
        else{
            rootp->fwd=newNode;
            newNode->bwd=nullptr;

        }
         rootp->bwd=newNode;
    }
//变形二：

    if(next!=nullptr){
        newNode->fwd=next;
    }else{
        newNode->fwd=nullptr;
    }

    if(fd!=rootp){          
         fd->fwd=newNode;
         newNode->bwd=fd;
    }else{
        rootp->fwd =newNode;
        newNode->bwd=nullptr;
    }

    rootp->bwd=newNode;