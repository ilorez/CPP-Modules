
int main()
{
  PhoneBook phonebook;
  Contact *contact;

  std::cout << "Hello in WooW phonebook." << std::endl;
  std::cout << "Command List:" << std::endl;
  std::cout << "\tADD: add new contact" << std::endl;
  std::cout << "\tSEARCH: search in contacts" << std::endl;
  std::cout << "\tEXIT: exit phonebook" << std::endl;
  while (1)
  {
    std::string cmd;
    std::wint_t index;
    std::cout << "Write A Command: ";
    std::getline(std::cin, cmd);
    if (std::cin.eof())
        return (0);
    if (cmd == "ADD")
      phonebook.addContact();
    else if (cmd == "SEARCH")
    {
      if (!phonebook.getSize())
      {
        std::cout << "Phone book is empty!" << std::endl;
        continue;
      }
        
      phonebook.printAll();
      std::cout << "get info of (1-8): ";
      std::cin >> index;
      if (std::cin.eof())
        return (0);
      contact = phonebook.getContact(index);
      if (!contact)
          continue;
      contact->printInfo();
    }
    else if (cmd == "EXIT")
        break;
    else
      std::cout << "Command not found" << std::endl;
  }
}
