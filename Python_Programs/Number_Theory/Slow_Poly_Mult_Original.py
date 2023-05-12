import math

# [c , r , s , a , m]
POLYNOMIALS = [
[1,0,1,1,3],
[2,1,2,10,15],
[1,0,2,1,3],
[2,0,2,5,15],
[1,0,2,2,3],
[1,0,30,0,1],
[1,0,6,1,1],
[1,3,30,1,1],
[1,0,6,0,1]
]

min = 0
size = 6000

def mult(P, Q):
    result = [0]*size

    for i in range(size):
        for j in range(size):
            if i + j < size:
                result[i+j] += P[i]*Q[j]
    return result

def add(P, Q):
    result = [0]*size
    for i in range(size):
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
            initiated_poly[int(t)] += c
            t += ((s*(2*i*m + m - a)) / 2)
            i = i + 1

    return initiated_poly


def main():
    #generates the first term (the multiplied sum out front)
    print("---------FIRST TERM---------")
    first_term = init(0)
    print(POLYNOMIALS[0])
    for j in range(size):
        print(first_term[j])
    print("----------------------------")

    #generates the second term (added polynuminal sums)
    second_term = [0] * size
    for i in range((len(POLYNOMIALS)-1)//2):
        temp = mult(init(2 * i + 1), init(2*i + 2))
        second_term = add(second_term, temp)

        #prints the individual peices of the second term
        print(POLYNOMIALS[2*i + 1], " x ", POLYNOMIALS[2*i + 2])
        for j in range(size):
            print(temp[j])

    #prints the final second term
    print("---------SECOND TERM---------")
    for j in range(size):
        if second_term[j] != 0:
            print(second_term[j])
    print("-----------------------------")

    #generates the result
    result = mult(first_term, second_term)
    print("---------RESULT---------")
    for j in result:
        print(j)

main()