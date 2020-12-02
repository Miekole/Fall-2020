#include <iostream>
#include <fstream>

int twoH, threeH, fourH, fiveH, sixH, sevenH, eightH, nineH, tenThou;

int main()
{
	const int ISIZE = 10, DSIZE = 10;
	int fixedAmount[ISIZE] = {200, 400, 600, 150, 500, 600, 450, 800, 1000, 500};
	int salesArray [DSIZE];
	int twoH = 0, threeH = 0, fourH = 0, fiveH = 0, sixH = 0, sevenH = 0, eightH = 0, nineH = 0, tenThou = 0;
	std::ifstream file("data.txt");

	if (!file) {
		std::cout << "error, could not open the data file\n";
	}
	else
	{

		for (int i = 0; i < 10; i++)
		{
			file >> fixedAmount[i];
			file >> salesArray[i];
			if ((fixedAmount[i] + (0.05 * salesArray[i])) >= 200 && (fixedAmount[i] + (0.05 * salesArray[i])) <= 299){
				twoH += 1;
			}

			else if ((fixedAmount[i] + (0.05 * salesArray[i])) >= 300 && (fixedAmount[i] + (0.05 * salesArray[i])) <= 399){
				threeH += 1;
			}

			else if ((fixedAmount[i] + (0.05 * salesArray[i])) >= 400 && (fixedAmount[i] + (0.05 * salesArray[i])) <= 499){
				fourH += 1;
			}

			else if ((fixedAmount[i] + (0.05 * salesArray[i])) >= 500 && (fixedAmount[i] + (0.05 * salesArray[i])) <= 599){
				fiveH += 1;
			}

			else if ((fixedAmount[i] + (0.05 * salesArray[i])) >= 600 && (fixedAmount[i] + (0.05 * salesArray[i])) <= 699){
				sixH += 1;
			}

			else if ((fixedAmount[i] + (0.05 * salesArray[i])) >= 700 && (fixedAmount[i] + (0.05 * salesArray[i])) <= 799){
				sevenH += 1;
			}

			else if ((fixedAmount[i] + (0.05 * salesArray[i])) >= 800 && (fixedAmount[i] + (0.05 * salesArray[i])) <= 899){
				eightH += 1;
			}

			else if ((fixedAmount[i] + (0.05 * salesArray[i])) >= 900 && (fixedAmount[i] + (0.05 * salesArray[i])) <= 999){
				nineH += 1;
			}

			else if ((fixedAmount[i] + (0.05 * salesArray[i])) >= 1000){
				tenThou += 1;
			}
		}
		
		
	}
	file.close();

	std::cout << "$200-299 -> " << twoH << std::endl;
	std::cout << "$300-399 -> " << threeH << std::endl;
	std::cout << "$400-499 -> " << fourH << std::endl;
	std::cout << "$500-599 -> " << fiveH << std::endl;
	std::cout << "$600-699 -> " << sixH << std::endl;
	std::cout << "$700-799 -> " << sevenH << std::endl;
	std::cout << "$800-899 -> " << eightH << std::endl;
	std::cout << "$900-999 -> " << nineH << std::endl;
	std::cout << "$1000+   -> " << tenThou << std::endl;

	return 0;
}