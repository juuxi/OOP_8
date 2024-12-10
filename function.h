#ifndef TFUNCTION_H
#define TFUNCTION_H

#include <polinom.h>

template <class number>
class TFunction : private TPolinom<number>
{
    int fact(int);
public:
    TFunction(int, number*);
    using TPolinom<number>::operator();
    using TPolinom<number>::coefficients;
};

template <class number>
TFunction<number>::TFunction(int n, number* coefs) : TPolinom<number>::TPolinom(n, coefs)
{
    for (int i = 0; i < n; i++)
        coefficients[i] = coefficients[i]/fact(i);
}

template <class number>
int TFunction<number>::fact(int curr)
{
    if (curr == 0)
        return 1;
    if (curr == 1)
        return curr;
    else
        return fact(curr-1) * curr;
}

#endif // TFUNCTION_H
