#include <iostream>
#include "./hash_table.h"

namespace common {

/*! \brief Brief function description here
 *
 *  Detailed description
 *
 * \param size Parameter description
 * \return Return parameter description
 */
HashTable::HashTable(const int size) {
    size_ = size;
    data_ = new HashObject[size];
    assert(data_ != nullptr);

    for (int i = 0; i < size; ++i) {
        data_[i].SetKey(HashObject::GetNullKey());
    }
}

HashTable::~HashTable() {delete[] data_;};

/*! \brief Brief function description here
 *
 *  Detailed description
 *
 * \return Return parameter description
 */
void HashTable::Add(HashObject * object) {
    int index = Hash(object->Getkey());
    int original_index = index;
    int dummyIndex = -1;

    bool found = false;
    while (data_[index].Getkey() != HashObject::GetNullKey()) {
        if (data_[index].Getkey() == object->Getkey()) {
            found = true;
            break;
        } else if (data_[index].Getkey() == HashObject::GetDummyKey()) {
            dummyIndex = index;
        }

        index = (index + 1) % size_;

        if (index == original_index) {
            return;
        }

    }

    if (!found && dummyIndex != -1) {
        index = dummyIndex;
    }

    data_[index].SetKey(object->Getkey());
    data_[index].SetValue(object->GetValue());
}

/*! \brief Brief function description here
 *
 *  Detailed description
 *
 * \return Return parameter description
 */
int HashTable::Hash(const std::string key) {
    int hash = 0;

    int key_length = static_cast<int>(key.length());
    for (int i = 0; i < key_length; ++i) {
        hash = hash * 31 + key[i];
    }

    return abs(hash % size_);
}

/*! \brief Brief function description here
 *
 *  Detailed description
 *
 * \return Return parameter description
 */
bool HashTable::Exists(const std::string key) {
    int index = Hash(key);
    int original_index = index;
    bool found = false;

    while (data_[index].Getkey() != HashObject::GetNullKey()) {
        if (data_[index].Getkey() == key) {
            found = true;
            break;
        }

        index = (index + 1) % size_;

        // break out of while loop while traveling one cycle
        if (index == original_index) {
            break;
        }
    }
    return found;
}

/*! \brief Brief function description here
 *
 *  Detailed description
 *
 * \return Return parameter description
 */
const std::string HashTable::Get(std::string key) {
    int index = Hash(key);
    int original_index = index;

    while (data_[index].Getkey() != HashObject::GetNullKey()) {
        if (data_[index].Getkey() == key) {
            return data_[index].GetValue();
        }

        index = (index + 1) % size_;

        if (index == original_index) {
            break;
        }
    }

    return NULL;
}

/*! \brief Brief function description here
 *
 *  Detailed description
 *
 * \return Return parameter description
 */
void HashTable::Remove(const std::string key) {
    int index = Hash(key);
    int original_index = index;

    while (data_[index].Getkey() != HashObject::GetNullKey()) {
        if (data_[index].Getkey() == key) {
            data_[index].SetKey(HashObject::GetDummyKey());
            data_[index].SetValue("");
            break;
        }

        index = (index + 1) % size_;

        if (index == original_index) {
            break;
        }
    }
}

void HashTable::PringDebug() {
    for (int i = 0; i < size_; ++i) {
        std::cout << i << ": " << data_[i].Getkey() << ": " << data_[i].GetValue() << std::endl;
    }

    std::cout << "-----------------------------\n" << std::endl;
}

} /* namespace common */
