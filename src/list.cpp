#include "list.hpp"
#include <iosfwd>
#include <iostream>


namespace list {
// returns a linked list from a c-string s
Node* from_string(const char* s){
    Node* head = nullptr;
    Node* current = nullptr;
    while (*s!='\0') {
        if (head == nullptr) {
            head = current = new Node{*s, nullptr};
        }
        else {
            current->next = new Node{*s, nullptr};
            current =  current->next;
        }
        ++s;
    }
    return head;
}

// deletes all nodes of linked list
void free(Node* head) {
    while (head != nullptr) {
        Node *temp= head; 
        head = head->next;
        delete temp;
    }
}

// prints linked list to ostream out
void print(std::ostream& out, Node* head) {
    for (Node *p=head; p != nullptr; p=p->next) {
        out << p->data;
    }
}

// returns an exact duplicate of linked list starting at head
Node* copy(Node* head) {
    Node* new_head = nullptr;
    Node* current = nullptr;
    while (head != nullptr) {
        Node* new_node = new Node{head->data, nullptr};
        if (new_head == nullptr) {
            new_head = new_node;
        }
        else {
            current->next = new_node;
        }
        current = new_node;
        head = head->next;
    }
    return new_head;
}

// similar to strcmp but for lists
int compare(Node* lhs, Node* rhs){
    while (lhs != nullptr && rhs != nullptr) {
        if (lhs->data < rhs->data) {
            return -1;
        }
        else if (lhs->data > rhs->data){
            return 1;
        }
        lhs = lhs->next;
        rhs =  rhs->next;  
    }
    if (lhs == nullptr && rhs == nullptr) {
        return 0;
    }
    else if (lhs == nullptr) {
        return -1;
    }
    else {
        return 1;
    }
}

// similar to strncmp but for lists
int compare(Node* lhs, Node* rhs, int n) {
    for (int i = 0; i <n; i++) {
        if (lhs == nullptr && rhs == nullptr) {
            return 0;
        }
        else if (lhs == nullptr) {
            return -1;
        }
        else if (rhs == nullptr){
            return 1;
        }
        if (lhs->data > rhs->data) {
            return 1;
        }
        else if(lhs->data < rhs->data) {
            return -1;
        }
        lhs = lhs->next;
        rhs = rhs->next;
    }
    return 0;
}

// counts number of nodes in linked list
int length(Node * L) {
    int len = 0;
    for(Node *p = L; p!=nullptr; p=p->next) {
        len++;
    }
    return len;
}


// returns reversed copy of linked list
Node* reverse(Node* head) {
    Node* reversed_head = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* new_node = new Node{current->data, reversed_head};
        reversed_head = new_node;
        current = current->next;
    }
    return reversed_head;
}

// returns new list containing all nodes of lhs followed by all nodes of rhs
Node* append(Node* lhs, Node* rhs) {
    if (lhs == nullptr) {
        return copy(rhs);
    }
    Node* head = copy(lhs);
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = copy(rhs);
    return head;
}

// returns index of node in list starting at head
int index(Node* head, Node* node) {
    if (head == nullptr || node == nullptr) {
        return -1;
    }
    int i = 0;
    while (head != nullptr) {
        if (head == node) {
            return i;
        }
        i++;
        head = head->next;
    }
    return -1;
}

// similar to strchr but for a linked list
Node* find_char(Node* head, char c) {
    while (head != nullptr) {
        if (head->data == c) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

// similar to strstr but for two linked lists
Node* find_list(Node* haystack, Node* needle) {
    while (haystack != nullptr) {
        Node* h =  haystack;
        Node* n = needle;
        while (n!=nullptr && h!=nullptr && h->data==n->data) {
            h = h->next;
            n = n->next;
        }
        if (n==nullptr) {
            return haystack;
        }
        haystack = haystack->next;
    }
    return nullptr;
}

// get the nth node of linked list
Node* nth(Node* head, int n) {
    int i = 0;
    while (head != nullptr && i<n) {
        i++;
        head = head->next;
    }
    return head;
}

// get the last node of linked list
Node* last(Node* head) {
    while (head != nullptr and head->next!=nullptr) {
        head = head->next;
    }
    return head;
}

};

