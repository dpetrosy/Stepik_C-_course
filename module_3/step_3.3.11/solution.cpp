#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String
{
	size_t size;
	char *str;

	String(size_t n, char c) : size(n)
	{
	    this->str = new char[size + 1];
	    memset(str, c, size);
	    str[size] = '\0';
	}
	
	~String()
	{
	    delete[] str;
	}
};
