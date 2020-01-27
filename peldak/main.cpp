
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

