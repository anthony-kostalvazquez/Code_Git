#this will calculate the upper bound on the co efferents of a resulting polynomial
import math

#note: ∆ = g^2e

N = 2**40
A = 1/4
B = (5/4) - (math.log(3) / 2)

#finds the bound
bound = N // 16
print("bound = ", bound)

#finds the bundling parameter
for i in range(1, bound + 1):
    if bound % i == 0:
        bund_para = i

print("Bundling Parameter = ", bund_para)


#finds the largest fundamental discriminant e such that e divides ∆



CN = math.floor(1)
