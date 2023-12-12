#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
const int ROW_SIZE = 27;
int ROW_COUNT = 0;
char filename[25];
FILE *file;

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
int main() {
   while (1 > 0)
   {
        char record[ROW_SIZE];
        FITNESS_DATA data[59];
        char input;
        printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\nEnter choice: ");
        scanf(" %c", &input);
        if (input = 81)
        {
            input = 71;
        }

        switch (input - 64)
        {
            case 1:
            {
                printf("Input filename: ");
                scanf("%s", filename);

                file = fopen(filename, "r");
                if (file != NULL)
                {
                    break;
                }
                else
                {
                    printf("Error: Could not find or open the file.");
                }
            }
            case 2:
            {
                char record[ROW_SIZE];
                while(fgets(record, ROW_SIZE, file) != NULL)
                {
                    ROW_COUNT++;
                }
                printf("Total records: %d\n", ROW_COUNT);
                break;
            }
            case 3:
            {
                int counter = 0;
                char steps[10];
                while(fgets(record, ROW_SIZE, file) != NULL)
                {
                    tokeniseRecord(record, ",", data[counter].date, data[counter].time, steps);
                    data[counter].steps = atoi(steps);
                    counter++;
                }

                int low = 100;
                for(int i = 0; i<59; i++)
                {
                    if (data[i].steps < low)
                    {
                        low = data[i].steps;
                    }
                }
                
                for(int j = 0; j<59; j++)
                {
                    if (data[j].steps == low)
                    {
                        printf("%s/%s\n", data[j].date, data[j].time);
                    }
                }
                break;
            }
            case 4:
            {
                int counter = 0;
                char steps[10];
                while(fgets(record, ROW_SIZE, file) != NULL)
                {
                    tokeniseRecord(record, ",", data[counter].date, data[counter].time, steps);
                    data[counter].steps = atoi(steps);
                    counter++;
                }

                int high = 0;
                for(int i = 0; i<59; i++)
                {
                    if (data[i].steps > high)
                    {
                        high = data[i].steps;
                    }
                }
                
                for(int j = 0; j<59; j++)
                {
                    if (data[j].steps == high)
                    {
                        printf("%s/%s\n", data[j].date, data[j].time);
                    }
                }
                break;
            }
            case 5:
            {
                int counter = 0;
                char steps[10];
                while(fgets(record, ROW_SIZE, file) != NULL)
                {
                    tokeniseRecord(record, ",", data[counter].date, data[counter].time, steps);
                    data[counter].steps = atoi(steps);
                    counter++;
                }
                int total = 0;
                float mean = 0;
                for(int i = 0; i<59; i++)
                {
                    total = data[i].steps + total;
                }
                mean = total / counter;
                printf("%f\n", mean);
                break;
            }
            case 6:
            {
                int counter = 0;
                char steps[10];
                while(fgets(record, ROW_SIZE, file) != NULL)
                {
                    tokeniseRecord(record, ",", data[counter].date, data[counter].time, steps);
                    data[counter].steps = atoi(steps);
                    counter++;
                }
                int high = 0;
                int count = 1;
                for(int i=0; i<58; i++)
                {
                    if (data[i].steps > 500)
                    {
                        for(int j=i+1; j<59; j++)
                        {
                            if (data[j].steps > 500)
                            {
                                count++;
                            }
                            else
                            {
                                if (count > high)
                                {
                                    high = count;
                                }
                                count = 1;
                                break;
                            }
                        }
                    }
                }
                printf("%i\n", high);
                break;
            }
            case 7:
            {
                return 0;
            }
        }
   }
}