import math

# [c , r , s , a , m]
POLYNOMIALS = [
[.5,0,1,1,1],
[1,0,1,1,3],
[.5,0,1,1,1],
[1,0,4,1,3],
[1,0,4,0,1],
[2,1,4,2,3],
[.5,0,4,1,1]]

min = 0
size = 58

def mult(P, Q):
    m = len(P)
    n = len(Q)
    result = [0]*(m+n-1)

    for i in range(m):
        for j in range(n):
            result[i+j] += P[i]*Q[j]
    return result

def add(P, Q):
    m = len(P)
    n = len(Q)
    result = [0]*max(m,n)

    for i in range(max(m,n)):
        result[i] = (P[i] + Q[i])

    return result

def init(poly_num):

    initiated_poly = [0.0]*(size+1000)

    c = POLYNOMIALS[poly_num][0]
    r = POLYNOMIALS[poly_num][1]
    s = POLYNOMIALS[poly_num][2]
    a = POLYNOMIALS[poly_num][3]
    m = POLYNOMIALS[poly_num][4]

    for i in [-1,1]:
        power = 0
        k = 0
        while power < size:
            power = r + s * (((i*k) * ( (m * (i*k)) + a )) / 2)
            initiated_poly[int(power)] += c
            k = k + 1



    return initiated_poly


def main():
    temp1 = mult(init(1), init(2))
    temp2 = mult(init(3), init(4))
    temp3 = mult(init(5), init(6))

    temp4 = add(temp1, temp2)

    temp5 = add(temp4, temp3)
    
    tempf = mult(temp5, init(0))
    
    for i in range(len(POLYNOMIALS)):
        print(POLYNOMIALS[i])
        temp = init(i)
        for j in range(size):
            if temp[j] != 0:
                print(j, temp[j])
                ""

    for i in range(size):
        if tempf[i] != 0:
            print(i, tempf[i])
            ""

        



main()