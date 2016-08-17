Roadmap for MwENet
==================
- It has not yet been decided if the wrapper will be renamed or not, this is a pretty minor issue however. A motivation to rename would be primarily the fact that the header file names are very ambiguous and they can be confusing. There is plans to change the name of the header files regardless of it renaming or not.

- An integration with some kind of serialization might be nice, however it does not make too much sense to include it in this library. However we should guide a lot of misguided people and tell them about serialization since most do not know about it. We could definately come up with an example where we serialize something and send it over the network though.

- These header files (inside the include/ directory) still need to be documented, however documentation can always be improved. A starting draft of the documentation has been made.  

- A few interfaces wil be broken, the wrapper should be written in such a way that if someone wants all the fine details of ENet exposed to them we can give it to them. The original README mentioned that this is not a complete wrapper for ENet so we should try to change that.

- Header files need to be renamed to something less generic

- A few examples need to be written, such as a chat room, maybe a networked game of tic tac toe, and a serialization example with cereal on sending a struct over the network

- I might of broken the windows build for this thing by including the threading (which should of been there in the first place), before a release is made the build needs to be tested on as many platforms as possible.
