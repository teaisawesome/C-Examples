# Objektum Orientált Programozás - C++ alapokon 
## Note - Másolókonstruktor
```cpp
IntFifo(const IntFifo& fifo);
```
A másolókonstruktor esetében az újonnan létrehozott objektumot egy már meglévő objektum alapján inicializáljuk,célunk egy másolat létrehozása.

A másolókonstruktornak ugyanakkor van egy másik funkciója. Amikor érték szerint adunk át egy függvényparamétert, akkor mintegy a függvényhívás részeként lemásolódik az átadott változó, a függvénytörzsben azt használjuk, majd amikor kilépünk a függvényből, akkor felszabadul. Ezt a fordító automatikusan megoldja helyettünk. Ebből jön az, hogy az érték szerinti paraméterátadás esetén a függvény törzsében végrehajtott változtatások nem érintik az argumentumként átadott változót. **Ha azt szeretnénk, hogy változzon, akkor C-ben pointert, C++-ban pedig referenciát adunk át.**

Ha nem írunk másolókonstruktort, akkor bitenkénti másolásról másnéven **sekény másolásról (shallow copy)** beszélünk. A dinamikus adattagok másolását **mély másolásnak (deep copy)** nevezzük.

## Note - Tagváltozó inicializálás
Az inicializálás és az ertékadás C++-ban megkülönböztetjük.

**Inicializálás:**
```cpp
int i = 0; //konstruktorhívás
Point p1(10, 20); //konstruktorhívás
Point p2 = 10; //konstruktorhívás
```
**Értékadás:**
```cpp
int i;
i = 0; //értékadás
Point p; //konstruktorhívás
p = 2; //értékadás
```
