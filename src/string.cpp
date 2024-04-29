#include <iosfwd>
#include <iostream>
#include "string.hpp"
using namespace std;

String::String(const char *s) : buf(strdup(s)) {}

String::String(const String &s) : buf(strdup(s.buf)) {}
//move constructor
String::String(String &&s) {
    buf = s.buf;
    s.buf = nullptr;
}
void String::swap(String &s) {
    std::swap(buf, s.buf);
}
String& String::operator=(String &&s) {
    if (this != &s) {
        delete[] buf;
        buf = s.buf;
        s.buf = nullptr;
    }
    return *this;
}
//copy  assignment
String& String::operator=(String &s) {
    if (this != &s) {
        delete[] buf;
        buf = strdup(s.buf);
    }
    return *this;
}
char& String::operator[](int index){
    if (in_bounds(index)) {
        return buf[index];
    } 
    else {
        cout << "ERROR: Index Out Of Bounds" << endl;
        return buf[0];
    }
}
const char& String::operator[](int index) const {
    if (in_bounds(index)) {
        return buf[index];
    } 
    else {
        cout << "ERROR: Index Out Of Bounds" << endl;
        return buf[0];
    }
}
int String::size() const{
    return strlen(buf);
}
String String::reverse() const{
    char* reversed_string = new char[size() + 1];
    reverse_cpy(reversed_string, buf);
    String result(reversed_string);
    delete[] reversed_string;
    return result;
}
int String::indexOf(char c) const{
    const char *pointer = strchr(buf, c);
    if (pointer != nullptr) {
        return pointer - buf;
    }
    return -1;
}
int String::indexOf(String s) const {
    const char *pointer = strstr(buf, s.buf);
    if (pointer != nullptr) {
        return pointer - buf;
    }
    return -1;
}
bool String::operator==(String s) const{
    if (strcmp(buf, s.buf) == 0) {
        return true;
    }
    return false;
}
bool String::operator!=(String s) const{
    if (strcmp(buf, s.buf) != 0) {
        return true;
    }
    return false;
}
bool String::operator>(String s) const{
    if (strcmp(buf, s.buf) > 0) {
        return true;
    }
    return false;
}
bool String::operator<(String s) const{
    if (strcmp(buf, s.buf) < 0) {
        return true;
    }
    return false;
}
bool String::operator<=(String s) const {
    if (strcmp(buf, s.buf) <= 0) {
        return true;
    }
    return false;
}
bool String::operator>=(String s) const{
    if (strcmp(buf, s.buf) >= 0) {
        return true;
    }
    return false;
}
String String::operator+(String s) const {
    size_t len1 = size();
    size_t len2 = s.size();
    char* newBuf = new char[len1 + len2 + 1];
    strcpy(newBuf, buf);
    strcat(newBuf, s.buf);
    String result(newBuf);
    delete[] newBuf;
    return result;
}

const String& String::operator+=(String s) const {
   size_t len1 = size();
    size_t len2 = s.size();
    char* newBuf = new char[len1 + len2 + 1];
    strcpy(newBuf, buf);
    strcat(newBuf, s.buf);
    delete[] buf;
    *buf = *newBuf;
    return *this;
}
void String::print(std::ostream &out) const {
    out << buf;
}    
void String::read(std::istream &in) {
    std::string string;
    in >> string;
    char* tempBuf = new char[string.size() + 1];
    strcpy(tempBuf, string.c_str());
    delete[] buf;
    buf = tempBuf;
}
String::~String(){
    delete[] buf;
}

int String::strlen(const char *s) {
    int len = 0;
    while (s[len]!= '\0') {
        len++;
    }
    return len;
}
char* String::strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
char* String::strdup(const char* src) {
    if (src == nullptr)
        return nullptr;

    int length = strlen(src);
    char* newStr = new char[length + 1];
    strcpy(newStr, src);
    return newStr;
}

char* String::strncpy(char *dest, const char *src, int n) {
    int i = 0;
    while (src[i] != '\0' && i<n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
char* String::strcat(char *dest, const char *src) {
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;    
    }
    dest[i] = '\0';
    return dest;
}
char* String::strncat(char *dest, const char *src, int n){
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }
    int j = 0;
    while (j<n && src[j] != '\0' ) {
        dest[i] = src[j];
        i++;
        j++;    
    }
    dest[i] = '\0';
    return dest;
}
int String::strcmp(const char *left, const char *right) {
    int i = 0;
    while (left[i] != '\0' && right[i] != '\0' && left[i] == right[i]) {
        i++;
    }
    return left[i] - right[i];
}
int String::strncmp(const char *left, const char *right, int n) {
    int i = 0;
    while (i < n && left[i] != '\0' && right[i] != '\0' && left[i] == right[i]) {
        i++;
    }
    if (i == n) {
        return 0;
    } else {
        return left[i] - right[i];
    }
}
void String::reverse_cpy(char *dest, const char *src){
    int len = strlen(src);
    int i = 0;
    while (i<len) {
        dest[i] = src [len - i - 1];
        i++;
    }
    dest[len] = '\0';
}
const char* String::strchr(const char *str, char c) {
    while (*str != '\0') {
        if (*str == c) {
            return str;
        }
        str++;
        if (*str==c) {
            return str;
        }
    }
    return nullptr;
}
const char* String::strstr(const char *haystack, const char *needle){
    while (*haystack != '\0') {
        const char *haystack_pointer = haystack;
        const char *n = needle;
        while (*n==*haystack_pointer && *n != '\0') {
            n++;
            haystack_pointer++;
        }
        if (*n == '\0') {
            return haystack;
        }
        haystack++;
    }
    return nullptr;
}


std::ostream &operator<<(std::ostream &out,String s) {
    s.print(out);
    return out;
}
std::istream &operator>>(std::istream &in, String &s){
    s.read(in);
    return in;
}


