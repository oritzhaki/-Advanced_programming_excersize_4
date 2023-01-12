all: client.out server.out

client.out: *lient*.h *lient*.cpp 
	g++ -std=c++11 -fdiagnostics-color=always -g *lient*.cpp -o $@

server.out: *erver*.h reader.h knn.h distance.h distanceMetrics.h *erver*.cpp reader.cpp knn.cpp distance.cpp distanceMetrics.cpp 
	g++ -std=c++11 -fdiagnostics-color=always -g *erver*.cpp reader.cpp knn.cpp distance.cpp distanceMetrics.cpp -o $@