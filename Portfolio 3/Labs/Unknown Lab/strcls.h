#ifndef STRING_CLASS_HEADER_INCLUDED
#define STRING_CLASS_HEADER_INCLUDED

#include <iostream>

#include "strextra.h"

class String
{
// our data...
    char * string;
    long length;

// maintenance data...
    mutable long translate_position,
                 translate_state,
                 flags;

// internal utilities...
    void alloc_val(long new_len);
    void copy_val(const char s[]);

    void destroy(void);

    static char * new_and_cat(char * &old, const char block[],
                              long &had, long just_read);

public:

// allows debugging of memory leaks on systems that support it...
    static bool debug;

    enum TransState { goodbit = 1, failbit = 2, eosbit = 4 };

    enum Flags { case_on = 1 };

    short compare(const String & other) const;
    short compare(const char other[]) const;
    short compare(const char other) const;
    friend short compare(const char other[], const String & me);
    friend short compare(const char other, const String & me);

    bool operator==(const String & right) const;
    bool operator==(const char right[]) const;
    bool operator==(const char right) const;
    friend bool operator==(const char left[], const String & right);
    friend bool operator==(const char left, const String & right);

    bool operator<(const String & right) const;
    bool operator<(const char right[]) const;
    bool operator<(const char right) const;
    friend bool operator<(const char left[], const String & right);
    friend bool operator<(const char left, const String & right);

    bool operator>(const String & right) const;
    bool operator>(const char right[]) const;
    bool operator>(const char right) const;
    friend bool operator>(const char left[], const String & right);
    friend bool operator>(const char left, const String & right);

    bool operator!=(const String & right) const;
    bool operator!=(const char right[]) const;
    bool operator!=(const char right) const;
    friend bool operator!=(const char left[], const String & right);
    friend bool operator!=(const char left, const String & right);

    bool operator<=(const String & right) const;
    bool operator<=(const char right[]) const;
    bool operator<=(const char right) const;
    friend bool operator<=(const char left[], const String & right);
    friend bool operator<=(const char left, const String & right);

    bool operator>=(const String & right) const;
    bool operator>=(const char right[]) const;
    bool operator>=(const char right) const;
    friend bool operator>=(const char left[], const String & right);
    friend bool operator>=(const char left, const String & right);

    String operator+(const String & right) const;
    String operator+(const char right[]) const;
    String operator+(const char right) const;
    friend String operator+(const char left[], const String & right);
    friend String operator+(const char left, const String & right);

    String & operator+=(const String & right);
    String & operator+=(const char right[]);
    String & operator+=(const char right);

    String(void);
    String(const char s[]);
    String(const char ch);
    explicit String(long new_len, const char ch = EOS);
    String(const String & other);

    ~String(void);

    String & operator=(const String & right);
    String & operator=(const char right[]);
    String & operator=(const char right);

    long operator^(const String & find_me) const;
    long operator^(const char find_me[]) const;
    long operator^(const char find_me) const;
    friend long operator^(const char find_in[], const String & find_me);
    friend long operator^(const char find_in, const String & find_me);

    long find(const String & find_me, long start_looking) const;
    long find(const char find_me[], long start_looking) const;
    long find(const char find_me, long start_looking) const;

    long getline(std::istream &strm);

    friend std::istream & operator >>(std::istream & strm, String & me);

    long size(void) const;

    bool operator!(void) const;

    bool good(void) const;
    bool fail(void) const;
    bool eos(void) const;

    long clear(long new_state = goodbit) const;

    void skipws(void) const;
    long seekg(long new_position = 0) const;
    long tellg(void) const;

    long setf(long new_flags) const;
    long unsetf(long drop_flags) const;

    bool case_sensitive(void) const;

    friend std::ostream & operator<<(std::ostream & out, const String & other);

    char & operator[](long index);
    char operator[](long index) const;

    // not a great idea, but it needs to happen...
    const char * Cstring(void) const;

    const String & operator>>(long & data) const;
    const String & operator>>(short & data) const;
    const String & operator>>(double & data) const;
    const String & operator>>(float & data) const;
    const String & operator>>(char & data) const;
    const String & operator>>(String & data) const;
    const String & operator>>(bool & data) const;

    long getline(String & data,
                 const String & stop_at_any = String('\n')) const;
};

void get_line(String & line, std::istream & in = std::cin);

#endif