#include <vector>
#include <string>


struct PimpleStruct {
    int link_num = 1;
    std::vector<char> str;

    PimpleStruct() = default;
    ~PimpleStruct() = default;
};

struct PimpleStruct;

class String {
public:
    class Proxy;
    String();
    String (const char *str);
    String(const String &tmp);
    const String& operator+=(const std::string &tmp);
    String &operator= (const String &tmp);
    ~String();
    char operator[](int i) const;
    Proxy operator[](int i);
    operator std::string() const;

private:
    PimpleStruct *data;
};

class String::Proxy{
    char item;
    int ind;
    String *owner;
public:
    Proxy(char c, int ind, String* tmp) : item{c}, ind{ind}, owner{tmp} {};

    Proxy (const Proxy &tmp) : item{tmp.item}, ind{tmp.ind}, owner{tmp.owner} {};

    operator char () const {
        return item;
    }
    Proxy& operator=(char c) {
        auto data = owner->data;
        if (data->link_num != 1) {
            --data->link_num;
            auto *data_tmp = new PimpleStruct();
            for(auto &i : data->str) {
                data_tmp->str.emplace_back(i);
            }
            owner->data = data_tmp;
        }
        owner->data->str[ind] = c;
        return *this;
    }
    ~Proxy()= default;
};

String::String() : data(new PimpleStruct){}

String::String(const char *str) {
    data = new PimpleStruct();
    std::string s{str};
    for(auto &i : s) {
        data->str.emplace_back(i);
    }
}

String::String(const String &tmp) {
    tmp.data->link_num++;
    data = tmp.data;
}

const String& String::operator+=(const std::string &tmp) {
    if (data->link_num != 1) {
        --data->link_num;
        auto *data_tmp = new PimpleStruct();
        for(auto &i : data->str) {
            data_tmp->str.emplace_back(i);
        }
        data = data_tmp;
    }
    for(auto &i : tmp) {
        data->str.emplace_back(i);
    }
    return *this;
}

String& String::operator=(const String &tmp)  {
    if (this != &tmp) {
        --data->link_num;
        if (!data->link_num) {
            delete data;
        }
        tmp.data->link_num++;
        data = tmp.data;
    }
    return *this;
}

String::~String(){
    --data->link_num;
    if (!data->link_num) {
        delete data;
    }
}

char String::operator[](int ind) const {
    return data->str[ind];
}

String::Proxy String::operator[](int ind) {

    return Proxy(data->str[ind], ind, this);
}

String::operator std::string() const{
    std::string ans;
    for (auto &i : data->str) {
        ans += i;
    }
    return ans;
}