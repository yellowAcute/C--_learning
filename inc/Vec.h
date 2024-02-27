#if !defined(VEC_H)
#define VEC_H

#include <iostream>
#include <memory>
#include <utility>
#include <initializer_list>
using namespace std;

template <typename T>
class Vec
{
private:
    static std::allocator<std::T> alloc; // allocates the elements

    // utility functions:
    //  used by members that add elements to the Vec
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    // used by the copy constructor, assignment operator, and destructor
    std::pair<std::T *, std::T *> alloc_n_copy(const std::T *, const std::T *);
    void free();        // destroy the elements and free the space
    void reallocate();  // get more space and copy the existing elements
    std::T *elements;   // pointer to the first element in the array
    std::T *first_free; // pointer to the first free element in the array
    std::T *cap;        // pointer to one past the end of the array
public:
    Vec();
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    Vec(const Vec &);            // copy constructor
    Vec &operator=(const Vec &); // copy assignment
    ~Vec();

    void push_back(const std::T &); // copy the element

    // add elements
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    // iterator interface
    std::T *begin() const { return elements; }
    std::T *end() const { return first_free; }
};

#endif // VEC_H;