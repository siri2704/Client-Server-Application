#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 12345
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to store client information
typedef struct {
    int socket;
    char username[50];
} client_info;

// Global array to store connected clients
client_info clients[MAX_CLIENTS];
int num_clients = 0;

// Mutex to protect shared resources
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to broadcast a message to all clients except the sender
void broadcast(int sender, char *message) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket != sender) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}

// Function to handle each client's communication
void *handle_client(void *arg) {
    client_info client = *((client_info *)arg);
    char buffer[BUFFER_SIZE];
    
    while (1) {
        int bytes_received = recv(client.socket, buffer, sizeof(buffer), 0);
        
        if (bytes_received <= 0) {
            printf("Client %s disconnected\n", client.username);
            break;
        }

        buffer[bytes_received] = '\0'; // Null-terminate the received string
        printf("Received from %s: %s", client.username, buffer);

        // If the message is a command
        if (buffer[0] == '/') {
            // Command: Private message (/msg <username> <message>)
            if (strncmp(buffer, "/msg", 4) == 0) {
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
            // Broadcast the message to all clients
            broadcast(client.socket, buffer);
        }
    }

    // Remove client from the list upon disconnection
    pthread_mutex_lock(&mutex);
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

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("Acceptance failed");
            continue;
        }

        // Receive the client's username
        char username[50];
        recv(client_socket, username, sizeof(username), 0);

        // Add the new client to the list
        client_info new_client;
        new_client.socket = client_socket;
        strcpy(new_client.username, username);

        // Create a thread for the new client
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, (void *)&new_client);

        // Add the client to the global clients array
        pthread_mutex_lock(&mutex);
        clients[num_clients++] = new_client;
        pthread_mutex_unlock(&mutex);

        printf("New connection from %s:%d (username: %s)\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), username);
    }

    // Close the server socket (this won't be reached due to the infinite loop)
    close(server_socket);

    return 0;
}
