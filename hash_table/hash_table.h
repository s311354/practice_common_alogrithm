#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "./hash_object.h"
#include "./hash_object.h"

namespace common {

class HashTable
{
private:
    int size_;
    HashObject *data_;

    int Hash(const std::string key);
public:
    // Gold rule is to use explicit keyword for all constructors which can be called with one argument provided unless you want to enable implicit conversion from argument type.
    explicit HashTable(const int size);
    HashTable(const HashObject&) {};
    HashTable &operator=(const HashTable &);
    virtual ~HashTable();

    // Add the given key and object to hash table. If key exists, updated the value
    void Add(HashObject *object);

    // Returns true if the given key exist in the table
    bool Exists(const std::string key);

    // Returns the value associated with the given key, or NULL if it doesn't
    const std::string Get(const std::string key);

    // Remove the value associated with key from the table
    void Remove(const std::string key);

    // Outputs the content of the hash table for debugging purposes
    void PringDebug();

};


} /* namespace common */


#endif /* HASH_TABLE_H */
