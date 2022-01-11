#include "./priority_queue.h"

namespace common {

PriorityQueue::PriorityQueue(const int size): capacity_queue(size) 
{
    assert(size > 0 && size < INT_MAX);

    pelement = new PQElement[size];
}

PriorityQueue::~PriorityQueue() { delete [] pelement; };

void PriorityQueue::Insert(const int key, const std::string value)
{
    assert(size < capacity_queue);

    pelement[size].key = key;
    pelement[size].value = value;

    ++size;

    SiftUp(size - 1);
}

void PriorityQueue::Remove(int index)
{
    assert(index > 0 && index < size);

    Swap(index, size -1);
    --size;

    SiftDown(index);
}

int PriorityQueue::GetSize()
{
    return size;
}

bool PriorityQueue::IsEmpty()
{
    return size == 0;
}

PQElement* PriorityQueue::GetMax()
{
    assert(size > 0);

    return & pelement[0];
}


PQElement* PriorityQueue::ExtractMax()
{
    assert(size >0);

    PQElement* max = new PQElement;
    max->key = pelement[0].key;
    max->value = pelement[0].value;

    Swap(0 , size -1);
    -- size;

    SiftDown(0);
    return max;
}

void PriorityQueue::PrintDebug()
{
    for (int i = 0; i < size; ++i) {
        std::cout << i << ": " << pelement[i].key << ":" << pelement[i].value  << std::endl;
    }

    std::cout << "------------" << std::endl;
}



/*! \brief Brief function description here
 *
 *  SiftUp swaps a node that is too large with its parent (thereby moving it up) until it is no larger than the node above it.
 *
 * \param Parameter Parameter description
 * \return Return parameter description
 */
void PriorityQueue::SiftUp(int index)
{
   assert(index < capacity_queue);
   while (index > 0) {
    // Quick sorting
    int parent = (index - 1)/2;

    if (pelement[parent].key < pelement[index].key) {
        Swap(parent, index);
    } else {
        break;
    }

    index = parent;
   }
}

void PriorityQueue::Swap(const int index1, const int index2)
{
    int tmp_key = pelement[index1].key;
    std::string tmp_value = pelement[index1].value;

    pelement[index1].key = pelement[index2].key;
    pelement[index1].value = pelement[index2].value;
    pelement[index2].key = tmp_key;
    pelement[index2].value = tmp_value;
}



/*! \brief Brief function description here
 *
 *  SiftDown swaps a node that is too small with its largest child (thereby moving it down) until it is at least as large as both nodes below it.
 *
 * \param Parameter Parameter description
 * \return Return parameter description
 */
void PriorityQueue::SiftDown(int index)
{
    assert(index < capacity_queue);
    while (index *2 + 1 < size ) {
        int left_child_index = index*2 + 1;
        int right_child_index = index*2 + 2;
        bool has_left_child_index = left_child_index < size;
        bool has_right_child_index = right_child_index < size;
        int swap_index = index;

        if (has_right_child_index && has_left_child_index) {
            if(pelement[left_child_index].key > pelement[right_child_index].key) {
                swap_index = left_child_index;
            } else {
                swap_index = right_child_index;
            }
        } else if (has_left_child_index) {
            swap_index = left_child_index;
        } else if (has_right_child_index) {
            swap_index = right_child_index;
        } else {
            break;
        }


        if(pelement[swap_index].key > pelement[index].key) {
            Swap(swap_index, index);
        } else {
            break;
        }

        index = swap_index;
    }
}

/*! \brief Brief function description here
 *
 *  The heapify procedure can thought of as building a heap from the bottom up by successively sifting downward to establish the heap property.
 *
 * \return None
 */
void heapify(int *numbers, int count)
{
    for (int i = count/2 -1 ; i >= 0; --i) {
        precolate_down(numbers, count, i);

//         std::cout << " ==== Interation: " << i  << " ==== "<< std::endl;
//         for (int j = 0; j < count; ++j) {

//             std::cout << numbers[j] << std::endl;
//         }
    }
}

void precolate_down(int* numbers, int count, int index ) {
    while (index*2 + 1 < count) {
        int swap_index = index;
        int left_child_index = index*2 + 1;
        int right_child_index = index*2 + 2;
        bool has_left_child_index = left_child_index < count;
        bool has_right_child_index = right_child_index < count;

        if (has_left_child_index && has_right_child_index) {
            if(numbers[left_child_index] > numbers[right_child_index]){
                swap_index = left_child_index;
            } else {
                swap_index = right_child_index;
            }
        } else if (has_left_child_index) {
            swap_index = left_child_index;
        } else if (has_right_child_index) {
            swap_index = right_child_index;
        } else {
            break;
        }

        if (numbers[swap_index] > numbers[index]) {
            int tmp = numbers[swap_index];
            numbers[swap_index] = numbers[index];
            numbers[index] = tmp;

            index = swap_index;
        } else {
            break;
        }
    }

}

/*! \brief Brief function description here
 *
 *  Heap sort maintains the unsorted region in a heap data structure to more quickly find the largest element in each step. It is implementated by quicksort alogrithm
 *
 * \return Return parameter description
 */
void heap_sort(int* numbers, int count)
{
    int tmp = 0;
    for (int i = count - 1; i > 0; --i) {
        tmp = numbers[i];
        numbers[i] = numbers[0];
        numbers[0] = numbers[i];
    }

    precolate_down(numbers, count, 0);
}


void print_heap(int *numbers, int count)
{

    for (int i = 0; i < count; ++i) {
        std::cout << numbers[i] << std::endl;
    }

}


} /* namespace common */
