#include <iostream>

template <typename T, size_t N>
void temp_print(const T (&arr)[N]) {
	for(size_t i = 0; i < N; i++) {
		std::cout << arr[i] << std::endl;
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	temp_print(arr);
	return 0;
}
