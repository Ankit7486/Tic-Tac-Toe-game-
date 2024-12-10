#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void display(char dis[3][3])
{

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            
            if(dis[i][j] == '\0')
            {
            if(j<2) 
            printf("   |");
            else if(j ==2)
            printf("   ");  
            }
            else  
            printf(" %c |",dis[i][j]); 
               
        }
       if(i<2)
        printf("\n___|___|___\n");
    }
    printf("\n");
}
int user_choice(char dis[3][3])
{
    int uc;
    printf("Your turn : ");
    scanf("%d",&uc);
    if(uc>=1 && uc<=9)
    {
        int row = (uc-1)/3;
        int col = (uc-1)%3;
        if(dis[row][col] == '\0')
        {
        dis[row][col] = 'X';
           return 1; 
        }
        else 
        {
        printf("invalid choice choose another\n");
        return 0;
        }
    }
    else {
    printf("invalid input\n");
     return 0; }
}        

void comp_choice(char dis[3][3])
{
    srand(time(NULL));
    int com_row;
    int com_col;
    do {
     com_row = rand() % 3;
     com_col = rand() % 3;
    }
    while(dis[com_row][com_col] !='\0');
    
    dis[com_row][com_col] = 'O';
    
}
int win_cond(char dis[3][3])
{
    //condition check for row and column
    for(int i= 0; i<3 ; i++)
    {
        if(dis[i][0] == dis[i][1]  && dis[i][1]==dis[i][2] && dis[i][0] !='\0')
        {
         if (dis[i][0] == 'X') {
         printf("YOU WoN !!!\n");
         return 1; }
         else{
         printf("COMPUTER WON !!!\n");
         return 0; }
        }
        if(dis[0][i] == dis[1][i] && dis[1][i] == dis[2][i] && dis[0][i] !='\0')
        {
            if(dis[0][i] == 'X') {
            printf("YOU WON !!!\n");
            return 1;  }
            else {
            printf("COMPUTER WON !!!\n");
            return 0;  }
        }
        
    }
    //condition check for diagonal
    if(dis[0][0] == dis[1][1] && dis[1][1] == dis[2][2] && dis[0][0] !='\0')
       {
        if(dis[0][0] == 'X')  {
            printf("YOU WON !!!\n");
            return 1;  }
            else  {
            printf("COMPUTER WON !!!\n");
            return 0;  }
       }
    if(dis[0][2] == dis[1][1] && dis[1][1] == dis[2][0] && dis[0][2] !='\0')
    {
    if(dis[0][2] == 'X')  {
            printf("YOU WON !!!\n");
            return 1;  }
            else {
            printf("COMPUTER WON !!!\n");
            return 0;  }
     }
    return -1;           // no winner
}
int box_check (char dis[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(dis[i][j] == '\0')
            return 0;        //board stil blank           
        }
    }
       return 1;         //board full
}
int main()
{
    char dis[3][3] = { { '\0','\0','\0'},{ '\0','\0','\0'}, { '\0','\0','\0'}};
    int turn =0;
    
    while(1)
    { 
        
        if(turn == 0)    //player turn
        {
           display(dis);
           if(!user_choice(dis))
           continue;
           if(win_cond(dis) == 1) {
            display(dis);
           break; }
           if(box_check(dis))
           { 
            printf("IT`s A TIE");
               display(dis);
                   break;
           }
           turn =1;       //computer turn
        }
        
        else   {  
                  
          comp_choice(dis);
          if(win_cond(dis) == 0) {
              display(dis);
                break;  }
           if(box_check(dis))
           {
           printf("ITS A TIE");
               display(dis);
           break;
          }
          turn = 0;
        }
    }
    return 0;
}
