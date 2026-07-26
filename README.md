# Grade Tracker

Command-line grade tracker written in C for Windows. Served as an introduction into numerical arrays, sorting, and pointers.

## How to Use

The program will launch into a command-line menu with 5 selectable options. You can select an option by entering the corresponding number then enter.

1. Add a Grade

   Prompts you to enter a grade ranging from 0 to 100.

2. View Grades

   Displays a list of all the stored grades and allows you to delete a grade. To delete a grade enter its corresponding number.

3. Calculate Grades

   Displays the average of all the stored grades, and gives you a corresponding letter based on the percentage.

4. Calculate High/Low

   Calculates the highest and lowest grades that have been entered and outputs them to console.

5. Quit

   Exits the program.

## Notes

Despite the increase in complexity compared to my first project, this one utilized a lot of similar concepts and went much smoother. That is not to say everything went smooth as I introduced my first usage of functions, loops, arrays, pointers, and switch statements.

### Sorting

In my first project `scanf()` haunted me. Well in this one the idea of sorting an array puzzled my brain. This led me to learn about a sorting algorithm pretty much no one uses, but is easy to implement. Bubble sort iterates through the array multiple times using a nested for loop. The outer loop controls the total iterations, while the inner is the process of comparing each index to the index that comes after it. If the first index is greater than the next we would call a swap function that would move the greater number to the right before iterating. This sorting algorithm does have a simple optimization that's easy to implement that involves saving whether or not you swapped a number in an outer loop iteration. If you didn't you could end the algorithm early as that means the array is already sorted.

### Delay

This was completely unnecessary to learn about, but still an interesting experience. C doesn't really have a default uniform way of handling delays. Linux and Windows both have ways to use sleep, but I didn't want the same reliance my last project had which was `<Windows.h>`. The solution is surprisingly simple. All you need to do is take a counter that increments with time and save it to a variable then use a while loop that runs until the current time is greater than the stored time + whatever delay you want. Obviously the big thing here is to standardize everything into the same unit of time. `<time.h>` has a function I used in my first project `clock()`. Now this function usually returns milliseconds; however, this is based on `CLOCKS_PER_SEC`. Basically to ensure it's always in milliseconds you just multiply it by 1000 then divide by `CLOCKS_PER_SEC`, and this order is important because you can truncate the number if it's too small. One last thing, this while loop is not efficient as operating systems can just sleep the process if they use their related functions which does not actively consume the CPU.

## Building

Built and tested using GCC. Might work outside of Windows, but `system("cls")` will possibly spam your console log.

```powershell
gcc main.c -o main.exe
.\main.exe
```
