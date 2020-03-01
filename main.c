#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int dimX = 3;
int dimY = 3;
int board[3][3] = {0};
int totalmoves = 1;
int rowcrossed()
{
    int status = 0;
    //check every row to see if there is a win
    for (int y = 0; y < dimY; y++)
    {

        if (board[y][0] == board[y][1] && board[y][1] == board[y][2])
        {

            if (board[y][0] != 0) //so the empty board doesnt count as a win
            {
                status = board[y][0];
            }
        }
    }
    return status;
}
int collumncrossed()
{
    int status = 0;
    //check every row to see if there is a win
    for (int x = 0; x < dimX; x++)
    {

        if (board[0][x] == board[1][x] && board[1][x] == board[2][x])
        {

            if (board[0][x] != 0) //so the empty board doesnt count as a win
            {
                status = board[0][x];
            }
        }
    }
    return status;
}
int diagnalcrossed()
{
    int status = 0;
    //check every row to see if there is a win

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {

        if (board[1][1] != 0) //so the empty board doesnt count as a win
        {
            status = board[1][1];
        }
    }

    return status;
}
int printboard()
{
    for (int y = 0; y < dimY; y++)
    {
        printf("y%d : ", y);
        for (int x = 0; x < dimX; x++)
        {
            printf("%d", board[y][x]);
        }
        printf("\n");
    }
    return 0;
}
int checkboard()
{

    int isRowcrossed = rowcrossed();
    int isCollumncrossed = collumncrossed();
    int isDiagnalcrossed = diagnalcrossed();
    if (isRowcrossed != 0)
    {

        return isRowcrossed;
    }
    if (isCollumncrossed != 0)
    {

        return isCollumncrossed;
    }
    if (isDiagnalcrossed != 0)
    {

        return isDiagnalcrossed;
    }

    //if al lspots filled (tie)
    if (totalmoves >= 9)
    {
        return 2;
    }
    return 0;
}

int main()
{
    printf("Tic tac toe\n");
    printboard();
    int current_move = 1;

    for (;;)
    {
        //a human players players move
        char x[20];
        printf("Input the x : ");
        scanf("%s", x);
        char y[20];
        printf("Input the y : ");
        scanf("%s", y);
        printf("%s ", x);
        printf("%s\n", y);

        board[atoi(y)][atoi(x)] = current_move;

        printboard();

        // 0 is tie,1 is 1s win, -1 is -1's win, 2 is go on
        int gamestatus = checkboard();
        printf("Val returned: %d\n", gamestatus);
        if (gamestatus != 0)
        {
            if (gamestatus == 2)
            {
                printf("\n\nTIE\n\n");
            }
            else
            {
                printf("\n\nWIN OF %d\n\n", gamestatus);
            }
        }

        //after all game code is done, swap to next player
        current_move = current_move * -1;
        totalmoves++;
    }
}
