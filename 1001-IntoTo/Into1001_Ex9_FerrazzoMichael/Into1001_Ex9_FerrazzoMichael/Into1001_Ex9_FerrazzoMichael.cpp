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
        std::cout << num[i] << std::endl;
    }

    std::cout << "What number would you like to search for: ";              
    std::cin >> number;

    int left = 0, right = 99;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (num[mid] < number)
        {
            left = mid + 1;
        }
        else if (num[mid] > number)
        {
            right = mid - 1;
        }
        else
        {
            std::cout << "Found the number at position" << mid << std::endl;
            break;
        }
    }

    return 0;
}