#include "String.hpp"
#include <cstring>

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len+1];
	std::strcpy(str, s.str);
}

String::String(const int length)
{
	len = length;
	str = new char[len+1];
	str[0] = '\0';
}

char& String::operator[] (const int i)
{
	if (i >= 0 && i < len)
		return str[i];
	else
		return str[len];
}

String& String::operator= (const String& s)
{
	if (this == &s)
		return *this;

	delete[] str;
	len = s.len;
	str = new char[len+1];
	std::strcpy(str, s.str);
	return *this;
}

String& String::operator= (const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	return *this;
}

String String::operator+ (const String& s) const
{
	int length = len + s.len;
	String concat (length);
	std::strcpy(concat.str, str);
	std::strcpy(concat.str + len, s.str);
	return concat;
}

String String::operator+ (const char* s) const
{
	int length = len + std::strlen(s);
	String concat(length);
	std::strcpy(concat.str, str);
	std::strcpy(concat.str + len, s);
	return concat;
}

String& String::operator+= (const String& s)
{
	if (s.isEmpty())
		return *this;

	char* buf = new char[len + s.len + 1];
	std::strcpy(buf, str);
	std::strcpy(buf + len, s.str);
	delete[] str;
	str = buf;
	len += s.len;
	
	return *this;
}

String& String::operator+= (const char* s)
{
	if (s[0]=='\0')
		return *this;

	*this = *this + s;
	return *this;
}

bool String::isEmpty() const
{
	return (len ? false : true);
}

bool String::operator== (const String& s) const
{
	return ((std::strcmp(str, s.str) == 0) ? true : false);
}

bool String::operator== (const char* s) const
{
	return ((std::strcmp(str, s) == 0) ? true : false);
}

bool String::operator!= (const String& s) const
{
	return ((std::strcmp(str, s.str) != 0) ? true : false);
}

bool String::operator!= (const char* s) const
{
	return ((std::strcmp(str, s) != 0) ? true : false);
}

bool String::operator< (const String& s) const
{
	return ((std::strcmp(str, s.str) < 0) ? true : false);
}

bool String::operator< (const char* s) const
{
	return ((std::strcmp(str, s) < 0) ? true : false);
}

bool String::operator<= (const String& s) const
{
	return ((std::strcmp(str, s.str) <= 0) ? true : false);
}

bool String::operator<= (const char* s) const
{
	return ((std::strcmp(str, s) <= 0) ? true : false);
}

bool String::operator> (const String& s) const
{
	return ((std::strcmp(str, s.str) > 0) ? true : false);
}

bool String::operator> (const char* s) const
{
	return ((std::strcmp(str, s) > 0) ? true : false);
}

bool String::operator>= (const String& s) const
{
	return ((std::strcmp(str, s.str) >= 0) ? true : false);
}

bool String::operator>= (const char* s) const
{
	return ((std::strcmp(str, s) >= 0) ? true : false);
}

int String::length() const
{
	return len;
}

String& String::clear()
{
	len = 0;
	delete[] str;
	str = new char[1];
	*str = '\0';
	return *this;
}


String::~String()
{
	delete[] str;
}


std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.str;
	return os;
}

void
String::operator<<(const char* s)
{
	*this += s;
}
