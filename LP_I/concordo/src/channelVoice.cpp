#include "channelVoice.h"

/*Constructors and destructor */

ChannelVoice::ChannelVoice(){/* Empty */};

ChannelVoice::ChannelVoice(const string name)
{
  this->set_name(name);
};

ChannelVoice::~ChannelVoice(){/* Empty */};

/* Get method */

Message ChannelVoice::get_last_message() const
{ 
  return this->lastMessage;
};

/* Set method */

void ChannelVoice::set_last_message(const Message lastMessage)
{
  this->lastMessage = lastMessage;
};

/* Other methods */

void ChannelVoice::list_channel() const
{
  cout << lastMessage.get_send_from();
  cout << lastMessage.get_date_hour() << ": ";
  cout << lastMessage.get_content()  << endl;

};