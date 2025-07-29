#include "system.h"

System::System(){/* Empty */};

System::System(vector<User> allUsers, vector<Server> allServers, vector<ChannelText> allTextChannels, vector<ChannelVoice> allVoiceChannels)
{
  this->allUsers = allUsers;
  this->allServers = allServers;    
  this->allTextChannels = allTextChannels;
  this->allVoiceChannels = allVoiceChannels;
};

System::~System(){/* Empty */};

/* Get methods */

vector<User> System::get_all_users() const
{
  return this->allUsers;
}

vector<Server> System::get_all_servers() const
{
  return this->allServers;
}

vector<ChannelText> System::get_all_text_channels() const
{
  return this->allTextChannels;
};

vector<ChannelVoice> System::get_all_voice_channels() const
{
  return this->allVoiceChannels;
};

int System::get_user_logged_ID() const
{
  return this->userLoggedID;
};

Server* System::get_server_logged() const
{
  return this->serverLogged;
}

Channel* System::get_channel_logged() const
{
  return this->channelLogged;
};

/* Set methods */

void System::set_all_users(const vector<User> allUsers)
{
  this->allUsers = allUsers;
};

void System::set_all_servers(const vector<Server> allServers)
{
  this->allServers = allServers;
};

void System::set_all_text_channels(const vector<ChannelText> allTextChannels)
{
  this->allTextChannels = allTextChannels;
};

void System::set_all_voice_channels(const vector<ChannelVoice> allVoiceChannels)
{
  this->allVoiceChannels = allVoiceChannels;
};

void System::set_user_logged_ID(const int userLoggedID)
{
  this->userIsLogged = true;
  this->userLoggedID = userLoggedID;
};

void System::set_server_logged(Server *serverLogged)
{
  this->serverLogged = serverLogged;
};

void System::set_channel_logged(Channel *channelLogged)
{
  this->channelLogged = channelLogged;
};

/* Other methods */

bool System::is_logged()
{
  return this->userIsLogged;
}

void System::disconnect()
{
  this->userIsLogged = false;
}

void System::add_user(const User user)
{
  allUsers.push_back(user);
}

void System::add_server(const Server server)
{
  allServers.push_back(server);
}

void System::add_channel(const ChannelText channelT)
{
  allTextChannels.push_back(channelT);
};

void System::add_channel(const ChannelVoice channelV)
{
  allVoiceChannels.push_back(channelV);
};

void System::rem_user(const User user)
{
  for (auto it = allUsers.begin(); it != allUsers.end(); ++it)
  {
    if (*it == user)
    {
      allUsers.erase(it);
      return;
    }
  }
}

void System::rem_server(const Server server)
{
  for(auto it = allServers.begin(); it != allServers.end(); ++it){
    if(*it == server){
      allServers.erase(it);
      return;
    }
  }
}

User *System::find_user(const string email)
{
  for(auto& u : allUsers){
    if(u.get_email() == email) return &u;
  }
  return nullptr;
}

User *System::find_user(const int id)
{
  for (auto &u : allUsers)
  {
    if (u.get_ID() == id)
      return &u;
  }
  return nullptr;
}

Server *System::find_server(const string name)
{
  for (auto& s : allServers)
  {
    if (s.get_name() == name)
      return &s;
  }
  return nullptr;
}

ChannelText *System::find_text_channel(const string name)
{
  for (auto &c : allTextChannels)
  {
    if (c.get_name() == name)
      return &c;
  }

  return nullptr;
}

ChannelVoice *System::find_voice_channel(const string name)
{
  for (auto &c : allVoiceChannels)
  {
    if (c.get_name() == name)
      return &c;
  }

  return nullptr;
}

void System::saveUsers()
{
  ofstream archive("../data/users.txt");

  if (archive.is_open())
  {
    archive << allUsers.size() << endl;
    for (User u : allUsers)
    {
      archive << u.get_ID() << endl;
      archive << u.get_name() << endl;
      archive << u.get_email() << endl;
      archive << u.get_password() << endl;
    }
    archive.close();
  }
}

void System::saveServers()
{
  ofstream archive("../data/servers.txt");

  if (archive.is_open())
  {
    archive << allServers.size() << endl;
    for (Server s : allServers)
    {
      archive << s.get_owner_ID() << endl;
      archive << s.get_name() << endl;
      archive << s.get_description() << endl;
      archive << s.get_code_invite() << endl;
      archive << s.get_participant_IDs().size() << endl;
      for(int id : s.get_participant_IDs())
      {
        archive << id << endl;
      }
      archive <<  s.get_channels().size() << endl;
      for(Channel* c : s.get_channels())
      { 
        archive << c->get_name() << endl;
        if (ChannelText *ct = dynamic_cast<ChannelText *>(c))
        {
          archive << "TEXTO" << endl;
          archive << ct->get_messages().size() << endl;
          for(Message m : ct->get_messages())
          {
            archive << m.get_id_send_from() << endl;
            archive << m.get_date_hour() << endl;
            archive << m.get_content() << endl;
          }
        }
        else{
          ChannelVoice *cv = dynamic_cast<ChannelVoice *>(c);
          archive << "VOZ" << endl;
          Message m = cv->get_last_message();
          if( m.get_content() != "" )
          {
            archive << "1" << endl;
            archive << m.get_id_send_from() << endl;
            archive << m.get_date_hour() << endl;
            archive << m.get_content() << endl;
          }
          else{
            archive << "0" << endl;
          }
        }
      }
    }
    archive.close();
  }
}

void System::save()
{
  saveUsers();
  saveServers();
}

void System::loadUsers()
{
  allUsers = vector<User>();

  ifstream archive("../data/users.txt");

  if (archive.is_open())
  { 
    int amount_of_users;
    string line;

    getline(archive, line);
    istringstream ss(line);
    ss >> amount_of_users;

    for(int i=0; i<amount_of_users; i++ )
    {
      int id;
      string name, email, password;

      getline(archive, line);
      istringstream sa(line);
      sa >> id;

      getline(archive, line);
      istringstream sb(line);
      name = sb.str();

      getline(archive, line);
      istringstream sc(line);
      sc >> email;

      getline(archive, line);
      istringstream sd(line);
      sd >> password;

      User newUser(name, email, password, id);
      add_user(newUser);
    }
  }
}

void System::loadServers()
{
  string server_logged, channel_logged, type_of_channel;
  if(serverLogged != nullptr)  
  {
   server_logged = serverLogged->get_name();
  }
  if(channelLogged != nullptr)
  {
    channel_logged = channelLogged->get_name();
    if (ChannelVoice *cv = dynamic_cast<ChannelVoice *>(channelLogged))
    {
      type_of_channel = "VOZ";
    }
    else
    {
      type_of_channel = "TEXTO";
    }
  }
    
  allTextChannels = vector<ChannelText>();
  allVoiceChannels = vector<ChannelVoice>();
  allServers = vector<Server>();

  ifstream archive("../data/servers.txt");

  if (archive.is_open())
  {
    int amount_of_servers;
    string line;

    getline(archive, line);
    istringstream ss(line);
    ss >> amount_of_servers;

    for (int i = 0; i < amount_of_servers; i++)
    {
      int owner_id, amount_of_participants, amount_of_channels;
      string name, description, code_invite;

      getline(archive, line);
      istringstream sa(line);
      sa >> owner_id;

      getline(archive, line);
      istringstream sb(line);
      name = sb.str();
      Server newServer(name);
      newServer.set_owner_ID(owner_id);

      getline(archive, line);
      istringstream sc(line);
      description = sc.str();
      newServer.set_description(description);

      getline(archive, line);
      istringstream sd(line);
      sd >> code_invite;
      newServer.set_code_invite(code_invite);

      getline(archive, line);
      istringstream se(line);
      se >> amount_of_participants;

      for(int j=0; j<amount_of_participants; j++){
        int participant_id;

        getline(archive, line);
        istringstream sf(line);
        sf >> participant_id;

        newServer.add_participant_ID(participant_id);
      }

      getline(archive, line);
      istringstream sf(line);
      sf >> amount_of_channels;

      for (int j = 0; j < amount_of_channels; j++)
      {
        string name, type;

        getline(archive, line);
        istringstream sg(line);
        name = sg.str();

        getline(archive, line);
        istringstream sh(line);
        sh >> type;

        if(type == "TEXTO")
        {
          int amount_of_messages;
          ChannelText newChannel(name);

          getline(archive, line);
          istringstream si(line);
          si >> amount_of_messages;

          for(int k=0; k<amount_of_messages; k++){
            int id_send_from;
            string content, date_hour, send_from;

            getline(archive, line);
            istringstream sj(line);
            sj >> id_send_from;

            getline(archive, line);
            istringstream sk(line);
            date_hour = sk.str();

            getline(archive, line);
            istringstream sl(line);
            content = sl.str();

            send_from = find_user(id_send_from)->get_name();

            Message message( date_hour, send_from, content, id_send_from);
            newChannel.add_message(message);
          }

          add_channel(newChannel);
          newServer.add_channel(find_text_channel(name));
        }
        else
        {
          int amount_of_messages;
          ChannelVoice newChannel(name);

          getline(archive, line);
          istringstream si(line);
          si >> amount_of_messages;

          if(amount_of_messages == 1)
          {
            int id_send_from;
            string content, date_hour, send_from;

            getline(archive, line);
            istringstream sj(line);
            sj >> id_send_from;

            getline(archive, line);
            istringstream sk(line);
            date_hour = sk.str();

            getline(archive, line);
            istringstream sl(line);
            content = sl.str();

            send_from = find_user(id_send_from)->get_name();

            Message message(date_hour, send_from, content, id_send_from);
            newChannel.set_last_message(message);

          }
          
          add_channel(newChannel);
          newServer.add_channel(find_voice_channel(name));
        }
      }

      add_server(newServer);
    }
  }

  if(server_logged != string()) serverLogged = find_server(server_logged);
  if(channel_logged != string())
  {
    if(type_of_channel == "TEXTO")
    {
      channelLogged = find_text_channel(channel_logged);
    }
    else
    {
      channelLogged = find_voice_channel(channel_logged);
    }
  }
}

void System::load()
{
  loadUsers();
  loadServers();
}
