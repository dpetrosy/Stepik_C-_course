struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() {}
};

template <typename T>
struct ValueHolder : ICloneable
{
    T data_;

    ValueHolder(const T& data) : data_(data)
    {}

    ICloneable* clone() const
    {
        return (new ValueHolder(*this));
    }
};
