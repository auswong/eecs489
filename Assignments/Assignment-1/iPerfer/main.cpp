//
//  main.cpp
//  iPerfer
//
//  Created by Austin Wong on 9/3/20.
//  Copyright © 2020 Austin Wong. All rights reserved.
//

#include <iostream>

using namespace std;

void server(int listen_port) {
    cout << "listen port: " << listen_port << endl;
}

void client(string hostname, int server_port, int time) {
    
}

int main(int argc, const char * argv[]) {
    if(argc != 4 && argc != 8) {    // server mode(4) or client mode(8)
        cout << "Error: missing or extra arguments" << endl;
    }

    string mode = argv[1];
    // Server Mode: ./iPerfer -s -p <listen_port>
    if(mode ==  "-s") {
        int listen_port = stoi(argv[3]);
        if(listen_port < 1024 || listen_port > 65535) {
            cout << "Error: port number must be in the range of [1024, 65535]" << endl;
            return 0;
        }
        server(listen_port);
    }
    // Client Mode: ./iPerfer -c -h <server_hostname> -p <server_port> -t <time>
    else {
        int server_port = stoi(argv[5]);
        if(server_port < 1024 || server_port > 65535) {
            cout << "Error: port number must be in the range of [1024, 65535]" << endl;
            return 0;
        }
        int time = stoi(argv[7]);
        if(time < 0) {
            cout << "Error: time argument must be greater than 0" << endl;
            return 0;
        }
        client(string(argv[3]), server_port, time);
    }

    return 0;
}
