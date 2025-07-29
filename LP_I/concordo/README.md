# Concordo - Discord Clone

Concordo is a system inspired by Discord, but it operates only in text mode without networking capabilities. The project is implemented in C++ and utilizes the following features:

- Inheritance and abstract classes
- File manipulation
- Standard Template Library (STL) with the use of vectors

Created by: Beatriz Gouveia Gadelha
Registration number: 20220040029
Subject/class: DIM0120 - T01

## Implemented Features

The Concordo system includes the following entities:

- Users: contains information about a user account in the system.
- Servers: with multiple channels.
  - TextChannel: inherits from Channel and contains multiple messages.
    - Messages: written by users, with date/time information.
  - VoiceChannel: inherits from Channel and stores only the last posted message.
  
The system is operated through single-line commands, composed of a command followed by parameters. Each command is interpreted, processed, and generates an output according to the processing result.

The project is divided into three parts, each with its specific functionalities.

### Part 1

In the first part of the project, the commands related to Users, Servers, and Channel creation were implemented. In this part, it is not yet possible to join a channel or send/read messages within it.

### Part 1 Commands:

**A1 - If not logged in (Upon entering the system)**

- A1.1 - Quit the system: `quit`
- A1.2 - Create user: `create-user <email> <password_without_spaces> <name with spaces>`
- A1.3 - Log in: `login <email> <password>`

**A2 - Basic Interactions with Servers (When logged in)**

- A2.1 - Disconnect from Concordo: `disconnect`
- A2.2 - Create servers: `create-server <name>`
- A2.3 - Change server description: `set-server-desc <name> "<description>"`
- A2.4 - Set invite code for the server: `set-server-invitecode <name> <code>`
- A2.5 - List servers: `list-servers`
- A2.6 - Remove server: `remove-server <name>`
- A2.7 - Join a server: `enter-server <name>`
- A2.8 - Leave a server: `leave-server`
- A2.9 - List participants in the server: `list-participants`

### Part 2

In the second part of the project, the commands related to the resources of hte channels and messages were implemented. In this part, it is now possible to join a channel or send/read messages within it.

### Part 2 Commands:

**B1 - Channel Management (when inside a server)**

- B1.1 - List server channels: `list-channels`
- B1.2 - Create a channel in the server: `create-channel <name> <type>`
- B1.3 - Enter a channel in the server: `enter-channel <name>`
- B1.4 - Leave the channel: `leave-channel`


**B2 - Message Management (when inside a server and in some channel)**

- B2.1 - Send a message to the channel: `send-message <message>`
- B2.2 - View messages in the channel:  `list-messages`

### Part 3

In the last part of the project, there isn't any new command. In this part was implemented the saving and loading information part, so that during the use of the "Concordo" no information gets lost. And also if you end the aplication and run it again what was done before continues, such as messages sent, users, server and channels created and so on.  

## Prerequisites
Before you start, make sure you have installed one of the following components on your system:

- C++ compiler (such as g++ or clang++)
- CMake (only if you are using CMake to compile)

## Compilation and Execution using CMake

1. Navigate to the root directory of the project where the CMakeLists.txt file is located.
2. Create a build directory (e.g., "build") and navigate into it:
   ```
   mkdir build
   cd build
   ```
3. Generate the CMake configuration files inside the build directory:
   ```
   cmake ..
   ```
4. Run the make command to compile the program:
   ```
   make
   ```
   This will compile the source code and generate the executable file.
   
5. After a successful compilation, from the build directory, run the following command in the terminal to start the Concordo program:
   ```
   ./concordo
   ```
   You can interact with the program using the available commands.

## Compilation and Execution with C++ Compiler

If you are not using CMake to compile the Concordo program and dealing directly with the source files, follow the steps below:

1. Navigate to the root directory of the project where the source files are

 located.
2. Compile the source code using the C++ compiler. Suppose the main program file is `main.cpp`. Execute the following command in the terminal:
   ```
   g++ main.cpp user.cpp server.cpp system.cpp message.cpp channel.cpp channelText.cpp channelVoice.cpp -o concordo
   ```
   This will compile the source code and generate an executable file named `concordo`.

3. After a successful compilation, from the directory where the `concordo` executable file was generated, run the following command in the terminal:
   ```
   ./concordo
   ```
   This will start the execution of the Concordo program, and you can interact with it using the available commands.

Make sure to refer to the provided documentation for details on all available commands and their correct syntax to perform the desired operations within the Concordo program.

## Testing the Executable with the Test File

1. Make sure you have compiled the Concordo program following the instructions mentioned above, either using CMake or compiling directly without CMake.

2. In the directory where the `concordo` executable file is located, check if there is a file named `command.in`. This file contains a series of commands that can be used to test the program.

3. Open a terminal and navigate to the directory where the `concordo` executable is located.

4. Execute the following command to redirect the input from the `command.in` file to the Concordo program:
   ```
   ./concordo < ../command.in
   ```
   This will redirect the content of the `command.in` file as input to the Concordo program. The program will execute the commands present in the file and display the corresponding results in the terminal.

5. Observe the output generated by the Concordo program and verify if it is correct according to the commands present in the `command.in` file.

The `command.in` file can be customized according to the tests you want to perform. Each line of the file represents a command that can be recognized by the Concordo program.

Make sure to use the correct syntax of the commands and refer to the documentation provided with the Concordo program to understand the structure and details of each supported command.

Note that the `command.in` file is just a convenient option to automate the tests and is not strictly required. You can also interact with the program directly in the terminal by providing commands manually.