#include <iostream>
#include <sstream>
#include "utilities.h"

using namespace std;

int main(){
  System system;
  bool quit = false;

  while(true){
    string entry;
    string command;

    system.load();

    getline(cin, entry);

    istringstream ss(entry);
    ss >> command;
    
    if (command == "quit")
    {
      quit = true;
    }
    else if (command == "create-user")
    {
      if(!system.is_logged())
      {
        string email;
        string senha;
        string name;

        ss >> email >> senha;
        getline(ss, name);
        name.erase(0,1);

        create_user(system, email, senha, name);
        system.save();
      }
      else
      {
        cout << "\"Usuário já logado\"\n";
      }
    }
    else if (command == "login")
    {
      if (!system.is_logged())
      {
        string email;
        string senha;

        ss >> email >> senha;

        login(system, email, senha);
      }

      else
      {
        cout << "\"Usuário já logado\"\n";
      }
    }
    else if(command == "disconnect"){
      if(system.is_logged()){
        system.disconnect();
        cout << "\"Desconectando usuário " << system.find_user(system.get_user_logged_ID())->get_email() << "\"\n";
      }
      else{
        cout << "\"Não está conectado\"\n";
      }
    }
    else if(command == "create-server"){
      if(system.is_logged()){
        string name;
        ss >> name;

        create_server(system, name);
        system.save();
      }
      else{
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "set-server-desc"){
      if (system.is_logged())
      {
        string name;
        string description;

        ss >> name;
        getline(ss, description);
        description.erase(0, 1);

        set_description(system, name, description);
        system.save();
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if(command == "set-server-invite-code"){
      if (system.is_logged())
      {
        string name;
        string code;

        ss >> name >> code;

        set_code(system, name, code);
        system.save();
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if(command == "list-servers"){
      if(system.is_logged()){
        for(Server s : system.get_all_servers()){
          cout << s.get_name() << endl;
        }
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "remove-server")
    {
      if (system.is_logged())
      {
        string name;

        ss >> name;

        remove_server(system, name);
        system.save();
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "enter-server")
    {
      if (system.is_logged())
      {
        string name;
        string code;

        ss >> name >> code;

        enter_server(system, name, code);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "leave-server")
    {
      if (system.is_logged())
      {
        leave_server(system);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "list-participants")
    {
      if (system.is_logged())
      {
        list_participants(system);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "list-channels")
    {
      if (system.is_logged())
      {
        list_channels(system);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "create-channel")
    {
      if (system.is_logged())
      {
        string name;
        string type;

        ss >> name >> type;

        create_channel(system, name, type);
        system.save();
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "enter-channel")
    {
      if (system.is_logged())
      {
        string name;

        ss >> name;

        enter_channel(system, name);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "leave-channel")
    {
      if (system.is_logged())
      {
        leave_channel(system);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "send-message")
    {
      if (system.is_logged())
      {
        string content;

        getline(ss, content);
        content.erase(0, 1);

        send_message(system, content);
        system.save();
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "list-messages")
    {
      if (system.is_logged())
      {
        list_messages(system);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
  
    if (quit)
    {
      cout << "\"Saindo do concordo\"\n";
      break;
    }
   
  }
  return 0;
}