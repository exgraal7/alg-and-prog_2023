#include <iostream>

int* new_array(int len, int value);
int set_new_length(int** array, int old_len, int new_len);
int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array);
int dot(const int* a, const int* b, int len);
int* find(int* array, int len, int value);
void delete_array(int** array);

int main(){
    int len_first, len_second,
        first_init_val, second_init_val;
    std::cin >> len_first >> first_init_val >> len_second >> second_init_val;
    int* first  = new_array(len_first, first_init_val);
    int* second = new_array(len_second, second_init_val);
    
    int new_len_first;
    std::cin >> new_len_first;
    len_first = set_new_length(&first, len_first, new_len_first);
    for(int i=0; i < new_len_first; i++){
        int value;
        std::cin >> value;
        first[i] = value;
    }
    
    len_second = merge(&second, len_second, first, len_first);
    
    len_second = set_new_length(&second, len_second, len_first);
    
    int value = dot(first, second, len_first);
    
    int* value_ptr;
    while( (value_ptr = find(second, len_second, value)) != nullptr ){
        *value_ptr = 0;
    }
    
    for (int i=0; i < len_second; i++) std::cout << second[i] << ' ';

    delete_array(&first);
    delete_array(&first);  // Так и задумано
    delete_array(&second);
    delete_array(&second); // Так и задумано
}

// Начало вставленного кода
int* new_array(int len, int value) {
    int* arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = value;
    }
    return arr;
}

int set_new_length(int** array, int old_len, int new_len) {
    int* new_arr = new int[new_len];
    if (new_len < old_len) {
        for (int i = 0; i < new_len; i++) {
            new_arr[i] = (*array)[i];
        }
    } else if (new_len > old_len) {
        for (int i = 0; i < old_len; i++) {
            new_arr[i] = (*array)[i];
        }
        for (int i = old_len; i < new_len; i++) {
            new_arr[i] = 0;
        }
    }
    delete[] *array;
    *array = new_arr;
    return new_len;
}

int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array) {
    int total_len = len_dest_array + len_src_array;
    int* new_arr = new int[total_len];
    for (int i = 0; i < len_dest_array; i++) {
        new_arr[i] = (*dest_array)[i];
    }
    for (int i = len_dest_array, k = 0; i < total_len; i++, k++) {
        new_arr[i] = src_array[k];
    }
    delete[] *dest_array;
    *dest_array = new_arr;
    return total_len;
}

int dot(const int* a, const int* b, int len) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        res += a[i] * b[i];
    }
    return res;
}

int* find(int* array, int len, int value) {
    for (int i = 0; i < len; i++) {
        if (array[i] == value) {
            return &array[i];
        }
    }
    return nullptr;
}

void delete_array(int** array) {
    if (*array == nullptr) {
        return;
    }
    delete[] *array;
    *array = nullptr;
}
// Конец вставленного кода
