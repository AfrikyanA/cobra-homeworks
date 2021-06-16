template <typename T>
void bubbleSort(T* arr, size_t size){
    for (int i = 0; i < size; ++i){
        for (int j = size-1; j > i; --j){
            if(arr[j] < arr[j-1]){
                std::swap(arr[j], arr[j-1]);
            }
        }
    }
}