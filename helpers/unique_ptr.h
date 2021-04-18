#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#if __cplusplus < 201103L

template <class T>
class unique_ptr
{
public:
    unique_ptr();
    unique_ptr(T* pointer);
    ~unique_ptr();
    T* get();
    void operator = (T* pointer);
    T& operator * ();
    T& operator -> ();
    T* release();
    void reset();
    void swap(unique_ptr<T>& other);
private:
    T* pointer;
};

unique_ptr<class T>::unique_ptr() : pointer(0)
{
}

unique_ptr<class T>::unique_ptr(T* pointer) : pointer(pointer)
{
}

unique_ptr<class T>::~unique_ptr()
{
    delete pointer;
}

T* unique_ptr<class T>::get()
{
    return pointer;
}

void unique_ptr<class T>::operator = (T* pointer)
{
    if (this->pointer)
        delete this->pointer;
    this->pointer = pointer;
}

T& unique_ptr<class T>::operator * ()
{
    return *pointer;
}

T& unique_ptr<class T>::operator -> ()
{
    return *pointer;
}

T* unique_ptr<class T>::release()
{
    T* ret = pointer;
    pointer = 0;
    return ret;
}

void unique_ptr<class T>::reset()
{
    delete pointer;
    pointer = 0;
}

void unique_ptr<class T>::swap(unique_ptr<T>& other)
{
    T* temp = pointer;
    pointer = other.pointer;
    other.pointer = temp;
}

#endif

#endif //Unique_Ptr