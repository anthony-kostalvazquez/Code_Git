START_NUMBER = 300
COUNT = 0

for i in range(0,2022):
    if START_NUMBER % 2 == 0:
        START_NUMBER = START_NUMBER // 2
    else:
        START_NUMBER = (START_NUMBER * 3) - 1
    
    print(START_NUMBER)
