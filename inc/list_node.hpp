#ifndef LISTNODE_H
#define LISTNODE_H

namespace ft {
    template <class T>
    struct l_node {
        T data;
        l_node * next;
        l_node * prev;
    };
}

#endif // NODE_H
