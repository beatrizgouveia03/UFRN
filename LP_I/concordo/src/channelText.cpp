#include "channelText.h"

/* Constructors and destructor */

ChannelText::ChannelText(){/* Empty */};

ChannelText::ChannelText(const string name)
{
  this->set_name(name);
};

ChannelText::~ChannelText(){/* Empty */};

/* Get method */

vector<Message> ChannelText::get_messages() const
{
  return this->messages;
};

/* Set method */

void ChannelText::set_messages(const vector<Message> messages)
{
  this->messages = messages;
};

/* Other methods */

void ChannelText::add_message(const Message message
){
  messages.push_back(message);
};

void ChannelText::rem_message(const Message message)
{
  Message* aux = find_message(message);
  delete aux;
};

Message *ChannelText::find_message(const Message message)
{
  return nullptr;
};

void ChannelText::list_channel() const
{
  for(Message m : messages){
    cout << m.get_send_from();
    cout << m.get_date_hour() << ": ";
    cout << m.get_content()  << endl;
  }
};