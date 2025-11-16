class Parent
{
public:
    int m_public;
private:
    int m_private;
protected:
    int m_protected;
};

class Pub : public Parent // відкрите спадкування
{
    // Відкрите спадкування означає, що:
    // - public-члени залишаються public в дочірньому класі;
    // - protected-члени залишаються protected в дочірньому класі;
    // - private-члени залишаються недоступними в дочірньому класі.
public:
    Pub()
    {
        m_public = 1; // дозволено: доступ до m_public відкритий
        m_private = 2; // заборонено: доступ до m_private в дочірньому класі з батьківського класу закритий
        m_protected = 3; // дозволено: доступ до m_protected в дочірньому класі з батьківського класу відкритий
    }
};

int main()
{
    Parent parent;
    parent.m_public = 1; // дозволено: m_public доступний ззовні через батьківський клас
    parent.m_private = 2; // заборонено: m_private недоступний ззовні через батьківський клас
    parent.m_protected = 3; // заборонено: m_protected недоступний ззовні через батьківський клас

    Pub pub;
    pub.m_public = 1; // дозволено: m_public доступний ззовні через дочірній клас
    pub.m_private = 2; // заборонено: m_private недоступний ззовні через дочірній клас
    pub.m_protected = 3; // заборонено: m_protected недоступний ззовні через дочірній клас
}