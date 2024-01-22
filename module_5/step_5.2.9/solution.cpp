#include <cstddef> // size_t
#include <cstring>

struct String
{
    struct Proxy
    {
        Proxy(const char* str, int start_i) : start_i(start_i)
        {
            this->str = new char[strlen(str) + 1];
            strcpy(this->str, str);
        }
        
        Proxy(const Proxy& other)
        {
            start_i = other.start_i;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
    
        String operator[](int index)
        {
            if (index <= start_i)
                return "";
    
            char *new_str = new char[index - start_i + 1];
            strncpy(new_str, str, index - start_i);
            delete[] str;
            str = new_str;
            return *this;
        }
        
        ~Proxy()
        {
            delete[] str;
            str = nullptr;
        }
    
        int start_i;
        char* str;
    };

    String(const Proxy& p)
    {
        this->str = new char[strlen(p.str) + 1];
        size = strlen(p.str);
        strcpy(this->str, p.str);
    }

    Proxy operator[](int i) const
    {
        return Proxy(str + i, i);
    }

	  String(const char *str = "");
	  String(size_t n, char c);
	  ~String();

    String(const String &other);
    String &operator=(const String &other);

	  void append(const String &other);

  	size_t size;
  	char *str;
};
