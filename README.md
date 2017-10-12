# SOFE2850-Assignment1
Assignment-1

[![Build Status](https://travis-ci.org/RileyS17/SOFE2850-Assignment1.svg?branch=master)](https://travis-ci.org/RileyS17/SOFE2850-Assignment1)

## Output

The output will be seven columns of numbers with the following order;
```
time [s], x-position [m], y-position [m], z-position [m], x-speed [m/s], y-speed [m/s], z-speed[m/s]
```
Plot of x, y, z coordinates yielded from from the verlet algorithm:


## Questions

2. In the context of Question 1, how should the trajectory produced by the Verlet algorithm differ from the Euler integrator we used in the livecode?

    In general the result from the Verlet method is much more precise than the Euler method. In the Euler method, there is a larger    error per step, and that gradully compounds increasing the error over time. 

3. In livecode-projectile.hpp, we defined a type-constructor called VecR2<typename> along with operators for addition and scalar multiplication. Does the VecR2<int> type constitute a vector space? If yes, prove it. If not, explain why not.
  
    Sicne the type for VecR2 is <int>, it does not constitute a vector space. This is because <int> limits the scope of vector addition and scalar multiplication.

4. Using the type algebra we described in class, describe the type encoded in the following type equation: 𝐿⟨𝑇⟩ = 1 + 𝑇 × 𝐿⟨𝑇⟩

    The given type equation describes a product of T and the type constructor L. This type equation returns a list of elements of type T.
