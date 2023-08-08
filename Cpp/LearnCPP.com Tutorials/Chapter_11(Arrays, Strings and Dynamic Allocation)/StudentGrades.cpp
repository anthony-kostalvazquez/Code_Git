/*Write the following program: Create a struct that holds a student’s first name and grade (on a scale of 0-100). Ask the user how many students they want to enter. Create a std::vector to hold all of the students. Then prompt the user for each name and grade. Once the user has entered all the names and grade pairs, sort the list by grade (highest first). Then print all the names and grades in sorted order.*/


#include <algorithm> // std::shuffle
#include <array>
#include <iostream>
#include <numeric> // std::reduce

//names and grades (on 0-100 scale)
struct Student
{
    std::string name{};
    int grade{};
};

bool compare(Student a, Student b)
{
    if(a.grade > b.grade)
    {
        return true;
    }
    
    return false;
}

void printGradeBook(const std::vector<Student> &grade_book)
{
    for(Student i : grade_book)
    {
        std::cout << i.name << " Got a grade of " << i.grade << '\n';
    }
}


int main()
{
    //vector for struct gradebook
    std::cout << "How many students would you like to enter? \n";

    long unsigned int num_of_students{};
    std::cin >> num_of_students;

    std::vector<Student> grade_book(num_of_students);

    //gets names and grades from user
    for(auto& i : grade_book)
    {
        std::cout << "Name:";
        std::cin >> i.name;

        std::cout << "grade:";
        std::cin >> i.grade; 
    }

    //sorts by highest grade
    std::sort(grade_book.begin(), grade_book.end(), compare);

    //prints names and grades
    printGradeBook(grade_book);

    return 0;
}