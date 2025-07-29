#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include "channel.h"
#include "channelText.h"
#include "channelVoice.h"

using namespace std;

class Server
{
  //=== Private members
  private:
    int ownerID;
    int userID;
    string name;
    string description;
    string codeInvite;
    vector<Channel *> channels;
    vector<int> participantIDs;

  //=== Public methods
  public:
    /* Constructors and destructor */

    /*!
    * Default constructor that creates an empty server.
    */
    Server();

    /*!
    * Constructor that initializes the server with a name.
    *
    * \param name  The name of the server
    */
    Server(const string name);

    /*!
    * Default destructor.
    */
    ~Server();

    /* Get methods */

    /*!
    * Retrieves the server owner id.
    *
    * \return The server owner id.
    */
    int get_owner_ID() const;

    /*!
    * Retrieves the user id that is visualizing the server.
    *
    * \return The user id that is visualizing the server.
    */
    int get_user_ID() const;

    /*!
    * Retrieves the name of the server.
    *
    * \return The name of the server.
    */
    string get_name() const;

    /*!
    * Retrieves the description of the server.
    *
    * \return The description of the server.
    */
    string get_description() const;

    /*!
    * Retrieves the invitation code of the server.
    *
    * \return The invitation code of the server.
    */
    string get_code_invite() const;

    /*!
    * Retrieves the channels of the server.
    *
    * \return A vector containing the pointers to the channels of the server.
    */
    vector<Channel *> get_channels() const;

    /*!
    * Retrieves the participant ids from the server.
    *
    * \return A vector containing the participant ids from the server.
    */
    vector<int> get_participant_IDs() const;

    /* Set methods */

    /*!
    * Sets the server owner's name of the channel.
    *
    * \param userID The server owner's name to be set for the channel.
    */
    void set_owner_ID(const int userID);

    /*!
    * Sets the server user id of the channel.
    *
    * \param userID The server user id to be set for the channel.
    */
    void set_user_ID(const int userID);

    /*!
    * Sets the name of the server.
    *
    * \param name The name to be set for the server.
    */
    void set_name(const string name);

    /*!
    * Sets the description of the server.
    *
    * \param description The description to be set for the server.
    */
    void set_description(const string description);

    /*!
    * Sets the invitation code of the server.
    *
    * \param codeInvite The invitation code to be set for the server.
    */
    void set_code_invite(const string codeInvite);

    /*!
    * Sets the channels of the server.
    *
    * \param channels A vector containing pointers to the channels to be set for the server.
    */
    void set_channels(const vector<Channel *> channels);

    /*!
    * Sets the participant ids of the server.
    *
    * \param participantIDs A vector containing the participant ids to be set for the server.
    */
    void set_participant_IDs(const vector<int> participantIDs);

    /* Other methods */

    /*!
    * Equality operator for comparing servers.
    *
    * \param other The server to compare with.
    * \return True if the servers are equal, false otherwise.
    */
    bool operator==(const Server other);

    /*!
    * Adds a participant id to the list of the server.
    *
    * \param id The participant id to be added.
    */
    void add_participant_ID(const int id);

    /*!
    * Adds a channel to the list of the server.
    *
    * \param channel The pointer to the channel to be added.
    */
    void add_channel(Channel* channelT);
};

#endif