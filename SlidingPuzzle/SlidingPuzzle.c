#include <stdio.h>
#define TRUE 1
#define FALSE 0
void RandomPuzzle();
void PrintPuzzle();
int ReadInput();
int CheckGame();

int puzzle[3][3];
int blankX, blankY;
int main()
{
    int input;
    RandomPuzzle();
    do
    {
        system("cls");
        PrintPuzzle();
        input = ReadInput();
        switch (input)
        {
        case 1: //왼쪽
            if (blankY != 2)
            {
                puzzle[blankX][blankY] = puzzle[blankX][blankY + 1];
                puzzle[blankX][blankY + 1] = 9;
                blankY++;
            }
            break;
        case 2: //위
            if (blankX != 2)
            {
                puzzle[blankX][blankY] = puzzle[blankX + 1][blankY];
                puzzle[blankX + 1][blankY] = 9;
                blankX++;
            }
            break;
        case 3: //아래
            if (blankX != 0)
            {
                puzzle[blankX][blankY] = puzzle[blankX - 1][blankY];
                puzzle[blankX - 1][blankY] = 9;
                blankX--;
            }
            break;
        case 4: //오른쪽
            if (blankY != 0)
            {
                puzzle[blankX][blankY] = puzzle[blankX][blankY - 1];
                puzzle[blankX][blankY - 1] = 9;
                blankY--;
            }
            break;
        default:
            printf("Try Again!!!\n");
        }
    } while (!CheckGame());

    printf("축하합니다. 성공!!");
    return 0;
}
void swapIndex(int i, int j)
{
    int temp = puzzle[i / 3][i % 3];
    puzzle[i / 3][i % 3] = puzzle[j / 3][j % 3];
    puzzle[j / 3][j % 3] = temp;
}
void RandomPuzzle()
{
    int i, j, x, y;
    srand(time(NULL));
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            puzzle[i][j] = i * 3 + j + 1;

    for (i = 0; i < 9; i++)
    {
        j = rand() % 9; //0~8
        swapIndex(i, j);
    }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (puzzle[i][j] == 9)
            {
                blankX = i;
                blankY = j;
            }
}

void PrintPuzzle()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (puzzle[i][j] == 9)
                printf("  ");
            else
                printf("%d ", puzzle[i][j]);
        printf("\n");
    }
}
int ReadInput()
{
    int input;
    printf("Choice(←1,↑2,↓3,→4):");
    scanf_s("%d", &input);
    return input;
}
int CheckGame()
{
    int i, j, cnt = 1;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            if (puzzle[i][j] == cnt)
                cnt++;
        }
    if (cnt == 10) return TRUE;
    return FALSE;
}