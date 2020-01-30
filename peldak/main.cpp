
// -- void pointer
//However, because the void pointer does not know what type of object it is pointing to,
//it cannot be dereferenced directly! Rather, the void pointer must first be explicitly cast
//to another pointer type before it is dereferenced.
int fun(void* param)
{
   return *param; // NEM JÓ
   
   int *temptr = static_cast<int*>(param);
   return *temptr; // OK - dereferencia
}
// ha meg akarjuk tudni a típusát akkor írunk pl. enum típusokat és 2. argumentumként bekérjük a típust, majd a függvénybe az alapján
// dobjuk vissza az értéket, amelyet képvisel.

/*---pointerek, referenciák, konstruktorok, operatorok---*/

// referenciát tartalmazó konstruktor 
class A
{
   int a;
   int& b;
   
   A(int i = 0) : a(i), b(a) {}
   
   // saját copy assignment operator
   A& operator=(const A& param)
   {
      a = param.a;
      b = param.b;
      return *this;
   }
};

int main()
{
   A a;
   B b;
   
   a = b; // error: nem tudja kezelni a default assignment operátor a non-static ref miatt ezért sajátot kell, hogy írjunk!
}

/* --- TEMPLATES ---*/
// Example program
#include <iostream>
#include <string>

template <class C>
class A
{
  private:
    C x, y;
  public:
    A(C x1, C y1) :  x(x1), y(y1)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const A<C>& a)
    {
        os << a.x << " " << a.y << std::endl;
    
        return os;
    }
    
    A(const A& a) : x(a.x), y(a.y)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    
    A& operator=(const A& a)
    {
        this->x = a.x;
        this->y = a.y;
         std::cout << __PRETTY_FUNCTION__ << std::endl;
        
        
        return *this;
    }
};


template <typename T>


void swap(T &t1, T &t2)
{
    T temp = t1;
    t1 = t2;
    t2 = temp;
}


int main()
{
      double a = 5.1; double b = 0.10;
      std::cout << a << " " << b << std::endl;
      swap(a, b);
      std::cout << a << " " << b << std::endl;
      
      A<int> c(1, 2);
      A<int> d(10, 5);
      
      A<int> e = c;
      
      c = d;
      
}

// --- Move szemantika a felső példa alapján. --- //
// Example program
#include <iostream>
#include <string>
#include <typeinfo>

template <class C>
class A
{
  private:
    C x, y;
  public:
    A(C x1, C y1) :  x(x1), y(y1)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const A<C>& a)
    {
        os << a.x << " " << a.y << std::endl;
    
        return os;
    }
    
    A(const A& a) : x(a.x), y(a.y)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    
    A& operator=(const A& a)
    {
        this->x = a.x;
        this->y = a.y;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        
        
        return *this;
    }
    
    A(A&& a)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        x = a.x;
        y = a.y;
        
        a.y = 0;
        a.x = 0;
    }
    
    A& operator=(A&& e)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        
        x = e.x;
        y = e.y;
        
        e.y = 0;
        e.x = 0;
        
        return *this;
    }

};

template <typename F>
A<F> getback(A<F> b)
{
    return b;
}

template <typename T>


void swap(T &t1, T &t2)
{
    T temp = t1;
    t1 = t2;
    t2 = temp;
}


int main()
{
      double a = 5.1; double b = 0.10;
      std::cout << a << " " << b << std::endl;
      swap(a, b);
      std::cout << a << " " << b << std::endl;
      
      A<int> c(1, 2);
      A<int> d(10, 5);
      
      A<int> e = c;
      
      c = d; // sima másoló assigment 
        
      A<int> f = getback(c); // getback egy értéket kap, majd azzal tér vissza -> ez a függvény törzsbe ideiglenesen van jelen. ->
      //mivel megírtuk a move constructort ezért az fog lefutni - A<C>::A(A<C>&&) [with C = int]
      
      c = getback(c); // move assignment fog lefutni -> A<C>& A<C>::operator=(A<C>&&) [with C = int]
}

