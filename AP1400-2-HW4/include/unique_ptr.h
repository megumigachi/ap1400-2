#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <typename T>
class UniquePtr
{
private:
    T *_p;

public:
    UniquePtr()
    {
        this->_p = nullptr;
    };

    UniquePtr(T *ptr)
    {
        this->_p = ptr;
    };

    T *get()
    {
        return this->_p;
    };

    void reset()
    {
        delete this->_p;
        this->_p = nullptr;
    }

    void reset(T *another)
    {
        delete this->_p;
        this->_p = another;
    }

    operator bool() const
    {
        return this->_p != nullptr;
    }

    T operator*()
    {
        return *(this->_p);
    }

    T *operator->()
    {
        return this->_p;
    }

    // UniquePtr(const UniquePtr &other) = delete;

    void operator=(const UniquePtr<T> &another)
    {
        if (this != &another)
        {
            throw std::runtime_error("cannot use = to a unique ptr");
        }
    }

    T *release()
    {
        T *temp = this->_p;
        this->_p = nullptr;
        return temp;
    }
};

template <typename T>
UniquePtr<T> make_unique(T t)
{
    return UniquePtr<T>(new T(t));
}

#include "unique_ptr.hpp"
#endif
