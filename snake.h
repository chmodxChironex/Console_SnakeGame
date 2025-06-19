/**
 * @file snake.h
 * @brief Core snake game structures and function declarations
 * @author chmodxChironex
 * @date 2024
 */

#ifndef SNAKE_H
#define SNAKE_H

#include "point.h"
#include "obstacles.h"

extern int WIDTH;
extern int HEIGHT;

/**
 * @struct Snake
 * @brief Main snake game state structure
 * 
 * @var Snake::body
 * Array of points representing snake segments
 * @var Snake::length
 * Current length of the snake
 * @var Snake::food
 * Current position of the food item
 * @var Snake::speed
 * Game speed (lower value = faster)
 * @var Snake::direction
 * Current movement direction ('w', 'a', 's', 'd')
 */
typedef struct {
    Point body[100];
    int length;
    Point food;
    int speed;
    char direction;
} Snake;

/**
 * @brief Clears the terminal screen
 */
void clear_screen();

/**
 * @brief Renders the game field, snake, food and obstacles
 * 
 * @param snake Pointer to the snake structure
 * @param obstacles Pointer to the obstacles structure
 */
void draw(const Snake* snake, const Obstacles* obstacles);

/**
 * @brief Initializes the game state
 * 
 * @param snake Pointer to snake structure to initialize
 * 
 * @details Sets initial snake position, length, direction, speed and generates food
 */
void initialize_game(Snake* snake);

/**
 * @brief Updates game state for one frame
 * 
 * @param snake Pointer to snake structure
 * @param game_over Pointer to game over flag
 * @param obstacles Pointer to obstacles structure
 * 
 * @details Handles input, moves snake, checks collisions, manages food consumption
 */
void update_game(Snake* snake, int* game_over, const Obstacles* obstacles);

/**
 * @brief Generates new food at random valid position
 * 
 * @param snake Pointer to snake structure
 */
void generate_food(Snake* snake);

/**
 * @brief Enables raw terminal mode for immediate input
 */
void enable_raw_mode();

/**
 * @brief Restores normal terminal mode
 */
void disable_raw_mode();

/**
 * @brief Checks if a key has been pressed
 * 
 * @return 1 if key pressed, 0 otherwise
 */
int kbhit();

#endif