# School management project

## 1. Defining the structures

-   Creating a structure to contain student info: student id, name, array of subjects they study
-   Creating a linked list to store student structures
-   Creating a structure to contain subject info: subject name and subject id
-   Creating an array of subjects to store the subjects for each student
-   Creating a structure to contain teacher info: teacher id, name and id of the subject the teach
-   Creating a linked list to store teacher structures

## 2. Core Functionalities

### Student

-   Creating a student head
-   Creating a student
-   Checking if student's id is unique
-   If student id is not unique or empty the student won't be added to a list
-   Printing a specified student (with id, name and his/her subjects)
-   Printing all students
-   Adding a new student using information provided by a user in the command line (student id and student name)
-   Finding a student by id (used in other functions)
-   Adding subject to a student using information provided by a user (student id and subject id)
-   If student id or subject id are not correct (do not exist in the corresponding list and array) or empty the subject won't be added to a student's array of subjects
-   Adding grade to a given student for a specified subject using command line inputs (student id, subject id and grade)
-   Printing students with their grades
-   Finding all students studying a specified subject
-   Using helper functions (starting with user\_) for a better user experience

### Subject

-   Creating a subject
-   Checking if student's id is unique
-   If subject id is not unique or empty the subject won't be added to an array
-   Adding a subject to ArrayList (using memcpy() and then free())
-   Printing a specified subject
-   Adding a new student using information provided by a user in the command line (subject id and subject name)
-   Finding a subject by id (used in other functions)
-   Using helper functions (starting with user\_) for a better user experience

### Teacher

-   Creating a teacher head
-   Checking if teacher's id is unique
-   Checking if a teacher is assigned only one subject
-   Creating a teacher
-   Adding a teacher to a linked list
-   Printing a specified teacher
-   Printing all teachers (only with the corresponding subjects)
-   Adding a new teacher using information provided by a user in the command line
-   Finding a teacher by a given subject
-   Using helper functions (starting with user\_) for a better user experience
