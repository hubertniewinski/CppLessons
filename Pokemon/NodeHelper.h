//
// Created by User on 06.01.2022.
//

#ifndef POKEMON_NODEHELPER_H
#define POKEMON_NODEHELPER_H

class NodeHelper {
public:
    template <typename T>
    struct Node {
        T data;
        Node* next;
    };

    template <typename T>
    void showList(const Node<T>* head);

    template <typename T>
    Node<T>* arrayToList(const T a[], size_t size);

    template <typename T, typename Pred>
    Node<T>* extract(Node<T>*& head, Pred pred);

    template <typename T>
    void deleteList(Node<T>*& head);
};


#endif //POKEMON_NODEHELPER_H
