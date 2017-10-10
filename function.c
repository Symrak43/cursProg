#include "function.h"
#include "sort.h"
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double wtime(){
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void menu(int *mas, int n){
    double t;
    int choose;
    printf("\nВыберите сортировку:\n  1 - HeapSort\n  2 - SortInsertion\n");
    printf("Ввод: ");
    scanf("%d", &choose);
    switch ( choose ) {
        case 1:{
            printf("\n1 - HeapSort:\n");
            t = wtime();
            HeapSort(mas, n);
            t = wtime() - t;
            break;
        }

        case 2:{
            printf("\n2 - SortInsertion:\n");
            t = wtime();
            SortInsertion(mas, n);
            t = wtime() - t;        
            break;  
        }
        default:
            scanf("%*[^\n]%*c");
            printf( "\n----Некорректный ввод!----\nВведите цифру 1 или 2!\n" );
            menu(mas, n);
    } 
}

void fill_mas(int *mas, int n){
    int i, j, choose;
    printf("\nЗаполнение массива: \n");
    printf("1 - Случайными числами\n2 - Упорядоченного по возрастанию\n3 - Упорядоченного по убыванию\n");
    printf("Ввод: ");
    scanf("%d", &choose);
    switch(choose){
        case 1:
            // Заполнение массива СЛУЧАЙНЫМИ ЧИСЛАМИ
            for(i = 0; i < n; i++)
                mas[i] = rand()%100000 + 1;
            break;
        case 2:
            // Заполнение массива УПОРЯДОЧЕННОГО ПО ВОЗРАСТАНИЮ
            for(i = 0; i < n; i++)
                mas[i] = i+1;    
            break;
        case 3:
            // Заполнение массива УПОРЯДОЧЕННОГО ПО УБЫВАНИЮ
            for(i = 0, j = n; i < n; i++, j--)
                mas[i] = j;
            break; 
        default:
            scanf("%*[^\n]%*c");
            printf( "\n----Некорректный ввод!----\nВведите цифру 1, 2 или 3!\n" );
            fill_mas(mas, n);
    }
}

void output_sorting_mas(int *mas, int n){
    int choose, i;
    while(1){
        printf("\nВывести отсортированный массив?\n1 - ДА\n2 - НЕТ\nВвод: ");
        scanf("%d", &choose);
        if( (choose == 1) && (choose != 0) ){
            printf("\nОтсортированный массив: \n");
            for (i = 0; i < n; i++)
                printf("%d ", mas[i]);
            break;
        }
        else if(choose == 2)
            break;
        else{
            scanf("%*[^\n]%*c");
            printf( "\n----Некорректный ввод!----\nВведите цифру 1 или 2!\n" );
        }
    } 
}