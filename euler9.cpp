// Author: Jason Blanchard
// Solve Project Euler problem 9. Find the Pythagorean triplet where
// a + b + c = 1000, printing a*b*c as the answer.
//
// Use Euclid's formula to find Pythagorean triplets:
// Start with a pair of positive integers (m,n) where m > n.
// a = m^2 - n^2, b = 2mn, c = m^2+n^2 to form the triple.
// Then using k > 1, k*a, k*b, k*c we generate non-primative triples.
// Unfortunately, these aren't unique.

#include <iostream>

struct PythagoreanTriple {
    int a, b, c;
};

// Will generate triples from a specific m,n using k.
bool GenerateTriples(PythagoreanTriple *pt) {
    bool result_found = false;
    int k = 1;

    // Loop until we've reached a sum of 1000 or greater
    while (k*pt->a + k*pt->b + k*pt->c < 1000) {
        ++k;
    }

    // 1000 is our target, if we hit it, make our pt reflect the
    // correct numbers and say we've found result.
    if (k*pt->a + k*pt->b + k*pt->c == 1000) {
        pt->a = k*pt->a;
        pt->b = k*pt->b;
        pt->c = k*pt->c;
        result_found = true;
    }

    return result_found;
}

// When we find our triple we will return the product of the three
// numbers.
long ProductTriple() {
    PythagoreanTriple *pt = new PythagoreanTriple;
    pt->a = 0; pt->b=0; pt->c = 0;
    int m = 2, n = 1;
    bool result_found = false;
    long result = 0;

    // 1000 was chosen though it should never be reached, loop
    // through generating triples until we find it.
    for (m = 2; m < 1000; ++m) {
        for(n = 1; n < m; ++n) {
            pt->a = m*m - n*n;
            pt->b = 2*m*n;
            pt->c = m*m + n*n;

            result_found = GenerateTriples(pt);

            // After we've found our result, print what the numbers
            // are and then return the product.
            if (result_found) {
                std::cout << "a = " << pt->a << std::endl;
                std::cout << "b = " << pt->b << std::endl;
                std::cout << "c = " << pt->c << std::endl;
                result = pt->a * pt->b * pt->c;
                delete pt;
                return result;
            }
        }
    }

    delete pt;
    return 0;
}

int main() {
    std::cout << "Product triple: " << ProductTriple() << std::endl;

    return 0;
}
