#include <algorithm>
#include <iostream>
#include <chrono>

void test_array()
{
    // Generate data
    const int SIZE = 1500;
    int data[SIZE];

    for (int c = 0; c < SIZE; ++c)
    {
        data[c] = std::rand() % 256;
    }

    // With sort, the primary loop runs faster; why?
    std::sort(data, data + SIZE);

    auto start = std::chrono::steady_clock::now();

    long sum = 0;

    for (int i = 0; i < 200; ++i)
    {
        // Primary loop
        for (int k = 0; k < SIZE; ++k)
        {
            if (data[k] >= 128)
            {
                sum += data[k];
            }
        }
    }

    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << duration.count() << std::endl;
    std::cout << "sum = " << sum << std::endl;
    std::cin.get();
}
