# Windows Quiz Game

Welcome to Quiz Game! This is a fun, interactive and poorly written quiz game in C that puts your general knowledge to the test.And uh.... It kind of only works on Windows. You'll tackle a series of multiple-choice questions loaded from a text file, with each question giving you 10 seconds to answer. Let's dive in! I SUCK SO MUCH AT C OH MY GOD

## Features

- **Timed Challenges:** Each question must be answered within 10 seconds.
- **Multiple Choice:** Answer with A, B, C, or D.
- **Score Tracking:** See your score update as you progress through the quiz.

## Project Structure

- **`questions.txt`**  
  This file contains the quiz questions along with multiple-choice options. Each line in the file follows this format:
  ```
  Question text,Option A,Option B,Option C,Option D,Correct Option Letter
  ```
- **`quiz.c`**  
  This is the main C source file which:
  - Loads questions from `questions.txt`
  - Presents each question and its options to you
  - Uses a timer (via Windows APIs) to enforce a 10-second limit per question
  - Tracks and displays your final score

## Getting Started

### Prerequisites

- **C Compiler:** GCC, Clang, or any C compiler of your choice.
- **Operating System:** The project currently uses Windows-specific APIs (e.g., `<windows.h>`). If you’re on another platform, you may need to adjust the timer functionality. I'll make a Linux/Unix/MacOs version with a GUI once i get better at C.
- **Command Line Environment:** To build and run the project.

### Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/yourusername/quizgame.git
   ```
2. **Navigate to the Project Directory:**
   ```bash
   cd quizgame/C_Bass/quizgame
   ```

### Compilation

Compile the project using your preferred C compiler. For example, with GCC:

gcc quiz.c -o quiz -Wall

> **Note:** Since the project uses Windows-specific functions (e.g., `CreateWaitableTimer`), ensure you are compiling in a compatible environment or adjust the code accordingly.

### Running the Game

After compiling, execute the game:

- **On Windows:**
  ```bash
  quiz.exe
  ```
- **On Unix-like systems (if adapted):**
  ```bash
  ./quiz
  ```

Follow the on-screen prompts, and be sure to answer each question within 10 seconds!

## Contributing

Contributions are very welcome. If you have ideas for improvements, bug fixes, or new features, feel free to fork the repository and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contact

For any questions, feedback, or suggestions, please reach out at my instagram [polterwine_egoz](https://www.instagram.com/polterwine_egoz/).

Enjoy the game and happy quizzing!
