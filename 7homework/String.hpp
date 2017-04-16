
#ifndef _String_h_
#define _String_h_

#include <iostream>


class String
{
private:
	char* str;
	int len;
	String(const int length);
public:
	String(const char* s = "");
	String(const String& s);
	char& operator[] (const int i);
	String& operator= (const String& s);	
	String& operator= (const char* s);
	String operator+ (const String& s) const;
	String operator+ (const char* s) const;
	String& operator+= (const String& s);
	String& operator+= (const char* s);
	void operator << (const char* s);
	bool isEmpty() const;
	bool operator== (const String& s) const;
	bool operator== (const char* s) const;
	bool operator!= (const String& s) const;
	bool operator!= (const char* s) const;
	bool operator< (const String& s) const;
	bool operator< (const char* s) const;
	bool operator<= (const String& s) const;
	bool operator<= (const char* s) const;
	bool operator> (const String& s) const;
	bool operator> (const char* s) const;
	bool operator>= (const String& s) const;
	bool operator>= (const char* s) const;
	int length() const;
	String& clear();
	~String();
	friend std::ostream& operator<<(std::ostream& os, const String& s);
};

#endif