/**
 * @file score.h
 * @brief Score management system for the snake game
 * @author chmodxChironex
 * @date 2024
 */

#ifndef SCORE_H
#define SCORE_H

/**
 * @brief Saves a player's score to the high score file
 *
 * @param name Player's name
 * @param score Player's achieved score
 *
 * @details Scores are automatically sorted in descending order
 *          and stored in "scores.txt"
 */
void save_score(const char* name, int score);

/**
 * @brief Displays all saved high scores
 *
 * @details Reads and prints scores from "scores.txt" in descending order.
 *          If no scores exist, displays appropriate message.
 */
void load_scores();

#endif