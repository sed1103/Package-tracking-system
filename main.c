#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

/**
 * @file Main.c
 * @brief Main file for the package tracking program.
 */

int main() {
    char trackingNumber[20];
    char currentLocation[50];
    char estimatedArrivalTime[20];
    char destinationAddress[50];
    char action[10];

    // Main loop
    while (1) {
        printf("Enter action (add, display, update, exit): ");
        scanf("%s", action);

        if (strcmp(action, "add") == 0) {
            printf("Enter tracking number: ");
            scanf("%s", trackingNumber);
            printf("Enter current location: ");
            scanf("%s", currentLocation);
            printf("Enter estimated arrival time: ");
            scanf("%s", estimatedArrivalTime);
            printf("Enter destination address: ");
            scanf("%s", destinationAddress);
            addPackage(trackingNumber, currentLocation, estimatedArrivalTime, destinationAddress);
        } else if (strcmp(action, "display") == 0) {
            displayPackages();
        } else if (strcmp(action, "update") == 0) {
            printf("Enter tracking number to update: ");
            scanf("%s", trackingNumber);
            updatePackage(trackingNumber);
        } else if (strcmp(action, "exit") == 0) {
            // Save packages to a file before exiting
            saveToFile("packages.txt");
            freeMemory();
            break;  // Exit the loop
        } else {
            printf("Invalid action. Please try again.\n");
        }
    }

    return 0;
}
