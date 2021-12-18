#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void bubbleSort(long *mas, long n)
{
  long i = 0, j = 0, tmp = 0;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (mas[j] > mas[j + 1]) {
        tmp = mas[j];
        mas[j] = mas[j + 1];
        mas[j + 1] = tmp;
      }
    }
  }
}

void insertionSort(long* mas, long n)
{
  long i = 0, j = 0, tmp = 0;

  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0 && mas[j - 1] > mas[j]; j--) {
      tmp = mas[j - 1];
      mas[j - 1] = mas[j];
      mas[j] = tmp;
    }
  }
}

void quickSort(long* mas, long left, long right)
{
  long tmp = 0;
  long pivot = mas[(left + right)/2]; 
  long l = left; 
  long r = right; 
  while (l <= r)
  {
    while (mas[r] > pivot)
      r--;
    while (mas[l] < pivot)
      l++;
    if (l <= r)
    {
      tmp = mas[l];
      mas[l] = mas[r];
      mas[r] = tmp;
      l++;
      r--;
    } 
  }
  if (left < r)
    quickSort(mas, left, r);
  if (right > l)
    quickSort(mas, l , right);
}

long double norm(long* mas, long n, long p)
{
  long double result = 0;

  for (long i = 0; i < n; i++)
    result += pow(abs(mas[i]),p);

  return pow(result, 1.0/p);
}

long normInf(long* mas, long n)
{
  long tmp = 0;

  for (long i = 0; i < n; i++)
  {
    if (abs(mas[i]) > tmp)
      tmp = abs(mas[i]);
  }

  return tmp;
}

void writeFile(long* mas, long n)
{
  FILE* fo;
  fo = fopen("../lab2_1/mas.txt", "w");
  fprintf(fo, "%ld\n", n);
  for (long i = 0; i < n; i++) fprintf(fo, "%ld\n", mas[i]);
  fclose(fo);
}

long main()
{
  long n = 0;
  int a = 0;
  long* mas;
  long* backup;
  FILE* fi;

  setlocale(LC_ALL, "Rus");
  fi = fopen("../lab2_1/mas.txt", "r");
  fscanf(fi, "%ld\n", &n);
  mas = (long*)malloc(n * sizeof(long));
  backup = (long*)malloc(n * sizeof(long));

  for (long i = 0; i < n; i++)
  {
    fscanf(fi, "%ld\n", &mas[i]);
    backup[i] = mas[i];
  }

  fclose(fi);
  
  do
  {
    printf("1.Печать\n2.Сортировка\n3.Сброс\n4.Норма массива\n5.Выход\nВыберите и напишите номер: ");
    scanf("%d", &a);
    if (a == 1)
    {
      system("cls");
      printf("Печать:\n\n");
      for (long i = 0; i < n; i++) printf("mas[%ld] = %ld\n", i, mas[i]);
      printf("\n");
    }
    else if (a == 2)
    {
      int b = 0;
      system("cls");

      printf("Сортировка:\n1.Пузырьком\n2.Вставкой\n3.Быстрая\n\n0.Назад\nВыберите и напишите номер: ");
      scanf("%d", &b);
      if (b == 1)
      {
        system("cls");
        clock_t t;
        t = clock();
        bubbleSort(mas, n);
        t = clock() - t;

        writeFile(mas, n);
        printf("Сортировка пузырьком выполнена.\nВремя выполнения = %f sec\n\n", ((double)t) / CLOCKS_PER_SEC);
      }
      else if (b == 2)
      {
        system("cls");
        clock_t t;
        t = clock();
        insertionSort(mas, n);
        t = clock() - t;
        writeFile(mas, n);
        printf("Сортировка вставкой выполнена.\nВремя выполнения = %f sec\n\n", ((double)t) / CLOCKS_PER_SEC);
      }
      else if (b == 3)
      {
        system("cls");
        clock_t t;
        t = clock();
        quickSort(mas, 0, n - 1);
        t = clock() - t;
        writeFile(mas, n);
        printf("Быстрая сортировка выполнена.\nВремя выполнения = %f sec\n\n", ((double)t) / CLOCKS_PER_SEC);
      }
      else
      {
        system("cls");
        continue;
      }
    }
    else if (a == 3)
    {
      for (long i = 0; i < n; i++)
        mas[i] = backup[i];
      system("cls");
      writeFile(mas, n);
      printf("Сброс выполнен.\n\n");
    }
    else if (a == 4)
    {
      system("cls");
      int c = 0;
      do
      {
        printf("1.Первая норма вектора (массива)\n2.Вторая норма вектора (массива)\n3.Гёльдерова норма вектора (массива)\n");
        printf("4.Бесконечная норма вектора (массива)\n5.Нормировка вектора (массива)\n\n0.Назад\nВыберите и напишите номер: ");
        scanf("%d", &c);
        if (c == 1)
        {
          system("cls");
          printf("Первая норма вектора (массива) = %Lf\n\n", norm(mas, n, 1));
        }
        else if (c == 2)
        {
          system("cls");
          printf("Вторая норма вектора (массива) = %Lf\n\n", norm(mas, n, 2));
        }
        else if (c == 3)
        {
          system("cls");
          long p = 0;
          printf("Введите p - норму (p>=1): ");
          scanf("%ld", &p);
          printf("Гёльдерова норма вектора (массива) = %Lf\n\n", norm(mas, n, p));
        }
        else if (c == 4)
        {
          system("cls");
          printf("Бесконечная норма вектора (массива) = %ld\n\n", normInf(mas, n));
        }
        else if (c == 5)
        {
          system("cls");

          for (long i = 0; i < n; i++)
          {
            printf("unit[%ld] = %Lf\n", i, (long double)mas[i] / norm(mas, n, 2));
          }
          printf("Вектор (массив) нормирован.\n\n");
        }
        else
        {
          system("cls");
          break;
        }
      } while (c >= 0);
    }
    else if (a == 5)
    {
      free(backup);
      free(mas);
      return 0;
    }    
    else
    {
      system("cls");
      continue;
    }
      
  } while (a >= 0);
 
  free(backup);
  free(mas);
  return 0;
}
