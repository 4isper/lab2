#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

long main()
{
  long max = 0, min = 0, n = 0;
  long* mas;
  int a;
  FILE* fo;
  FILE* fi;

  setlocale(LC_ALL, "Rus");

  printf("1.Массив из случайных чисел\n2.Ввести массив с клавиатуры\n3.Считать массив из файла\n4.Заверишить работу\nВыберите и напишите номер: ");
  scanf("%d", &a);

  if (a == 1)
  {
    while ((min >= max) || (n <= 0))
    {
      system("cls");
      printf("1.Массив из случайных чисел\nНужно ввести такие значения чтобы min < max, a n > 0\n\nВведите минимальное значение: ");
      scanf("%ld", &min);
      printf("Введите максимальное значение: ");
      scanf("%ld", &max);
      printf("Введите количество чисел: ");
      scanf("%ld", &n);
    }

    mas = (long*)malloc(n * sizeof(long));
    srand(time(NULL));
    fo = fopen("mas.txt", "w+");
    fprintf(fo, "%ld\n", n);

    for (long i = 0; i < n; i++)
    {
      mas[i] = ((double)rand() / RAND_MAX) * (max - min) + min;
      fprintf(fo, "%ld\n", mas[i]);
    }

    printf("\nМассив сгенерирован.\n\n");
    fclose(fo);
    free(mas);

  } else if (a == 2)
  {
    system("cls");
    long b = 0;
    
    printf("2.Ввести массив с клавиатуры\nВведите количество чисел массива: ");
    scanf("%ld", &n);
    fo = fopen("mas.txt", "w");

    fprintf(fo, "%d\n", n);
    printf("Введите массив:\n");

    for (long i = 0; i < n; i++)
    {
      scanf("%ld", &b);
      fprintf(fo, "%ld\n", b);
    }

    printf("\nМассив записан.\n\n");
    fclose(fo);

  } else if (a == 3)
  {
    system("cls");
    char* address;
    long c = 0;
    
    printf("3.Считать массив из файла\n\nПервый элемент файла - это количество чисел массива.\nВведите абсолютное имя файла (используйте английский алфавит и спец.символы. Например: C:\\\\Users\\\\dima4\\\\source\\\\example.txt ):\n");
    address = (char*)malloc(RAND_MAX * sizeof(char));
    scanf("%s", address);
    fo = fopen("mas.txt", "w");
    fi = fopen(address, "r");
    free(address);
    fscanf(fi, "%ld\n", &n);
    fprintf(fo, "%ld\n", n);
    for (long i = 0; i < n; i++)
    {
      fscanf(fi, "%ld\n", &c);
      fprintf(fo, "%ld\n", c);
    }
    printf("\nМассив считан из файла.\n\n");
    fclose(fi);
    fclose(fo);

  } else return 0;
  
  return 0;
}
