struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;
    
    Rational& operator+=(const Rational& num)
    {
        this->add(num);
        return (*this);
    }
    
    Rational& operator-=(const Rational& num)
    {
        this->sub(num);
        return (*this);
    }
    
    Rational& operator*=(const Rational& num)
    {
        this->mul(num);
        return (*this);
    }
    
    Rational& operator/=(const Rational& num)
    {
        this->div(num);
        return (*this);
    }
    
    Rational operator-() const
    {
        Rational tmp(this->numerator_, this->denominator_);
        tmp.neg();
        return tmp;
    }
    
    Rational operator+() const
    {
        Rational tmp(this->numerator_, this->denominator_);
        return tmp;
    }

private:
    int numerator_;
    int denominator_;
};
