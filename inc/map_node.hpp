#ifndef MAPNODE_H
#define MAPNODE_H

namespace ft {
    template <class T>
    struct s_node {
        T data;
        s_node * left;
        s_node * right;
        s_node * parent;

        s_node(T d) : data(d) {}
    };

}

#endif // MAPNODE_H
