#ifndef LISTNODE_H
#define LISTNODE_H

namespace ft {
    template <class T>
    struct s_node {
        T data;
        s_node * next;
        s_node * prev;
    };
}

#endif // NODE_H
