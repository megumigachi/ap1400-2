#ifndef SHARED_PTR
#define SHARED_PTR

template <typename T>
class SharedPtr
{
private:
    struct ControlBlock
    {
        int usedcnt;
    };
    T *_p;
    ControlBlock *ctrl_block;

public:
    SharedPtr()
    {
        this->_p = nullptr;
        this->ctrl_block = new ControlBlock();
        this->ctrl_block->usedcnt = 1;
    };

    SharedPtr(T *ptr)
    {
        this->_p = ptr;
        this->ctrl_block = new ControlBlock();
        this->ctrl_block->usedcnt = 1;
    };

    SharedPtr(const SharedPtr<T> &another)
    {
        this->_p = another._p;
        this->ctrl_block = another.ctrl_block;
        this->ctrl_block->usedcnt++;
    };

    ~SharedPtr()
    {
        // 由于测试用例15显式地调用了析构函数，可能此时该变量已经被析构了
        if (this->_p == nullptr)
        {
            return;
        }
        this->ctrl_block->usedcnt--;
        if (this->ctrl_block->usedcnt == 0)
        {
            delete this->ctrl_block;
            delete this->_p;
            this->ctrl_block = nullptr;
            this->_p = nullptr;
        }
    };

    T *get()
    {
        return this->_p;
    };

    void reset()
    {
        this->ctrl_block->usedcnt--;
        if (this->ctrl_block->usedcnt == 0)
        {
            delete this->_p;
        }
        this->_p = nullptr;
    }

    void reset(T *another)
    {
        this->ctrl_block->usedcnt--;
        if (this->ctrl_block->usedcnt == 0)
        {
            delete this->_p;
        }
        this->_p = another;
        this->ctrl_block = new ControlBlock();
        this->ctrl_block->usedcnt = 1;
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

    SharedPtr<T> operator=(const SharedPtr<T> &another)
    {
        if (this == &another)
        {
            return *this;
        }
        // 释放自身资源
        this->reset();
        this->ctrl_block = another.ctrl_block;
        this->_p = another._p;
        this->ctrl_block->usedcnt++;
        return *this;
    }

    T *release()
    {
        T *temp = this->_p;
        this->_p = nullptr;
        this->ctrl_block->usedcnt--;
        return temp;
    }

    int use_count()
    {
        if (this->ctrl_block == nullptr)
        {
            return 0;
        }
        return this->ctrl_block->usedcnt;
    }
};

template <typename T>
SharedPtr<T> make_shared(T t)
{
    return SharedPtr<T>(new T(t));
}

#endif // SHARED_PTR