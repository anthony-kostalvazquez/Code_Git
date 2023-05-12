first_poly = open("C:/Users/antho/Desktop/Code/python/Number_Theory/first_poly", "r")
second_poly = open("C:/Users/antho/Desktop/Code/python/Number_Theory/second_poly", "r")
size = 2049


for i in range(size):
    first_poly_coef = int(first_poly.readline().split()[0])
    second_poly_coef = int(second_poly.readline().split()[0])

    print(2 * first_poly_coef + second_poly_coef)

first_poly.close()
second_poly.close()