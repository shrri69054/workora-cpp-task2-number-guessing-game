# Task 2 – Number Guessing Game (C++)

The computer picks a random number from 1–100 and you guess it with "Too High" / "Too Low" hints.

## Features
- Random target seeded with `srand(time(0))`
- Attempt counter, score out of 100 (−10 per extra attempt) and best-attempts tracking
- Validates non-numeric and out-of-range guesses (these do not count as attempts)
- Replay option

## Concepts used
`<cstdlib>` / `<ctime>`, `rand()`, conditional logic, `do-while` loops, input validation.

## Build & Run
```bash
g++ -std=c++17 -Wall -Wextra guessing_game.cpp -o guessing_game
./guessing_game
```

## Files
| File | Purpose |
|------|---------|
| `guessing_game.cpp` | Source code |
| `sample_output.txt` | Captured output (random number differs each run) |
