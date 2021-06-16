template <typename Iter>
void insertionSort(Iter begin, Iter end){
    for (auto it = begin; it != end; ++it){
        std::rotate(std::upper_bound(begin, it, *it), it, it+1);
    }
}