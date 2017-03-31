/* Program to print all combination of size r in an array of size n
 * on a teensy device emulating a keyboard. This can serve as a very dumb fuzzer for all applications supporting keystrokes
 * or as a very basic bruteforcing tool.
 */
#include <stdio.h>

void setup() {
  // put your setup code here, to run once:

}

void combinationUtil(char arr[], char data[], int start, int end, 
                     int index, int r);
 
// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(char arr[], int n, int r)
{
    // A temporary array to store all combination one by one
    char data[r];
 
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r);
}
 
/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(char arr[], char data[], int start, int end,
                     int index, int r)
{
    // Current combination is ready to be printed, print it
    if (index == r)
    {
        Keyboard.println(data);
        delay(10);//100ms Because computers have a keystroke limit of 500 keystrokes per second => 500/1000 = 0.5 keystroke per milisecond
        return;
    }
 
    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
    char arr[] = "abcedfghij";
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
}
