#include <iostream>
#include <cereal/archives/binary.hpp>
#include <sstream>

struct MyClass {
  int x, y, z;

  template<class Archive>
  void serialize(Archive &archive) {
    archive(x, y, z);
  }
};

struct MyData {
  MyData() : i(1), j(2), k(3) {}
  int i, j, k;
};

int main(int argc, char *argv[]) {

  std::stringstream ss; // any stream can be used

  {
    cereal::BinaryOutputArchive oarchive(ss); //create an output archive

    MyData m1, m2, m3;
    oarvhive(m1, m2, m3); // Write the data to the archive
  } //archive goes out of scope, ensuring all contents are flushed

  cereal::BinaryInputArchive iarchive(ss); // Create an input archive

  MyData m1, m2, m3;
  iarchive(m1, m2, m3); // Read the data from the archive
}
