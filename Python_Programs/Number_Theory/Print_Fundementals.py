fundemental = [3, 4, 7, 8, 11, 15, 19, 20, 23, 24, 31, 35, 39, 40, 43, 47, 51, 52, 55, 56, 59, 67, 68, 71, 79, 83, 84, 87, 88, 91, 95, 103, 104, 107, 111, 115, 116, 119, 120, 123, 127, 131, 132, 136, 139, 143, 148, 151, 152, 155, 159, 163, 164, 167, 168, 179, 183, 184, 187, 191]


#Prints out everything 1 - 120 seperated by comma
for i in range(1,121):
    print(-i, end = ", ")

print("\n\n")


#Prints highlights only the fundemental discriminants
for i in range(1,121):
    if i in fundemental:
        print("\hl{" + str(-i) + "}", end = ", ")
    else:
        print(-i, end = ", ")

print("\n\n")

#Prints only the fundemental discriminants
for i in range(1,121):
    if i in fundemental:
        print(-i, end = ", ")

print("\n\n")

#Prints only the fundemental discriminants if they are = 3 mod 8, or 4,8mod 16
for i in range(1,121):
    if i in fundemental:
        if(i%8 == 3 or i%16 == 4 or i%16 == 8):
            print("\hl{" + str(-i) + "}", end = ", ")
        else:
            print(-i, end = ", ")

print("\n\n")

#Prints only the fundemental discriminants if they are = 7,15 mod 24 or 23,47,95 mod 120
for i in range(1,121):
    if i in fundemental:
        if(i%8 == 3 or i%16 == 4 or i%16 == 8):
            print("\hl{" + str(-i) + "}", end = ", ")
        elif (i%24 == 7 or i%24 == 15  or i%120 == 23 or i%120 == 47 or i%120 == 95):
            print("\hlyellow{" + str(-i) + "}", end = ", ")
        else:
            print(-i, end = ", ")



