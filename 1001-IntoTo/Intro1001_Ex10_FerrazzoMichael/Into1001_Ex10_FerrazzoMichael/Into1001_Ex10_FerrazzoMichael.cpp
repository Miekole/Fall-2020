#include <iostream>
#include <time.h>



int main()
{
    int number;
	int num[100];
	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		num[i] = rand();
	}

    int carry = 0;
    int flag = 0;

    while (flag == 0)
    {
        flag = 1;
        for (int counter = 0; counter < 100 - 1; counter++)
        {
            if (num[counter] > num[counter + 1])
            {
                carry = num[counter];
                num[counter] = num[counter + 1];
                num[counter + 1] = carry;
                flag = 0;
            }

        }

    }

    for (int i = 0; i < 100; i++)
    {
        if ((num[i] % 5) == 0)
        std::cout << num[i] << std::endl;
    }

    std::cout << "Press Enter when you are finnished.\n";              
    std::cin.get();

    for (int i = 0; i < 100; i++)
    {
        delete[] &num[i];
    }
    delete[] num;

    return 0;
}