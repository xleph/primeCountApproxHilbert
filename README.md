# π(x)

## A number theoretical function allows striking visualization

The original prime visualization project repo'd [here](deadlink) follows a narrow train of thought. It was my expectation that patterned adjacencies would arise in the process of formatting prime numbers to a Hilbert curve presentation. In fact, this is ultimately unsurprising, given the existence of spokes on the Ulam spiral. Hilbert curves are, however, a flavor of prime density different from the prime-rich polynomials that are described by the Ulam spiral.

Narrow expectations and vision aside, there was yet still to explore. Many approximations exist for the *n*th prime, formulations related to the Zeta function exist, formulations leveraging clever techniques related to factorials are also acknowledged, albeit not discussed. 

## The formal approximation

![Eq1](https://math.vercel.app/?color=cyan&from=%5Cpi%28x%29%5Csim%5Cfrac%7Bx%7D%7B%5Cln%28x%29%7D.svg)

is ineffably useful and impactful in its simplicity. This expression falls naturally out of an understanding that, within the exact formulation of π(x) (namely the one given in the below source) is a summation of Li(x<sup>ρ</sup>)'s which is in fact asymptotic to x/ln(x). What we have above is several tiers removed from any rigorous process of derivation, and yet, is usually presented as a standalone awe-inspiring formula.

I would argue from a pedagogical standpoint, the clear and total force of the above asymptotic relation can really only be felt in the presence of:

![Eq2](https://math.vercel.app/?color=cyan&from=%5CPi%28x%29%20%3D%20%5Csum_%7B%5Crho%7D%5Ctext%7BLi%7D%28x%5E%5Crho%29%20-%20%5Cln%282%29%20%2B%20%5Cint_%7Bx%7D%5E%7B%5Cinfty%7D%7B%5Cfrac%7Bdt%7D%7Bt%281-t%5E2%29%5Cln%28t%29%7D%7D%0A.svg)

![State1](https://math.vercel.app/?color=cyan&from=%5Ctext%7Bwhere%20%7Dx%20%3E%200%5Ctext%7B%20and%20%7D%5Crho%5Ctext%7B%20iterates%20all%20zeroes%20of%20the%20Riemann%20Zeta%20function%7D.svg)

![State2](https://math.vercel.app/?color=cyan&from=%5Ctext%7BNow%20the%20following%20two%20equations%20hold%7D.svg)

![Eq3](https://math.vercel.app/?color=cyan&from=%5CPi%28x%29%20%3D%20%5Csum_%7Br%3D1%7D%5E%7B%5Cinfty%7D%7B%5Cfrac%7B1%7D%7Br%7D%7D%5Cpi%28x%5E%5Cfrac%7B1%7D%7Br%7D%29.svg)

![Eq4](https://math.vercel.app/?color=cyan&from=%5Cpi%28x%29%20%3D%20%5Csum_%7Br%3D1%7D%5E%7B%5Cinfty%7D%7B%5Cfrac%7B%5Cmu%28x%29%7D%7Br%7D%7D%5CPi%28x%5E%5Cfrac%7B1%7D%7Br%7D%29.svg)

![State3](https://math.vercel.app/?color=cyan&from=%5Ctext%7Bwhere%20%7D%5Cmu%28r%29%5Cbegin%7Bcases%7D%20%0A1%20%26%20r%20%3D%201%20%5C%5C%0A0%20%26%20%5Ctext%7Bthere%20is%20a%20square%20in%20%7Dr%5Ctext%7B's%20factorization%7D%20%5C%5C%0A%28-1%29%5Ek%20%26%20%5Ctext%7Bwhere%20%7Dr%5Ctext%7B%20is%20made%20up%20of%20%7Dk%5Ctext%7B%20primes%7D%0A%5Cend%7Bcases%7D.svg)

[Source](deadlink)

## Highlights

# Deriving meaning from the images

## No meaning?

It is unclear whether the progression of 2^10 consecutive nonprime integers
