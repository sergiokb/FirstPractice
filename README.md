# FirstPractice
## Техническая часть 
> $ git clone git@github.com:sergiokb/PythonReview1.git    

### Запуск    
Build:    
>mkdir build    
cd build    
cmake ..    
cmake --build .    

Cвой тест:
>./my_main    

Unit-тесты:   
>./my_test   

### Проверка code-coverage    

Используем __gcov__:    
>cd CMakeFiles/my_test.dir/src    
gcov solution.cpp.gcno    
lcov --capture --directory . --output-file gtest_coverage.info    
genhtml gtest_coverage.info --output-directory CODE_COVERAGE    
cd CODE_COVERAGE    

Осталось открыть index.html:    
>open index.html 

## Описание
#### Задача 20    

**Условие:** Даны регулярное выражение reg в обратной польской записи и буква x.    
Найти максимальное k такое, что в языке L, задаваемом reg, есть слова, содержащие подслово x^k.

### Алгоритм
Действуем внешне так же, как при вычислении арифметического выражения в обратной польской записи. Заводим стек, в котором будем хранить регулярки, а точнее, некоторые их параметры. Затем по очереди берем символы строки. Если символ - буква/1, отправляем её в стек (в качестве регулярки из одной буквы), если же это операция, выполняем её над верхними элементами стека, результат отправляем туда вместо них.

*Во избежание недопонимания! Я называю суффиксом подстроку. Икс - буква, что нам дали*.    

Что же будет хранить класс регулярки?    
Основные три параметра - длина максимального префикса из подряд идущих иксов, длина максимального суффикса(подстроки) из подряд идущих иксов и длина максимального постфикса из подряд идущих иксов среди слов данного языка.    
Также будем хранить булеву переменную того, является ли регулярка просто 1, а также переменную того, есть ли в языке слово из одних только иксов, и максимальную длину такого.
Наконец, храним булевы флаги ошибки (error) и бесконечного ответа (inf).

Тогда понятно как будет устроен пересчет (везде имею в виду макс. префикс, суффикс, постфикс):    
- Для (regex)*  : префикс равен префиксу regex, постфикс равен постфиксу regex, суффикс - максимуму из суффикса regex и суммы префикса и постфикса regex. Если же в regex есть слово из одних лишь иксов, то inf = true, остальное уже не важно.    
- Для regex1+regex2  : префикс равен максимуму из префиксов regex1 и regex2, постфикс - максимуму из постфиксов,  суффикс - максимуму из суффиксов.    
- Для конкатенации regex1 и regex 2: префикс равен префиксу regex1, постфикс - постфиксу regex2,  суффикс - сумме постфикса regex1 и префикса regex2, либо максимуму из суффиксов, если он больше. Отдельно есть случаи, когда в языках есть слова из одних иксов, для них тоже формулы понятны (префикс regex2 складывается с длиной иксов из regex1, постфикс regex1 складывается с длиной иксов из regex2).        
- Inf, равный true, наследуется в результат при любой операции.

Если одна из двух регулярок, над которыми мы собираемся произвести операцию есть 1, просто удаляем 1 из стека, а операцию игнорируем.
При ошибке (число операндов меньше нужного) выходим из цикла, сделав error = true

В итоге, при правильной регулярке, в стеке останется один элемент, содержащий информацию про всю регулярку из входной строки. Ответом на задачу будет её максимальный суффикс.

Асимптотика - линия от длины входа, так как мы по очереди берем элементы из строки, и производим пересчет (конструируем новый элемент стека) за О(1).
