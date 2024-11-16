/*
    Класс Number - класс положительных больших чисел

    Большое число будет храниться в массиве в сегменте куча.
    В самом объекте будем хранить указатель на данные в куче.
    Также, в самом объекте будут храниться размер и вместимость массива.

        data - указатель, на элементы, хранящиеся в куче.
        capacity - размер массива data.
        size - сколько ячеек занимет число в массиве data, size <= capacity.

    По условию задачи класс Number должен поддерживать только положительные числа.
    Это сделано для того, чтобы задача не была слишком сложной.

    Каждый элемент массива должен содержать разряд числа в 100-ричной системе счисления (так как base = 100).
    По сути, каждый элемент массива должен хранить две цифры числа в десятичной записи.

    Значение 100 для системы счисления выбрано для того, чтобы задача была не такой сложной.
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа, размером 1 байт),
    то алгоритм печати на экран усложнится. Наиболее эффективный вариант - использование 64 битных чисел
    (то есть uint64_t вместо char) и базы 2^64, но это бы ещё сильнее усложнило эту задачу.

    Для удобства разряды числа хранятся в обратном порядке (это упрощает многие алгоритмы с такими числами). 
    Например, число 12345678 соответствует массиву:
    
        {78, 56, 34, 12}
    
    Для выделения/освобождения памяти в куче были использованы операторы new[] и delete[].
    Хотя можно было бы и использовать функции malloc и free из библиотеки cstdlib.

    Выделение/освобождения с использованием malloc/free:

        data = static_cast<char*>(std::malloc(capacity * sizeof(char)));
        ...
        std::free(data);

    То же самое с использованием new[]/delete[]:

        data = new char[capacity];
        ...
        delete[] data;

*/


#include <iostream>
#include <iomanip>
#include <string>

class Number 
{
private:
    static const int base = 100;

    char* data;
    std::size_t size;
    std::size_t capacity;

public:

    Number(int a) 
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0) 
            capacity = 1;

        // Выделяем память в куче и записывем число a в массив data
        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }


    ~Number() 
    {
        // Освобождаем память в куче
        delete [] data;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Number& num);

    Number()
    {
        capacity = 1;
        size = 1;
        data = new char[capacity];
        data[0] = 0;
    }

    Number(const Number& other)
    {
        capacity = other.capacity;
        size = other.size;
        data = new char[capacity];

        for (std::size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    Number(const std::string& str)
    {
        int a = std::stoi(str);
        capacity = str.capacity();
        size = capacity;

        if (capacity == 0) 
            capacity = 1;

        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        size = capacity;
    }


    Number& operator=(const Number& n)
    {
        capacity = n.capacity;
        size = n.size;
        size = n.size;
        data = new char[capacity];

        for (std::size_t i = 0; i < size; i++)
        {
            data[i] = n.data[i];
        }

        return *this;
    }

    Number& operator+=(const Number& n) 
{
    std::size_t maxSize = std::max(size, n.size) + 1; 
    char* result = new char[maxSize](); 

    int carry = 0; 
    for (std::size_t i = 0; i < maxSize; ++i) 
    {
        int sum = carry;
        if (i < size) sum += data[i];
        if (i < n.size) sum += n.data[i];
        result[i] = sum % base;
        carry = sum / base;
    }

    delete[] this->data;
    data = result;
    size = carry;

    return *this;
}

Number operator+(const Number& n) const 
{
    Number result = *this; 
    result += n;           
    return result;
}

Number fibonacci(int n) 
{
    if (n == 0) return Number(0);
    if (n == 1) return Number(1);

    Number a = 0, b = 1;
    for (int i = 2; i <= n; ++i) 
    {
        Number next = a + b;
        a = b;
        b = next;
    }
    return b;
}

bool isEven()const
{
    return data[0]%2 == 0;
}

Number operator*(const Number& n) const
{
    std::size_t resSize = size + n.size;
    char* result = new char[resSize];

    for (std::size_t i = 0; i < size; ++i) 
    {
        int carry = 0;
        for (std::size_t j = 0; j < n.size; ++j) 
        {
            int product = data[i] * n.data[j] + result[i + j] + carry;
            result[i + j] = product % base;
            carry = product / base;
        }
        result[i + n.size] += carry;
    }

    Number resNum;
    resNum.data = result;


    resNum.capacity = resSize;
    return resNum;
}


static Number factorial(int n) 
{
    Number result = 1;
    for (int i = 2; i <= n; ++i) 
    {
        result = result*Number(i);
    }
    
    return result;

}

};

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    // Печатаем самый большой разряд
    stream << static_cast<int>(num.data[num.size - 1]);

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw используются для того, чтобы замостить ноликом, элемент будет меньше чем 10.
    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.size - 2 - i]);

    return stream;
}

#include <iostream>
int main() 
{
    int n = 100;

    Number fact = Number::factorial(n);
    
    std::cout << fact << std::endl;

    return 0;
}