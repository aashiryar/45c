#include <iostream>
#include <iosfwd>
#include "string.hpp"
using namespace std;

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

String::String(const char *s){
    if (strlen(s) >= MAXLEN) {
       cout << "ERROR: String Capacity Exceeded" << endl;
        buf[0] = '\0';
    }
    else {
        strncpy(buf, s, MAXLEN-1);
        buf[MAXLEN-1] = '\0';
    }
}
String::String(const String &s) {
    if (s.size() >= MAXLEN) {
        cout << "ERROR: String Capacity Exceeded" << endl;
        buf[0] = '\0';
    }
    else {
        strncpy(buf, s.buf, MAXLEN);
		buf[MAXLEN - 1] = '\0';
    }
}
String& String::operator=(const String &s) {
    if (this != &s) {
        strcpy(buf, s.buf);
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
int String::size() const{
    return strlen(buf);
}
String String::reverse() const{
    char reversed_string[MAXLEN];
    reverse_cpy(reversed_string, buf);
    return String(reversed_string);
}
int String::indexOf(char c) const{
    const char *pointer = strchr(buf, c);
    if (pointer != nullptr) {
        return pointer - buf;
    }
    return -1;
}
int String::indexOf(const String &s) const {
    const char *pointer = strstr(buf, s.buf);
    if (pointer != nullptr) {
        return pointer - buf;
    }
    return -1;
}
bool String::operator==(const String &s) const{
    if (strcmp(buf, s.buf) == 0) {
        return true;
    }
    return false;
}
bool String::operator!=(const String &s) const{
    if (strcmp(buf, s.buf) != 0) {
        return true;
    }
    return false;
}
bool String::operator>(const String &s) const{
    if (strcmp(buf, s.buf) > 0) {
        return true;
    }
    return false;
}
bool String::operator<(const String &s) const{
    if (strcmp(buf, s.buf) < 0) {
        return true;
    }
    return false;
}
bool String::operator<=(const String &s) const {
    if (strcmp(buf, s.buf) <= 0) {
        return true;
    }
    return false;
}
bool String::operator>=(const String &s) const{
    if (strcmp(buf, s.buf) >= 0) {
        return true;
    }
    return false;
}
String String::operator+(const String &s) const {
    char string[MAXLEN];
    if (size() + s.size() >= MAXLEN) {
        cout << "ERROR: String Capacity Exceeded" << endl;
        string[0] = '\0';
    } 
    else {
        strcpy(string, buf);
        strcat(string, s.buf);
    }
    return String(string);
}
//check
String& String::operator+=(const String &s) {
    if (size() + s.size() >= MAXLEN) {
        cout << "ERROR: String Capacity Exceeded" << endl;
	} 
    else {
        strncat(buf, s.buf, MAXLEN-1);
    }
    return *this;
}
void String::print(std::ostream &out) const {
    out << buf;
}    
void String::read(std::istream &in) {
    in >> buf;  
}
String::~String(){}

std::ostream &operator<<(std::ostream &out, const String &s) {
    s.print(out);
    return out;
}
std::istream &operator>>(std::istream &in, String &s){
    s.read(in);
    return in;
}

