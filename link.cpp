#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    struct Node * link;
    int m_Value;
} node;


int sll_insert(Node *current ,int new_value){
    Node* previous ;
    Node* newNode1;

    /* 插入新的节点，按顺序访问链表，直到其大于或者等于新插入的值*/
    while(current->m_Value<new_value){
        previous=current;
        current=current->link;
    }

    //为新节点分配内存，把新值存储到新的节点中，如果内存分配失败，函数返回false

    Node * newNode=new Node();
    if(newNode==nullptr){
        return false;
    }
    newNode->m_Value=new_value;

    //把新的节点的插入链表，并返回true；
    newNode1->link=current;
    previous->link=new;
    return True;
}
//上述程序缺少一个边界条件，即不能够将数据插入到队尾，同时插入到第一个位置也将发生变化，


//===================================================
//方法二：进行改进，对首尾节点进行处理
//======================================================

int sll_insert(Node ** rootp ,int new_value){
    Node* previous ;
    Node* current;
    Node* pNode;

    current=*rootp;
    previous=nullptr;
      

    /* 插入新的节点，按顺序访问链表，直到其大于或者等于新插入的值*/
    while(current!=nullptr&&current->m_Value<new_value){
        previous=current;
        current=current->link;
    }

    //为新节点分配内存，把新值存储到新的节点中，如果内存分配失败，函数返回false

    Node * newNode=new Node();
    if(newNode==nullptr){
        return false;
    }
    newNode->m_Value=new_value;

    //把新的节点的插入链表，并返回true；
    newNode->link=current;
    if(previous==nullptr){//对于边界条件进行处理
        *rootp=newNode;
    }else{
        previous->link=newNode;
    }
    return True;
}


//===================================================
//方法三：进行改进，通过指向指针地址进行遍历节点，提高程序运行的速度
//======================================================

int sll_insert(register Node ** rootp ,int new_value){
    Node* current;
    Node* pNode;

    current=*rootp;
    previous=nullptr;
      

    /* 插入新的节点，按顺序访问链表，直到其大于或者等于新插入的值,采用直接地址访问的形式进行 */
    while((current=*rootp)!=nullptr&&current->m_Value<new_value){
        rootp=&rootp->link;
    }

    //为新节点分配内存，把新值存储到新的节点中，如果内存分配失败，函数返回false

    Node * newNode=new Node();
    if(newNode==nullptr){
        return false;
    }
    newNode->m_Value=new_value;

    //把新的节点的插入链表，并返回true；
    newNode->link=current;

    *rootp=newNode;
    
    return True;
}






