MwEnet
======
Server and client class using enet (http://enet.bespin.org/) library and MwExtra. The classes works as a c++ wrapper around enet but it is not a pure wrapper. This library tries to simplify the usage of sending data and is a much simplified way of using the enet library.

It uses C++14 and has no external dependencies, it can use the system ENet libraries but also has it's own bundled version.

The enet version 1.3.13 source is in included in the MwEnet project.
Enet is available under the license (LICENSE) specified in the enet directory.

Free Software
======
The project is under the zlib license (see LICENSE.txt).

The framework is being refractored and documented currently, when released it will be used in such a way that it is placed into your project with other source and then you build on top of the classes to suit your needs. No interfaces are being supported until release.