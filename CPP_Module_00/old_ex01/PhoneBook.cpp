#include <cwctype>
#include <iostream>


// TODO: use getline instead of std::cin >>
// create a fucntion that get input and tests if it not valid like when user click "CTRL+D"
// reformat code
class Contact {
private:
  std::string firstn, lastn, nickname, num, secret; public:
  Contact() {}
  Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string dark_secret): firstn(first_name), lastn(last_name), nickname(nickname), num(phone_number), secret(dark_secret){}
  // setters
  /*void setFirstName(std::string str){
    this->firstn = str;
  }
  void setLastName(std::string str){ this->lastn = str; } void setNickname(std::string str){ this->nickname = str;
  }
  void setPhoneNumber(std::string str){
    this->num = str;
  }
  void setDarkSecret(std::string str){
    this->secret = str;
  }*/
  // getters
  std::string getFirstName(){
    return this->firstn;
  }
  std::string getLastName(){
    return this->lastn;
  }
  std::string getNickname(){
    return this->nickname;
  }
  std::string getPhoneNumber(){
    return this->num;
  }
  std::string getDarkSecret(){
    return this->secret;
  }

  void printInfo ()
  {
    std::cout << "First Name: " << this->firstn << std::endl;
    std::cout << "Last Name: " << this->lastn << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "phone_number: " << this->num << std::endl;
    std::cout << "Dark Secret: " << this->secret << std::endl;
  };

  void createContact()
  {
    std::cout << "First Name: ";
    std::cin >> this->firstn;
    std::cout << "Last Name: ";
    std::cin >> this->lastn;
    std::cout << "Nickname: ";
    std::cin >> this->nickname;
  }
};


class PhoneBook {
  private:
    Contact list[8];
    int index;
    int size;
    char hdelim;
    char vdelim;
    void _columnTUI(std::string str, int len)
    {
      int sp = 0;
      int plen;

      if (len >= 10)
      {
        sp = 0; // no spaces if number of chars is 7 or more
        plen = 9; 
      }
      else
      {
        sp = (10 - len);
        plen = len;
      }
      std::cout << vdelim << std::string(sp/2, ' ') << std::string(str.begin(), str.begin() + plen) <<  char ('.' * (len >= 10)) << std::string(sp/2, ' ')  << char(' ' * (sp % 2));
    }
    void _printContatColumn(char id, Contact c)
    {
        std::string tmp;

        _columnTUI(std::string(2, id), 1);
        tmp = c.getFirstName();
        _columnTUI(tmp, tmp.length());
        tmp = c.getLastName();
        _columnTUI(tmp, tmp.length());
        tmp = c.getNickname();
        _columnTUI(tmp, tmp.length());
    }
  public:
    PhoneBook()
    {
      this->index = 0;
      this->size = 0;
      this->vdelim = '|';
      this->hdelim = '-';
    }
    void addContact()
    {
      Contact contact;
      contact.createContact();
      if (index >= 8)
        index = 0;
      list[index++] = contact;
      size++;
      if (size > 8)
        size = 8;
    }
    int getSize()
    {
      return (this->size);
    }
    Contact *getContact(int index)
    {
      if (index >= this->size)
      {
        std::cout << "Incorrect Index." << std::endl;
        return (NULL);
      }
      return (&(this->list[index]));
    }
    void printAll()
    {
      if (!this->size)
      {
        std::cout << "Phone book is empty!" << std::endl;
        return ;
      }
      std::cout << "┌"  << std::string(4*10+3, hdelim) << "┐"<< std::endl;
      //std::cout << vdelim  << " index. " << vdelim << "FrstName" << vdelim << "LastName" <<  "NickName" << vdelim << std::endl;
      for (int i = 0; i < index; i++)
      {
        _printContatColumn(i+49, list[i]);
        std::cout << vdelim << std::endl;
      }
      std::cout << "└"  << std::string(4*10+3, hdelim) << "┘"<< std::endl;
    }
};


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
