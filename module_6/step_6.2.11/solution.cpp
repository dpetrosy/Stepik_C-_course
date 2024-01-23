struct ICloneable;

template <typename T>
struct ValueHolder;

class Any
{
public:
    Any()
    {
        _ptr = nullptr;
    }

    template <typename T>
    Any(const T& value)
    {
        _ptr = new ValueHolder<T>(value);
    }

    ~Any()
    {
        delete _ptr;
        _ptr = nullptr;
    }

    Any(const Any& other)
    {
        if (!other.get_ptr())
            _ptr = nullptr;
        else
            _ptr = other.get_ptr()->clone();
    }

    Any& operator=(const Any& other)
    {
        if (this != &other)
        {
            delete _ptr;
            if (!other.get_ptr())
                _ptr = nullptr;
            else
                _ptr = other.get_ptr()->clone();
        }
        return (*this);
    }

    template <typename T>
    T* cast()
    {
        ValueHolder<T>* value_ptr = dynamic_cast<ValueHolder<T>*>(_ptr);
        if (!value_ptr)
            return nullptr; 
        return &(value_ptr->data_);
    }

    ICloneable* get_ptr() const
    {
        return _ptr;
    }

private:
    ICloneable* _ptr;
};
