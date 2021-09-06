#include <iostream>
#include "queue.h"
#include <queue>

int main()
{
	std::cout << "std::queue has push(), pop(), _pop, front(), size()\n"
		std::cout << "\n test own queue";

	ADS101::queue<char> queue1;
	queue1.push('a');
	queue1.push('b');
	queue1.push('c');
	auto ch = queue1.front();
	std::cout << "queue.front() = " << ch << std::endl;
	queue1.pop();
	queue1.pop();
	queue1.push('a');
	std::cout << "queue size = " << queue.size() << std::endl;

	std::cout << "\n Testing std::queue...\n";

	std::queue<char> queue2;
	queue2.push('a');
	queue2.push('b');
	queue2.push('c');
	ch = queue2.front();
	std::cout << "queue front = " << ch << std::endl;
	queue2.pop();
	queue2.pop();
	queue2.push('a');
	std::cout << "queue size = " << queue2.size() << std::endl;
	std::cin >> ch;
	return 0;
}