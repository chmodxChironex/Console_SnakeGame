/**
 * @file obstacles.h
 * @brief Obstacle management system for the snake game
 * @author chmodxChironex
 * @date 2024
 */

#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "point.h"

extern int WIDTH;
extern int HEIGHT;

/**
 * @struct Obstacles
 * @brief Container for storing game obstacles
 *
 * @var Obstacles::obstacles
 * Array of obstacle positions
 * @var Obstacles::count
 * Number of active obstacles
 */
typedef struct {
    Point obstacles[100];
    int count;
} Obstacles;

/**
 * @brief Loads obstacles from a file
 *
 * @param filename Path to the file containing obstacle coordinates
 * @param obstacles Pointer to Obstacles structure to populate
 *
 * @details File format: Each line contains two integers (x y) representing obstacle position.
 *          Only obstacles within valid game boundaries are loaded.
 */
void load_obstacles(const char* filename, Obstacles* obstacles);

#endif