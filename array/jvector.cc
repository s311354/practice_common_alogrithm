#include "./jvector.h"
#include <iostream>

namespace common {
    

Jvector::Jvector(int capacity) : size(0) {
    if (capacity < 1) {
        std::cout << "Cannot make vector of that size" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int Jvector::DeterminesCapacity(int capacity) const {
    int ture_capacity = kMincapacity;

    while (capacity > ture_capacity / kGrowthFactor) {
        ture_capacity *= kGrowthFactor;
    }

    return ture_capacity;
}

void Jvector::ResizeForSize(int candidate_size) {
    if (size < candidate_size) {
        if (size == capacity) {
            IncreaseSize();
        }
    } else if (size > candidate_size) {
        if (size < capacity / kShrinkFactor) {
            DecreasesSize();
        }
    } // nothing need to happen otherwise
}

void Jvector::IncreaseSize() {
    int old_capacity = capacity;
    int new_capacity = DeterminesCapacity(old_capacity);

    if (old_capacity != new_capacity) {
        std::unique_ptr<int[]> new_data(new int[new_capacity]);

        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        data = std::move(new_data);
        capacity = new_capacity;
    }
}

void Jvector::DecreasesSize() {
    int old_capacity = capacity;
    int new_capacity = old_capacity / 2;

    if (new_capacity < kMincapacity) {
        new_capacity = kMincapacity;
    }

    if (new_capacity != old_capacity) {
        std::unique_ptr<int []> new_data(new int[new_capacity]);

        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        data = std::move(new_data);
        capacity = new_capacity;
    }
}

int Jvector::GetSize() const { return size; };
bool Jvector::IsEmpty() const { return size == 0; };
int Jvector::GetCapacity() const { return capacity; };

void Jvector::DebugString() const {
    std::cout << "size: " << size << std::endl
            << "capacity: " << capacity << std::endl
            << "items: " << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cout << "Index: "<< i << " Data: " << data[i] << std::endl;
    }
}

void Jvector::Push(int value) {
    ResizeForSize(size + 1);

    data[size] = value;
    ++ size;
}

int Jvector::Pop() {
    if (size == 0) {
        std::cout << "Nothing to pop" << std::endl;
        exit(EXIT_FAILURE);
    }

    ResizeForSize(size -1);

    int value = data[size -1];
    --size;

    return value;
}

int Jvector::GetValueAt(int index) const {
    if (index < 0 or index > size){
        std::cout << "Index out of bpunds" << std::endl;
        exit(EXIT_FAILURE);
    }

    return data[index];
}

void Jvector::Insert(int index, int value) {
    if (index < 0 or index >= size) {
        std::cout << "Index out of bounds." << std::endl;
        exit(EXIT_FAILURE);
    }

    ResizeForSize(size + 1);

    // shift items to right
    for (int i = size; i > index; --i) {
        data[i] = data[i -1];
    }

    // insert item
    data[index] = value;

    ++size;
}

void Jvector::Deletes(int index) {
    if (index < 0 or index > size) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    ResizeForSize(size -1);

    //shift items to the left
    for (int i = index; i < size - 1 ; ++i) {
        data[i] = data[i+1];
    }

    --size;
}

void Jvector::Prepends(int value) {Insert(0, value) ;};

void Jvector::Remove(int value) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) {
            Deletes(i);
            --i;
        }
    }
}

int Jvector::Find(int value) const {
    int found_index = -1;

    for (int i = 0; i < size; ++i) {
        if (data[i] == value) {
            found_index = i;
            break;
        }
    }

    return found_index;
}

} /* namespace common */
