# Exercise_3
__Client-Server practice__

We created a program that practises client-server interactions and runs KNN algorithm on the server with user input received from the client.

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

The correct input from the command line for client: ./client.out IP PORT where IP is the form of A.B.C.D, where A B C D are numbers from 0-255 (The numbers cannot be 0 prefixed unless they are 0) and IP is an int between 1024 and 65535.
The correct input from the command line for server: ./server.out DATAFILE PORT where DATAFILE is a file with classified data (beans_Classified.csv, iris_classified.csv, wine_Classified.csv) and PORT is an int between 1024 and 65535.
In order to connect between client and server the PORT number should be the same.

The correct input from the user: VECTOR DISTANCE K where VECTOR includes valid numbers separated by spaces, DISTANCE is one of the following metrics- AUC MAN CHB CAN MIN and K is a valid positive int. The amount of numbers inserted in VECTOR should be the same amount of features from the stated data file (4 features for iris, 13 for wine and 16 for beans). 

All other input is considered invalid.

Before you run the program, you need to build it: 
```
make
```
Then, run in 2 different terminals the client and the server.
In first terminal insert:
```
./server.out DATAFILE PORT
```
e.g.
```
./server.out iris_classified.csv 5555
```
In second terminal insert:
```
./client.out IP PORT
```
e.g.
```
./client.out 127.0.0.1 5555
```
then insert your input in the client terminal:
```
VECTOR DISTANCE K
```
e.g.
```
1.1 2.2 3.3 4.4 AUC 3
```
if a user wants to insert new inputs they can repeat the last step as many time as wished.
if a user wants to disconnect between server and client they can insert -1 and the server will wait for a connection to a new client.



