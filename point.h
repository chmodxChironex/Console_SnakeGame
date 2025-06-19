/**
 * @file point.h
 * @brief Point structure definition for 2D coordinates
 * @author chmodxChironex
 * @date 2024
 */

#ifndef POINT_H
#define POINT_H

/**
 * @struct Point
 * @brief Represents a 2D point with integer coordinates
 *
 * @var Point::x
 * X-coordinate of the point
 * @var Point::y
 * Y-coordinate of the point
 */
typedef struct {
    int x, y;
} Point;

#endif