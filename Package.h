#ifndef PACKAGE_H
#define PACKAGE_H

/**
 * @file Package.h
 * @brief Definition of the Package structure.
 */

/**
 * @struct Package
 * @brief Represents information about a package.
 */
typedef struct {
    char trackingNumber[20]; /**< Tracking number of the package. */
    char currentLocation[50]; /**< Current location of the package. */
    char estimatedArrivalTime[20]; /**< Estimated arrival time of the package. */
    char destinationAddress[50]; /**< Destination address of the package. */
} Package;

#endif // PACKAGE_H
