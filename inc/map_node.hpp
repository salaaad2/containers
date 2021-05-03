#ifndef MAPNODE_H
# define MAPNODE_H

namespace ft {
    template <class T>
    struct m_node {
        T data;
        m_node * left;
        m_node * right;
        m_node * parent;

        m_node(T d) : data(d) {}
    };

}

#endif // MAPNODE_H
