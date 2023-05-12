Print_Stop = 10000
START_SUM = 1000
RESERVE_REQUIREMENT = 0.008

#Exponential Function
for i in range(0,Print_Stop):
    #print("%.100f" %2**-i)
    print(" 2^-%d" %i,"=", 2**-i)

#for i in range(0,Print_Stop):
    #print(2**-i)


#Fractional Reserve Banking
SUM = 0
#for i in range(0,Print_Stop):
    #SUM = SUM + START_SUM * (1-RESERVE_REQUIREMENT) ** i
    #print(SUM)