union LN {
double    x; // 
long long y; // series of bits
};

static union LN LN2 = {
.y = 0b0011111111100110001011100100001011111110111110100011100111101111
}; 

double power(double a, long long b) {

    if (b == 0) {
    return 1;
    }

double ret = 1.0;

int bitlength = 0;

    while (b >> bitlength) {
    bitlength++;
    };

    while (bitlength) {
    ret *= ret;
        if ( (b >> bitlength - 1) & 1 ) {
        ret *= a;
        }
    bitlength--;
    }

return ret;

}

#define MAX 150

double logarithm(long long x) {
// only takes positive x. Weird stipulation, but necessary.
    if (!x) {
    return 0.0; // NEG_INF really
    }

int baseq = 0;
long long base = 1; // we will work only in positive numbers
double operand, doperand;

    while (x >> baseq) { // wish I could do binary tree pow here
    baseq++;
    }

base = 1<<baseq;

char base_or_x_heavy = base * base / 2 > x * x; // is base/x or 2x/base bigger?
                                                // Want to use _smaller_
    if (base_or_x_heavy) {
    base = base>>1;
    operand = (double)x / (double)base;
    } else {
    operand = (double)base / (double)x;
    }

// now we take the log of that value in range [1,2]

operand = (operand * operand - 1) / (operand * operand + 1);
doperand = operand * operand;
double accum = doperand / (double)(2 * MAX + 1);
long long i = MAX;

    while (--i) {
    accum = (accum + 1.0 / (double)(2 * i + 1) ) * doperand;
    }

accum += 1.0;

    if (base_or_x_heavy) {
    return (baseq - 1) * LN2.x + accum * operand;
    } else {
    return baseq * LN2.x - accum * operand;
    }

}
