/*
 * randomgenerator.c
 *
 *  Created on: Aug 28, 2013
 *      Author: Nathan Lane
 *       Class: CSIS-2430
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "randomgenerator.h"

/**
 * Generates a list of maxValue possible values (minValue..maxValue).
 */
int * generateListOfPossibleValues(const unsigned int minValue, const unsigned int maxValue)
{
  static int * controlArray;
  int index;
  size_t size;
  
  size = (maxValue - minValue + 1);
  
  controlArray = calloc(size, sizeof(int));

  for (index = 0; index < size; index++)
  {
    controlArray[index] = (index);
  }

  return controlArray;
}

/**
 * Shuffles a list of possible values.
 */
int * shufflePossibleValues(int * possibleValues, const int maxValue, const size_t numValues)
{
  int index;
  int nextRand;
  int swapValue;

  srand(time(NULL));

  for (index = 0; index < numValues; index++)
  {
    nextRand = rand() % maxValue;

    swapValue = possibleValues[index];

    possibleValues[index] = possibleValues[nextRand];
    possibleValues[nextRand] = swapValue;
  }

  return possibleValues;
}

/**
 * Generates a random list of numbers - exposed by randomgenerator.h.
 */ 
int * generateRandomArray(const size_t arraySize, const unsigned int minValue, const unsigned int maxValue)
{
  static int * array;
  int * shuffledValues = shufflePossibleValues(generateListOfPossibleValues(minValue, maxValue), maxValue, arraySize);
  int index;

  array = calloc(arraySize, sizeof(int));

  for (index = 0; index < arraySize; index++)
  {
    array[index] = shuffledValues[index];
  }
  
  free(shuffledValues);

  return array;
}
