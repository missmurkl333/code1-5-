#include <iostream>
#include <vector>
#include <Windows.h>


int product_of_elements_with_even_indices(const std::vector<int>& array) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int product = 1;
    for (int i = 0; i < array.size(); i += 2) {
        product *= array[i];
    }
    return product;
}


int sum_between_first_and_last_zeros(const std::vector<int>& array) {
    int sum = 0;
    bool found_first_zero = false;

    for (int i = 0; i < array.size(); ++i) {
        if (array[i] == 0) {
            if (found_first_zero) {
                break;
            }
            else {
                found_first_zero = true;
            }
        }
        else if (found_first_zero) {
            sum += array[i];
        }
    }

    return sum;
}

void transform_array(std::vector<int>& array) {
   
    std::vector<int> positive_elements;
    std::vector<int> negative_elements;

    for (int i = 0; i < array.size(); ++i) {
        if (array[i] >= 0) {
            positive_elements.push_back(array[i]);
        }
        else {
            negative_elements.push_back(array[i]);
        }
    }

    
    array.clear();
    array.insert(array.end(), positive_elements.begin(), positive_elements.end());
    array.insert(array.end(), negative_elements.begin(), negative_elements.end());
}

int main() {
    
    std::vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1, -2, -3, 0, -4, -5 };

    std::cout << "Product of elements with even indices: " << product_of_elements_with_even_indices(array) << std::endl;
    std::cout << "Sum between first and last zeros: " << sum_between_first_and_last_zeros(array) << std::endl;

    transform_array(array);

    std::cout << "Transformed array: ";
    for (int num : array) {
        std::cout << num << " ";
    }

    return 0;
}