class Parent
{
public:
    int m_public;
private:
    int m_private;
protected:
    int m_protected;
};

class Priv : private Parent // закрите спадкування
{
    // Закрите спадкування означає, що:
    // - public-члени стають private (m_public тепер private) в дочірньому класі;
    // - protected-члени стають private (m_protected тепер private) в дочірньому класі;
    // - private-члени залишаються недоступними (m_private недоступний) в дочірньому класі.
public:
    Priv()
    {
        m_public = 1; // дозволено: m_public тепер private в Priv
        m_private = 2; // заборонено: дочірні класи не мають доступу до закритих членів батьківського класу
        m_protected = 3; // дозволено: m_protected тепер private в Priv
    }
};

int main()
{
    Parent parent;
    parent.m_public = 1; // дозволено: m_public доступний ззовні через батьківський клас
    parent.m_private = 2; // заборонено: m_private недоступний ззовні через батьківський клас
    parent.m_protected = 3; // заборонено: m_protected недоступний ззовні через батьківський клас

    Priv priv;
    priv.m_public = 1; // заборонено: m_public недоступний ззовні через дочірній клас
    priv.m_private = 2; // заборонено: m_private недоступний ззовні через дочірній клас
    priv.m_protected = 3; // заборонено: m_protected недоступний ззовні через дочірній клас
}