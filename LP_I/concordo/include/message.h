#ifndef MESSAGE_H
#define	MESSAGE_H

#include <string>

using namespace std;

class Message
{
  //=== Private members
  private:
    string dateHour;
    int idSendFrom;
    string sendFrom;
    string content;

  //=== Public methods
  public:
    /* Constructors and destructor */

    /*!
    * Default constructor that creates an empty message.
    */
    Message();

    /*!
    * Constructor that initializes the with a date/hour, 
    * the user id that sent the message and its content.
    *
    * \param dateHour The date/hours of the message.
    * \param sentFrom The name of the user that sent the message.
    * \param content The content of the message.
    */
    Message(const string dateHour, const string sendFrom, const string content, const int idSendFrom);

    /*!
    * Default destructor.
    */
    ~Message();

    /* Get methods */

    /*!
    * Retrieves the date/hour of the message.
    *
    * \return The date/hour of the message.
    */
    string get_date_hour() const;

    /*!
    * Retrieves the name of the user that sent the message.
    *
    * \return The name of the user that sent the message.
    */
    string get_send_from() const;

    /*!
    * Retrieves the id of the user that sent the message.
    *
    * \return The id of the user that sent the message.
    */
    int get_id_send_from() const;

    /*!
    * Retrieves the content of the message.
    *
    * \return The content of the message.
    */
    string get_content() const;

    /* Set methods */

    /*!
    * Sets date/hour of the message.
    *
    * \param dateHour The date/hour of the message.
    */
    void set_date_hour(const string dateHour);

    /*!
    * Sets the name of the user that sent the message.
    *
    * \param sendFrom The name of the user that sent the message.
    */
    void set_send_from(const string sendFrom);

    /*!
    * Sets the id of the user that sent the message.
    *
    * \param sendFrom The id of the user that sent the message.
    */
    void set_send_from(const int IDsendFrom);

    /*!
    * Sets content of the message.
    *
    * \param dateHour The content of the message.
    */
    void set_content(const string content);

    /* Other methods */

    /*!
    * Equality operator for comparing messages.
    *
    * \param other The message to compare with.
    * \return True if the messages are equal, false otherwise.
    */
    bool operator==(const Message other);
};

#endif