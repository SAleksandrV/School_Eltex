## task_09
### Программа создана в виде основного файла, четырёх файлов по функциям (add, subtract, multiply, divide) и одного заголовочного файла, а также Makefile. В результате компиляции дополнитильно создаются объектные файлы, а также динамическая библиотека.

Программа "Простой калькулятор" при запуску (make start) просит ввести два целых числа, далее предлагается выбрать одну из четырёх метематических операций (сложение, вычитание, умножение, деление) вводом соответствующий цифры (от 1 до 4). Выбрав из меню цифру 5 программа завершится.

### Создание динамической библиотеки:
    - компиляция объектных файлов (gcc -c -fPIC file.c)
        * Объектные файлы для динамической библиотеки должны содержать так называемый позиционно-независимый код (PIC position independent code), это позволяет библиотеке подключаться к программе, когда программа загружается в память. Библиотека и программа не являются единой программой, а значит как угодно могут располагаться в памяти относительно друг друга
    - создание динамической библиотеки (gcc -shared -o libmy_library.so file_1.o file_2.o)
        * -shared - утилита указывает компилятору создать динамическую библиотеку вместо исполняемого файла
        * -o lib... - в Linux название библиотеки всегда должно начинаться с lib
        * file_1.o .. - объектные файлы, которые будут включены в динамическую библиотеку без файла main.o
        * .so - расширение динамической библиотеки (для Linux/Unix) .dll (для Windows)
    - создание исполняемого (бинарного) файла (gcc file.c -L. -lmy_library -o file)
        * -L. - опция указывает на адрес где находится библиотека, . - означает текущий каталог 
        * -lmy_library - имя библиотеки, при этом префикс lib и суффикс .so усекаются
    - использование динамической библиотеки (gcc file.c -o file -L. -libmy_library) в данном случае линковщик не найдёт файл библиотеки, необходимо динамическому загрузчику указать путь до библиотеки (LD_LIBRARY_PATH=$PWD:LD_LIBRARY_PATH ./file)
        * LD_LIBRARY_PATH - это переменная окружения в операционной системе Linux, которая используется для указания дополнительных путей поиска динамических библиотек (shared libraries) при выполнении программы
        * ./file - означает запуск исполняемого файла "file". При этом переменная окружения LD_LIBRARY_PATH устанавливается в значение "$PWD:LD_LIBRARY_PATH", что добавляет текущую директорию (где находится исполняемый файл) в список путей поиска динамических библиотек.
