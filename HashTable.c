#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

Node* hashTable[TABLE_SIZE];

/**
 * @brief Calculates the hash value for a given key.
 * @param key Key to calculate the hash value.
 * @return Hash value.
 */
int hash(char* key) {
    int hashValue = 0;
    for (int i = 0; i < strlen(key); i++) {
        hashValue += key[i];
    }
    return hashValue % TABLE_SIZE;
}

/**
 * @brief Adds a new package to the hash table.
 * @param trackingNumber Tracking number of the package.
 * @param currentLocation Current location of the package.
 * @param estimatedArrivalTime Estimated arrival time of the package.
 * @param destinationAddress Destination address of the package.
 */
void addPackage(char* trackingNumber, char* currentLocation, char* estimatedArrivalTime, char* destinationAddress) {
    int index = hash(trackingNumber);

    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->package.trackingNumber, trackingNumber);
    strcpy(newNode->package.currentLocation, currentLocation);
    strcpy(newNode->package.estimatedArrivalTime, estimatedArrivalTime);
    strcpy(newNode->package.destinationAddress, destinationAddress);
    newNode->next = NULL;

    // Insert the node into the hash table
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

/**
 * @brief Displays information about a specific package.
 * @param trackingNumber Tracking number of the package to display.
 */
void displayPackage(char* trackingNumber) {
    int index = hash(trackingNumber);

    // Search for the package with the given tracking number
    Node* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->package.trackingNumber, trackingNumber) == 0) {
            // Package found, display its information
            printf("Tracking Number: %s\n", current->package.trackingNumber);
            printf("Current Location: %s\n", current->package.currentLocation);
            printf("Estimated Arrival Time: %s\n", current->package.estimatedArrivalTime);
            printf("Destination Address: %s\n", current->package.destinationAddress);
            return;
        }
        current = current->next;
    }

    // If the loop completes, the package was not found
    printf("Package with tracking number %s not found.\n", trackingNumber);
}

/**
 * @brief Updates information about a specific package.
 * @param trackingNumber Tracking number of the package to update.
 */
void updatePackage(char* trackingNumber) {
    int index = hash(trackingNumber);

    // Search for the package with the given tracking number
    Node* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->package.trackingNumber, trackingNumber) == 0) {
            // Package found, prompt user for update information
            printf("Enter new current location for tracking number %s: ", trackingNumber);
            scanf("%s", current->package.currentLocation);
            printf("Enter new estimated arrival time for tracking number %s: ", trackingNumber);
            scanf("%s", current->package.estimatedArrivalTime);
            printf("Enter new destination address for tracking number %s: ", trackingNumber);
            scanf("%s", current->package.destinationAddress);
            printf("Information updated successfully.\n");
            return;
        }
        current = current->next;
    }

    // If the loop completes, the package was not found
    printf("Package with tracking number %s not found.\n", trackingNumber);
}

/**
 * @brief Displays information about all packages in the hash table.
 */
void displayPackages() {
    char trackingNumber[20];

    printf("Enter tracking number to display (or type 'all' to display all packages): ");
    scanf("%s", trackingNumber);

    if (strcmp(trackingNumber, "all") == 0) {
        // Display all packages
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* current = hashTable[i];
            while (current != NULL) {
                printf("Tracking Number: %s\n", current->package.trackingNumber);
                printf("Current Location: %s\n", current->package.currentLocation);
                printf("Estimated Arrival Time: %s\n", current->package.estimatedArrivalTime);
                printf("Destination Address: %s\n", current->package.destinationAddress);
                printf("\n");
                current = current->next;
            }
        }
    } else {
        // Display a specific package
        displayPackage(trackingNumber);
    }
}

/**
 * @file HashTable.h
 * @brief Definition of the hash table functions.
 */

// ... (previous contents of HashTable.h)

/**
 * @brief Saves the packages to a file.
 *
 * This function saves the information about each package in the hash table to a specified file.
 *
 * @param filename The name of the file to which packages will be saved.
 *
 * @note The file will be opened in write mode ("w"). If the file does not exist, it will be created.
 *
 * @warning If the file cannot be opened for writing, an error message will be printed, and the function will return without saving.
 *
 * The package information will be saved in CSV (Comma-Separated Values) format, with each line representing a package and fields separated by commas.
 * The order of fields is as follows:
 * - Tracking Number
 * - Current Location
 * - Estimated Arrival Time
 * - Destination Address
 *
 * Example CSV format:
 * ```
 * ABC123,Storage,2023-01-01,123 Main St
 * XYZ789,In Transit,2023-01-05,456 Oak Ave
 * ```
 *
 * @warning If a package has special characters, the CSV format may need to be adjusted to accommodate those characters.
 *
 * Example Usage:
 * ```c
 * saveToFile("package_data.csv");
 * ```
 *
 * @see Node
 * @see hashTable
 */
void saveToFile(char* filename) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Save each package to the file
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            fprintf(file, "%s,%s,%s,%s\n", current->package.trackingNumber,
                    current->package.currentLocation, current->package.estimatedArrivalTime,
                    current->package.destinationAddress);
            current = current->next;
        }
    }

    fclose(file);
    printf("Packages saved to %s successfully.\n", filename);
}


/**
 * @brief Frees the memory allocated for the hash table.
 */
void freeMemory() {
    // Free memory (not implemented in this simple example)
    // You should free each node and its package
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
        hashTable[i] = NULL;
    }
}
