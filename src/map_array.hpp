#ifndef MAP_ARRAY_HPP
#define MAP_ARRAY_HPP
#include<cassert>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>


template <typename Key, typename Value>
class MapArray {
public:
    class ArrayIterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = std::pair<Key, Value>;
        using difference_type = std::ptrdiff_t;
        using pointer = std::pair<Key, Value>*;
        using reference = std::pair<Key, Value>&;
        explicit ArrayIterator(std::pair<Key, Value>* ptr = nullptr) : ptr(ptr) {};
        ArrayIterator& operator++(){
            ++ptr;
            return *this;
        }
        ArrayIterator& operator--() {
            --ptr;
            return *this;
        }
        ArrayIterator operator++(int) {
            ArrayIterator temp= *this;
            ++(*this);
            return temp;
        }
        ArrayIterator operator--(int) {
            ArrayIterator temp= *this;
            --(*this);
            return temp;
        }
        ArrayIterator& operator+=(difference_type d) {
            ptr= ptr+d;
            return *this;
        }
        ArrayIterator& operator-=(difference_type d) {
            ptr = ptr -d;
            return *this;
        }
        friend ArrayIterator operator+(ArrayIterator it, difference_type d) {
            it = it+d;
            return it;
        }
        friend ArrayIterator operator+(difference_type d, ArrayIterator it) {
            return ArrayIterator(d+it.ptr);
        }
        friend ArrayIterator operator-(ArrayIterator it, difference_type d) {
            it = it - d;
            return it;
        }
        friend difference_type operator-(ArrayIterator lhs, ArrayIterator rhs) {
            return lhs.ptr - rhs.ptr;
        }
        auto operator<=>(const ArrayIterator& other) const = default;
        std::pair<Key, Value>& operator*() const {
            return *ptr;
        }
        std::pair<Key, Value>* operator->() const {
            return ptr;
        }
        std::pair<Key, Value>& operator[](difference_type d) const {
            return *(ptr+d);
        }
    private:
        std::pair<Key, Value>* ptr;
    };
    using value_type = std::pair<Key, Value>;
    using citerator = const ArrayIterator;
    ArrayIterator begin() {
        return ArrayIterator(data.data());
    }
    ArrayIterator end(){
        return ArrayIterator(data.data() + data.size());
    }
    ArrayIterator begin() const{
        return citerator(data.data());
    }
    ArrayIterator end() const {
        return citerator(data.data() + data.size());
    }
    Value& operator[](const Key& key) {
        auto it = std::lower_bound(data.begin(), data.end(), key, [](const value_type& lhs, const Key& rhs) {
            return lhs.first < rhs;
        });

        if (it != data.end() && it->first == key) {
            return it->second;
        } else {
            it = data.insert(it, {key, Value{}});
            return it->second;
        }
    }
private:
    std::vector<std::pair<Key, Value>> data;
};

#endif
