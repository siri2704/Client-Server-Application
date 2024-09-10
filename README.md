# Client-Server-Application
The application allows multiple clients to connect to a server, perform database operations, and communicate with each other in real-time. This project helped me enhance my understanding of network programming, database management, and concurrent programming.
ABSTRACT
 
The serverclient chat application project endeavours to create an efficient, reliable, and featurerich platform for facilitating realtime communication among multiple users. Built using the C programming language and following a clientserver architecture, the application aims to provide a seamless user experience through communication with the host server. The server component of the application is designed to manage multiple client connections concurrently, leveraging multithreading and robust error handling mechanisms to ensure stability and scalability. Conversely, the client component offers an intuitive interface for users to connect to the server, set usernames, and send messages effortlessly. Rigorous testing, comprising unit tests, integration tests, and stress tests, is conducted to validate the application's functionality, robustness, and scalability. Overall, the project endeavors to deliver a highquality, reliable, and comprehensive chat application that caters to diverse communication needs across various contexts.

















 

 

 

 
 
 
 
 
 
 
INTRODUCTION
In the everevolving landscape of digital communication, the development of robust and efficient platforms is paramount to meeting the dynamic needs of users. This project undertakes the creation of a clientserver communication interface using the C programming language, focusing on enabling realtime communication from individual clients to a central server. The objective is to build a versatile and userfriendly application that not only facilitates seamless interactions but also emphasizes scalability, reliability, and effective error handling.
Communication platforms play a pivotal role in fostering connections, collaboration, and information exchange. Whether used for casual conversations, professional collaboration, or specialized applications, the demand for realtime communication solutions continues to grow. This project addresses this demand by leveraging the power of C and implementing a clientserver architecture over TCP/IP sockets.
The envisioned application seeks to provide a comprehensive solution, allowing individual clients to connect to a central server and exchange messages efficiently. Key features such as setting usernames, broadcasting messages, and enabling private messaging to enhance the versatility of the platform. The server component, developed using the POSIX socket API, implements multithreading to handle concurrent client connections, ensuring a responsive and scalable communication environment.
Furthermore, the project places a strong emphasis on user experience by designing a client interface that simplifies connection setup, username assignment, and message exchange. Rigorous testing methodologies, including unit tests, integration tests, and stress tests, are employed to guarantee the functionality, reliability, and scalability of the developed application.
As the project unfolds, it aspires to deliver a communication platform that not only meets the immediate requirements of realtime interactions but also anticipates future needs in the everdynamic realm of digital communication. Through thoughtful design, efficient implementation, and thorough testing, this project aims to contribute to the evolution of clientserver communication systems, setting new standards for versatility, reliability, and user satisfaction.  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
PROBLEM STATEMENT
The project aims to develop a serverclient communication interface in C, focusing on realtime communication from individual clients to the server. The application will utilize a clientserver architecture over TCP/IP sockets, allowing clients to connect to a central server. Key features include setting usernames, broadcasting messages. The server, developed using the POSIX socket API, will handle concurrent client connections through multithreading and implement basic error handling for connection failures and malformed messages.
The client interface will facilitate userfriendly connections to the server, support username setup, and enable message exchange. Clients can initiate public broadcasts and private messages, providing a comprehensive solution for individual interactions with the server. Rigorous testing, including unit, integration, and stress tests, will ensure functionality, reliability, and scalability. The project aims to deliver a robust, versatile, and userfriendly platform tailored for communication from individual clients to the server.
In summary, the project focuses on creating an efficient communication platform in C, emphasizing features, concurrent handling, error resilience, and rigorous testing to meet the requirements of realtime interactions from individual clients to the server.
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
APIs Used
In the SERVER: 
Socket API:  
Sockets are used for communication between processes on different hosts. In this program, the server creates a socket using the socket() function and then binds it to a specific address and port using bind(). It listens for incoming connections using listen(), and when a client connects, it accepts the connection using accept(). 
● socket(): Creates a new socket. 
● bind(): Associates a socket with a specific address and port. 
● listen(): Listens for incoming connections on a socket. 
● accept(): Accepts an incoming connection, creating a new socket for communication with the client. 
Thread API (pthreads):  
This program uses POSIX threads (pthreads) for handling multiple clients concurrently. Each client connection is handled in a separate thread. 
● pthread_create(): Creates a new thread. 
● pthread_mutex_lock() and pthread_mutex_unlock(): These functions are used to lock and unlock a
​mutex respectively, ensuring that critical sections of code are executed atomically and preventing ​race conditions.
Client-Server Communication:  
The program uses functions like send() and recv() to send and receive data over sockets. 
● send(): Sends data on a connected socket. 
● recv(): Receives data from a connected socket. 
Networking API
● struct sockaddr_in: This structure represents a socket address in the Internet domain. It contains fields for the address family, port number, and IP address. 
● inet_ntoa(): Converts an IP address from binary to a string in the standard "dot notation" format. 
● htons() and ntohs(): Functions for converting between host byte order and network byte order for 16-bit values (such as port numbers). 
Standard C Library Functions
printf(), perror(), strcpy(), strtok(), strlen(), strcmp(), memset(): These are standard C library functions for printing messages, error handling, string manipulation, and memory operations. 
 
 
 
 
 
 
In the Client
Socket API
● socket(): This function creates a new socket. 
● connect(): It establishes a connection to a remote socket. 
● send(): Sends data over a connected socket. 
● recv(): Receives data from a connected socket. 
● close(): Closes a socket. 
These functions are used to establish communication between the client and the server. The client creates a socket using socket(), connects to the server with connect(), sends and receives messages using send() and recv(), and closes the socket with close() when done. 
Networking API
● struct sockaddr_in: This structure represents a socket address in the Internet domain. It contains fields for the address family, port number, and IP address. 
● inet_addr(): Converts an IPv4 address from a string in dotted-decimal notation to a binary representation. 
● htons(): Converts a 16-bit integer from host byte order to network byte order for the port number. 
These functions and structures are used to define and set up the server's address and port to establish a connection with the server. 
Standard C Library Functions 
printf(), fgets(), strlen(), memset(), exit(), perror(): These are standard C library functions used for general input/output, string manipulation, memory operations, error handling, and program termination. 
These functions are used for user interaction, printing messages, handling user input, string manipulation, error reporting, and program termination. 
 
 
 
 
 
 
 
 
 
 
 
Process Controls Used
In the SERVER:
Thread Creation (pthread_create()): 
● The server creates a new thread for each incoming client connection using the pthread_create() function. 
● This function takes several parameters, including a pointer to a pthread_t object that will hold the thread ID, a pointer to a thread attributes object (usually set to NULL for default attributes), the entry point function for the thread, and an optional argument to pass to the thread function. 
Thread Function
● Each thread executes the same function, typically called handle_client(). 
● This function is responsible for handling communication with the client associated with the thread. 
● Inside this function, the server receives messages from the client, processes them, and sends responses if necessary. 
● When the client disconnects or an error occurs, the thread terminates gracefully. 
Thread Synchronization
● To ensure thread safety when accessing shared data structures (such as an array storing information about connected clients), the code uses mutexes (mutual exclusion locks). 
● Mutexes are acquired using pthread_mutex_lock() before accessing shared data and released using pthread_mutex_unlock() afterward. 
● This prevents race conditions where multiple threads may try to modify shared data simultaneously, leading to inconsistencies or errors. 
Thread Termination and Cleanup
● Threads are terminated when the client disconnects or when the server shuts down. 
● Upon termination, threads release any acquired resources and perform cleanup tasks. 
● This may include closing socket descriptors associated with the client connection and removing the client's information from any shared data structures. 
 
In the CLIENT  
Sequential Execution 
● The program follows a sequential execution model, where instructions are executed one after the other in the order they appear in the code. 
● It starts by creating a socket, setting up the server address, establishing a connection with the server, setting a username, and then enters a loop to send and receive messages indefinitely until the program is terminated. 
● Each step is executed in sequence, ensuring that the necessary setup is completed before the main communication loop begins. 
Looping
● The program utilizes a while loop to continuously send and receive messages between the client and the server. 
● Within this loop, the client prompts the user for a message, sends it to the server, receives a response from the server, and then prints the received message. 
● This loop allows for continuous interaction between the client and the server until the program is terminated or an error occurs. 
Error Handling
● Error handling is an essential aspect of process control, even though it's not explicitly labeled as such. 
● The program uses error-checking mechanisms such as if statements to detect errors during socket creation, connection establishment, and message sending/receiving. 
● Upon encountering an error, the program prints an error message using perror() and exits the program using exit() to prevent further execution. 
Input/Output Control
● The program uses input/output operations to interact with the user and communicate with the server. 
● It prompts the user to enter a username and messages using printf() statements and reads user input using fgets(). 
● Messages received from the server are printed to the console using printf(). 
Resource Management
● Although not explicitly labeled as process control, resource management is crucial for the program's correct operation. 
● The program opens a socket connection with the server using socket() and connect(), and it closes the socket using close() when the program terminates. 
● Proper resource management ensures that network resources are released appropriately and prevents resource leaks. 
 
 
 
 
 
 
 
 
 
Implementation and Code
Client Implementation:
Connection Setup
● The client initiates communication by establishing a connection to the server using TCP/IP sockets.
Username Setup:
● Clients set their usernames upon connection to the server.
● The username is used for identification in subsequent communications.
Message Exchange
● Clients can send messages to the server by inputting text through the user interface.
● The client program then sends the message to the server over the established socket connection.
Public Broadcasts:
● Clients have the capability to initiate public broadcasts that are sent to the server.
● Broadcasting allows messages to be disseminated to all connected clients through the server.
Private Messaging:
● Private messages are supported, allowing clients to send messages directly to specific users.
● The client specifies the recipient's username in addition to the message content.
Error Handling:
● Basic error handling is implemented to manage scenarios such as connection failures and malformed messages.
● Clients receive appropriate feedback or notifications in case of errors.
Server Implementation:
Connection Handling:
● The server listens for incoming client connections on a specified port using TCP/IP sockets.
● Upon connection, each client is assigned a separate thread to handle its communication.
Multithreading:
● Multithreading is employed to handle concurrent connections from multiple clients efficiently.
● Each client's communication is managed independently, preventing blocking issues.
Message Routing:
● The server receives messages from clients and performs necessary routing based on the type of message (public or private).
● Broadcast messages are sent to all connected clients, while private messages are directed to the intended recipient.
Error Handling:
● The server implements basic error handling to gracefully manage connection failures and handle improperly formatted messages.
● Error messages are logged, and appropriate actions are taken to ensure the server's stability.
Scalability:
● The server is designed to handle a scalable number of clients concurrently through effective multithreading.
 
Testing:
● Rigorous testing is conducted to ensure the functionality, reliability, and scalability of the client-server communication system.
● Unit tests verify individual components, integration tests assess the collaboration between server and client, and stress tests evaluate performance under various conditions.
CODE
SERVER CODE:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 12345
#define BUFFER_SIZE 1024
int main() {
   int client_socket;
   struct sockaddr_in server_addr;
   char buffer[BUFFER_SIZE];
   char username[50];
   // Create socket
   if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
       perror("Socket creation failed");
       exit(EXIT_FAILURE);
   }
   // Setup server address struct
   memset(&server_addr, 0, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   server_addr.sin_port = htons(PORT);
   // Connect to server
   if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
       perror("Connection failed");
       exit(EXIT_FAILURE);
   }
 
printf("Connected to server on port %d\n", PORT);
   // Set username
   printf("Enter your username: ");
   fgets(username, sizeof(username), stdin);
   username[strcspn(username, "\n")] = '\0'; // Remove trailing newline
   // Send username to server
   send(client_socket, username, strlen(username), 0);
   // Start receiving and sending messages
   while (1) {
       printf("Enter message: ");
       fgets(buffer, sizeof(buffer), stdin);
       // Send message to server
       send(client_socket, buffer, strlen(buffer), 0);
       // Receive and print server's response
       recv(client_socket, buffer, sizeof(buffer), 0);
       printf("Server: %s", buffer);
   }
   // Close the socket
   close(client_socket);
   return 0;
}
----------------------------------------------------------------------------------------------------------------------
CLIENT CODE:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#define PORT 12345
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
typedef struct {
   int socket;
   char username[50];
} client_info;
 
client_info clients[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void broadcast(int sender, char *message) {
   pthread_mutex_lock(&mutex);
   for (int i = 0; i < num_clients; i++) {
       if (clients[i].socket != sender) {
           send(clients[i].socket, message, strlen(message), 0);
       }
   }
   pthread_mutex_unlock(&mutex);
}
void *handle_client(void *arg) {
   client_info client = *((client_info *)arg);
   char buffer[BUFFER_SIZE];
   while (1) {
       int bytes_received = recv(client.socket, buffer, sizeof(buffer), 0);
       if (bytes_received <= 0) {
           printf("Client %s disconnected\n", client.username);
           break;
       }
       buffer[bytes_received] = '\0';
       printf("Received from %s: %s", client.username, buffer);
       if (buffer[0] == '/') {
           // Command handling
           // Add more commands as needed
           if (strncmp(buffer, "/msg", 4) == 0) {
               // Private message: /msg <username> <message>
               char *recipient_username = strtok(buffer + 5, " ");
               char *message = strtok(NULL, "");
               pthread_mutex_lock(&mutex);
               for (int i = 0; i < num_clients; i++) {
                   if (strcmp(clients[i].username, recipient_username) == 0) {
                       send(clients[i].socket, message, strlen(message), 0);
                       break;
                   }
               }
               pthread_mutex_unlock(&mutex);
           }
       } else {
           broadcast(client.socket, buffer);
       }
   }
   pthread_mutex_lock(&mutex);
   // Remove client from the list
   for (int i = 0; i < num_clients; i++) {
       if (clients[i].socket == client.socket) {
           for (int j = i; j < num_clients - 1; j++) {
               clients[j] = clients[j + 1];
           }
           num_clients--;
           break;
       }
   }
   pthread_mutex_unlock(&mutex);
   close(client.socket);
   pthread_exit(NULL);
}
int main() {
   int server_socket, client_socket;
   struct sockaddr_in server_addr, client_addr;
   socklen_t client_len = sizeof(client_addr);
   // Create socket
   if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
       perror("Socket creation failed");
       exit(EXIT_FAILURE);
   }
   // Setup server address struct
   memset(&server_addr, 0, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(PORT);
   // Bind socket
   if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
       perror("Binding failed");
       exit(EXIT_FAILURE);
   }
   // Listen for incoming connections
   if (listen(server_socket, MAX_CLIENTS) == -1) {
       perror("Listening failed");
       exit(EXIT_FAILURE);
   }
   printf("Server listening on port %d...\n", PORT);
   while (1) {
       // Accept connection from client
       if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) == -1) ​{
           perror("Acceptance failed");
           continue;
       }
       // Receive client's username
       char username[50];
       recv(client_socket, username, sizeof(username), 0);
       // Add client to the clients array
       client_info new_client;
       new_client.socket = client_socket;
       strcpy(new_client.username, username);
       pthread_t tid;
       pthread_create(&tid, NULL, handle_client, (void *)&new_client);
       pthread_mutex_lock(&mutex);
       clients[num_clients++] = new_client;
       pthread_mutex_unlock(&mutex);
       printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ​ntohs(client_addr.sin_port));
   }
 
   close(server_socket);
   return 0;
}
Result and Snapshots
1. Client 1 terminal
 
 

 
 
 
2. Client 2 terminal
 
 
 
 
 
 
3. Server terminal (run before the clients but displays output after the clients are run)
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
REFRENCES
● Beej’s guide to network programming
● POSIX Threads Programming
● https://www.researchgate.net/publication/377231781_A_pneumatic_reconfigurable_socket_for_transtibial_amputees?_tp=eyJjb250ZXh0Ijp7ImZpcnN0UGFnZSI6ImhvbWUiLCJwYWdlIjoic2VhcmNoIiwicG9zaXRpb24iOiJwYWdlSGVhZGVyIn19
● A chat client-server application for E-learning | IEEE Conference Publication | IEEE Xplore
 
 
 
**************************************
