#include "channel.h"

/*Constructors and destructor*/

Channel::Channel() {/* Empty */};

Channel::Channel(const string name)
{
  this->name = name;
};

Channel::~Channel(){/* Empty */};

/* Get method */

string Channel::get_name() const
{
  return this->name;
};

/* Set method */

void Channel::set_name(const string name)
{
  this->name = name;
};