class KeyCombination
{
private:
    int _key1 = 0;
    int _key2 = 0;
    int _key3 = 0;
    int _key4 = 0;

public:
    KeyCombination(int key1, int key2, int key3, int key4)
    {
        _key1 = key1;
        _key2 = key2;
        _key3 = key3;
        _key4 = key4;
    }
    int getKey1()
    {
        return _key1;
    }
    int getKey2()
    {
        return _key2;
    }
    int getKey3()
    {
        return _key3;
    }
    int getKey4()
    {
        return _key4;
    }
};
