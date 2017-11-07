#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Stroing start time
    clock_t start_time = clock();
 
    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}
void main()
{
    printf("\n       |               |                |'\'                               |'\'                    ");
    delay(500);
    printf("\n       |               |                | '\'                              | '\'                    ");
    delay(500);                  
    printf("\n       |               |                |   '\'                            |  '\'                   ");
    delay(500);
    printf("\n       |               |                |    '\'                           |   '\'                   ");
    delay(500);
    printf("\n       |               |                |      '\'                         |    '\'                   ");
    delay(500);
    printf("\n       |               |                |       '\'                        |     '\'                   ");
    delay(500);
    printf("\n       |               |                |        '\'                       |      '\'                   ");
    delay(500);
    printf("\n       |               |                |         '\'                      |       '\'                   ");
    delay(500);
    printf("\n       |               |                |          '\'                     |        '\'                   ");
    delay(500);
    printf("\n       |               |                |            '\'                   |         '\'                   ");
    delay(500);
    printf("\n       |               |                |             '\'                  |          '\'                   ");
    delay(500);
    printf("\n       |               |                |              '\'                 |           '\'                   ");
    delay(500);
    printf("\n       |               |                |               '\'                |            '\'                   ");
    delay(500);
    printf("\n       |               |                |                //               |             '\'                   ");
    delay(500);
    printf("\n       |               |                |               //                |              '\'                   ");
    delay(500);
    printf("\n       |---------------|                |              //                 |               '\'                   ");
    delay(500);
    printf("\n       |               |                |             //                  |                '\'                   ");
    delay(500);
    printf("\n       |               |                |            //                   |                 '\'                   ");
    delay(500);
    printf("\n       |               |                |           //                    |                  '\'                   ");
    delay(500);
    printf("\n       |               |                |          //                     |                   '\'                   ");
    delay(500);
    printf("\n       |               |                |         //                      |                    '\'                   ");
    delay(500);
    printf("\n       |               |                |        '\'                       |                     '\'                   ");
    delay(500);
    printf("\n       |               |                |         '\'                      |                     //                    ");
    delay(500);
    printf("\n       |               |                |          '\'                     |                    //                    ");
    delay(500);
    printf("\n       |               |                |           '\'                    |                   //                    ");
    delay(500);
    printf("\n       |               |                |            '\'                   |                  //                    ");
    delay(500);
    printf("\n       |               |                |             '\'                  |                 //                    ");
    delay(500);
    printf("\n       |               |                |              '\'                 |                //                    ");
    delay(500);
    printf("\n       |               |                |               '\'                |               //                    ");
    delay(500);
    printf("\n       |               |                |               //                |              //                    ");
    delay(500);
    printf("\n       |               |                |              //                 |             //                    ");
    delay(500);
    printf("\n       |               |                |             //                  |            //                    ");
    delay(500);
    printf("\n       |               |                |            //                   |           //                    ");
    delay(500);
    printf("\n       |               |                |           //                    |          //                    ");
    delay(500);
    printf("\n       |               |                |          //                     |         //                    ");
    delay(500);
    printf("\n       |               |                |         //                      |        //                    ");
    delay(500);
    printf("\n       |               |                |        //                       |       //                    ");
    delay(500);
    printf("\n       |               |                |       //                        |      //                    ");
    delay(500);
    printf("\n       |               |                |      //                         |     //                    ");
    delay(500);
    printf("\n       |               |                |     //                          |    //                    ");
    delay(500);
    printf("\n       |               |                |    //                           |   //                    ");
    delay(500);
    printf("\n       |               |                |   //                            |  //                    ");
    delay(500);
    printf("\n       |               |                |  //                             | //                    ");
    delay(500);
    printf("\n       |               |                | //                              |//                    ");
    delay(500);
    
}