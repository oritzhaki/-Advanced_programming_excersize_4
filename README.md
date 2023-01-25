# Exercise 4
__MultiClient-Server practice__

This program is a multi-client server application that allows multiple clients to interact with a single server simultaneously. The program utilizes a thread pool to handle multiple connections at the same time, and implements the Command design pattern to organize the handling of client requests.

## How it works

The program uses a main thread to listen for incoming connections from clients. When a client connects, a task is added to the thread pool, where it is executed by one of the available threads. This allows the server to handle multiple clients at the same time, and reduces the overhead of creating and destroying threads for each client connection.

The Command design pattern is used to organize the handling of client requests. Each client request is wrapped in a command object, which is then executed by the appropriate handler. This allows for a clear separation of concerns, and makes it easy to add new functionality or modify existing functionality in the future.

There are 38 files we use in this program-

The client has 5 files:
* client.cpp - Contains the main function that receives arguments from the command line including IP and PORT, creates a client object and runs it. 
* myClient.cpp & myClient.h - client class which receives from the user input including a vector, distance metric and k (num of neighbors).
* clientUtilityFunctions.cpp & clientUtilityFunctions.h - Includes all utility functions that are used by the cllient.

The server has 13 files:
* server.cpp - Contains the main function that receives arguments from the command line including DATAFILE and PORT, creates a server object and runs it. 
* myServer.cpp & myServer.h - server class which receives from the client input icluding a vector, distance metric and k (num of neighbors).
* knn.cpp & knn.h - A class for a KNN model. The model object implements the KNN algorithm for training and prodiction of data. The model predicts the new label according to the most popular label of the K closest (by distance) neighbors. The object has a Distance Metric and data Reader as members.
* distance.cpp & distance.h - A class for Distances object which is an object that can find the difference between two vectors according to a certain distance metric. 
* reader.cpp & reader.h - A class for a Reader object which is an object that reads data and translates it into a vector of features and a vector of labels, ready for the KNN object to use. The Reader reads from a specific csv data file which includes lines in the format of: {x1, x2, ..., xn, y} where xi are the features of a sample and y is the label.
* distanceMetrics.cpp & distanceMetrics.h - Includes the distance functions from Excercise 1. 
* serverUtilityFunctions.cpp & serverUtilityFunctions.h- Includes all utility functions that are used by the server.

The Command design pattern has 15 files:
* CLI.cpp & CLI.h - Responsible for interpreting user input and converting it into command objects that can be executed.
* command.h - Abstact class where all command* classes inherit from. Like an interface of all commands.
* command*.h - Each file contains it's own special command class (of the 8 commands that are shown in the server's menu) and it's methods declarations.
* command*.cpp - Each file contains the implementation of each command's methods.
* varHolder.cpp & varHolder.h - A class where it's instance will be a member in all the command in order to be able to share information between all commands.

The IO has 3 files:
* DefaultIO.h - An abstuct class using for input output. All IO inherit from this class. It is like an interface of all IOs. 
* SockectIO.cpp & Socket.h - input and output functionality that is specifically designed for use with network sockets. SocketIO provides a way to communicate with a server using a web socket.

## How to run
The correct input from the command line for client: ./client.out IP PORT where IP is the form of A.B.C.D, where A B C D are numbers from 0-255 (The numbers cannot be 0 prefixed unless they are 0) and IP is an int between 1024 and 65535.
The correct input from the command line for server: ./server.out PORT where PORT is an int between 1024 and 65535.

Before you run the program, you need to build it: 
```
make
```

To run the program, you need to open three separate terminal windows.

## Running the Server
1. Open a terminal window.
2. Navigate to the directory where the server file is located.
3. Run the command: `./server.out PORT` e.g. `./server.out 8888`
4. The server will start running and will be ready to accept connections from clients.

## Running the Clients
1. Open another terminal window.
2. Navigate to the directory where the client file is located.
3. Run the command: `./client.out IP PORT` e.g. `./client.out 127.0.0.1 8888`
4. The client will connect to the server. Repeat steps 1-3 for each additional client that you want to connect.
5. The client will follow the instructions that are shown in the menu from the server as explained below.

**Note**: Make sure the server is running before starting the clients and that client connects to the same port as server.

## Example for client interaction with server's menu:

The server will present the client with a menu of 6 options. The client can select one of the options by entering the corresponding number. The server will then execute the command associated with the selected option. The server will then present the menu again and repeat this process. To end the interaction between the server and the client, the user should enter 8, which corresponds to the last command.
All other input is considered invalid.


The user will see the following menu:

![image](https://user-images.githubusercontent.com/118104474/214587711-15b0a355-0337-4f46-a64b-d9ecf7204638.png)

Now the user needs to choose the option from the menu he wants to be execute. 
**If 1 is chosen ->**
user will write a valid path of his local train data and then another path of his local test data like this:
```
1
```
>Please upload your local train CSV file.
```
/train_path
```
>Upload complete.>Please upload your local test CSV file.
```
/train_path
```
>Upload complete.

**If 2 is chosen ->** 
user will see the current k and metric. if he press enter the current values stay the same, if you want to edit you insert your updates like this:
```
K METRIC
```
or
```
METRIC K
```
where k is a positive number that is smaller then number of samples in train set and k is one of the 5 distance metrics- AUC MAN CUB CYB 

**If 3 is chosen ->**
the data will get classified.

**If 4 is chosen ->**
you will see the results of classification.

**If 5 is chosen ->** 
you need to insert a local path to download the results of classification. Like this:
```
/path
```
where path could be `results.csv.`

**If 8 is chosen ->** 
client disconnect from server.


In general, the user needs to choose the option and to insert valid input according to the server's requests.


