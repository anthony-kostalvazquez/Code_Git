#This is a program I made to automatically extract all the relevant data from the output of Polymult-1.4 and Clrp-1.3 after running
#This data is then put into a format that is easy to cut and paste into a excel document. 

import os
from tkinter import SE

#Here you put where the folder containing the mixed output.txt files are
FOLDER_PATH = "C:/Users/antho/Desktop/printstatements.txt"


FIRST_POLY = [[],[]]
SECOND_POLY = [[],[]]
RESULT_POLY = [[],[]]

temp = []

def main():
    #initialize
    for i in range(0,4500):
        FIRST_POLY[0].append(0)
        FIRST_POLY[1].append(0)
        SECOND_POLY[0].append(0)
        SECOND_POLY[1].append(0)
    
    for i in range(0,9000):
        RESULT_POLY[0].append(0)
        RESULT_POLY[1].append(0)


    f_in = open(FOLDER_PATH, "r")

    current_file = 0
    current_list = "n/a"

    c = 0
    power = 0

    #splits the data up with lots of hard coding
    for i in f_in:
        if("init block" in i):
            current_list = "first poly"
        elif("nabla pro" in i):
            current_list = "second poly"

        if("File" in i):
            temp = i.split()
            current_file = int(temp[1])
        
        if("data" in i):
            temp = i.split()
            power = int(temp[1])
            c = int(temp[2])
            min = int(temp[3])

            if (current_list == "first poly"):
                FIRST_POLY[current_file][power+min] += c
    
            elif (current_list == "second poly"):
                SECOND_POLY[current_file][power+min] += c


    print(SECOND)
    f_in.close()

main()