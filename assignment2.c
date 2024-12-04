#include <stdio.h>
#include <math.h>

// Function prototypes
int determineMaxItems(int maximumLimit);
double determineNumericalGrade();
char outputProcessGrade(double calculatedGrade);
void sendEmails(int daysLeft, int hoursLeft);

int main(int argc, char **argv) {
    int budget;
    printf("Enter your maximum spending limit: ");
    scanf("%d", &budget);
    determineMaxItems(budget);

    double average = determineNumericalGrade();
    outputProcessGrade(average);

    int days, hours;
    printf("Enter days and hours remaining (format: days hours): ");
    scanf("%d %d", &days, &hours);
    sendEmails(days, hours);

    return 0;
}

// Function to determine maximum items a user can afford
int determineMaxItems(int maximumLimit) {
    int cost = 0, items = 0;

    for (int i = 1; cost <= maximumLimit; i++) {
        int itemCost = 2 + (i - 1); // Base cost
        if (i % 3 == 0) {
            itemCost = (itemCost * 34) / 100; // Apply 66% coupon
        }
        if (cost + itemCost > maximumLimit) {
            break;
        }
        cost += itemCost;
        items++;
    }

    printf("I can only afford %d items.\n", items);
    return items <= 5 ? 1 : 5; // Return difficulty rating
}

// Function to calculate weighted numerical grade
double determineNumericalGrade() {
    int grades[8];
    double weights[] = {0.1, 0.1, 0.1, 0.2, 0.2, 0.05, 0.05, 0.2};
    double weightedAverage = 0;

    printf("Enter 8 grades out of 100 (one per line):\n");
    for (int i = 0; i < 8; i++) {
        scanf("%d", &grades[i]);
        weightedAverage += grades[i] * weights[i];
    }

    printf("The weighted average based on the entered values is %.2f\n", weightedAverage);
    return weightedAverage;
}

// Function to output process grade
char outputProcessGrade(double calculatedGrade) {
    char letterGrade;

    if (calculatedGrade >= 90) {
        letterGrade = 'A';
    } else if (calculatedGrade >= 80) {
        letterGrade = 'B';
    } else if (calculatedGrade >= 70) {
        letterGrade = 'C';
    } else if (calculatedGrade >= 60) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }

    printf("Your grade based on %.2f will be %c\n", calculatedGrade, letterGrade);
    return letterGrade;
}

// Function to send emails based on remaining time
void sendEmails(int daysLeft, int hoursLeft) {
    int totalHours = (daysLeft * 24) + hoursLeft;

    if (totalHours > 24) {
        printf("Sent an email with %d hours remaining.\n", totalHours);
    }
}
