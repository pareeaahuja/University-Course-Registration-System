 #include <stdio.h>
#include <string.h>
#include <ctype.h>

char student_ids[9][20] = {
    "S1A1","S2B2","S3C3","S4D4","S5E5",
    "S6F6","S7G7","S8H8","S9I9"
};

char passed_courses[9][20] = {
    "CS101","CS201","MA101","CS301","CS201",
    "MA101","CS101","CS301","CS201"
};

int current_credits[9] = {
    6,9,12,3,15,6,9,12,3
};

int max_credits[9] = {
    18,18,18,18,18,18,18,18,18
};

char course_codes[5][20] = {
    "CS101","CS201","CS301","CS401","MA201"
};

char prerequisites[5][20] = {
    "none","CS101","CS201","CS301","MA101"
};

int seats_available[5] = {
    25,20,10,0,5
};

// =============================================
//  TOKENIZER FOR STUDENT ID
//  Token 1: first Letter + first Digit  (e.g. S1)
//  Token 2: second Letter + second Digit (e.g. A1)
// =============================================
int tokenizeStudentID(char id[])
{
    int len = strlen(id);
    char t1[3] = "--";
    char t2[3] = "--";

    printf("\n[Tokenizer] Student ID: %s\n", id);

    // Token 1: id[0] + id[1]
    if(len >= 2)
    {
        t1[0] = id[0];
        t1[1] = id[1];
        t1[2] = '\0';
    }
    printf("  Token 1 (Letter+Digit): %s\n", t1);

    // Token 2: id[2] + id[3]
    if(len >= 4)
    {
        t2[0] = id[2];
        t2[1] = id[3];
        t2[2] = '\0';
    }
    printf("  Token 2 (Letter+Digit): %s\n", t2);

    if(len > 20)
    {
        printf("[Tokenizer] INVALID: ID must not exceed 20 characters.\n");
        return 0;
    }

    printf("[Tokenizer] Student ID Tokenization DONE.\n");
    return 1;
}

// =============================================
//  TOKENIZER FOR COURSE CODE
//  Token 1: first 2 Letters (dept)   e.g. CS
//  Token 2: last 3 Digits (number)   e.g. 101
// =============================================
int tokenizeCourseCode(char code[])
{
    int len = strlen(code);
    char t1[3] = "--";
    char t2[4] = "---";

    printf("\n[Tokenizer] Course Code: %s\n", code);

    // Token 1: code[0] + code[1]
    if(len >= 2)
    {
        t1[0] = code[0];
        t1[1] = code[1];
        t1[2] = '\0';
    }
    printf("  Token 1 (Dept Letters): %s\n", t1);

    // Token 2: code[2] + code[3] + code[4]
    if(len >= 5)
    {
        t2[0] = code[2];
        t2[1] = code[3];
        t2[2] = code[4];
        t2[3] = '\0';
    }
    printf("  Token 2 (Course Digits): %s\n", t2);

    if(len > 20)
    {
        printf("[Tokenizer] INVALID: Course code must not exceed 20 characters.\n");
        return 0;
    }

    printf("[Tokenizer] Course Code Tokenization DONE.\n");
    return 1;
}

int findStudent(char id[])
{
    int i;
    for(i = 0; i < 9; i++)
    {
        if(strcmp(student_ids[i], id) == 0)
            return i;
    }
    return -1;
}

int findCourse(char code[])
{
    int i;
    for(i = 0; i < 5; i++)
    {
        if(strcmp(course_codes[i], code) == 0)
            return i;
    }
    return -1;
}

void showStudents()
{
    int i;
    printf("\n-------------- STUDENTS ----------------\n");
    for(i = 0; i < 9; i++)
    {
        printf("%s  Passed:%s  Current_Credits:%d   Max_credits %d\n",
               student_ids[i], passed_courses[i],
               current_credits[i], max_credits[i]);
    }
}

void showCourses()
{
    int i;
    printf("\n----------------- COURSES-----------------\n");
    for(i = 0; i < 5; i++)
    {
        printf("%s  Prereq:%s  Seats:%d\n",
               course_codes[i], prerequisites[i], seats_available[i]);
    }
}

void registerCourse()
{
    char studentID[20];
    char courseCode[20];
    int studentIndex;
    int courseIndex;

    printf("\nEnter Student ID: ");
    scanf("%s", studentID);

    // q1 - Tokenize and Check ID
    tokenizeStudentID(studentID);

    studentIndex = findStudent(studentID);
    if(studentIndex == -1)
    {
        printf("\nHALT\n");
        printf("Student ID not found.\n");
        return;
    }

    printf("Student ID Verified.\n");

    // q2 -> q3 -> q4 Loop
    while(1)
    {
        printf("\nEnter Course Code: ");
        scanf("%s", courseCode);

        // q2 - Tokenize and Pick Course
        tokenizeCourseCode(courseCode);

        courseIndex = findCourse(courseCode);
        if(courseIndex == -1)
        {
            printf("\nHALT\n");
            printf("Course not found.\n");
            return;
        }

        printf("Course Found.\n");

        // q3 Check Prerequisite
        if(strcmp(prerequisites[courseIndex], "none") != 0 &&
           strcmp(prerequisites[courseIndex], passed_courses[studentIndex]) != 0)
        {
            printf("\nPrerequisite Not Completed.\n");
            printf("Returning to Course Selection...\n");
            continue;
        }

        printf("Prerequisite Completed\n");

        // q4 Check Seats
        if(seats_available[courseIndex] <= 0)
        {
            printf("\nNo Seats Available.\n");
            printf("Returning to Course Selection...\n");
            continue;
        }

        printf("Seats Available.\n");

        // q5 Check Credits
        if(current_credits[studentIndex] + 3 > max_credits[studentIndex])
        {
            printf("\nHALT\n");
            printf("Credit Limit Exceeded.\n");
            return;
        }

        printf("Credit Limit OK.\n");

        // qa Accept
        current_credits[studentIndex] += 3;
        seats_available[courseIndex]--;

        printf("\n--------------------------------\n");
        printf("ACCEPT STATE REACHED\n");
        printf("----------------------------------\n");
        printf("Enrollment Successful!\n");
        printf("Student ID : %s\n", studentID);
        printf("Course     : %s\n", courseCode);
        printf("New Credits: %d/%d\n",
               current_credits[studentIndex], max_credits[studentIndex]);

        break;
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n-----------------------------------\n");
        printf("University Course Registration System\n");
        printf("-------------------------------------\n");
        printf("1. Show Students\n");
        printf("2. Show Courses\n");
        printf("3. Register Student\n");
        printf("0. Exit\n");
        printf("Enter Choice: ");

        scanf("%d", &choice);

        if(choice == 1)       showStudents();
        else if(choice == 2)  showCourses();
        else if(choice == 3)  registerCourse();
        else if(choice == 0)  { printf("Program Ended.\n"); break; }
        else                  printf("Invalid Choice.\n");
    }

    return 0;
}
