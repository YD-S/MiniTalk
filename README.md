
![Banner](https://github.com/byaliego/42-project-badges/blob/main/covers/cover-minitalk-bonus.png?raw=true)

## About

> Minitalk is a project at [42](https://www.42.fr/) that focuses on interprocess communication using signals. The goal is to create a client and server program that can exchange messages using signals. This project enhances your understanding of signal handling and basic IPC concepts.

## Usage

To use Minitalk, follow these steps:

1. Clone the repository to your local machine:

   ```
   git clone [repository_url]
   ```

2. Navigate to the project directory:
    ```
    cd minitalk
    ```
3. Compile the server and client programs:
    ```
    make
    ```
4. Run the server:
    ```
    ./server
    ```
5. In another terminal, run the client with the server's process ID:
    ```
    ./client [server_process_id] "Your message here"
    ```
    Replace [server_process_id] with the actual process ID of the server.

## Communication Protocol
- The server and client communicate using signals.
- The client sends each character of the message as a series of bits using the `kill` system call.
- The server, upon receiving the signal, reconstructs the message and displays it.

## Compilation
The project can be compiled using the provided Makefile. Simply run:
    ```
    make
    ```
    This will generate the server and client executables.

## Example

1. Start the server:
    ```
    ./server
    ```
2. In another terminal, run the client:
    ´´´
    ./client [server_process_id] "Hello, Minitalk!"
    ´´´
    Replace [server_process_id] with the actual process ID of the server.

3. The server will display the received message.

## Notes
- Make sure to handle errors and edge cases gracefully.
- The communication is one-way, from client to server.
- Understand the limitations and constraints of signal handling in different contexts
## Author

Yashdev Singh (Ysingh)

