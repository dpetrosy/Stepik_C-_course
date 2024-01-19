#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String
{
	String(const char *str = "");
	String(size_t n, char c);
	~String();

	void append(String &other)
	{
	    int total_size = this->size + other.size;
	    
	    char *new_str = new char[total_size + 1];
	    strcpy(new_str, this->str);
	    strcat(new_str, other.str);
	    delete[] str;
	    str = new_str;
      size = total_size;
	}

	size_t size;
	char *str;
};
