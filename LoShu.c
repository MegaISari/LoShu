#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int gridSize = 3;

int checkingRows(const int[][gridSize]);
int checkingColumns(const int[][gridSize]);
int checkingDiagonals(const int[][gridSize]);
int checkingLoshu(const int[][gridSize]);
void printArray(const int[][gridSize]);
void shuffle(int *array, int n);

int main () {
    int array[][3] = {{4, 9, 2}, 
                    {3, 5, 7}, 
                    {8, 1, 6}};
    printArray(array); //working
 
    if(checkingRows(array)== 1 && checkingColumns(array) == 1 && checkingDiagonals(array)==1)
        printf("This is a Lo Shu square.\n");
    else   
        printf("This is not a Lo Shu square.\n");

    int array1[][3] = {{5, 4, 2}, 
                    {6, 9, 7}, 
                    {8, 1, 3}};
    printArray(array1); //not working

    if(checkingRows(array1)== 1 && checkingColumns(array1) == 1 && checkingDiagonals(array1)==1)
        printf("This is a Lo Shu square.\n");
    else   
        printf("This is not a Lo Shu square.\n");

    //generating random numbers 
    time_t t;
    srand((unsigned) time(&t));
    int randomCounter = 0; 
    int array2[3][3];
    int arrayRandom[9] = {1,2,3,4,5,6,7,8,9};
    do {
        shuffle(arrayRandom, 9);
        array2[0][0] = arrayRandom[0];
        array2[0][1] = arrayRandom[1];
        array2[0][2] = arrayRandom[2];

        array2[1][0] = arrayRandom[3];
        array2[1][1] = arrayRandom[4];
        array2[1][2] = arrayRandom[5];

        array2[2][0] = arrayRandom[6];
        array2[2][1] = arrayRandom[7];
        array2[2][2] = arrayRandom[8];

        randomCounter++;
        printf("\nTries: %d", randomCounter);
    } while(!(checkingRows(array2) == 1 && checkingColumns(array2) == 1 && checkingDiagonals(array2)==1));

    printArray(array2);
    printf("This took %d tries.", randomCounter);
}

void shuffle(int *array, int n)
{
    srand((unsigned) time(NULL));
    for(int i=0; i< n-1; i++)
    {
        size_t j=i + rand() / (RAND_MAX / (n-i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

int checkingRows(const int numbers[][gridSize])
{
    int sum[3];
    for (int i = 0; i < gridSize; i++){
        sum[i] = numbers[i][0] + numbers[i][1] + numbers[i][2];
    }

    if (sum[0] == sum[1] && sum[1] == sum[2] && sum[0] == 15)
        return 1;
    else
        return 0;
}

int checkingColumns(const int numbers[][gridSize])
{
    int sum[3];
    for (int i = 0; i < gridSize; i++){
        sum[i] = numbers[0][i] + numbers[1][i] + numbers[2][i];
    }

    if (sum[0] == sum[1] && sum[1] == sum[2] && sum[0] == 15)
        return 1;
    else
        return 0;
}

int checkingDiagonals(const int numbers[][gridSize])
{
    int sum1 = numbers[0][0] + numbers[1][1] + numbers[2][2];
    int sum2 = numbers[2][0] + numbers[1][1] + numbers[0][2];

    if (sum1 == sum2 && sum1 == 15)
        return 1;
    else
        return 0;
}

void printArray(const int arr[][gridSize])
{
    int i, j;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}