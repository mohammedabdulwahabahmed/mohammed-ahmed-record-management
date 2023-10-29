//name:mohammed ahmed
//student number:2010213571




//1- Write a function that adds all odd numbers to the beginning of the list and all even
//numbers to the end of the list until -1 is entered from the keyboard.

void add_node_to_end(node_t **head, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
    return;
  }
  node_t *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
}
node_t *add_odd_even_to_list() {
  node_t *head = NULL;

  int number;
  printf("Enter a number: ");
  scanf("%d", &number);
  while (number != -1) {
    if (number % 2 == 1) {
      add_node_to_beginning(&head, number);
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

typedef struct node {
  int data;
  struct node *next;
} node_t;

void add_node_to_beginning(node_t **head, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void swap_nodes(node_t *node1, node_t *node2) {
  int temp = node1->data;
  node1->data = node2->data;
  node2->data = temp;
}

void sort_list(node_t **head) {
  node_t *current = *head;
  node_t *next;

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

void print_list(node_t *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }

  printf("\n");
}

int main() {
  node_t *head = NULL;

  srand(time(NULL));

  for (int i = 0; i < 100; i++) {
    int random_number = rand() % 100 + 1;
    add_node_to_beginning(&head, random_number);
  }

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

typedef struct student {
    int student_number;
    char name[50];
    int age;
    struct student *next;
} student_t;

void add_student(student_t **head, student_t *new_student) {
    if (*head == NULL) {
        *head = new_student;
        (*head)->next = NULL;
        return;
    }

    student_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_student;
    new_student->next = NULL;
}

void print_students(student_t *head) {
    int count = 1;
    while (head != NULL) {
        printf("%d. %s %d %d\n", count, head->name, head->age, head->student_number);
        head = head->next;
        count++;
    }
}

int count_students(student_t *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

int main() {
    student_t *head = NULL;

    student_t *student1 = (student_t *)malloc(sizeof(student_t));
    student1->student_number = 1;
    strcpy(student1->name, "Saliha");
    student1->age = 27;

    student_t *student2 = (student_t *)malloc(sizeof(student_t));
    student2->student_number = 2;
    strcpy(student2->name, "Ece");
    student2->age = 19;

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

student_t *search_student_by_name(student_t *head, const char *name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

//6- Write the function that deletes the next node from the node with the searched student
//name in the list.

void delete_next_node_with_name(student_t *head, const char *name) {
    student_t *current = search_student_by_name(head, name);
    if (current != NULL && current->next != NULL) {
        student_t *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

//7- Write the function that prints the record with the longest name in the list.
//Output : the longest name in the list: Abdurrahmangazi
//Length : 15

void print_longest_name(student_t *head) {
    int max_length = 0;
    char *longest_name = NULL;

    while (head != NULL) {
        int current_length = strlen(head->name);
        if (current_length > max_length) {
            max_length = current_length;
            longest_name = head->name;
        }
        head = head->next;
    }

    printf("The longest name in the list: %s\n", longest_name);
    printf("Length: %d\n", max_length);
}
