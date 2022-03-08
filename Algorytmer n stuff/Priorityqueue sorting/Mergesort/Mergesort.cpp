

//14, 33, 12, 4, 7, 19, 29, 11, 21, 17,
//14, 33, 4, 12, 7, 19, 11, 29, 17, 21,
//4, 12, 14, 33, 7, 11, 19, 29, 17, 21,
//4, 7, 11, 12, 14, 19, 29, 33, 17, 21,
//4, 7, 11, 12, 14, 17, 19, 21, 29, 33,
// 
//a) Forklar hvordan tallene er sortert, og hvilken algoritme som er benyttet.
// 
// Det er flettesortering som er brukt. Til andre linje er to og to tall flettet
//sammen, slik at alle subarrayer av lengde 2 er sortert.Deretter flettes disse
//sammen til subarrayer av lengde 4, og dette gjentas slik at vi har en subarray
//av lengde 8 (og en av lengde 2) i nest siste linje, siden arraylengde 10 ikke er en
//potens av 2. Til slutt flettes disse to.
// 
//b) Skriv kode hvor du bruker std::priority_queue til å sortere de samme
//tallene(14, 33, 12, 4, 7, 19, 29, 11, 21, 17) i avtakende rekkefølge.
#include <iostream>
#include <queue>
#include <set>
int main()
{
	int a[]{ 14, 33, 12, 4, 7, 19, 29, 11, 21, 17 };
	std::priority_queue<int> pq;
	for (int i = 0; i < 10; i++)
	{
		pq.push(a[i]);
	}
	while (!pq.empty())
	{
		std::cout << pq.top() << ", ";
		pq.pop();
	}
}

