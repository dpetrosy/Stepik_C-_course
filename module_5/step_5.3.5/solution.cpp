struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtrHelper
{
    SharedPtrHelper(Expression *ptr)
    {
        _counter = 0;
        if (ptr != 0)
            _counter = 1;
        this->_ptr = ptr;
    }

    SharedPtrHelper(const SharedPtrHelper& other)
    {
        this->_counter = other._counter;
        this->_ptr = other._ptr;
        if (_ptr != 0)
            this->_counter += 1;
    }

    ~SharedPtrHelper()
    {
        delete _ptr;
    }

    void callHelperDestructor()
    {
        if (_ptr != 0)
            _counter -= 1;
    }

    Expression* _ptr = 0;
    int _counter = 0;
};

struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = 0)
    {
        _helper = new SharedPtrHelper(ptr);
    }

    ~SharedPtr()
    {
        callDestructor();
    }

    SharedPtr(const SharedPtr& other)
    {
        _helper = other._helper;
        _helper->_counter += 1;
    }

    SharedPtr& operator=(const SharedPtr& other)
    {
        if (this != &other)
        {
            callDestructor();
            _helper = other._helper;
            _helper->_counter += 1;
        }
        return (*this);
    }

    Expression* get() const
    {
        return _helper->_ptr;
    }

    void reset(Expression *ptr = 0)
    {
        callDestructor();
        _helper = new SharedPtrHelper(ptr);
    }

    Expression& operator*() const
    {
        return *(_helper->_ptr);
    }

    Expression* operator->() const
    {
        return (_helper->_ptr);
    }

    void callDestructor()
    {
        _helper->callHelperDestructor();
        if (_helper->_counter <= 0)
            delete _helper;
    }

    SharedPtrHelper* _helper;
};
