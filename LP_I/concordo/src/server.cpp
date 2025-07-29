#include "server.h"

/* Constructors and destructor */

Server::Server(){/* Empty */};

Server::Server(const string name)
{
  this->name = name;
};

Server::~Server(){/* Empty */};

/* Get methods */

int Server::get_owner_ID() const
{
  return this->ownerID;
};

int Server::get_user_ID() const
{
  return this->userID;
};

string Server::get_name() const
{
  return this->name;
};

string Server::get_description() const
{
  return this->description;
};

string Server::get_code_invite() const
{
  return this->codeInvite;
};

vector<Channel *> Server::get_channels() const
{
  return this->channels;
};

vector<int> Server::get_participant_IDs() const
{
  return this->participantIDs;
};

/* Set methods */

void Server::set_owner_ID(const int userID)
{
  this->ownerID = userID;
};

void Server::set_user_ID(const int userID){
  this->userID = userID;
};

void Server::set_name(const string name)
{
  this->name = name;
};

void Server::set_description(const string description)
{
  this->description = description;
};

void Server::set_code_invite(const string codeInvite)
{
  this->codeInvite = codeInvite;
};

void Server::set_channels(const vector<Channel *> channels)
{
  this->channels = channels;
};

void Server::set_participant_IDs(const vector<int> participantIDs)
{
  this->participantIDs = participantIDs;
};

/* Other methods */

bool Server::operator==(const Server other){
  return name == other.name && description == other.description;
};

void Server::add_participant_ID(const int id){
  for(int participantid : participantIDs){
    if(participantid == id) return;
  }
  participantIDs.push_back(id);
};

void Server::add_channel(Channel *channel){
  channels.push_back(channel);
};
