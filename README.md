# π(x)

## A number theoretical function allows striking visualization

![Img1](img/squared.png)

The original prime visualization project repo'd [here](https://github.com/xleph/HilbertPrimes) follows a narrow train of thought. It was my expectation that patterned adjacencies would arise in the process of formatting prime numbers to a Hilbert curve presentation. In fact, this is ultimately unsurprising, given the existence of spokes on the Ulam spiral. Hilbert curves are, however, a flavor of prime density different from the prime-rich polynomials that are described by the Ulam spiral.

Narrow expectations and vision aside, there was yet still to explore. Many approximations exist for the *n*th prime, formulations related to the Zeta function exist, formulations leveraging clever techniques related to factorials are also acknowledged, albeit not discussed. 

## The formal approximation

![Eq1](https://math.vercel.app/?color=cyan&from=%5Cpi%28x%29%5Csim%5Cfrac%7Bx%7D%7B%5Cln%28x%29%7D%5Ctext%7B%20as%20%7Dx%5Cto%5Cinfty.svg)

is ineffably useful and impactful in its simplicity. This expression falls naturally out of an understanding that, within the exact formulation of π(x) (namely the one given in the below source) is a summation of Li(x<sup>ρ</sup>)'s which is in fact asymptotic to x/ln(x). What we have above is several tiers removed from any rigorous process of derivation, and yet, is usually presented as a standalone awe-inspiring formula.

I would argue from a pedagogical standpoint, the clear and total force of the above asymptotic relation can really only be felt in the presence of:

![Eq2](https://math.vercel.app/?color=cyan&from=%5CPi%28x%29%20%3D%20%5Csum_%7B%5Crho%7D%5Ctext%7BLi%7D%28x%5E%5Crho%29%20-%20%5Cln%282%29%20%2B%20%5Cint_%7Bx%7D%5E%7B%5Cinfty%7D%7B%5Cfrac%7Bdt%7D%7Bt%281-t%5E2%29%5Cln%28t%29%7D%7D%0A.svg)

![State1](https://math.vercel.app/?color=cyan&from=%5Ctext%7Bwhere%20%7Dx%20%3E%200%5Ctext%7B%20and%20%7D%5Crho%5Ctext%7B%20iterates%20all%20zeroes%20of%20the%20Riemann%20Zeta%20function%7D.svg)

![State2](https://math.vercel.app/?color=cyan&from=%5Ctext%7BNow%20the%20following%20two%20equations%20hold%7D.svg)

![Eq3](https://math.vercel.app/?color=cyan&from=%5CPi%28x%29%20%3D%20%5Csum_%7Br%3D1%7D%5E%7B%5Cinfty%7D%7B%5Cfrac%7B1%7D%7Br%7D%7D%5Cpi%28x%5E%5Cfrac%7B1%7D%7Br%7D%29.svg)

![Eq4](https://math.vercel.app/?color=cyan&from=%5Cpi%28x%29%20%3D%20%5Csum_%7Br%3D1%7D%5E%7B%5Cinfty%7D%7B%5Cfrac%7B%5Cmu%28x%29%7D%7Br%7D%7D%5CPi%28x%5E%5Cfrac%7B1%7D%7Br%7D%29.svg)

![State3](https://math.vercel.app/?color=cyan&from=%5Ctext%7Bwhere%20%7D%5Cmu%28r%29%5Cbegin%7Bcases%7D%20%0A1%20%26%20r%20%3D%201%20%5C%5C%0A0%20%26%20%5Ctext%7Bthere%20is%20a%20square%20in%20%7Dr%5Ctext%7B's%20factorization%7D%20%5C%5C%0A%28-1%29%5Ek%20%26%20%5Ctext%7Bwhere%20%7Dr%5Ctext%7B%20is%20made%20up%20of%20%7Dk%5Ctext%7B%20primes%7D%0A%5Cend%7Bcases%7D.svg)

Considering that all of the above still do not fully realize the mode of discovery for π(x), it is still a worthy pursuit to state them in tandem, because of their value in computation.

[Source](deadlink)

## What the approximation tells us

As can be seen, the presence of [Li(x)](https://en.wikipedia.org/wiki/Logarithmic_integral_function) is as foundational as x/ln(x). If one attempts a standard Taylor series for Li(x) they will not have much success, as Li(x) possesses a simple pole at x = 1. This would seem to doom the derivation of such a series to failure. Indeed, the procured summation from such an excersize contains terms that grow in the factorial of n. One would then have the mind to defer to one of the formula's due to Ramanujan or Hardy. Each of those formulas depend somewhat on Li(x)'s definition in terms of Ei(ln(x)).

Alas, but what if there were an easier way?

Padé approximants seem a good candidate for upgrading our divergent, Taylor-adjacent series. Indeed, it has been loosely shown that on whatever order a Taylor-adjacent series diverges, its respective Padé approximants appear to converge as quickly if not more quickly. This, however leads to some frustration in that the pole Li(x = 1) seems to duplicate itself nastily and present transient poles where there were none in the original definition.

This is all to say, that I was simply not going to putz around with calculating Li(x) when several expressions of interest were clearly available.

Namely, I wanted to inspect the individual terms in the Taylor-adjacent series that all looked something like:

![Eq5](https://math.vercel.app/?color=cyan&bgcolor=none&from=%28n%29!%5Cleft%28%5Cfrac%7Bx%7D%7Bln%28x%29%7D%5Cright%29%5En.svg)

## Highlights

![img2](img/cubed.png)
![img2](img/triangle_table_ln3.png)
![img2](img/boxes.png)

# Deriving meaning from the images

## No meaning?

It is unclear whether the progression of 2^10 consecutive nonprime integers

## Equations of potential future relevance

![Eq5](https://math.vercel.app/?color=cyan&from=%5Czeta%281%20-%20x%29%20%3D%20%5Cfrac%7B2%7D%7B%282%5Cpi%29%5E%7Bx%7D%7D%5CGamma%28x%29%5Ccos%28%5Cfrac%7B%5Cpi%20x%7D%7B2%7D%29%5Czeta%28x%29.svg)

![Eq6](https://math.vercel.app/?color=cyan&from=%5Czeta%28x%29%20%3D%20%5Cfrac%7B1%7D%7B1-2%5E%7B1-x%7D%7D%5Csum_%7Bn%3D1%7D%5E%7B%5Cinfty%7D%7B%5Cfrac%7B%28-1%29%5E%7Bn-1%7D%7D%7Bn%5Ex%7D%7D.svg)
