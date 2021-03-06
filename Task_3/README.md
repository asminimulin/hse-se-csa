# Это второе домашнее задание в курсе Архитектура компьютерных систем на 2-ом курсе ОП "Программная инженерия" в НИУ ВШЭ. 2021-2022

## Описание задания.
В ходе выполнения задания необходимо написать программу, которая должна быть оформлена в виде консольного приложения, удовлетворяющего следующим требованиям:
1. Запуск программы осуществляется из командной строки, в которой указываются: имя запускаемой программы; имя файла с исходными данными; имя файла с выходными данными.
2. Для каждого программного объекта, загружаемого в контейнер (на основе массива максимальной размерности), исходный файл с тестовым набором должен содержать, признак альтернативы, а также список параметров, необходимых этой альтернативе. Этот список должен быть представлен в формате, удобном для обработки компьютером. При больших данных во входном файле должны быть указаны только параметры для генератора случайных наборов данных, который и заполняет контейнер.
3. В выходной файл необходимо вывести введенные в контейнер данные. Помимо этого необходимо вывести информацию об общем количестве объектов, содержащихся в контейнере. После этого в тот же файл необходимо вывести новые данные в соответствии с результатами, полученными в ходе работы программы. Информация для вывода должна быть представлена в форме, удобной для восприятия пользователем.
4. Программа должна иметь модульную структуру, соответствующую выданному варианту задания.
5. Для   представления   символьных   данных,   обрабатываемых   в   программе предлагается использовать только латиницу. Это обусловлено стремлением упростить их обработку. Дело в том, что в Linux в качестве основной кодировки символов принята UTF-8, которая за пределами кодировки ASCII использует двухбайтовый формат, в том числе и для русских букв. Комментарии, пояснительный текст, не требующий обработки можно писать  с использованием как русского, так и английского языков, а также транлитом.

**Вариант задания: 21**

---------

## Начальное условие задачи
| Обобщённый артефакт| Базовые альтрнативы | Общие для всех алтернитив перменные | Общие для всех альтернитив функции |
| :---: | :--- | :--- | --- |
| Фильмы | 1. Игровой<br> 2. Мультфильмы <br> 3. Документальный | 1. Название фильма<br> 2. Год выхода | Частное от деления года выхода фильма на на количество сиволов в названии фильма.

---

## Обработка данных в контейнере
Упорядочить элементы контейнера по возрастанию используя сортировку _Сортировка с помощью прямого выбора_ (_Straight Selection_). В качестве ключей для сортировки и других действий используются результаты функции, общей для всех альтернатив.

----

## Тестирование
Исходные данные для тестирования содержатся в каталоге `tests/data`.

Файл с результатами прогонов тестов `tests/report.txt`.

Для запуска поставляемых с решением тестов есть заготовленный скрипт `run-script.sh`.

Пример использования скрипта в ОС Linux, интерпретатор bash.
```
./run-script.sh main.py
```

Примеры использования программы без тестирующего скрипта. Предполагается, что сейчас мы в корне проекта.
```
# Parse input file with data
python main.py tests/data/test_001.txt tests/test_001.out
# Parse input file with random generator setup for the test
python main.py -n 100 tests/data/test_random_004.txt tests/test_004.out
```

Время работы программы на разных размерах входных данных:
Количество фильмов | Время работы, seconds | Потребляемая память, MB
--- | --- | ---
7 | 0.01 | ~10.3
100 | 0.03 | ~10.5
1000 | 0.23 | ~10.7
5000 | 5.70 | ~11.8
10000 | 23.50 | ~13.2
---

## Метрики, определяющие характеристики программы:
| Метрика | Значение |
| :---: | --- |
| Число файлов с исходным кодом | 8 + 1(файл тестирующий библиотеку) |
| Общий размер исходных текстов программы | 9.877 KB |

__*__ Версии подробнее:
```
$ python --version
Python 3.8.5

$ lsb_release -a
Distributor ID: Ubuntu
Description:    Ubuntu 20.04.2 LTS
Release:        20.04
Codename:       focal

$ uname -a
Linux DESKTOP-641N9G3 5.10.16.3-microsoft-standard-WSL2 #1 SMP Fri Apr 2 22:23:49 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
```

## Описание структуры вычислительной системы:

Информация о типах данных и сами данные хранятся в оперативной памяти процесса.

### Таблица имён модуля main.py
| Имя   | Тип     | Данные |
| :--- | :---:   | :---   |
| `sys.argv` | List[str] | Параметры коммандной строки
| `MAX_ELEMENTS_IN_CONTAINER` | int | Макисмальное количество элементов в контейнере
| `input_filename` | str | имя входного файла
| `output_filename` | str | имя выходного файла
| `films_count` | int | количество фильмов для генерации, при использовании генератора для заполнения контейнера
| `random_seed` | int | seed для генератора случайных чисел, при использовании генератора для заполнения контейнера
| `conatainer` | Container[Film] | считанные или сгенерированные фильмы
| `fatal_error` | Функция | Код функции `fatal_error`
| `print_usage` | Функция | Код функции `print_usage`
| `read_contaienr` | Функция | Код функции `read_container`
| `generate_container` | Функция | Код фнукции `read_container`
| `print_container` | Функция | Код функции `print_container`
| `main` | Функция | Код функции `main`
| `exit` | Функция | Код функции `exit`

### Таблица имён модуля cartoon.py
| Имя   | Тип     | Данные |
| :--- | :---:   | :---   |
| `Film `| Class | Данные класса `Film`, в т.ч. его таблица имён
| `Cartoon` | Class | Данные класса `Cartoon`, в т.ч. таблица имён класса `Cartoon`
| `CartoonType` | Class | Данные класса `CartoonType`, в т.ч. таблица имён `CartoonType`
| `Cartoon.__init__` | Функция | Код функции `Cartoon.__init__`
| @property <br> `Cartoon.type `| Функция | Код функции `Cartoon.type()`
| `CartoonType.PUPPET` | str | строка 'puppet'
| `CartoonType.CLAY` | str | строка 'puppet'
| `CartoonType.HANDDRAWN` | str | строка 'handdrawn'
| `CartoonType.__str__` | Функция | Код функции `CartoonType.__str__`

### Таблица имён модуля fiction.py
| Имя   | Тип     | Данные |
| :--- | :---:   | :---   |
| `Film` | Class | Данные класса `Film`, в т.ч. его таблица имён
| `Fiction` | Class | Данные класса `Fiction`, в т.ч. таблица имён класса Fiction
| @property <br> `Fiction.director` | Функция | Код функции `Fiction.director()`
| `Fiction.__init__` | Функция | Код функции `Fiction.__init__`

### Таблица имён модуля documentary.py
| Имя   | Тип     | Данные |
| :--- | :---:   | :---   |
| `Film` | Class | Данные класса `Film`, в т.ч. его таблица имён
| `Documentary` | Class | Данные класса `Documentary`, в т.ч. таблица имён класса `Documentary`
| @property <br> `Documentary.duration` | Функция | Код функции `Documentary.duration()`
| `Documentary.__init__` | Функция | Код функции `Documentary.__init__`

### Таблица имён модуля container.py
| Имя   | Тип     | Данные |
| :--- | :---:   | :---   |
| `Film` | Class | Данные класса `Film`, в т.ч. его таблица имён
| `List` | Class | Данные класса `List`, в т.ч. его таблица имён
| `Container` | Class | Данные класса `Container`, в т.ч. таблица имён класса `Container`
| `Container.__init__` | Функция | Код функции `Container.__init__`
| `Container.append_film` | Функция | Код функции `Container.append_film`
| `Container.__getitem__` | Функция | Код функции `Container.__getitem__`
| `Container.__len__` | Функция | Код функции `Container.__len__`
| `Container.sort_with_selection_sort` | Функция | Код функции `Container.sort_with_selection_sort`

### Таблица имён модуля film_generator.py
| Имя   | Тип     | Данные |
| :--- | :---:   | :---   |
| `Random` | Class | Данные класса `Random`
| `Film` | Class | Данные класса `Film`, в т.ч. его таблица имён
| `Cartoon` | Class | Данные класса `Cartoon`, в т.ч. его таблица имён
| `Documentary` | Class | Данные класса `Documentary`, в т.ч. его таблица имён
| `Fiction` | Class | Данные класса `Fiction`, в т.ч. его таблица имён
| `FilmGenerator` | Class | Данные класса `FilmGenerator`, в т.ч. таблица имён класса `FilmGenerator`
| `FilmGenerator.__init__` | Функция | Код функции `FilmGenerator.__init__`
| `FilmGenerator.generate_film` | Функция | Код функции `FilmGenerator.generate_film`
| `FilmGenerator._gen_string` | Функция | Код функции `FilmGenerator._gen_string`

### Таблица имён модуля film_printer.py
| Имя   | Тип     | Данные |
| :--- | :---:   | :---   |
| `Film` | Class | Данные класса `Film`, в т.ч. его таблица имён
| `Cartoon` | Class | Данные класса `Cartoon`, в т.ч. его таблица имён
| `Documentary` | Class | Данные класса `Documentary`, в т.ч. его таблица имён
| `FilmPrinter` | Class | Данные класса `FilmPrinter`, в т.ч. таблица имён класса `FilmPrinter`
| `FilmPrinter.__init__` | Функция | Код функции `FilmPrinter.__init__`
| `FilmPrinter.print_container_size` | Функция | Код функции `FilmPrinter.print_container_size`
| `FilmPrinter.print` | Функция | Код функции `FilmPrinter.print`

### Таблица имён модуля film_reader.py
| Имя   | Тип     | Данные |
| :--- | :---:   | :---   |
| `Film` | Class | Данные класса `Film`, в т.ч. его таблица имён
| `Cartoon` | Class | Данные класса `Cartoon`, в т.ч. его таблица имён
| `Documentary` | Class | Данные класса `Documentary`, в т.ч. его таблица имён
| `Fiction` | Class | Данные класса `Fiction`, в т.ч. его таблица имён
| `FilmReader` | Class | Данные класса `FilmReader`, в т.ч. таблица имён класса `FilmReader`
| `FilmReader.__init__` | Функция | Код функции `FilmReader.__init__`
| `FilmReader.read_film` | Функция | Код функции `FilmReader.read_film`
| `FilmReader.read_films_count` | Функция | Код функции `FilmReader.read_films_count`

Таблицы имён создаются не только для каждого импортированного модуля, но и для каждого объекта, который создаётся в ходе работы программы. Из-за того, что используемый язык python использует динамическую типизацию,
таблица имён любого оюъекта меняется в ходе работы программы, в т.ч. могут меняться таблицы имён модулей, описанных выше, и таблицы имён конкретных объектов инстанциированных классов.