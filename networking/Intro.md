5 layer model to understand how network devices communicate

1. Physical Layer
2. Data Link Layer(network interface or the network access layer)
3. Network Layer(internet layer)
4. Transport Layer
5. Application Layer

*** Mental Model ***
Think of layers like different aspects of a package being delivered. 

The physical layer is the delivery truck and the roads. 

The data link layer is how the delivery trucks get from one intersection to the next over and over. 

The network layer identifies which roads need to be taken to get from address A to address B. 

The transport layer ensures that delivery driver knows how to knock on your door to tell you your package has arrived. 

And the application layer is the contents of the package itself.

In addition to the five layer model we are working with, it’s important to note that other models exist. The traditional TCP/IP Model only has four layers, as it doesn’t differentiate between the physical layer and the data link layer, but is otherwise very similar to the one we’ll be working with. The most well known other model is the OSI model. It’s the model taught by many other networking certificate programs, like Net+ and Cisco’s many networking certifications. The primary difference between our five layer model and the seven layer OSI model is that the OSI model abstracts the application layer into three layers total.

*** Detail ***
Physical Layer: It represents the physical devices that interconnect computers. This includes the specifications for the networking cables and the connectors that join devices together along with specifications describing how signals are sent over these connections.

Data Link Layer: While the physical layer is all about cabling, connectors and sending signals, the data link layer is responsible for defining a common way of interpreting these signals, so network devices can communicate. Lots of protocols exist at the data link layer, but the most common is known as Ethernet, although wireless technologies are becoming more and more popular. Beyond specifying physical layer attributes, the Ethernet standards also define a protocol responsible for getting data to nodes on the same network or link.

Network Layer: It's this layer that allows different networks to communicate with each other through devices known as routers. A collection of networks connected together through routers is an internetwork, the most famous of these being the Internet. Hopefully you've heard of it. While the data link layer is responsible for getting data across a single link, the network layer is responsible for getting data delivered across a collection of networks. Think of when a device on your home network connects with a server on the Internet. It's the network layer that helps gets the data between these two locations. The most common protocol used at this layer is known as IP or Internet Protocol. IP is the heart of the Internet and most small networks around the world. Network software is usually divided into client and server categories, with the client application initiating a request for data and the server software answering the request across the network.

Transport Layer: While the network layer delivers data between two individual nodes, the transport layer sorts out which client and server programs are supposed to get that data. When you heard about our network layer protocol IP, you may have thought of TCP IP, which is a pretty common phrase. That's because the protocol most commonly used in the fourth layer, the transport layer, is known as TCP or Transmission Control Protocol. While often said together as the phrase TCP IP, to fully understand and troubleshoot networking issues, it's important to know that they're entirely different protocols serving different purposes. Other transfer protocols also use IP to get around, including a protocol known as UDP or User Datagram Protocol. The big difference between the two is that TCP provides mechanisms to ensure that data is reliably delivered while UDP does not.

Application Layer: There are lots of different protocols at this layer, and as you might have guessed from the name, they are application-specific. Protocols used to allow you to browse the web or send receive email are some common ones. The protocols at play in the application layer will be most familiar to you, since they are ones you probably interacted with directly before even if you didn't realize it.








