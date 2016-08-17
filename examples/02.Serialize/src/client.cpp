#include <iostream>
#include <cereal/archives/binary.hpp>
#include <sstream>

struct MyClass {
  MyClass() : x(1), y(2), z(3) {}

  int x, y, z;

  template<class Archive>
  void serialize(Archive &archive) {
    archive(x, y, z);
  }
};

int main(int argc, char *argv[]) {

  std::stringstream ss; // any stream can be used

  {
    cereal::BinaryOutputArchive oarchive(ss); //create an output archive

    MyClass m1, m2, m3;
  std::cout << m1.x << m1.y << m1.z << std::endl;
    oarchive(m1, m2, m3); // Write the data to the archive

  } //archive goes out of scope, ensuring all contents are flushed

  cereal::BinaryInputArchive iarchive(ss); // Create an input archive

  MyClass m1, m2, m3;
  iarchive(m1, m2, m3); // Read the data from the archive

  std::cout << m1.x << m1.y << m1.z << std::endl;
}
