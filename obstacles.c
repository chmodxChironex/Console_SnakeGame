/**
 * @file obstacles.c
 * @brief Implementation of obstacle loading functionality
 * @author chmodxChironex
 * @date 2024
 */

#include "point.h"
#include <stdio.h>
#include "obstacles.h"

/**
 * @brief Loads obstacles from a file
 *
 * @param filename Path to the file containing obstacle coordinates
 * @param obstacles Pointer to Obstacles structure to populate
 *
 * @details Reads pairs of integers from the file, validates boundaries,
 *          and stores valid obstacle positions. Invalid positions are ignored.
 */
void load_obstacles(const char* filename, Obstacles* obstacles) {
    FILE* file = fopen(filename, "r");
    if (file) {
        obstacles->count = 0;
        int x, y;

        while (fscanf(file, "%d %d", &x, &y) != EOF) {
            if (x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1) {
                obstacles->obstacles[obstacles->count].x = x;
                obstacles->obstacles[obstacles->count].y = y;
                obstacles->count++;
            }
        }
        fclose(file);
    }
}