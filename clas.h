#pragma once
class Clas {
private:
    int num;
    string b;
    int count;
    float avg;

public:    
      Student stt[30];
      Clas() {}
      void setNum(int nNum) {
          num = nNum;
      }
      void setB(string b) {
          this->b = b;
      }
      void setCount(int nCount) {
          count = nCount;
      }
      void setAvg(float nAvg) {
          avg = nAvg;
      }
      int getNum() {
          return num;
      }
      string getB() {
          return b;
      }
      int getCount() {
          return count;
      }
      float getAvg() {
          return avg;
      }
      Clas operator + (const Clas &clas) {
          for (int i = this->count; i < this->count + clas.count; i++) {
              this->stt[this->count + i] = clas.stt[i];
          }
          this->count += clas.count;
          return *this;
      }
      

};