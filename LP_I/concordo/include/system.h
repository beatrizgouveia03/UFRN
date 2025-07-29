#ifndef SYSTEM_M
#define SYSTEM_H

#include "user.h"
#include "server.h"

#include <fstream>
#include <sstream>

class System
{
  //=== Private members
  private:
    vector<User> allUsers;
    vector<Server> allServers;
    vector<ChannelText> allTextChannels;
    vector<ChannelVoice> allVoiceChannels;
    int nextID = 1;
    bool userIsLogged = false;
    int userLoggedID;
    Server* serverLogged = nullptr;
    Channel* channelLogged = nullptr;

  //=== Public methods
  public:
    /* Constructors and destructor*/

    /*!
    * Default constructor that creates an empty system.
    */
    System();

    /*!
    * Constructor that initializes the server with a list of users and servers.
    *
    * \param allUsers The vector of users of the system
    * \param allServers The vector of servers of the system
    * \param allTextChannels The vector of text channels of the system
    * \param allVoiceChannels The vector of voice channels of the system
    */
    System(vector<User> allUsers, vector<Server> allServers, vector<ChannelText> allTextChannels, vector<ChannelVoice> allVoiceChannels);

    /*!
    * Default destructor.
    */
    ~System();

    /* Get methods */

    /*!
    * Retrieves the users from the system.
    *
    * \return A vector containing the users from the system.
    */
    vector<User> get_all_users() const;

    /*!
    * Retrieves the servers from the system.
    *
    * \return A vector containing the servers from the system.
    */
    vector<Server> get_all_servers() const;

    /*!
    * Retrieves the text channels from the system.
    *
    * \return A vector containing the text channels from the system.
    */
    vector<ChannelText> get_all_text_channels() const;

    /*!
    * Retrieves the voice channels from the system.
    *
    * \return A vector containing the voice channels from the system.
    */
    vector<ChannelVoice> get_all_voice_channels() const;

    /*!
    * Retrieves the logged user ID in the system.
    *
    * \return The logged user ID in the system.
    */
    int get_user_logged_ID() const;

    /*!
    * Retrieves the server that is being visualized in the system.
    *
    * \return The server that is being visualized in the system.
    */
    Server* get_server_logged() const;

    /*!
    * Retrieves the channel that is being visualised in the system.
    *
    * \return The channel that is being visualised in the system.
    */
    Channel* get_channel_logged() const;  

    /* Set methods */

    /*!
    * Sets the users of the system.
    *
    * \param allUsers A vector containing the users to be set for the system.
    */
    void set_all_users(const vector<User> allUsers);

    /*!
    * Sets the servers of the system.
    *
    * \param allServers A vector containing the servers to be set for the system.
    */
    void set_all_servers(const vector<Server> allServers);

    /*!
    * Sets the text channels of the system.
    *
    * \param allTextChannels A vector containing the text channels to be set for the system.
    */
    void set_all_text_channels(const vector<ChannelText> allTextChannels);

    /*!
    * Sets the voice channels of the system.
    *
    * \param allVoiceChannels A vector containing the voice channels to be set for the system.
    */
    void set_all_voice_channels(const vector<ChannelVoice> allVoiceChannels);

    /*!
    * Sets the logged user ID in the system.
    *
    * \param userLogged The logged user ID in the system.
    */
    void set_user_logged_ID(const int userLoggedID);

    /*!
    * Sets the server that is being visualized in the system.
    *
    * \param serverLogged The server that is being visualized in the system.
    */
    void set_server_logged(Server *serverLogged = nullptr);

    /*!
    * Sets the channel that is being visualized in the system.
    *
    * \param channelLogged The channel that is being visualized in the system.
    */
    void set_channel_logged(Channel *channelLogged = nullptr); 

    /* Other methods */

    /*!
    * Checks if the user is logged in.
    *
    * \return True if the user is logged in, false otherwise.
    */
    bool is_logged();

    /*!
    * Disconnects the user from the system.
    */
    void disconnect();

    /*!
    * Adds a user to the list of the system.
    *
    * \param user The user to be added.
    */
    void add_user(const User user);

    /*!
    * Adds a server to the list of the system.
    *
    * \param server The server to be added.
    */
    void add_server(const Server server);

    /*!
    * Adds a text channel to the list of the system.
    *
    * \param channelT The text channel to be added.
    */
    void add_channel(const ChannelText channelT);

    /*!
    * Adds a voice channel to the list of the system.
    *
    * \param channelV The voice channel to be added.
    */
    void add_channel(const ChannelVoice channelV);

    /*!
    * Removes a user from the list of the system.
    *
    * \param user The user to be removed.
    */
    void rem_user(const User user);

    /*!
    * Removes a server from the list of the system.
    *
    * \param server The server to be removed.
    */
    void rem_server(const Server server);

    /*!
    * Finds a user from the system.
    *
    * \param email The email of the user to be found.
    * \return A pointer to the found user, or nullptr if not found.
    */
    User *find_user(const string email);

    /*!
    * Finds a user from the system.
    *
    * \param id The id of the user to be found.
    * \return A pointer to the found user, or nullptr if not found.
    */
    User *find_user(const int id);

    /*!
    * Finds a server from the system.
    *
    * \param name The name of the server to be found.
    * \return A pointer to the found server, or nullptr if not found.
    */
    Server *find_server(const string name);

    /*!
    * Finds a text channel from the system.
    *
    * \param name The name of the text channel to be found.
    * \return A pointer to the found channel, or nullptr if not found.
    */
    ChannelText *find_text_channel(const string name);

    /*!
    * Finds a voice channel from the system.
    *
    * \param name The name of the voice channel to be found.
    * \return A pointer to the found channel, or nullptr if not found.
    */
    ChannelVoice *find_voice_channel(const string name);


    /*!
    * Saves all the info of the server 
    */
    void save();

    /*!
    * Loads all the info to the server 
    */
    void load();

    //=== Private methods
  private:

    /*!
    * Saves all the users of the server with all their info 
    */
    void saveUsers();

    /*!
    * Saves all the servers of the server with all their info 
    */
    void saveServers();

    /*!
    * Loads all the users of the server with all their info 
    */
    void loadUsers();

    /*!
    * Loads all the servers of the server with all their info 
    */
    void loadServers();
};

#endif