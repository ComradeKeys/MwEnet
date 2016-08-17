#include <iostream>
//#include <>

struct MyClass {
  int x, y, z;

  template<class Archive>
  void serialize(Archive &archive) {
    archive(x, y, z);
  }
};

int main(int argc, char *argv[]) {


}
