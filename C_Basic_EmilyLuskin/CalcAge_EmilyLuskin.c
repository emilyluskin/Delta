/*------------------------------------------------------
* Filename: CalcAge_EmilyLuskin.c
* Description: A program that calculates age in days, months, and years
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
#define DAYS_IN_MONTH 30
#define DAYS_IN_YEAR 365

int calculate_total_days(int day, int month, int year){
    return day + month * DAYS_IN_MONTH + year * DAYS_IN_YEAR;
}

int main(){
    int current_day, current_month, current_year;
    int birth_day, birth_month, birth_year;
    int current_days, birth_days, age_days;
    double days_to_months, days_to_years;

    printf("Enter current date (dd mm yyyy): ");
    scanf("%d %d %d", &current_day, &current_month, &current_year);
    printf("Enter your birth date (dd mm yyyy): ");

    scanf("%d %d %d", &birth_day, &birth_month, &birth_year);
    current_days = calculate_total_days(current_day, current_month, current_year);
    birth_days = calculate_total_days(birth_day, birth_month, birth_year);
    age_days = current_days - birth_days;
    days_to_months = (double)age_days / DAYS_IN_MONTH;
    days_to_years = (double)age_days / DAYS_IN_YEAR;

    printf("your Age in days: %d\n", age_days);
    printf("your Age in months: %f\n", days_to_months);
    printf("your Age in years: %f\n", days_to_years);
    return 0;
}