struct Foo1 : Foo
{
    Foo1(const char *msg) : Foo(msg) {}
};

Foo get_foo(const char *msg)
{
    Foo1 obj(msg);
    return obj;
}
