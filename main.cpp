﻿//Практика 1:
// enum class
// initializer_list и универсальные списки инициализации
// auto
// decltype
// lambda

#include <deque>
#include <list>
#include <set>
#include "printConteiner.h"
#include "myConteinerFunction.h"
#include "enumstring.h"

int main()
{
//Задание 1.
    {
        enum class months : unsigned char { January, February, March/*...*/ };
        enum class weekDays { Monday, Tuesday /*...*/ };

        months m = months::January;
        //а) уберите проблемы (это значит, что КОМПИЛЯТОР не
        //должен позволять программисту осуществлять опасные
        //сравнения!)

        //if (m == Monday) { /*...*/ }

        //б) оптимизируйте использование памяти
        months year[] = { months::January, months::February, months::March };
        size_t n = sizeof(year); //???
        std::cout << n << '\n';//3
        //__asm nop
    }


    /**********************************************************/
    //Задание 2. Создайте и с помощью списка инициализации
    //заполните значениями вектор с элементами - string
    //С помощью range-based for преобразуйте все буквы в
    //верхний регистр а остальные символы должны остаться
    //неизменными
    {
        std::vector <std::string> vs = { "Qwer23ty", "a/.23sdfg", "Zx./23<.cxc" };
        for (auto& str : vs)
        {
            for (auto& ch : str)
            {
                ch = toupper(ch);
            }
        }
        printConteiner(vs);
        //__asm nop
    }


    /**********************************************************/
    //Задание 3. Создайте и заполните значениями
    //map таким образом, чтобы он содержал в качестве ключа
    //букву, а в качестве значения отсортированную по
    //алфавиту совокупность слов (string), начинающихся с
    //этой буквы

    std::map<char, std::set<std::string>> ms = {
                        { 'A', {"any", "apple", "away"} },
                        { 'C', {"capital", "car", "canteen"} },
                        { 'H', {"hello", "hand", "hammer"} }
    };

    //3а. Проинициализируйте map "вручную" посредством списка инициализации
    //С помощью range-based for и structured binding
    //распечатайте содержимое, например: A: any, apple, away

    for (auto& [C, S] : ms)
    {
        std::cout << C << ": ";
        printConteiner(S);
    }

    //3б. Создайте пустой map и используйте заданный массив
    //для выполнения задания.
    //С помощью range-based for и structured binding
    //распечатайте содержимое, например: A: any, apple, away
    {
        //дано (например):
        const char* s[] = { "yong", "away", "bar", "any", "son", "apple" };
        std::map<char, std::set<std::string>> ms;
        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            for (auto str : s)
            {
                if (toupper(str[0]) == (ch))
                {
                    ms[ch].insert(str);
                }
            }
        }

        for (auto& [C, S] : ms)
        {
            std::cout << C << ": ";
            printConteiner(S);
        }
        //		__asm nop
    }


    /*********************************************************/
    //Задание 4. создать функцию для вывода на печать
    //элементов последовательностей, заданных ниже:
    {
        std::vector<double> vd = { 1.1,2.2,3.3 };
        printConteiner(vd);

        std::string s("abc");
        printConteiner(s);

        int ar[] = { 1, 2, 3 };
        printConteiner(ar);

        std::initializer_list<int> il{ 3,4,5 };
        printConteiner(il);

        //__asm nop
    }


    /********************************************************/
    //Задание 5.
    //Cоздать функцию для "отрицания" значений, например:
    //было: {1, -2, 5}, стало: {-1, 2, -5})
    //изменение объектов типа std::string может выглядеть "aBc1" -> "AbC1"
    //элементов последовательностей, заданных ниже:
    {
        std::vector<double> vd{ 1.1,2.2,3.3 };
        NegateAll(vd);
        printConteiner(vd);

        std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
        NegateAll(ls);
        printConteiner(ls);

        int ar[]{ 1, 2, 3 };
        NegateAll(ar);
        printConteiner(ar);
        //__asm nop

    }


    /********************************************************/
    //Задание 6. Реализовать функцию сортировки по модулю
    //элементов последовательностей, заданных ниже
    //Собственно для сортировки можно использовать обобщенный
    //алгоритм sort(), а для задания условия - лямбда-функцию
    {
        std::vector<double> vd = { -3.3,  2.2, -1.1 };
        absSort(vd);
        printConteiner(vd);

        int ar[] = { -3, 2, -1 };
        absSort(ar);
        printConteiner(ar);

        //__asm nop
    }


    /********************************************************/
    //Задание 7.
    //Напишите функцию, которая будет формировать и
    //возвращать вектор, каждый элемент
    //которого является суммой элементов двух
    //последовательностей РАЗНОЙ длины
    //и с элементами РАЗНОГО типа.

    //Подсказка 1: так как последовательности могут быть
    //разной длины, логично сделать размер результирующего
    //вектора максимальным из двух

    //Подсказка 2: подумайте о возможности использования
    //алгоритмов copy() и transform(), в котором
    //трансформирующее действие удобно в свою очередь
    //задавать лямбда-функцией

    //например:
    {
        std::vector<int> v{ 1,2,3,4 };
        std::list<double> l{ 1.1, 2.2, 3.3, 4.4, 5.5 };

        auto res = SumCont(v, l);
        printConteiner(res);


        std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
        double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
        auto res2 = SumCont(ar, ll);
        printConteiner(res2);


        std::set<std::string> s{ "abc", "qwerty", "my" };
        std::deque<const char*> d{ "111", "22" };
        auto res3 = SumCont(s, d);
        printConteiner(res3);

        //__asm nop
    }


    /********************************************************/
    //Задание 8. Реализуйте функцию, которая принимает следующие параметры:
    //сформированную последовательность любого типа с элементами любого типа,
    //два (пустых) контейнера любого типа из vector, list, deque, set
    //с элементами того же типа, что и у сформированной последовательности

    //Функция должна "разложить" значения заданной последовательности в два пустых контейнера
    //согласно заданному условию. Условие задать лябда-функцией
    //Исходная последовательность при этом не меняется
    {
        //Например:
        std::vector<int> v{ 1,2,3,4,5 };
        std::set<int> l; //сюда четные
        std::list<int> d; //а сюда нечетные
        Separate1(v, l, d, [](int x) {return !(x & 1); });
        printConteiner(l);
        printConteiner(d);
        //__asm nop
    }


    /********************************************************/
    //Задание 9. C помощью алгоритма for_each()!!!
    //(а не count_if()) посчитать сколько букв в верхнем
    //регистре.
    //Использовать лямбда функцию
    {
        char s[] = "Hello World!";
        size_t sum = 0;
        std::for_each(std::begin(s), std::end(s),
            [&sum](char ch) { if (isupper(ch)) { sum++; }});

        std::cout << '\n' << sum << '\n';

        //__asm nop
    }


    /********************************************************/
    //Задание 10. Реализовать конвертацию enum в строковое представление  - enumToString
    // и наоборот - stringToEnum

    //Подсказки:

    //***********

    //1. Соответствующие именованным константам строки все равно нужно где-то хранить =>

    //1.1 Именованные константы в перечислении должны быть уникальными => соответствующие строки
    //тоже должны быть уникальными, => уникальные строки могут быть использованы в качестве
    //ключа в std::map

    //1.2 а вот значения (соответствующие именованым константам)
    //могут быть любыми и даже могут повторяться (упрощаем задачу, считая, что значения НЕ повторяются)
    //=> подходит контейнер std::map<string,<значение> >

    //1.3 Согласно стандарту С++11 переменные перечислимого типа могут быть разного размера и типа,
    //а хотелось бы обеспечить универсальную конвертацию

    //***********

    //2. Так как типы перечислений разные, то enumToString и stringToEnum должны быть шаблонными

    //2.1 Пользователь может ошибиться или злонамеренно передать в функции значения, которым
    //ничего не соответствует => защита!

    //2.2 В функциях enumToString и stringToEnum (в зависимости от типа перечисления) нужно будет
    //анализировать соответствующий используемому типу перечисления контейнер

    //***********

    //3. Чтобы действия с map<string, <значение> > не зависили от типа перечисления, логично реализовать "обертку":
    /*
    template<typename T> struct EnumMap
    {
        static std::map<std::string, T> m_eMap;
        static const auto& getMap() { return m_eMap; }
    };
    */

    //***********

    //{
        //Например:
        /*
        COLORS c1;
        try {
            c1 = stringToEnum<COLORS>("blue");
        }
        catch (...)
        {
            //...
        }


        auto Str = enumToString(c1);
        */
    //}


    COLORS c1;
    try {
        c1 = stringToEnum<COLORS>(std::string("blue"));
    }
    catch (...)
    {
        //
    }
    auto Str = enumToString(c1);
    std::cout << Str << '\n';
    //__asm nop


    return 0;
}
