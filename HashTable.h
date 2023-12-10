#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"

/**
 * @file HashTable.h
 * @brief Definition of the hash table functions.
 */

/**
 * @brief Adds a new package to the hash table.
 * @param trackingNumber Tracking number of the package.
 * @param currentLocation Current location of the package.
 * @param estimatedArrivalTime Estimated arrival time of the package.
 * @param destinationAddress Destination address of the package.
 */
void addPackage(char* trackingNumber, char* currentLocation, char* estimatedArrivalTime, char* destinationAddress);

/**
 * @brief Displays information about a specific package.
 * @param trackingNumber Tracking number of the package to display.
 */
void displayPackage(char* trackingNumber);

/**
 * @brief Updates information about a specific package.
 * @param trackingNumber Tracking number of the package to update.
 */
void updatePackage(char* trackingNumber);

/**
 * @brief Displays information about all packages in the hash table.
 */
void displayPackages();

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
void saveToFile(char* filename);

/**
 * @brief Frees the memory allocated for the hash table.
 */
void freeMemory();

#endif // HASHTABLE_H
