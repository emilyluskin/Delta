/*------------------------------------------------------
* Filename: DynamicAllocation_EmilyLuskin.c
* Description: The program sums the hours, minutes and seconds of 2 times.
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int hours;
    int minutes;
    int seconds;
} Time;

Time* sum_times(const Time* time1 ,const Time* time2);
/*------------------------------------------------------
* Function Name - sum_times
*
* Function Purpose - Sums the hours, minutes and seconds of 2 times.
*
* Parameters –  [IN time1 - a pointer to Time, IN time2 - a pointer to Time ]
*
* Return Values - Time*
*
* Author - Emily Luskin
-------------------------------------------------------*/
Time* sum_times(const Time* time1 ,const Time* time2){
    Time *sum_time;
    sum_time = (Time*) malloc(sizeof(Time));
    if (sum_time == NULL){
        exit(1);
    }

    sum_time->hours   = time1->hours   + time2->hours;
    sum_time->minutes = time1->minutes + time2->minutes;
    sum_time->seconds = time1->seconds + time2->seconds;

    if(sum_time->seconds >= 60){
        sum_time->minutes += sum_time->seconds / 60;
        sum_time->seconds %= 60;
    }

    if(sum_time->minutes >= 60){
        sum_time->hours += sum_time->minutes / 60;
        sum_time->minutes %= 60;
    }

    sum_time->hours %= 24;

    return sum_time;
}

int main(){
    Time *time1 = NULL, *time2 = NULL, *sum = NULL;

    time1 = (Time*) malloc(sizeof(Time));
    if(time1 == NULL){
        return 1;
    }

    printf("Number 1:\n");
    printf("Enter hours: ");
    scanf("%d", &time1->hours);
    printf("Enter minutes: ");
    scanf("%d", &time1->minutes);
    printf("Enter seconds: ");  
    scanf("%d", &time1->seconds);

    time2 = (Time*) malloc(sizeof(Time));
    if(time2 == NULL){
        return 1;
    }

    printf("Number 2:\n");
    printf("Enter hours: ");
    scanf("%d", &time2->hours);
    printf("Enter minutes: ");
    scanf("%d", &time2->minutes);
    printf("Enter seconds: ");  
    scanf("%d", &time2->seconds);

    sum = sum_times(time1, time2);

    printf("The sum of the times is: %d hours, %d minutes, %d seconds\n",
           sum->hours, sum->minutes, sum->seconds);

    // free memory
    free(time1);
    free(time2);
    free(sum);

    return 0;
}
