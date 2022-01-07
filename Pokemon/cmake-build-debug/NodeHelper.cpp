//
// Created by User on 06.01.2022.
//

#include "NodeHelper.h"
#include <iostream>
#include <string>

template <typename T>
void NodeHelper::showList(const Node<T> *head) {
    while(head){
        std::cout<<head->data<<" ";
        head = head->next;
    }

    std::cout<<std::endl;
}

template <typename T>
NodeHelper::Node <T> *NodeHelper::arrayToList(const T *a, size_t size) {
    if(size < 1)
        return nullptr;

    Node<T>* head = new Node<T>{a[0], nullptr};
    Node<T>* currentNode = head;

    for(int i=1; i < size; i++){
        Node<T>* next = new Node<T>{a[i], nullptr};
        currentNode = currentNode->next = next;
    }

    return head;
}

template <typename T>
void NodeHelper::deleteList(Node<T> *&head) {
    Node<T>* currentNode = head;

    while(currentNode){
        Node<T>* tmp = currentNode;
        currentNode = currentNode->next;
        std::cout<<"DEL "<<tmp->data<<";";
        delete(tmp);
    }

    std::cout<<std::endl;
}

template <typename T, typename Pred>
NodeHelper::Node <T> *NodeHelper::extract(Node<T> *&head, Pred pred) {
    Node<T>* headTruePred = nullptr;

    Node<T>* lastTruePred = nullptr;
    Node<T>* lastFalsePred = nullptr;

    Node<T>* currentNode = head;

    while(currentNode){
        if(pred(currentNode->data)){
            if(!lastTruePred)
                lastTruePred = headTruePred = currentNode;
            else{
                lastTruePred = lastTruePred->next = currentNode;
                lastFalsePred->next = nullptr;
            }
        }
        else{
            if(!lastFalsePred)
                lastFalsePred = head = currentNode;
            else{
                lastFalsePred = lastFalsePred->next = currentNode;
                lastTruePred->next = nullptr;
            }
        }

        currentNode = currentNode->next;
    }

    return headTruePred;
}