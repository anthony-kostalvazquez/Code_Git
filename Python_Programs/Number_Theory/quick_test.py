import math

# [c , r , s , a , m]
POLYNOMIALS = [
[1,0,1,1,1],
[1,0,1,1,3],
[1,0,1,1,1],
[1,0,4,1,3],
[1,0,4,0,1],
[2,1,4,2,3],
[1,0,4,1,1]]

min = 0
size = 2000

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

    initiated_poly = [0]*(size)

    c = POLYNOMIALS[poly_num][0]
    r = POLYNOMIALS[poly_num][1]
    s = POLYNOMIALS[poly_num][2]
    a = POLYNOMIALS[poly_num][3]
    m = POLYNOMIALS[poly_num][4]

    if r >= min:
        i = 0
    else:
        d = math.ceil(math.sqrt((a*a*s + 8*m*(min-r)) / s))
        i = (d - a) // (2*m)

        if ((d - a) % (2*m) != 0):
            i = i + 1
    
    t = r + ((s * i * (m * i + a)) / 2) - min

    while(t < size):
        initiated_poly[int(t)] += c
        t += ((s*(2*i*m + m + a)) / 2)
        i = i + 1
    
    if ((a != 1) or (m != 1)):
        if (r >= min):
            i = 1
        else:
            i = (d + a) / (2 * m)

            if ((d + a) % (2*m) != 0):
                i = i+1
    
        t = r + ((s * i * (m * i - a)) / 2) - min
        while(t < size):
            #print(t)
            initiated_poly[int(t)] += c
            t += ((s*(2*i*m + m - a)) / 2)
            i = i + 1

    return initiated_poly


def main():
    temp3 = mult(init(5), init(6))


    for i in range(size):
        if temp3[i] != 0:
            print("power = ", i + min, "\tco-efficent = ",temp3[i], "\tD = ", -(7 + 24*i))

    
    


main()