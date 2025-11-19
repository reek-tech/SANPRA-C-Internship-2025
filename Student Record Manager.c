#include <stdio.h>

// maximum number of student records
#define MAX 100   

// Structure to store student details
struct Student {
    char name[50];
    int id;
    float grade;
};

// Function to add a new student
void addStudent(struct Student s[], int *count) {
    printf("Enter name: ");
    scanf("%s", s[*count].name);

    printf("Enter ID: ");
    scanf("%d", &s[*count].id);

    printf("Enter Grade: ");
    scanf("%f", &s[*count].grade);

    (*count)++;  // increase student count
    printf("Student added successfully!\n");
}

// Function to display all students
void viewStudents(struct Student s[], int count) {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | ID: %d | Grade: %.2f\n",
               s[i].name, s[i].id, s[i].grade);
    }
}

int main() {
    struct Student students[MAX];  // array of students
    int count = 0;                 // current number of students
    int choice;

    while (1) {
        printf("\n1. Add Student\n2. View All Students\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
