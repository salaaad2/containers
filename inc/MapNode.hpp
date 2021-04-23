#ifndef MAPNODE_H
#define MAPNODE_H

namespace ft {
    template <class Key,
              class T >
    struct s_node {
        Key key;
        T data;
        s_node * left;
        s_node * right;
    };

}

#endif // MAPNODE_H
