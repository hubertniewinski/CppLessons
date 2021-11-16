#include <iostream>

struct Node{
    int data;
    Node* next;
};

Node* arrayToList(const int arr[], size_t size){
    Node* head = new Node();
    head->data = arr[0];
    Node* currentNode = head;

    for(int i=1;i<size;i++){
        Node* tmp = new Node();
        tmp->data = arr[i];
        currentNode->next = tmp;
        currentNode = currentNode->next;
    }

    return head;
}

Node* removeOdd(Node* head){
    Node* firstValid = nullptr;
    Node* lastValid = nullptr;

    while(head){
        while(lastValid && lastValid->next && lastValid->next->data % 2 ==1)
            lastValid->next = lastValid->next->next;

        if(head->data % 2 == 1){
            Node* tmp = head->next;
            std::cout<<"DEL: "<<head->data;std::cout<<" ";
            delete(head);
            head = tmp;
        }
        else{
            if(!firstValid)
                firstValid = head;

            lastValid = head;

            head = head->next;
        }
    }
    std::cout<<std::endl;

    return firstValid;
}

void showList(const Node* head){
    if(head){
        std::cout<<head->data<<" ";
        if(head->next){
            showList(head->next);
        }
        else
            std::cout<<std::endl;
    }
    else{
        std::cout<<std::endl;
        std::cout<<"Empty list.";
    }
}

void deleteList(Node*& head){
    if(head->next){
        Node*& next = head->next;
        std::cout<<"DEL: "<<head->data;std::cout<<" ";
        head = nullptr;
        deleteList(next);
    }
    else{
        std::cout<<"DEL: "<<head->data;std::cout<<" ";
        head = nullptr;
    }
}


int main() {
    int arr[] = {1,2,3,4,5,6};
    size_t size = sizeof(arr)/sizeof(*arr);
    Node* head = arrayToList(arr,size);
    showList(head);

    head = removeOdd(head);
    showList(head);
    deleteList(head);
    showList(head);

    return 0;
}
