# School_Eltex

## Task 01

Дано 4-х байтовое число (в шестьнадцатеричной системе счисления 0xAABBCCDD), вывести по байтам (битам) значения данного числа.
Изменить значение 3-го байта в данном числе:

- инвертировать биты в 3 байте;
- изменить байт по заданной маске.

## Task 02

Выполнить задание 1 применяя указатели, массивы, структуры.

## Task 03

Создать и вывести на экран одно и двухмерные статичные массивы.

- заполнение и вывод одномерного массива, переворот и вывод этого же массива
- заполнение и вывод квадратной матрицы
- заполнение и вывод массива из 0 1 разделённых по диагоналям:
  - по главной;
  - по побочной.
- заполнение матрицы по спирали (вправо, вниз, влево, вверх)
- транспонирование матрицы - горизонтали становятся вертикалями (вверх -> влево)

## Task 04

Создать программу "Телефонный справочник"

## Task 05

Работа с GDB: The GNU Project Debugger

- изменить имеющуюся программу проверки пароля. Пароль считывть из файла, пароль любой кроме правильного (test);
- установить, запустить отладчик GDB;
- с помощью отладчика GDB изменить исходную программу так, чтобы в консоль выводилась надпись "Access granted!";
- описать процесс работы, результат - модифицированная программа и скриншот

## Task 06

Создать программу "Телефонный справочник" используя динамическое выделение памяти.

## Task 07

Установить Valgrind, проверить на использования памяти, обнаружения утечек памяти программы "Телефонный справочник" (Task 06)

## Task 08

Создать программу "Простой калькулятор" с функциями:
  - сложение
  - вычитание
  - умножение
  - деление

Создать статическую библиотеку из функций программы

## Task 09

Используя созданную ранее программу "Простой калькулятор" собрать для неё динамическую библиотеку

## Task 10

Используя созданную ранее программу "Простой калькулятор" собрать для неё четыре динамических библиотеки (по количеству функций).
Изменить пользовательский интерфейс программы так, чтобы при загрузке определённой библиотеки в меню пользователя предлагалась/предлагались только функции из этой/этих библиотек.

## Task 11

Основные системные вызовы, осуществляющие ввод-вывод: open(), close(), read(), write().

## Task 12

Создать программу "Текстовый редактор" используя библиотеку Ncurses

## Task 13

Создать программу "Файловый менеджер" используя библиотеку Ncurses

## Task 14

Управление процессами, системные вызовы: fork, exec, wait и exitПроцесс fork().
Создать программу создающую дочерний процесс. Программа выводит pid родительского и дочернего процессов, а также статус завершения дочернего процесса.
Создать программу создающую два дочерних процесса с выводом их pid, которые в свою очередь создают:
  - первый процесс - один дочерний процесс;
  - второй процесс - два дочерних процесса.

## Task 15

Объединить программы "Текстовый редактор" и "Файловый менеджер" в одну программу с примениением системных вызовов.


## Task 16

Создать программу порождающую 1000 потоков и инкрементирующую глобальную переменную каждым потоком на 100_000.


