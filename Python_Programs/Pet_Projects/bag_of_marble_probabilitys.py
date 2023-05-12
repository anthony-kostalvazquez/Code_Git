#1 = Red
#2 = Blue
#3 = Green

import random

marble_list = [1,1,1,2,2,2,2,2,3,3,3,3,3,3,3]
analysis_list = []
LOOKING_FOR = 1
NUMBER_OF_TRIALS = 1000


#this list will return 0 if the list still has all of the colors
#it will return the number of the color if 
def list_check(list_a):
    if (1 in list_a) and (2 in list_a) and (3 in list_a):
        return 0
    else:
        for i in [1,2,3]:
            if not(i in list_a):
                return i

#Will take in the final result list and return the probablility that the specific colour your lookings for comes up
def list_analysis(final_list):
    number_of_occurences = final_list.count(LOOKING_FOR)
    return number_of_occurences/len(final_list)


def main():
    loop_count = 0
    while(loop_count != NUMBER_OF_TRIALS):
        sacrificial_list = marble_list.copy()

        pull_count = 0

        while(list_check(sacrificial_list) == 0):
            rand_pull = random.randint(0,len(sacrificial_list) - 1)
            sacrificial_list.pop(rand_pull)
            print(sacrificial_list)

            #Not really needed
            pull_count = pull_count + 1
            #Not really needed
        
        #print(sacrificial_list)

        #adding the depleated color to a list
        analysis_list.append(list_check(sacrificial_list))

        loop_count = loop_count + 1
   
    #print("ANALYSIS LIST")
    #print(analysis_list)
    #print("ANALYSIS LIST")

    print("over",NUMBER_OF_TRIALS, "trials red was the first ball to be depleted ", list_analysis(analysis_list)*100, "percent of the time" )


main()