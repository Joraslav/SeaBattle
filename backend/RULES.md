# Правила разработки

## Требования к напасинаю переменных

Все переменные именуются в стиле snake_case. Пример:

- локальная переменная:

```cpp
int snake_case = 10;
```

- переменная структуры:

```cpp
struct Struct {
    int snake_case = 10;
};
```

- private переменная:

```cpp
class Class {
private:
    int snake_case_ = 10;
};
```

- наименование функции:

```cpp
void FuncName(int param){}
```

## Требования к написанию комментариев и документации

К каждой функции, классу и глобальной переменной должно прилагаться описание в стиле оформления doxigen.
Примеры:

- описание глобальной переменной:

```cpp
/**
 * @breif Глобальная переменная
*/
constexpr int GLOBAL_VAR = 10;
```

- описание шаблонной функции:

```cpp
/**
 * @breif Шаблонная функция
 * @tparam T Тип параметра
 * @param param Параметр
 * @return Возвращаемое значение
*/
template<typename T>
T TemplateFinc(const T& param) {
    return param;
}
```

- описание класса:

```cpp
/**
 * @breif Класс
*/
class Class {
public:
    /**
     * @breif Конструктор
     */
    Class() {}

    /**
     * @breif Деструктор
     */
    ~Class() {}
};
```
