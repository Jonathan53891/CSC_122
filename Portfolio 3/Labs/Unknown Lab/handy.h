#ifndef HANDY_UTILITY_LIBRARY_HEADER_INCLUDED
#define HANDY_UTILITY_LIBRARY_HEADER_INCLUDED

// protects division by this denominator by disallowing
// division by 0.
inline double prot_div_zero(double denom)
{
// NOTE:  equality of a double with 0 is suspect as 0 is
//        not an even power of 2 and so is not precisely
//        stored
    return ((short)denom == 0) ? (1.0) : (denom);
}

// protects division by this denominator by disallowing
// division by 0.
// (this version is for denominators which can't be negative, either)
inline double prot_div_nonpos(double denom)
{
    return (denom <= 0) ? (1.0) : (denom);
}

// returns minimum of two arguments
inline double min(double x, double y)
{
    return (x < y) ? (x) : (y);
}
inline long min(long x, long y)
{
    return (x < y) ? (x) : (y);
}
inline char min(char x, char y)
{
    return (x < y) ? (x) : (y);
}

// returns maximum of two arguments
inline double max(double x, double y)
{
    return (x > y) ? (x) : (y);
}
inline long max(long x, long y)
{
    return (x > y) ? (x) : (y);
}
inline char max(char x, char y)
{
    return (x > y) ? (x) : (y);
}

#endif
