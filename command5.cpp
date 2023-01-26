#include "command5.h"

Command5::Command5(DefaultIO* io, varHolder& variables) : Command("download results"), io_(io), var(variables){
    this->io_ = io;
}

string Command5::execute() {
    // make sure to print result only after there has been valid classification
    if(this->var.getTrainDBR().is_empty() || this->var.getTestDBR().is_empty()){ // data check
        return "please upload data\n";
    } else if(this->var.getClassifications().empty()){ // classification check
        return "please classify the data\n";
    } else { // if got here - classifications info is available
        string out_classifications;
        string out_row;
        for(pair<int, string> c: this->var.getClassifications()){
            out_row = to_string(c.first) + "\t" + c.second + "\n";
            out_classifications = out_classifications + out_row;
        }
        
        this->io_->write("upload results:");

        // generate random port and send to client in range (10,000-60,000)
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(0, 50000);
        // send the new port to client so they can both know the new one
        auto random_integer = uni(rng);
        int port = 10000 + random_integer;
        
        int sock = listenToPort(port);
        this->io_->write(to_string(port)); // send new port to client
        int client_sock = acceptClient(sock);

        // send file to client and close sockets
        thread t([client_sock, out_classifications]() {
            cout << "IN SERVER THREAD" << endl;
            SocketIO* sio = new SocketIO(client_sock);
            sio->write(out_classifications);
            delete sio;
            close(client_sock);
            cout << "FINISH SERVER THREAD" << endl;

            
        });
        t.detach();
        
        return "";
    
    }
    return "";
}