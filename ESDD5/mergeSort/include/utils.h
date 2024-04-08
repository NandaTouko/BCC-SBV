/**
 * @file utils.h
 * @author Prof. Dr. David Buzatto
 * @brief Utilitary functions and constants declarations.
 *
 * @copyright Copyright (c) 2024
 */
#pragma once

double toRadians(double degrees);
double toDegrees(double radians);
void topDown(int array[], int inicio, int fim, int arrayCopia[], int tamanho);
void merge(int array[], int inicio, int meio, int fim, int arrayCopia[]);
void printArray(int array[], int tamanho);