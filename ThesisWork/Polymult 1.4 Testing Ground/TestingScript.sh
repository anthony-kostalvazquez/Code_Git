#here are all of the class number formulas
declare -A ClassNumberRoutines=(
    [(LOCAL) H3MOD8 To 2^16*3*5]="./polymult 122880 2 4 7802 h3mod8. ~/Class_Number_Tabulation/h3mod8 1 0 1 1 1 1 0 1 1 1 1 0 1 1 1"

    [(LOCAL) ALL MOD8,16,24 To 2^16*3*5]="./polymult 61440 2 4 4256 h8mod16. ~/Class_Number_Tabulation/h8mod16 1 0 2 0 1 1 0 2 1 1 1 0 2 1 1 && ./polymult 61440 2 4 4256 h4mod16. ~/Class_Number_Tabulation/h4mod16 1 0 2 1 1 1 0 2 0 1 1 0 2 0 1 && ./polymult 122880 2 4 7802 h3mod8. ~/Class_Number_Tabulation/h3mod8 1 0 1 1 1 1 0 1 1 1 1 0 1 1 1 && ./polymult 40960 2 4 7802 h7mod24. ~/Class_Number_Tabulation/h7mod24 1 0 1 1 1 1 0 1 1 3 1 0 1 1 1 1 0 4 1 3 1 0 4 0 1 2 1 4 2 3 1 0 4 1 1 && ./polymult 40960 2 4 7802 h15mod24. ~/Class_Number_Tabulation/h15mod24 1 0 1 1 1 1 0 3 1 1 1 0 1 1 1 1 1 12 1 1 1 0 4 0 1 1 0 12 0 1 1 0 4 1 1"

    [(LOCAL) ALL MOD8,16,24,120 To 2^16*3*5]="./polymult 61440 2 4 4256 h8mod16. ~/Class_Number_Tabulation/h8mod16 1 0 2 0 1 1 0 2 1 1 1 0 2 1 1 && ./polymult 61440 2 4 4256 h4mod16. ~/Class_Number_Tabulation/h4mod16 1 0 2 1 1 1 0 2 0 1 1 0 2 0 1 && ./polymult 122880 2 4 7802 h3mod8. ~/Class_Number_Tabulation/h3mod8 1 0 1 1 1 1 0 1 1 1 1 0 1 1 1 && ./polymult 40960 2 4 7802 h7mod24. ~/Class_Number_Tabulation/h7mod24 1 0 1 1 1 1 0 1 1 3 1 0 1 1 1 1 0 4 1 3 1 0 4 0 1 2 1 4 2 3 1 0 4 1 1 && ./polymult 40960 2 4 7802 h15mod24. ~/Class_Number_Tabulation/h15mod24 1 0 1 1 1 1 0 3 1 1 1 0 1 1 1 1 1 12 1 1 1 0 4 0 1 1 0 12 0 1 1 0 4 1 1 && ./polymult 8192 2 4 7802 h23mod120PART1. ~/Class_Number_Tabulation/h23mod120 1 0 1 1 3 2 0 2 2 15 1 0 2 1 3 1 1 2 8 15 1 0 2 1 3 1 1 2 7 15 1 0 2 2 3 1 3 2 13 15 1 0 2 2 3 1 3 2 12 15 2 0 6 1 1 1 0 2 3 15 1 0 6 0 1  && ./polymult 8192 2 4 7802 h23mod120PART2. ~/Class_Number_Tabulation/h23mod120 2 0 3 1 1 2 1 2 2 15 2 0 6 1 1 2 2 2 8 15 2 0 6 1 1 1 1 2 7 15 1 0 6 0 1 1 3 2 13 15 1 0 6 0 1  && ./polyadd ~/Class_Number_Tabulation 23 120 && ./polymult 8192 2 4 7802 h47mod120PART1. ~/Class_Number_Tabulation/h47mod120 1 0 1 1 3 2 1 2 4 15 1 0 2 1 3 2 3 2 14 15 1 0 2 1 3 2 0 2 1 15 1 0 2 2 3 2 2 2 11 15 1 0 2 2 3 2 1 2 6 15 2 0 6 1 1 1 1 2 9 15 1 0 6 0 1 && ./polymult 8192 2 4 7802 h47mod120PART2. ~/Class_Number_Tabulation/h47mod120 2 0 3 1 1 4 1 2 4 15 2 0 6 1 1 4 4 2 14 15 2 0 6 1 1 2 0 2 1 15 1 0 6 1 1 2 2 2 11 15 1 0 6 0 1 && ./polyadd ~/Class_Number_Tabulation 47 120 && ./polymult 8192 2 4 7802 h95mod120PART1. ~/Class_Number_Tabulation/h95mod120 2 0 1 1 3 2 1 2 10 15 1 0 2 1 3 2 0 2 5 15 1 0 2 2 3 1 0 30 0 1 1 0 6 1 1 1 3 30 1 1 1 0 6 0 1 && ./polymult 8192 2 4 7802 h95mod120PART2. ~/Class_Number_Tabulation/h95mod120 1 0 3 1 1 2 0 2 5 15 1 0 6 0 1 4 2 2 10 15 1 0 6 1 1 && ./polyadd ~/Class_Number_Tabulation 95 120"

    [(LOCAL) H23MOD120 2^16*3*5]="./polymult 8192 1 4 7802 h23mod120PART1. ~/Class_Number_Tabulation/h23mod120 1 0 1 1 3 2 0 2 2 15 1 0 2 1 3 1 1 2 8 15 1 0 2 1 3 1 1 2 7 15 1 0 2 2 3 1 3 2 13 15 1 0 2 2 3 1 3 2 12 15 1 0 6 1 1 1 0 2 3 15 1 0 6 0 1  && ./polymult 8192 1 4 7802 h23mod120PART2. ~/Class_Number_Tabulation/h23mod120 2 0 3 1 1 2 1 2 2 15 1 0 6 1 1 2 2 2 8 15 1 0 6 1 1 1 1 2 7 15 1 0 6 0 1 1 3 2 13 15 1 0 6 0 1  && ./polyadd ~/Class_Number_Tabulation 23 120"

    [(LOCAL) H95mod120 2^16*3*5]="./polymult 8192 1 4 7802 h95mod120PART1. ~/Class_Number_Tabulation/h95mod120 2 0 1 1 3 2 1 2 10 15 1 0 2 1 3 2 0 2 5 15 1 0 2 2 3 1 0 30 0 1 1 0 6 1 1 1 3 30 1 1 1 0 6 0 1 && ./polymult 8192 1 4 7802 h95mod120PART2. ~/Class_Number_Tabulation/h95mod120 1 0 3 1 1 2 0 2 5 15 1 0 6 0 1 4 2 2 10 15 1 0 6 1 1 && ./polyadd ~/Class_Number_Tabulation 95 120"

    [(LOCAL) H47mod120 2^16*3*5]="./polymult 8192 1 4 7802 h47mod120PART1. ~/Class_Number_Tabulation/h47mod120 1 0 1 1 3 2 0 2 4 15 1 0 2 1 3 2 3 2 14 15 1 0 2 1 3 2 0 2 1 15 1 0 2 2 3 2 2 2 11 15 1 0 2 2 3 2 1 2 6 15 2 0 6 1 1 1 1 2 9 15 1 0 6 0 1 && ./polymult 8192 1 4 7802 h47mod120PART2. ~/Class_Number_Tabulation/h47mod120 2 0 3 1 1 4 1 2 4 15 2 0 6 1 1 4 4 2 14 15 2 0 6 1 1 2 0 2 1 15 1 0 6 0 1 2 2 2 11 15 1 0 6 0 1 && ./polyadd ~/Class_Number_Tabulation 47 120"
)

#Shows user the options
echo Hello, what whould you like to test:?
for i in "${!ClassNumberRoutines[@]}"
do
    #echo "${i} = ${ClassNumberRoutines[$i]}"
    echo "${i}"
done

#gets user input
read Routine_To_Run

##################################TEST##################################

#delete the old files
eval find ~/Class_Number_Tabulation -type f -delete

#Run Chosen Routine
eval ${ClassNumberRoutines[$Routine_To_Run]}

#Verify Results
if [ "$Routine_To_Run" == "(LOCAL) H23MOD120 2^16*3*5" ]
then
    eval ./polycheck ~/Class_Number_Tabulation 23 120 1 >>H23MOD120_2^16*3*5_test.txt
fi

if [ "$Routine_To_Run" == "(LOCAL) H3MOD8 To 2^16*3*5" ]
then
    eval ./polycheck ~/Class_Number_Tabulation 3 8 3 >>H3MOD8_To_2^16*3*5_test.txt
fi

if [ "$Routine_To_Run" == "(LOCAL) H95mod120 2^16*3*5" ]
then
    eval ./polycheck ~/Class_Number_Tabulation 95 120 1 >>H95mod120_To_2^16*3*5_test.txt
fi

if [ "$Routine_To_Run" == "(LOCAL) H47mod120 2^16*3*5" ]
then
    eval ./polycheck ~/Class_Number_Tabulation 47 120 2 >>H47mod120_To_2^16*3*5_test.txt
fi
