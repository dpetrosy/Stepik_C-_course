#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String
{
	size_t size;
	char *str;

	String(const char *str = "") : size(strlen(str))
	{
	    this->str = new char[size + 1];
	    strcpy(this->str, str);
	}
};
