#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to convert feet and inches to total inches
int heightToInches(int feet, int inches) {
    return (feet * 12) + inches;
}

// Function to calculate the shadow length based on height and time of day
double calculateShadowLength(int heightInInches, double sunAngle) {
    // Shadow length formula using trigonometry (tan(theta) = opposite / adjacent)
    return heightInInches / tan(sunAngle);
}

// Function to convert 12-hour time format to sun angle (simplified approximation)
double timeToSunAngle(int hour, char period[]) {
    // Convert 12-hour format to 24-hour format
    if (strcmp(period, "PM") == 0 && hour != 12) {
        hour += 12;  // Convert PM hours to 24-hour format
    } else if (strcmp(period, "AM") == 0 && hour == 12) {
        hour = 0;  // Midnight case
    }

    // Calculate hours from noon (12:00 PM)
    int hoursFromNoon = abs(12 - hour);
    double sunAngleInDegrees = 90.0 - (hoursFromNoon * 15);

    // Convert degrees to radians for trigonometric calculations
    return sunAngleInDegrees * (M_PI / 180.0);
}

int main() {
    int feet, inches, hour;
    double sunAngle, shadowLength;
    char period[3];  // "AM" or "PM"

    // Get the user's height in feet and inches
    printf("Enter your height:\nFeet: ");
    scanf("%d", &feet);
    printf("Inches: ");
    scanf("%d", &inches);

    // Get the time of day (in 12-hour format with AM/PM)
    printf("Enter the time of day (hour in 12-hour format): ");
    scanf("%d", &hour);
    printf("Enter AM or PM: ");
    scanf("%s", period);

    // Convert height to inches
    int heightInInches = heightToInches(feet, inches);

    // Convert time to sun angle
    sunAngle = timeToSunAngle(hour, period);

    // Calculate shadow length
    if (sunAngle > 0) {
        shadowLength = calculateShadowLength(heightInInches, sunAngle);
        printf("The length of your shadow is approximately %.2f inches.\n", shadowLength);
    } else {
        printf("It's night, there is no shadow.\n");
    }

    return 0;
}
