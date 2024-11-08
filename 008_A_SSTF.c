#include<stdio.h> // is included for standard input and output functions (printf, scanf).
#include<stdlib.h> // is included for the abs function, which calculates the absolute difference.

int main() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial, count = 0;
    
    printf("Enter the number of Disk Requests\n");
    scanf("%d", &n);
    
    printf("Enter the Requests sequence\n");
    for(i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    
    // Logic for SSTF disk scheduling
    /* loop will execute until all process is completed */
    while(count != n) {
        int min = 1000, d, index; // d calculates the distance between the current head position and each request RQ[i]
        
        for(i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
            if(min > d) {
                min = d;
                index = i; // If d is smaller than min, min is updated with d, and index is set to i.
            }
        }
        
        TotalHeadMoment = TotalHeadMoment + min;
        initial = RQ[index];
        
        // 1000 is for max; you can use any number
        RQ[index] = 1000;
        count++;
    }
    
    printf("Total head movement is %d", TotalHeadMoment);
    return 0;
}


/*
Enter the number of Requests
8
Enter the Requests sequence
95 180 34 119 11 123 62 64
Enter initial head position
50
Total head movement is 236
*/