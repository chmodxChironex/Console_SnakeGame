/**
 * @file score.c
 * @brief Implementation of the score management system
 * @author chmodxChironex
 * @date 2024
 */

#include "score.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct ScoreEntry
 * @brief Structure for storing individual score records
 * 
 * @var ScoreEntry::name
 * Player's name (max 50 characters)
 * @var ScoreEntry::score
 * Player's achieved score
 */
typedef struct {
    char name[50];
    int score;
} ScoreEntry;

/**
 * @brief Comparison function for qsort to sort scores in descending order
 * 
 * @param a First score entry
 * @param b Second score entry
 * @return Positive if b > a, negative if a > b, 0 if equal
 */
int compare_scores(const void* a, const void* b) {
    return ((ScoreEntry*)b)->score - ((ScoreEntry*)a)->score;
}

/**
 * @brief Saves a player's score to the high score file
 * 
 * @param name Player's name
 * @param score Player's achieved score
 * 
 * @details Loads existing scores, adds new score, sorts in descending order,
 *          and saves back to file. Maximum 100 scores are maintained.
 */
void save_score(const char* name, int score) {
    FILE* file = fopen("scores.txt", "r");
    ScoreEntry scores[100];
    int count = 0;

    if (file) {
        while (fscanf(file, "%s %d", scores[count].name, &scores[count].score) != EOF && count < 100) {
            count++;
        }
        fclose(file);
    }

    if (count < 100) {
        strncpy(scores[count].name, name, sizeof(scores[count].name) - 1);
        scores[count].name[sizeof(scores[count].name) - 1] = '\0';
        scores[count].score = score;
        count++;
    }

    qsort(scores, count, sizeof(ScoreEntry), compare_scores);

    file = fopen("scores.txt", "w");
    if (file) {
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s %d\n", scores[i].name, scores[i].score);
        }
        fclose(file);
    }
}

/**
 * @brief Displays all saved high scores
 * 
 * @details Reads scores from "scores.txt" and prints them to stdout.
 *          Displays appropriate message if no scores exist.
 */
void load_scores() {
    FILE* file = fopen("scores.txt", "r");
    if (file) {
        char name[50];
        int score;

        printf("Top Scores:\n");
        while (fscanf(file, "%s %d", name, &score) != EOF) {
            printf("%s %d\n", name, score);
        }
        fclose(file);
    } else {
        printf("No scores available.\n");
    }
}