template <typename Iter>
void selectionSort(Iter begin, Iter end){
    for (; begin != end; ++begin){
        Iter min = std::min_element(begin,end);
        std::swap (*begin, *min);
    }
}