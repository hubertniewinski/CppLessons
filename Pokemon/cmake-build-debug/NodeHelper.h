//
// Created by User on 06.01.2022.
//

#ifndef POKEMON_NODEHELPER_H
#define POKEMON_NODEHELPER_H


static class NodeHelper {
public:
    template <typename T>
    struct Node {
        T data;
        Node* next;
    };

    template <typename T>
    static void showList(const Node<T>* head);

    template <typename T>
    static Node<T>* arrayToList(const T a[], size_t size);

    template <typename T, typename Pred>
    static Node<T>* extract(Node<T>*& head, Pred pred);

    template <typename T>
    static void deleteList(Node<T>*& head);
};


#endif //POKEMON_NODEHELPER_H
