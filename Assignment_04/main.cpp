#include <iostream>
#include <string>

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
void showList(const Node<T>* head){
    while(head){
        std::cout<<head->data<<" ";
        head = head->next;
    }

    std::cout<<std::endl;
};

template <typename T>
Node<T>* arrayToList(const T a[], size_t size){
    if(size < 1)
        return nullptr;

    Node<T>* head = new Node<T>{a[0], nullptr};
    Node<T>* currentNode = head;

    for(int i=1; i < size; i++){
        Node<T>* next = new Node<T>{a[i], nullptr};
        currentNode = currentNode->next = next;
    }

    return head;
};

template <typename T, typename Pred>
Node<T>* extract(Node<T>*& head, Pred pred){
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
};

template <typename T>
void deleteList(Node<T>*& head){
    Node<T>* currentNode = head;

    while(currentNode){
        Node<T>* tmp = currentNode;
        currentNode = currentNode->next;
        std::cout<<"DEL "<<tmp->data<<";";
        delete(tmp);
    }

    std::cout<<std::endl;
};

bool isLong(const std::string& s) { return s.size() >= 5; }

int main() {
    int tabi[] = {2, 1, 4, 3, 6, 5, 7, 8};
    size_t sizei = sizeof(tabi) / sizeof(tabi[0]);
    Node<int> *listAi = arrayToList(tabi, sizei);
    showList(listAi);
    Node<int> *listBi = extract(listAi,
                                [](int n) {
                                    return n % 2 == 0;
                                });
    showList(listBi);
    showList(listAi);
    deleteList(listBi);
    deleteList(listAi);
    std::string tabs[]{"Kasia", "Ola", "Ala",
                       "Zosia", "Ela", "Basia"};
    size_t sizes = sizeof(tabs) / sizeof(tabs[0]);
    Node<std::string> *listAs = arrayToList(tabs, sizes);
    showList(listAs);
    Node<std::string> *listBs = extract(listAs, isLong);
    showList(listBs);
    showList(listAs);
    deleteList(listBs);
    deleteList(listAs);
}