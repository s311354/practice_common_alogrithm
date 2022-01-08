#ifndef HASH_OBJECT_H
#define HASH_OBJECT_H
#include <string>

namespace common {

class HashObject
{
private:
    std::string key_;
    std::string value_;

public:
    HashObject() {};
    HashObject(const HashObject &) {};
    HashObject &operator=(const HashObject &);
    virtual ~HashObject() {};

    std::string &Getkey() { return key_; };
    std::string &GetValue() { return value_; };

    void SetKey(const std::string key) { key_ = key;};
    void SetValue(const std::string value) { value_ = value;};

    static const std::string GetDummyKey() { return "<Dummy>"; };
    static const std::string GetNullKey() { return "<NULL>";};

    void SetAsDummy() {
        key_ = GetDummyKey();
        value_ = "";
    }

};


} /* namespace common */

#endif /* HASH_OBJECT_H */
