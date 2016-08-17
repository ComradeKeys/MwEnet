Roadmap for MwENet
==================
- It has not yet been decided if the wrapper will be renamed or not, this is a pretty minor issue however. A motivation to rename would be primarily the fact that the header file names are very ambiguous and they can be confusing. There is plans to change the name of the header files regardless of it renaming or not.

- An integration with some kind of serialization might be nice, however it does not make too much sense to include it in this library. However we should guide a lot of misguided people and tell them about serialization since most do not know about it. We could definately come up with an example where we serialize something and send it over the network though.

- The API needs to be documented, there is almost no documentation to be found at all for this wrapper. Doxygen will be used to create documentation for this wrapper and I will host it on doc.bkeys.org, once I do this I need to mention it on the readme
  These header files (inside the include/ directory) still need to be documented, however documentation can always be improved
  - enetclient.h
  - enetserver.h
  - packet.h
  - server.h

- A few interfaces might be broken, the wrapper should be written in such a way that if someone wants all the fine details of ENet exposed to them we can give it to them. The original README mentioned that this is not a complete wrapper for ENet so we should try to change that.

- I might of broken the windows build for this thing by including the threading (which should of been there in the first place), before a release is made the build needs to be tested on as many platforms as possible.
