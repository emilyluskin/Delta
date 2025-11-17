/*------------------------------------------------------
* Filename: CalcPrice_EmilyLuskin.c
* Description: The program calculates the price of a package based on its size and weight
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
#define POSTAGE 5.5
#define KG_RATE 11
#define CMR_RATE 0.3

double calculate_size_cmr(int length_mm, int width_mm){
    return (length_mm/10.0) * (width_mm/10.0);
}
double calculate_weight_kg(int weight_gr){
    return weight_gr / 1000.0;
}
double calculate_price(double weight_kg, double size_cmr){
    return POSTAGE + (weight_kg * KG_RATE) + (size_cmr * CMR_RATE) +(0.1 * size_cmr/weight_kg);
}

int main(){
    int weight_gr, length_mm, width_mm;
    double size_cmr, weight_kg, price;
    printf("Enter The length and width of the package in millimeters and weight in grams: ");
    scanf("%d %d %d", &length_mm, &width_mm, &weight_gr);
    weight_kg = calculate_weight_kg(weight_gr);
    size_cmr = calculate_size_cmr(length_mm, width_mm);
    price = calculate_price(weight_kg, size_cmr);

    printf("The size in cm^2 is: %.2f\n", size_cmr);
    printf("The weight in kg is: %.3f\n", weight_kg);
    printf("The price of the package is: %.2f\n", price);
    return 0;
}