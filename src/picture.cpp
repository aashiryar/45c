#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture() : head(nullptr), tail(nullptr) {}
Picture::Picture(const Picture& other)  {
    head = nullptr;
    tail = nullptr;
    for (ListNode* n = other.head; n != nullptr; n = n->next) {
        add(*n->shape);
    }
}
Picture::Picture(Picture&& other) {
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}
void Picture::swap(Picture& other) {
    ListNode* temphead = head;
    ListNode* temptail = tail;
    head = other.head;
    tail = other.tail;
    other.head = temphead;
    other.tail = temptail;
}
Picture& Picture::operator=(const Picture& other) {
    if (this!=&other) {
        Picture temp(other);
        swap(temp);
    }
    return *this;
}
Picture& Picture::operator=(Picture&& other) {
    if (this!=&other) {
        swap(other);
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}
void Picture::add(const Shape& shape) {
    Shape* newShape = shape.clone();
    ListNode* newNode = new ListNode{newShape, nullptr};
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } 
    else {
        tail->next = newNode;
        tail = newNode;
    }
}
void Picture::print_all(std::ostream& out) const {
    for(ListNode* n = head; n != nullptr; n=n->next) {
        n->shape->print(out);
        //out <<'\n';
       //n->shape->draw(out);
        //if (n->next != nullptr) {
           // out << '\n'; 
        //}
    }
}
void Picture::draw_all(std::ostream& out) const {
    for (ListNode* n = head; n != nullptr; n =n->next) {
        n->shape->draw(out);
        //out <<'\n';
    }
}
double Picture::total_area() const{
    double total = 0.0;
    for (ListNode* n = head; n != nullptr; n=n->next) {
        total+=n->shape->area();
    }
    return total;
}
Picture::~Picture() {
    while(head != nullptr) {
        ListNode*temp = head;
        head = head->next;
        delete temp->shape;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}