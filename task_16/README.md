## task_16

Включаем необходимые заголовочные файлы `stdio.h` и `pthread.h`.
Определяем константу `SIZE` равную 1000.
Объявляем функцию `increment` без аргументов и возвращаемого значения.
Объявляем глобальную переменную `number` со значением 100000.
В функции `main` объявляем переменные `i`, `array` и указатель `s`.
Объявляем массив из 1000 потоков `thread`.
Используя цикл, создаем 1000 потоков, каждый из которых вызывает функцию `increment` и передает ей адрес элемента `array[i]` в качестве аргумента.
Используя цикл, вызываем `pthread_join` для каждого потока, чтобы дождаться их завершения. Возвращаемое значение каждого потока сохраняется в указателе `s`.
Выводим значение `number` после завершения всех потоков.


Функция `increment` принимает указатель на `array[i]` в качестве аргумента, но не использует его. Вместо этого, она инкрементирует глобальную переменную `number` на 100000. Значение `number` увеличивается в каждом потоке, что приводит к итоговому значению после завершения всех потоков.

Таким образом, программа создает 100 потоков, каждый из которых инкрементирует глобальную переменную `number` на 100000, и выводит итоговое значение `number`.

Запуск программы с подключением библиотеки -lpthread (gcc main.c -lpthread)