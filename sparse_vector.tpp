#include "sparse_vector.hpp"
//constructor
template<typename T>
SparseVector<T>::SparseVector() {
	guard.next = guard.prev = &guard;
}
template<typename T>
SparseVector<T>::SparseVector(std::size_t length) {
    guard.next = guard.prev = &guard;
    size = length;//initialize size
}

// copy constructor
template<typename T>
SparseVector<T>::SparseVector(const SparseVector<T>& x) {
    guard.next = guard.prev = &guard;
    NodePtr xcurr = x.guard.next;//the node next to the guard node in the rhs
    NodePtr curr = &guard;
    while(xcurr != &x.guard) {
        NodePtr temp = new Node<T>;
        temp->data = xcurr->data;
        temp->position = xcurr->position;
        size = x.size;
        temp->prev = curr;
        temp->next = &guard;
        curr->next = temp;
        guard.prev = temp;
        xcurr = xcurr->next;
        curr = temp;
    }

}
template<typename T>
SparseVector<T>::SparseVector(SparseVector<T>&& x) {
    std::swap(size, x.size);
    if (size > 0) {
        guard.next = x.guard.next;
        x.guard.next = &x.guard;
        guard.prev = x.guard.prev;
        x.guard.prev = &x.guard;
        guard.next->prev = &guard;
        guard.prev->next = &guard;
    }
    else {
        guard.prev = guard.next = &guard;
    }
}
template<typename T>
SparseVector<T>::~SparseVector() {
    clear();
}

template<typename T>
SparseVector<T>& SparseVector<T>::operator=(const SparseVector<T>& x) {
    if (this != &x) {
        clear();   
        //guard.next = guard.prev = &guard;
        NodePtr xcurr = x.guard.next;
        NodePtr curr = &guard;
        while (xcurr != &x.guard) {
            NodePtr temp = new Node<T>;
            temp->data = xcurr->data;
            temp->position = xcurr->position;
            size = x.size;
            temp->prev = curr;
            temp->next = &guard;
            curr->next = temp;
            guard.prev = temp;
            xcurr = xcurr->next;
            curr = temp;       
        }
    }
    return *this;
}
// TODO
template<typename T>
SparseVector<T>& SparseVector<T>:: operator=(SparseVector<T>&& x) {
    clear();
    if (this != &x) {
        std::swap(size, x.size);
        if (size > 0) {
            guard.next = x.guard.next;
            x.guard.next = &x.guard;
            guard.prev = x.guard.prev;
            x.guard.prev = &x.guard;
            guard.next->prev = &guard;
            guard.prev->next = &guard;
        }
    }

    return *this;
}
template<typename T>
void SparseVector<T>::clear() {

    NodePtr curr = guard.next;
    while (curr != &guard) {
        guard.next = curr->next;
        delete curr;
        size--;
        curr = guard.next;
    }
}

template<typename T>
std::size_t SparseVector<T>::length() const noexcept {
    return size;
}
//get entry
template<typename T>
const T& SparseVector<T>::operator() (std::size_t index) const {
    if (index== 0 || index > size) {
        throw std::invalid_argument("invalid index");
    }
   // NodePtr curr = find(index);
    NodePtr curr = guard.next;
    while (curr != &guard) {
        if (index == curr->position) {
            return curr->data;
        }
        else if (index < curr->position) {
            break;
        }
        else if (index > curr->position) {
            curr = curr->next;
        }
    }

    return default_value;
}

template<typename T>
T& SparseVector<T>::operator()(std::size_t index) {
    if (index == 0 || index > size) {
        throw std::invalid_argument("invalid index!");
    }
    NodePtr curr = guard.next;
    while (curr != &guard) {
        if (index == curr->position) {
            return curr->data;
        }
        else if (index < curr->position) {
            break;
        }
        else if (index > curr->position) {
            curr = curr->next;
        }
    }
    NodePtr temp = new Node<T>;
    temp->data = T();
    temp->position = index;
    curr->prev->next = temp;
    temp->prev = curr->prev;
    temp->next = curr;
    curr->prev = temp;
    return temp->data;
    
}