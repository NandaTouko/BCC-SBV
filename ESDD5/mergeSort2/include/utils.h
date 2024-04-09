/**
 * @file utils.h
 * @author Prof. Dr. David Buzatto
 * @brief Utilitary functions and constants declarations.
 *
 * @copyright Copyright (c) 2024
 */
#pragma once

#include "GameWorld.h"

double toRadians(double degrees);
double toDegrees(double radians);
void topDown(int inicio, int fim, GameWorld* gw);
void merge(int inicio, int meio, int fim, GameWorld* gw);
void printArray(int array[], int tamanho);