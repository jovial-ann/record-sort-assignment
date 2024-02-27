#include <stdio.h>
#include <stdbool.h> // Include standard boolean library to use bool for flags

// Define a struct named Person with three fields: age, name, and salary
typedef struct
{
    int age;
    char name[50]; // Array of characters for storing names up to 49 characters plus null terminator
    float salary;  // Floating point number for salary
} Person;

// Function to sort an array of Person by their age using bubble sort
void optimizedSortPersonsByAge(Person persons[], int size)
{
    int i;
    bool swapped; // Flag to check if any swapping occurred in the current iteration
    do
    {
        swapped = false; // Initially set to false on each new iteration
        for (i = 1; i < size; i++) // Loop through the array starting from the second element
        {
            // If the current person's age is greater than the next person's age, swap them
            if (persons[i - 1].age > persons[i].age)
            {
                Person temp = persons[i - 1]; // Temporary storage for swapping
                persons[i - 1] = persons[i];
                persons[i] = temp;
                swapped = true; // Set swapped to true as swapping occurred
            }
        }
        size--; // Decrement size to avoid checking the last sorted element in the next iteration
    } while (swapped); // Repeat if any swapping occurred in the last iteration
}

int main()
{
    // Initialize an array of Person with 3 elements
    Person persons[3] = {
        {19, "Venessa", 50000.0},
        {20, "Steve", 50000.0},
        {16, "Jovial", 50000.0},
    };

    int size = sizeof(persons) / sizeof(persons[0]); // Calculate the number of elements in the array

    optimizedSortPersonsByAge(persons, size); // Sort the persons by age

    // Print the sorted array
    printf("Persons sorted by age:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Name: %s, Age: %d, Salary: %.2f\n", persons[i].name, persons[i].age, persons[i].salary);
    }

    return 0;
}
