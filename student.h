#pragma once
class Student {
private:
    string fio;
    static int count;
public:
    Attestat att;
    Student() { }
    void setFio(string fio) {
        this->fio = fio;
    }
    static void setCount(int n) { count += n; }
    string* getFio() {
        return &fio;
    }
    int getCount() { return count; }
};
    