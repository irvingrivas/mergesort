#include <iostream>
#include <vector>

void merge(std::vector<int>& v_in, std::vector<int>& v_out, int leftStart, int leftEnd, int rightStart, int rightEnd);
void mergesort(std::vector<int>& v_in, std::vector<int>& v_out, int leftStart, int rightEnd);

int main() {

    std::vector<int> v_in({ 10, 5, 20, 4, 2, 1, 3, 7, 5, 6, 1, 3, 4, 3, 2 });
    std::vector<int> v_out(v_in);

    mergesort(v_in, v_out, 0, v_in.size() - 1);

    for (int elem : v_in)
        std::cout << elem << " ";
    std::cout << std::endl;

    return 0;
}

void mergesort(std::vector<int>& v_in, std::vector<int>& v_out, int leftStart, int rightEnd) {

    if (leftStart >= rightEnd)
        return;

    int leftEnd = leftStart + (rightEnd - leftStart)/2;
    int rightStart = leftEnd + 1;

    mergesort(v_in, v_out, leftStart, leftEnd);
    mergesort(v_in, v_out, rightStart, rightEnd);
    merge(v_in, v_out, leftStart, leftEnd, rightStart, rightEnd);
}

void merge(std::vector<int>& v_in, std::vector<int>& v_out, int leftStart, int leftEnd, int rightStart, int rightEnd) {

    int leftInd = leftStart;
    int mainInd = leftStart;
    int rightInd = rightStart;

    while (leftInd <= leftEnd && rightInd <= rightEnd)
        if (v_in[leftInd] <= v_in[rightInd])
            v_out[mainInd++] = v_in[leftInd++];
        else
            v_out[mainInd++] = v_in[rightInd++];

    while (leftInd <= leftEnd)
        v_out[mainInd++] = v_in[leftInd++];

    while (rightInd <= rightEnd)
        v_out[mainInd++] = v_in[rightInd++];

    for (int i = leftStart; i <= rightEnd; ++i)
        v_in[i] = v_out[i];
}
