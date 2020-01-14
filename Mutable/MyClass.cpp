class MyClass
{
  mutable int accessCount;
  int flag;
public:
  bool GetFlag() const
  {
    // A tagfüggvény konstans, de a következő sor nem hibás, mert az accessCount mutable.
    ++accessCount;
    return flag;
  }
};
