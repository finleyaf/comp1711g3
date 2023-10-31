#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
const int ROW_SIZE = 27;
int ROW_COUNT = 0;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main()
{
    // Declare array of chars to store a row from the csv file.
    char record[ROW_SIZE];

    // Declare a file pointer and open the csv file in read mode. Also check for error / NULL.
    FILE *file = fopen("FitnessData_2023.csv", "r");
    if (file != NULL)
    {
        // Loop through the file, counting the number of rows before reaching NULL and storing the number in ROW_COUNT.
        while(fgets(record, ROW_SIZE, file) != NULL)
        {
            ROW_COUNT++;
        }
        // Print the number of records to the console.
        printf("Number of records in file: %d\n", ROW_COUNT);

        // Rewind the file to to prepare for a second loop from the start.
        rewind(file);

        // Declare a struct of type FITNESS_DATA to store the data from the csv.
        FITNESS_DATA data[ROW_COUNT];
        char steps[10];
        int counter = 0;

        // Loop through the file and call the tokeniseRecord function on each iteration to split the data. Also convert the steps from a string to an integer.
        while(fgets(record, ROW_SIZE, file) != NULL)
        {
            tokeniseRecord(record, ",", data[counter].date, data[counter].time, steps);
            data[counter].steps = atoi(steps);
            counter++;
        }
        // Close the file.
        fclose(file);

        // Loop through the first three records in the data struct and print to the console.
        for (int i=0; i<3; i++)
        {
            printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
        }
        // Exit the program.
        return 0;        
    }
    // If the file returns NULL, print an error to the console and quit the program.
    else
    {
        printf("failed");
        return 1;
    }
}