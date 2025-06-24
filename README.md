# Snake Game (C Version)

This project is a basic terminal-based Snake game written in C, originally created as a school project. It was built purely for learning and fun – with a focus on practicing low-level logic, terminal input handling, file I/O, and raw mode control.

The project later inspired the creation of a more advanced modern version in C++ with graphics and animation, but this C version remains a solid demonstration of clean procedural design and structured code in a minimal environment.

## Features

- Terminal-based gameplay with raw input handling
- Dynamic food spawning and increasing difficulty
- Obstacles loaded from file
- Local leaderboard saved to `scores.txt`
- Grid size configurable via `field_size.txt`

## Build and Run (Linux / WSL)

```bash
make
./snake
```

## Files

- `snake.c` – main entry point
- `snake_logic.c` – core game loop and mechanics
- `obstacles.c` – file-based obstacle loading
- `score.c` – persistent score saving
- `snake.h`, `score.h`, `obstacles.h`, `point.h` – headers

## Notes

- Run in a terminal for best experience.
- This game uses raw terminal mode to capture real-time input.
- Scores are saved in a text file (`scores.txt`) automatically.