/* Daniel O'Connell
 * Intro to C Programming
 *
 * Assignment 1
 * Due: 26 January 2016 @ 2359
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int genQuestion(int number, int diff);
int answerQuestion(int ans);
void response(int a, int ans);

int main (void){
    int questions;
    int difficulty;
    int sentinel;
    int currentAnswer;
    int correctness;
    int totalCorrect = 0;
    srand(time(NULL));

    printf("How many questions for this test(1-20)? ");
    scanf("%d", &questions);
    while(questions > 20 || questions < 1){
        printf("How many questions for this test(1-20)? ");
        scanf("%d", &questions);
    }

    printf("Select difficulty (1-4): ");
    scanf("%d", &difficulty);
    while(difficulty > 4 || difficulty < 1){
        printf("Select difficulty (1-4)");
        scanf("%d", &difficulty);
    }

    for(sentinel = 0; sentinel < questions; sentinel++){
        currentAnswer = genQuestion(sentinel + 1, difficulty);
        correctness = answerQuestion(currentAnswer);
        if(correctness == 1){
            /*correct answer*/
            response(1, currentAnswer);
            totalCorrect++;
        }
        else{
            /*incorrect answer*/
            response(0, currentAnswer);
        }
    }
    printf("Your score was: %d/%d\n", totalCorrect, questions);
    return 0;
}

/* Used to randomly generate and output a random question based upon
 * a difficulty which is passed as a parameter. Returns the answer 
 * of the question.
 */
int genQuestion(int number, int diff){
    int value1;
    int value2;
    int operator = rand() % 4;
    int toReturn;

    switch(diff){
        case 1: /*difficulty 1 - range 1 - 10*/
            value1 = (rand() % 10) + 1;
            value2 = (rand() % 10) + 1;
            break;
        case 2: /*difficulty 2 - range 1 - 50*/
            value1 = (rand() % 50) + 1;
            value2 = (rand() % 50) + 1;
            break;
        case 3: /*difficulty 3 - range 1 - 100*/
            value1 = (rand() % 100) + 1;
            value2 = (rand() % 100) + 1;
            break;
        case 4: /*difficulty 4 - range -100 - 100*/
            value1 = (rand() % 201) + (-100);
            while(value2 == 0){
                value2 = (rand() % 201) + (-100);
            }
            break;
        default:
            printf("An error occurred\n");
            break;
    }

    switch(operator){
        case 0: /*operator is '/'*/
            printf("Question %d: %d / %d = \n", number, value1, value2);
            toReturn  = (value1 / value2);
            break;
        case 1: /*operator is '*'*/
            printf("Question %d: %d * %d = \n", number, value1, value2);
            toReturn  = (value1 * value2);
            break;
        case 2: /*operator is '+'*/
            printf("Question %d: %d + %d = \n", number, value1, value2);
            toReturn  = (value1 + value2);
            break;
        case 3: /*operator is '-'*/
            printf("Question %d: %d - %d = \n", number, value1, value2);
            toReturn  = (value1 - value2);
            break;
        default:
            printf("An error occurred\n");
    }

    return toReturn;
}

/*prompts for an answer, checks if correct based on actual solution*/
int answerQuestion(int ans){
    int input;
    int answer = ans;
    int toReturn;

    printf("Enter Answer: ");
    scanf("%d", &input);

    if(answer == input){
        toReturn = 1;
    }
    else{
        toReturn = 0;
    }
    return toReturn;
}

/*outputs a response to the users answer based on passed boolean value*/
void response(int a, int ans){
    int response;
    int answer = ans;

    if(a == 1){ /* was correct, randomly choose from "nice!",
                 * "good job!", and "you're right!"
                 */
        response = rand() % 3;
        switch(response){
            case 0:
                printf("Nice!\n");
                break;
            case 1:
                printf("Good Job!\n");
                break;
            case 2:
                printf("You're Right!\n");
                break;
            default:
                printf("An error occurred\n");
                break;
        }
    }
    else{ /*was not correct, print actual answer*/
        printf("Sorry! \nThe correct answer was %d\n", answer);
    }
}


