#This is a program I made to automatically extract all the relevant data from the output of Polymult-1.4 and Clrp-1.3 after running
#This data is then put into a format that is easy to cut and paste into a excel document. 

import os

#Here you put where the folder containing the mixed output.txt files are
FOLDER_PATH = "C:/Users/antho/Desktop/Tabulations/Local 2^16, 18, 20, 22, 24, 26"
REAL_LIST = []
USER_LIST = []
SYS_LIST = []

def main():
    
    #this loop iterates over all the files names within the folder you put as FOLDER_PATH
    for file_name in os.listdir(FOLDER_PATH):
        #Separates the data into ordered lists
        separator(file_name)

        #Prints the lists into a format that can be copies and pasted into excel
        print("----------------------------------")
        print(file_name)
        print("----------------------------------")
        print("Real Times")
        for i in REAL_LIST:
            print(i)

        print("User Times")
        for i in USER_LIST:
            print(i)

        print("Sys Times")
        for i in SYS_LIST:
            print(i)
        
        REAL_LIST.clear()
        USER_LIST.clear()
        SYS_LIST.clear()


#This takes the file and separates out the Real, Usr and Sys times into ordered lists
def separator(file):
        f_in = open(FOLDER_PATH + "/" + file, "r")

        for i in f_in:
            temp_list = i.split()

            if (temp_list != []):

                time_list = temp_list[1].split("m")
                mins = time_list[0]
                secs = time_list[1]

                secs = secs.rstrip("s")

                time_in_seconds = round((int(mins) * 60) + float(secs), 3)
                
                if (temp_list[0] == 'real'):
                    REAL_LIST.append(time_in_seconds)
                elif (temp_list[0] == 'user'):
                    USER_LIST.append(time_in_seconds)
                elif (temp_list[0] == 'sys'):
                    SYS_LIST.append(time_in_seconds)
        

        f_in.close()

main()