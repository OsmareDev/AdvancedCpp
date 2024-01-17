/*
3. We have a recursive function that calculates the power of two natural numbers (a^b):
*/

unsigned elev(unsigned a, unsigned b)
{
    unsigned e;
    if(b == 0)
        e = 1;
    else
        e = elev(a, b - 1) * a;
    return e;
}

/*
a) Transform the previous function to a tail recursive function (i_elev) using the method of
unfold/fold transformation.
*/

unsigned i_elev(unsigned a, unsigned b, unsigned w) {
    
    if (b==0)
        return w;
    else 
        return i_elev(a, b-1, a*w);
}

/*
b) Write a function (elev2) that calculates the power of two natural numbers doing a call to
i_elev with the appropriate parameters.
*/

unsigned elev2(unsigned a, unsigned b) {
    return i_elev(a, b, 1);
}

/*
c) Transform the previous functions (elev2 + i_elev) to an iterative function (elev3).
*/

unsigned elev3(unsigned a, unsigned b) {
    unsigned e;
    if (b == 0)
        e = 1;
    else
        for (unsigned i = b; i > 1; ++i)
            e = e * a;
    
    return e;
}