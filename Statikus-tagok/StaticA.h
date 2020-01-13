#pragma once
class StaticA
{
	// változó és statikus változó
	int x;
	static int count;

public:

	StaticA() { count++; }

	~StaticA() { count--; }

	static int GetCount()
	{
		// statikus metódusok csak statikus változókon dolgoznak
		// return x; hiba

		return count;
	}
};
