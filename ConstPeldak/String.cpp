#include <iostream>

class String
{
    char* data;
   public:
    String(const char* s)
    {
      data = new char[ strlen(s) + 1 ];
      strcpy(data, s);
    }
    ~String()
    {
      delete[] data;
    }
    //konstans [] operátor tulterhelés -> csak konstansra 
    char operator[](int i) const { return data[i]; }
    // sima [] operátor tulterheles
    char operator[](int i) { return data[i]; }
};

int main()
{
  String s("kiskutya");
  const String cs("kiskutya");
  std::cout << s[0] << std::endl; // 0 elem 
  std::cout << cs[0] << std::endl; // 0 elem const ot után
  
  cs[0] = 'a'; // error -> const
  
  return 0;
}
