all: client.out server.out

client.out: *lient*.h *lient*.cpp 
	g++ -std=c++11 -fdiagnostics-color=always -g *lient*.cpp -o $@

server.out: *erver*.h co*.h reader.h knn.h distance.h distanceMetrics.h CLI.h *IO.h varHolder.h co*.h *IO.cpp *erver*.cpp reader.cpp knn.cpp distance.cpp distanceMetrics.cpp CLI.cpp varHolder.cpp
	g++ -std=c++11 -fdiagnostics-color=always -g *erver*.cpp co*.cpp reader.cpp knn.cpp distance.cpp distanceMetrics.cpp *IO.cpp CLI.cpp varHolder.cpp -o $@