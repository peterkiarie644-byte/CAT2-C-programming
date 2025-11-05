#include <stdio.h>

// Function to calculate and print the pay details
void calculate_pay() {
    // Variable declarations (using double for financial accuracy)
    double hours_worked, hourly_wage, gross_pay, taxes, net_pay;
    
    // Constants defined as per the problem
    const int STANDARD_HOURS = 40;
    const double OVERTIME_RATE_MULTIPLIER = 1.5;
    const double TAX_RATE_LOWER = 0.15; // 15%
    const double TAX_RATE_UPPER = 0.20; // 20%
    const double TAX_BREAKPOINT = 600.00;

    // 1. Request user input
    printf("Enter hours worked in a week: ");
    if (scanf("%lf", &hours_worked) != 1) {
        printf("Invalid input. Please enter a numerical value.\n");
        return;
    }
    
    printf("Enter the hourly wage: ");
    if (scanf("%lf", &hourly_wage) != 1) {
        printf("Invalid input. Please enter a numerical value.\n");
        return;
    }

    // 2. Calculate Gross Pay
    if (hours_worked <= STANDARD_HOURS) {
        // Standard pay
        gross_pay = hours_worked * hourly_wage;
    } else {
        // Overtime pay (time and a half)
        double standard_pay = STANDARD_HOURS * hourly_wage;
        double overtime_hours = hours_worked - STANDARD_HOURS;
        double overtime_pay = overtime_hours * hourly_wage * OVERTIME_RATE_MULTIPLIER;
        gross_pay = standard_pay + overtime_pay;
    }

    // 3. Calculate Taxes
    if (gross_pay <= TAX_BREAKPOINT) {
        // 15% of the first $600 (which is the whole amount here)
        taxes = gross_pay * TAX_RATE_LOWER;
    } else {
        // 15% of the first $600 PLUS 20% of the rest
        double tax_on_first_600 = TAX_BREAKPOINT * TAX_RATE_LOWER;
        double remaining_income = gross_pay - TAX_BREAKPOINT;
        double tax_on_rest = remaining_income * TAX_RATE_UPPER;
        taxes = tax_on_first_600 + tax_on_rest;
    }

    // 4. Calculate Net Pay
    net_pay = gross_pay - taxes;

    // 5. Print the results (%.2lf ensures two decimal places for currency)
    printf("\n--- Payroll Summary ---\n");
    printf("Gross Pay: $%.2lf\n", gross_pay);
    printf("Taxes:     $%.2lf\n", taxes);
    printf("Net Pay:   $%.2lf\n", net_pay);
    printf("-----------------------\n");
}

// Main function where program execution begins
int main() {
    calculate_pay();
    return 0;
}
