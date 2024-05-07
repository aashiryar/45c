#include <compare>
#include <iosfwd>
#include <iostream>
#include "list.hpp"
#include "string.hpp"

using namespace std;

String::String(const char *s) {
    head = list::from_string(s);
} 

String::String(const String &s) {
    head = list::copy(s.head);
}

    // construct this string by moving from string s
String::String(String &&s) {
    head = s.head;
    s.head = nullptr;
}

    // swap this string with s
void String::swap(String &s) {
    list::Node* temp = head;
    head = s.head;
    s.head = temp;
}

    // assignment operator from one string, s, to this string
String& String::operator=(const String &s) {
    if (this !=&s) {
        String temp(s);
        swap(temp);
    }
    return *this;
}

    // assign to this string by moving
String& String::operator=(String &&s) {
    swap(s);
    return *this;
}

    // check if we can index at position i in this string
bool String::in_bounds(int index) const {
    if (index >= 0 && index < list::length(head)) {
        return true;
    }
    return false;
}

    // allow const indexing
char String::operator[](int index) const {
    if (in_bounds(index)) {
        list::Node *node = list::nth(head, index);;
        return node->data;
    }
    else {
        std::cout << "ERROR: Index out of bounds" << std::endl;
        return 0;
    }
}

    // returns the logical length of this string (# of chars up to '\0')
int String::size() const {
    return list::length(head);
}

    // returns a reversal of this string, does not modify this string
String String::reverse() const{
    String reversed;
    reversed.head = list::reverse(head);
    return reversed;
}

    // returns index into this string for first occurrence of c
int String::indexOf(char c) const {
    list::Node* node = list::find_char(head, c);
    if (node != nullptr) {
        return list::index(head, node);
    }
    return -1;
}

    // returns index into this string for first occurrence of s
int String::indexOf(const String &s) const {
    if (s.head == nullptr) {
        return 0;
    }
    list::Node* node = list::find_list(head, s.head);
    if (node != nullptr) {
        return list::index(head, node);
    }
    return -1;
}

    // compare this string with another string by equality
    // note: != is auto-generated since C++20
bool String::operator==(const String &s) const {
    return list::compare(head, s.head) == 0;
}

    // C++20 way of defining all comparisons at once
std::strong_ordering String::operator<=>(const String &s) const {
    return list::compare(head, s.head) <=> 0;
}

    // concatenate this and s to form a return string
String String::operator+(const String &s) const {
    String newstr;
    newstr.head = list::append(head, s.head);
    return newstr;
}

    // concatenate s onto the end of this string
String& String::operator+=(const String &s) {
    if (head == nullptr) {
        head = list::copy(s.head);
    } else {
        list::Node* tail = list::last(head);
        tail->next = list::copy(s.head);
    }
    return *this;
}
    // print this string, hint: use operator << to send buf to out
void String::print(std::ostream &out) const {
    list::print(out, head);
}

    // read next word into this string
    // hint: use operator >> to read from in into a temporary buffer
void String::read(std::istream &in){
    const int temp_size = 1024;
    char temp[temp_size];
    in >> temp;
    *this = String(temp);
}

    // destructor for this string
String::~String() {
    list::free(head);
}
String::String(list::Node* head) {
    this->head = head;
}
std::ostream &operator<<(std::ostream &out, const String &s) {
    s.print(out);
    return out;
}
std::istream &operator>>(std::istream &in, String &s){
    s.read(in);
    return in;
}