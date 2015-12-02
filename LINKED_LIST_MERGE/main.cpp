//
//  main.cpp
//  LINKED_LIST_MERGE
//
//  Created by Chandan Paul on 12/2/15.
//  Copyright © 2015 Chandan Paul. All rights reserved.
//

#include <iostream>

typedef struct node
{
    int val;
    struct node* next;
    node(int value):val(value),next(NULL){}
}LNode;

LNode* getMergedAndReversedNode(LNode* l1, LNode* l2){
    LNode* result = NULL;
    if(!l1 and !l2){
        return NULL;
    }
    if(!l1){ return l2;}
    else if(!l2){return l1;}
    if(l1->val < l2->val){
        result = l1;
        result->next = getMergedAndReversedNode(l1->next, l2);
    }else{
        result = l2;
        result->next = getMergedAndReversedNode(l1,l2->next);
    }
    return result;
}

LNode* getReversedList(LNode* start){
    LNode *iter = start;
    while(iter->next != NULL){
        LNode* temp= iter->next;
        iter->next = temp->next;
        temp->next = start;
        start = temp;
    }
    return start;
}

void printTheList(LNode *res){
    std::cout<< "The List is \n";
    while(res!=NULL){
        std::cout<< res->val<<"\n";
        res= res->next;
    }
}


int main() {
    LNode* lnode = new LNode(5);
    lnode->next = new LNode(10);
    lnode->next->next = new LNode(15);
    lnode->next->next->next = new LNode(40);
    LNode* lnode2 = new LNode(2);
    lnode2->next = new LNode(3);
    lnode2->next->next = new LNode(20);
    //LNode *result = getMergedAndReversedNode(lnode,lnode2);
    LNode *result = getMergedAndReversedNode(NULL,lnode);
    if(result){
        result = getReversedList(result);
        printTheList(result);
    }else{
        std::cout<<"not Possible\n";
    }
    return 0;
}
