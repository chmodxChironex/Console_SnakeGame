/**
* @file snake.c
 * @brief Main entry point for the console snake game
 * @author chmodxChironex
 * @date 2024
 */

#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "snake.h"
#include "score.h"
#include "obstacles.h"

/**
 * @brief Main function - Entry point of the snake game
 *
 * @return 0 on successful execution
 *
 * @details Initializes game field, loads obstacles, handles game loop,
 *          manages scoring system and user interaction
 */
int main() {
    char player_name[50];
    Obstacles obstacles;

    FILE* field_file = fopen("field_size.txt", "r");
    if (field_file) {
        fscanf(field_file, "%d %d", &WIDTH, &HEIGHT);
        fclose(field_file);
    }

    printf("Enter your name: ");
    fgets(player_name, sizeof(player_name), stdin);

    size_t len = strlen(player_name);
    if (len > 0 && player_name[len - 1] == '\n') {
        player_name[len - 1] = '\0';
    }

    Snake snake;
    int game_over = 0;

    load_obstacles("obstacles.txt", &obstacles);

    enable_raw_mode();
    initialize_game(&snake);

    while (!game_over) {
        clear_screen();
        draw(&snake, &obstacles);
        update_game(&snake, &game_over, &obstacles);
        usleep(snake.speed * 50000);
    }

    disable_raw_mode();
    save_score(player_name, snake.length);
    printf("Game Over!\n");

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("Do you want to see the top scores? (y/n): ");
    char choice = getchar();
    if (choice == 'y' || choice == 'Y') {
        load_scores();
    }

    return 0;
}