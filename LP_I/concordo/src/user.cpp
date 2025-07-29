#include "user.h"

/* Constructors and destructor */

User::User(){/* Empty */};

User::User(const string name, const string email, const string password, const int id)
{
  this->id = id;
  this->name = name;
  this->email = email;
  this->password = password;
};

User::~User(){/* Empty */};

/* Get methods */

int User::get_ID() const 
{
  return this->id;
};

string User::get_name() const
{
  return this->name;
};

string User::get_email() const
{
  return this->email;
};

string User::get_password() const
{
  return this->password;
};

/* Set methods */

void User::set_ID(const int id)
{
  this->id = id;
};

void User::set_name(const string name)
{
  this->name = name;
};

void User::set_email(const string email)
{
  this->email = email;
};

void User::set_password(const string password)
{
  this->password = password;
};

/* Other methods */

bool User::operator==(const User other){
  return id == other.id;
};