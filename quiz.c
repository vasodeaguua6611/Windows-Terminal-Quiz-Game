#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>

#define MAX_QUESTIONS 100
#define MAX_QUESTION_LEN 256
#define MAX_OPTION_LEN 64

typedef struct {
    char question[MAX_QUESTION_LEN];
    char options[4][MAX_OPTION_LEN];
    char correct_answer;
} Question;

volatile sig_atomic_t timeout = 0;

void alarm_handler(int sig) {
    timeout = 1;
}

int load_questions(const char *filename, Question *questions, int max_questions) {
    FILE *file = fopen(filename, "r");
    if (!file) return -1;

    char line[512];
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < max_questions) {
        line[strcspn(line, "\n")] = '\0';
        char *token = strtok(line, ",");
        if (!token) continue;

        strncpy(questions[count].question, token, MAX_QUESTION_LEN - 1);
        questions[count].question[MAX_QUESTION_LEN - 1] = '\0';

        for (int i = 0; i < 4; i++) {
            token = strtok(NULL, ",");
            if (!token) break;
            strncpy(questions[count].options[i], token, MAX_OPTION_LEN - 1);
            questions[count].options[i][MAX_OPTION_LEN - 1] = '\0';
        }

        token = strtok(NULL, ",");
        if (token) questions[count].correct_answer = toupper(token[0]);
        else continue;

        count++;
    }

    fclose(file);
    return count;
}

int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions = load_questions("questions.txt", questions, MAX_QUESTIONS);
    if (num_questions <= 0) return 1;

    printf("Welcome to the Quiz Game!\nYou have 10 seconds per question.\n\n");
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }

        printf("\nYour answer (A/B/C/D): ");
        fflush(stdout);

        HANDLE hTimer = CreateWaitableTimer(NULL, TRUE, NULL);
        LARGE_INTEGER liDueTime;
        liDueTime.QuadPart = -100000000LL; // 10 seconds
        SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, FALSE);

        char input[10];
        if (fgets(input, sizeof(input), stdin)) {
            char answer = toupper(input[0]);
            if (answer == questions[i].correct_answer) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Wrong! Correct answer: %c\n", questions[i].correct_answer);
            }
        }

        CloseHandle(hTimer);
        printf("--------------------------\n");
    }

    printf("\nFinal Score: %d/%d\n", score, num_questions);
    return 0;
}