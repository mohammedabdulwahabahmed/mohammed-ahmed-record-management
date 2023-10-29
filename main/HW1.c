Name: Mohammed Ahmad

Student Number:2010213571







//1- Write a function that adds all odd numbers to the beginning of the list and all even
//numbers to the end of the list until -1 is entered from the keyboard.

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} node_t;

// Function to add a new node with data at the end of the linked list.
void add_node_to_end(node_t** head, int data) {

    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty, make the new node the head.
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Traverse the list to find the last node and add the new node at the end.
    node_t* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

// Function to create a linked list based on user input for odd and even numbers.
node_t* add_odd_even_to_list() {
    node_t* head = NULL;

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // Continue adding numbers to the list until -1 is entered.
    while (number != -1) {
        if (number % 2 == 1) {

            add_node_to_end(&head, number);
        } else {
            add_node_to_end(&head, number);
        }
        printf("Enter a number: ");
        scanf("%d", &number);
    }

    return head;
}
//
//2- Add 100 randomly generated numbers to the list, write the c code that sorts all the
//numbers entered from largest to smallest and prints them on the screen
//3- Output : 54->58->62->65->71->73->……102

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} node_t;

// Function to add a new node with data at the beginning of the linked list.
void add_node_to_beginning(node_t** head, int data) {

    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to swap data between two nodes.
void swap_nodes(node_t* node1, node_t* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Function to sort the linked list in descending order.
void sort_list(node_t** head) {
    node_t* current = *head;
    node_t* next;

    while (current != NULL) {
        next = current->next;

        while (next != NULL) {
            if (current->data < next->data) {
                swap_nodes(current, next);
            }

            next = next->next;
        }

        current = current->next;
    }
}

// Function to print the linked list.
void print_list(node_t* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main() {
    node_t* head = NULL;

    srand(time(NULL));

    // Generate and add 100 random numbers to the beginning of the list.
    for (int i = 0; i < 100; i++) {
        int random_number = rand() % 100 + 1;
        add_node_to_beginning(&head, random_number);
    }

    // Sort the list in descending order.
    sort_list(&head);


    print_list(head);

    return 0;
}

//4- Write a function that stores the student number, name and age, traverses all the nodes in
//the list, writes all the student information on the screen and counts it.
//The output should look like this on the screen: 1- Saliha 27 201
//2- Ece 19 203

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student {
    int student_number;
    char name[50];
    int age;
    struct Student* next;
} student_t;

// Function to add a student to the end of the linked list
void add_student(student_t** head, student_t* new_student) {
    if (*head == NULL) {
        *head = new_student;
        (*head)->next = NULL;
        return;
    }

    student_t* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_student;
    new_student->next = NULL;
}


void print_students(student_t* head) {
    int count = 1;
    while (head != NULL) {
        printf("%d. Student Name: %s, Age: %d, Student Number: %d\n", count, head->name, head->age, head->student_number);
        head = head->next;
        count++;
    }
}

// Function to count the number of students in the list
int count_students(student_t* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    student_t* head = NULL;

    // Create and populate the first student
    student_t* student1 = (student_t*)malloc(sizeof(student_t));
    student1->student_number = 1;
    strcpy(student1->name, "Saliha");
    student1->age = 27;

    // Create and populate the second student
    student_t* student2 = (student_t*)malloc(sizeof(student_t));
    student2->student_number = 2;
    strcpy(student2->name, "Ece");
    student2->age = 19;

    // Add the students to the linked list
    add_student(&head, student1);
    add_student(&head, student2);


    print_students(head);


    int count = count_students(head);

    printf("The total number of students is: %d\n", count);


    free(student1);
    free(student2);

    return 0;
}

//5- Write the function that searches records by student name in the list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student {
    int student_number;
    char name[50];
    int age;
    struct Student* next;
} student_t;


student_t* search_student_by_name(student_t* head, const char* name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int main() {
    student_t* head = NULL;


    student_t* student1 = (student_t*)malloc(sizeof(student_t));
    student1->student_number = 1;
    strcpy(student1->name, "Saliha");
    student1->age = 27;

    // Add the student to the linked list
    student1->next = head;
    head = student1;

    // Search for a student by name
    const char* search_name = "Saliha";
    student_t* found_student = search_student_by_name(head, search_name);

    if (found_student != NULL) {
        printf("Student found: Name: %s, Age: %d, Student Number: %d\n", found_student->name, found_student->age, found_student->student_number);
    } else {
        printf("Student not found.\n");
    }

    free(student1);
    return 0;
}

//6- Write the function that deletes the next node from the node with the searched student
//name in the list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int student_number;
    char name[50];
    int age;
    struct Student* next;
} student_t;

// Function to delete the next student with a specific name
void delete_next_node_with_name(student_t* head, const char* name) {

    student_t* current = search_student_by_name(head, name);

    // Check if the current student exists and has a next student
    if (current != NULL && current->next != NULL) {
        student_t* temp = current->next;

        current->next = temp->next;

        free(temp);
    }
}

//7- Write the function that prints the record with the longest name in the list.
//Output : the longest name in the list: Abdurrahmangazi
//Length : 15


#include <stdio.h>
#include <string.h>

typedef struct Student {
    int student_number;
    char name[50];
    int age;
    struct Student* next;
} student_t;


void print_longest_name(student_t* head) {

    int max_length = 0;
    char* longest_name = NULL;


    while (head != NULL) {
        // Calculate the length of the current student's name
        int current_length = strlen(head->name);

        // Compare the length of the current name with the maximum length found so far
        if (current_length > max_length) {
            // If the current name is longer, update the maximum length and longest name
            max_length = current_length;
            longest_name = head->name;
        }

        head = head->next;
    }


    printf("The longest name in the list: %s\n", longest_name);
    printf("Length: %d\n", max_length);
}
