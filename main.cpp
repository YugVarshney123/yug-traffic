#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <unistd.h> // For sleep function

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

int main() {
    std::unordered_map<int, int> map;

    int arr[4];
    int n = 1;
    while (n != -1) {
        int count = 0;
        std::cout << "Enter traffic count in four lanes" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cin >> arr[i];
            map[arr[i]] = i;
        }

        std::sort(arr, arr + 4);

        for (int i = 0; i < 4; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        long time = 0;
        for (int i = 3; i >= 0; i--) {
            if (arr[i] >= 100) {
                try {
                    time = 6;
                    count++;

                    for (int j = 0; j < 4; j++) {
                        if (j == i) {
                            std::cout << GREEN << " " << (map[arr[j]] + 1) << " Lane  " << RESET;
                        } else if (j == (i - 1)) {
                            std::cout << YELLOW << " " << (map[arr[j]] + 1) << " Lane  " << RESET;
                        } else {
                            std::cout << RED << " " << (map[arr[j]] + 1) << " Lane  " << RESET;
                        }
                    }
                    std::cout << std::endl;
                    sleep(time);
                } catch (std::exception &e) {
                    std::cout << "error occurred in >=100" << std::endl;
                }
            } else if (arr[i] >= 50 && arr[i] < 100) {
                try {
                    count++;
                    time = 4;

                    for (int j = 0; j < 4; j++) {
                        if (j == i) {
                            std::cout << GREEN << " " << (map[arr[j]] + 1) << " Lane  " << RESET;
                        } else if (j == (i - 1)) {
                            std::cout << YELLOW << " " << (map[arr[j]] + 1) << " Lane  " << RESET;
                        } else {
                            std::cout << RED << " " << (map[arr[j]] + 1) << " Lane  " << RESET;
                        }
                    }
                    std::cout << std::endl;
                    sleep(time);
                } catch (std::exception &e) {
                    std::cout << "error occurred in >=50 and <100" << std::endl;
                }
            } else if (arr[i] < 50) {
                try {
                    count++;
                    time = 3;

                    for (int j = 0; j < 4; j++) {
                        if (j == i) {
                            std::cout << GREEN << " " << (map[arr[j]] + 1) << " Lane  " << RESET;
                        } else if (j == (i - 1)) {
                            std::cout << YELLOW << " " << (map[arr[j]] + 1) << " Lane  " << RESET;
                        } else {
                            std::cout << RED << " " << (map[arr[j]] + 1) << " Lane  " << RESET;
                        }
                    }
                    std::cout << std::endl;
                    sleep(time);
                } catch (std::exception &e) {
                    std::cout << "error occurred in <50" << std::endl;
                }
            }
        }
        if (count == 4) {
            std::cout << "If you want to run again type 1 otherwise type -1" << std::endl;
            std::cin >> n;
        }
    }

    return 0;
}