#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

using namespace std;

class Channel
{
  //=== Private members
  private:
    string name;

  //=== Public methods
  public:
    /*Constructors and destructor*/

    /*!
    * Default constructor that creates an empty channel.
    */
    Channel();

    /*!
    * Constructor that initializes the channel with a name.
    *
    * \param name The name of the channel.
    */
    Channel(const string name);

    /*!
    * Default destructor.
    */
    ~Channel();

    /* Get method */

    /*!
    * Retrieves the name of the channel.
    *
    * \return The name of the channel.
    */
    string get_name() const;

    /* Set method */

    /*!
    * Sets the name of the channel.
    *
    * \param name The name to be set for the channel.
    */
    void set_name(const string name);


    /* Other methods */

    /*!
    * Lists the channel in the terminal
    */
    virtual void list_channel() const = 0;
};

#endif
