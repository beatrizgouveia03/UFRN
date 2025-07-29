#include "message.h"

/* Constructors and destructor */

Message::Message(){/* Empty */};

Message::Message(const string dateHour, const string sendFrom, const string content, const int idSendFrom)
{
  this->dateHour = dateHour;
  this->sendFrom = sendFrom;
  this->content = content;
  this->idSendFrom = idSendFrom;
};

Message::~Message(){/* Empty */};

/* Get methods */

string Message::get_date_hour() const
{
  return this->dateHour;
};

string Message::get_send_from() const
{
  return this->sendFrom;
};

int Message::get_id_send_from() const
{
  return this->idSendFrom;
};

string Message::get_content() const
{
  return this->content;
};

/* Set methods */

void Message::set_date_hour(const string dateHour)
{
  this->dateHour = dateHour;
};

void Message::set_send_from(const string sendFrom)
{
  this->sendFrom = sendFrom;
};

void Message::set_send_from(const int idSendFrom)
{
  this->idSendFrom = idSendFrom;
};

void Message::set_content(const string content)
{
  this->content = content;
};

/* Other methods */

bool Message::operator==(const Message other){
  return dateHour == other.dateHour && idSendFrom == other.idSendFrom && content == other.content;  
};