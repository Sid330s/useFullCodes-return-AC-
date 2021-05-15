class Test
{
private:
    ~Test() {}

};


int main()
{
    Test t;
    Test *ptr = new Test;

    return 0;
}
