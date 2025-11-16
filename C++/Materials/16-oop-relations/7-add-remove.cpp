
void insertBefore(int value, int index)
{
    // Перевірка коректності переданого індексу
    assert(index >= 0 && index <= m_length);

    // Створюємо новий масив на один елемент більше старого масиву
    int* data = new int[m_length + 1];

    // Копіюємо всі елементи аж до index
    for (int before = 0; before < index; ++before)
        data[before] = m_data[before];

    // Додаємо наш новий елемент в наш новий масив
    data[index] = value;

    // Копіюємо всі значення після доданого елементу
    for (int after = index; after < m_length; ++after)
        data[after + 1] = m_data[after];

    // Видаляємо старий масив і використовуємо замість нього новий масив
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void remove(int index)
{
    // Перевірка на коректність переданого індексу
    assert(index >= 0 && index < m_length);

    // Якщо це останній елемент масиву, то робимо масив пустим і виконуємо return
    if (m_length == 1)
    {
        erase();
        return;
    }

    // Створюємо новий масив на один елемент менше нашого старого масиву
    int* data = new int[m_length - 1];

    // Копіюємо всі елементи аж до index
    for (int before = 0; before < index; ++before)
        data[before] = m_data[before];

    // Копіюємо всі значення після видаленого елементу
    for (int after = index + 1; after < m_length; ++after)
        data[after - 1] = m_data[after];

    // Видаляємо старий масив і використовуємо замість нього новий масив
    delete[] m_data;
    m_data = data;
    --m_length;
}

// Декілька додаткових функцій просто для зручності
void insertAtBeginning(int value) { insertBefore(value, 0); }
void insertAtEnd(int value) { insertBefore(value, m_length); }