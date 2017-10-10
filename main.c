#include "sort.h"
#include "function.h"
#include <stdio.h>
#include <malloc.h>
#include <sys/time.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int *mas;  // указатель на массив
    int i, n = 0, j, choose;
    double t;

    while(1){
        printf("\nВведите размер массива: ");
        scanf("%d", &n);
        if( (n == 0) ){
            scanf("%*[^\n]%*c");
            printf( "\n----Некорректный ввод!----\nВведите целое число больше нуля!\n" );
        }
        else break;
    }

    // Выделение памяти
    mas = malloc(n * sizeof(int));

    //Заполнение массива
    fill_mas(mas, n);
     
    // Вывод элементов массива
    while(1){
        printf("\nВывести массив?\n1 - ДА\n2 - НЕТ\nВвод: ");
        scanf("%d", &choose);
        if( (choose == 1) && (choose != 0) ){
            printf("\nЭлементы массива: \n");
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

    printf("\n");

    //Выбор сортировки
    menu(mas, n);

    // Вывод отсортированных элементов массива
    output_sorting_mas(mas, n);

    printf("\n");

    //освобождение динамической памяти
    free(mas);
    return 0;
}
