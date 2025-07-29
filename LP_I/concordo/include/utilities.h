#include <ctime>
#include <chrono>
#include <iostream>
#include <fstream>

#include "system.h"

/*!
 * Creates a new user in the system.
 *
 * \param system The adress of the system.
 * \param email The email of the user.
 * \param password The password of the user.
 * \param name The name of the user.
 */
void create_user(System &system, string email, string password, string name){
  if(system.find_user(email) == nullptr){
    User newUser(name, email, password, system.get_all_users().size()+1);
    system.add_user(newUser);

    cout << "\"Usuário criado\"\n";
  }
  else{
    cout << "\"Usuário já existe\"\n";
  }
};

/*!
 * Logs in a user to the system.
 *
 * \param system The adress of the system.
 * \param email The email of the user.
 * \param password The password of the user.
 */
void login(System &system, string email, string password){
  if(system.find_user(email) != nullptr){
    User *user = system.find_user(email);
    if(user->get_password() == password){
      system.set_user_logged_ID(user->get_ID());
      system.set_server_logged();
      system.set_channel_logged();
      cout << "\"Logado como " << email << "\"\n";
    }
    else{
      cout << "\"Senha ou usuário inválidos!\"\n";
    }
  }
  else{
    cout << "\"Senha ou usuário inválidos!\"\n";
  }
}

/*!
 * Creates a new server in the system.
 *
 * \param system The adress of the system.
 * \param name The name of the server.
 */
void create_server(System &system, string name){
  if(system.find_server(name) == nullptr){
    Server newServer(name);
    newServer.set_owner_ID(system.get_user_logged_ID());
    newServer.add_participant_ID(system.get_user_logged_ID());
    system.add_server(newServer);

    cout << "\"Servidor criado\"\n";
  }
  else
  {
    cout << "\"Servidor com esse nome já existe\"\n";
  }
}

/*!
 * Sets the description of a server.
 *
 * \param system The adress fo the system.
 * \param name The name of the server.
 * \param description The new description for the server.
 */
void set_description(System &system, string name, string description){
  if(system.find_server(name) != nullptr){
    Server* server = system.find_server(name);
    if(server->get_owner_ID() == system.get_user_logged_ID()){
      server->set_description(description);

      cout << "\"Descrição do servidor \'" << name << "\' modificada!\"\n";
    }
    else{
      cout << "\"Você não pode alterar a descrição de um servidor que não foi criado por você\"\n";
    }
  }
  else{
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
}

/*!
 * Sets the invitation code of a server.
 *
 * \param system The adress fo the system.
 * \param name The name of the server.
 * \param code The new invitation code for the server.
 */
void set_code(System &system, string name, string code){
  if (system.find_server(name) != nullptr)
  {
    Server *server = system.find_server(name);
    if (server->get_owner_ID() == system.get_user_logged_ID())
    {
      server->set_code_invite(code);
      if(code != ""){
        cout << "\"Código de convite do servidor \'" << name << "\' modificado!\"\n";
      }
      else {
        cout << "\"Código de convite do servidor \'" << name << "\' removido!\"\n";
      }
    }
    else
    {
      cout << "\"Você não pode alterar o código de convite de um servidor que não foi criado por você\"\n";
    }
  }
  else
  {
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
}

/*!
 * Removes a new server from the system.
 *
 * \param system The adress of the system.
 * \param name The name of the server.
 */
void remove_server(System &system, string name){
  if (system.find_server(name) != nullptr)
  {
    Server *server = system.find_server(name);
    if (server->get_owner_ID() == system.get_user_logged_ID())
    {
      system.rem_server(*server);
      cout << "\"Servidor \'" << name << "\' removido\"\n";
    }
    else
    {
      cout << "\"Você não é o dono do servidor \'" << name << "\'\"\n";
    }
  }
  else
  {
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
};

/*!
 * Enters a server.
 *
 * \param system The adress of the system.
 * \param name The name of the server.
 * \param code The invite code for the server.
 */
void enter_server(System &system, string name, string code){
  if(system.find_server(name) != nullptr){
    Server* server = system.find_server(name);
    if(server->get_code_invite() == code || server->get_owner_ID() == system.get_user_logged_ID()){
      server->add_participant_ID(system.get_user_logged_ID());
      server->set_user_ID(system.get_user_logged_ID());
      system.set_server_logged(server);
      cout << "\"Entrou no servidor com sucesso\"\n";
    }
    else{
      cout << "\"Servidor requer código de convite\"\n";
    }
  }
  else
  {
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
}

/*!
 * Leaves the server being visualized.
 *
 * \param system The adress of the system.
 */
void leave_server(System &system){
  if(system.get_server_logged() != nullptr){
    Server *server = system.find_server(system.get_server_logged()->get_name());
    server->set_user_ID(-1);
    system.set_server_logged();
    cout << "\"Saindo do servidor \'" <<  server->get_name() << "\'\"\n";
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

/*!
 * Lists all the participants of the server being visualized.
 *
 * \param system The adress of the system.
 */
void list_participants(System &system){
  if (system.get_server_logged() != nullptr)
  {
    Server* server = system.get_server_logged();
    for (int partID : server->get_participant_IDs())
    {
      User *part = system.find_user(partID);
      cout << part->get_name() << endl;
    }
  }
  else 
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

/*!
 * Lists all the channels of the server being visualized.
 *
 * \param system The adress of the system.
 */
void list_channels(System &system)
{
  if (system.get_server_logged() !=  nullptr)
  {
    Server* server = system.get_server_logged();
    cout << "#canais de texto\n";
    for (Channel* c : server->get_channels())
    {
      if (ChannelText *ct = dynamic_cast<ChannelText *>(c))
      {
        cout << ct->get_name() << endl;
      }
    }
    cout << "#canais de audio\n";
    for (Channel *c : server->get_channels())
    {
      if (ChannelVoice *cv = dynamic_cast<ChannelVoice *>(c))
      {
        cout << cv->get_name() << endl;
      }
    }
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

/*!
 * Creates a channel on the server being visualized.
 *
 * \param system The adress of the system.
 * \param name The name of the channel to be created.
 * \param type The type of the channel to be created.
 */
void create_channel(System &system, string name, string type){
  if (system.get_server_logged() != nullptr)
  {
    Server* server = system.find_server(system.get_server_logged()->get_name());

    if(type == "texto"){
      for (Channel *c : server->get_channels())
      {
        if (ChannelText *ct = dynamic_cast<ChannelText *>(c))
        {
          if (ct->get_name() == name){
            cout << "\"Canal de texto \'" << name << "\' já existe!\"\n";
            return;
          }
        }
      }
      ChannelText newChannel(name);
      system.add_channel(newChannel);
      server->add_channel(system.find_text_channel(name));

      cout << "\"Canal de texto \'" << name << "\' criado\"\n";
    }
    else if (type == "voz")
    {
      for (Channel *c : server->get_channels())
      {
        if (ChannelVoice *ct = dynamic_cast<ChannelVoice *>(c))
        {
          if (ct->get_name() == name)
          {
            cout << "\"Canal de voz \'" << name << "\' já existe!\"\n";
            return;
          }
        }
      }
      ChannelVoice newChannel(name);
      system.add_channel(newChannel);
      server->add_channel(system.find_voice_channel(name));

      cout << "\"Canal de voz \'" << name << "\' criado\"\n";
    }
    else{
      cout << "Tipo de canal inválido.\n Tipos de canais disponíveis:\n - texto\n - voz\n";
    }
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

/*!
 * Enters a channel of the server being visualized.
 *
 * \param system The adress of the system.
 * \param name The name of the channel.
 */
void enter_channel(System &system, string name)
{
  if (system.get_server_logged() != nullptr)
  {
    if(system.get_channel_logged() == nullptr){
      Server *server = system.find_server(system.get_server_logged()->get_name());
      ChannelText *ct = system.find_text_channel(name);
      ChannelVoice *cv = system.find_voice_channel(name);

        if(ct == nullptr && cv != nullptr){
          system.set_channel_logged(cv);
          cout << "\"Entrou no canal \'" << name << "\'\"\n";
          return;
        }
        else if(cv == nullptr && ct != nullptr){
          system.set_channel_logged(ct);
          cout << "\"Entrou no canal \'" << name << "\'\"\n";
          return;
        } 
        else if(cv != nullptr && ct != nullptr ){
          string type;
          cout << "Existem dois canais com esse nome. Informe o tipo do canal:(texto ou voz)\n";
          getline(cin, type);
          if(type == "texto"){
            system.set_channel_logged(ct);
          } else{
            system.set_channel_logged(cv);
          }
          cout << "\"Entrou no canal \'" << name << "\'\"\n";
        }
        else{
          cout << "\"Canal \'" << name << "\' não existe\"\n";
        }
    }
    else{
      cout << "\"Você já está visualizando um canal!\"\n";
    }
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

/*!
 * Leaves the channel being visualized.
 *
 * \param system The adress of the system.
 */
void leave_channel(System &system)
{
  if (system.get_server_logged() != nullptr)
  {
    if (system.get_channel_logged() != nullptr)
    {
      system.set_channel_logged();
      cout << "\"Saindo do canal\"\n";
    }
    else
    {
      cout << "\"Você não está visualizando nenhum canal!\"\n";
    }
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

/*!
 * Formats the time to the format wanted.
 *
 * \param timePoint The time to be formated.
 * \param format The format wanted.
 */
string formatDateTime(const chrono::system_clock::time_point &timePoint, const string &format)
{
  time_t currentTime = chrono::system_clock::to_time_t(timePoint);
  tm *timeinfo = localtime(&currentTime);

  const int bufferSize = 100;
  char buffer[bufferSize];

  strftime(buffer, bufferSize, format.c_str(), timeinfo);

  return string(buffer);
}

/*!
 * Sends a message on the channel logged.
 *
 * \param system The adress of the system.
 * \param content The content of the message sent.
 */
void send_message(System &system, string content){
  Server* s = system.get_server_logged();
  Channel* c = system.get_channel_logged();
  int userID = system.get_user_logged_ID();
  string sendFrom = system.find_user(userID)->get_name();

  if (s == nullptr)
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
    return;
  }
  if(c == nullptr){
    cout << "\"Você não está visualizando nenhum canal!\"\n";
    return;
  }
  chrono::system_clock::time_point now = chrono::system_clock::now();
  string dateHour = formatDateTime(now, "<%d/%m/%Y - %H:%M>");

  Message newMessage(dateHour, sendFrom, content, userID);

  if (ChannelVoice *ct = dynamic_cast<ChannelVoice *>(c))
  {
    ct->set_last_message(newMessage);
  }
  else
  {
    ChannelText *cv = dynamic_cast<ChannelText *>(c);
    cv->add_message(newMessage);
  }
}

/*!
 * Lists the messages of the channel logged.
 *
 * \param system The adress of the system.
 */
void list_messages(System &system){
  Server *s = system.get_server_logged();
  Channel *c = system.get_channel_logged();

  if (s == nullptr)
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
    return;
  }
  if (c == nullptr)
  {
    cout << "\"Você não está visualizando nenhum canal!\"\n";
    return;
  }

  if (ChannelVoice *ct = dynamic_cast<ChannelVoice *>(c)){
    if(ct->get_last_message() != Message()){
      ct->list_channel();
    }
    else{
      cout << "\"Sem mensagem para exibir\"\n";
    }
  }else{
    ChannelText *cv = dynamic_cast<ChannelText *>(c);
    if(!(cv->get_messages().empty())){
      cv->list_channel();
    }
    else
    {
      cout << "\"Sem mensagens para exibir\"\n";
    }
  }
}

