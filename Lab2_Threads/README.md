# Console Process with Multiple Threads

This project aims to create a console program consisting of three threads: `main`, `min_max`, and `average`. The program performs various operations on an array of integers provided by the user.

## Functionality

The `main` thread performs the following actions:

1. Create an integer array by taking input for the size and elements from the console.
2. Create the `min_max` and `average` threads.
3. Wait for the `min_max` and `average` threads to finish.
4. Replace the maximum and minimum elements in the array with the average value of all elements.
5. Display the modified array on the console.
6. Terminate the program.

The `min_max` thread performs the following actions:

1. Find and display the minimum and maximum elements of the array on the console. After each element comparison, sleep for 7 milliseconds.
2. Terminate its execution.

The `average` thread performs the following actions:

1. Calculate and display the average value of the elements in the array on the console. After each summing operation, sleep for 12 milliseconds.
2. Terminate its execution.

## Usage

To use the program, follow these steps:

1. Run the program.
2. Enter the size and elements of the integer array when prompted.
3. Wait for the program to display the modified array with the replaced minimum and maximum elements.

## Notes

- The program utilizes multiple threads to perform concurrent operations on the array.
- Sleeping intervals are added to simulate delays and allow better observation of the thread synchronization.
- The program demonstrates a simple example of using threads in a console application.

 ## Contributors
- [Zavadsky Kirill](https://github.com/Kiriller102)
