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

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;
    
    int get_num() const
    {
        return numerator_;
    }
    
    int get_denom() const
    {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);

bool operator==(const Rational& num1, const Rational& num2)
{
    return ((num1.get_num() == num2.get_num()) && (num1.get_denom() == num2.get_denom()));
}

bool operator!=(const Rational& num1, const Rational& num2)
{
    return !(num1 == num2);
}

bool operator<(const Rational& num1, const Rational& num2)
{
    return (num1.get_num() * num2.get_denom() < num2.get_num() * num1.get_denom());
}

bool operator>(const Rational& num1, const Rational& num2)
{
    return (num2 < num1);
}

bool operator<=(const Rational& num1, const Rational& num2)
{
    return !(num2 < num1);
}

bool operator>=(const Rational& num1, const Rational& num2)
{
    return !(num1 < num2);
}
