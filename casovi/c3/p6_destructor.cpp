// destructor

#include <iostream>
#include <string>

std::string prefix;

class Logger
{
  public:
    using ID = unsigned int;

    Logger() : id_(++id_counter)
    {
      std::cout << prefix << "Logger kreiran sa id " << id_ << std::endl;
    }

    ~Logger()
    {
      std::cout << prefix << "Logger sa id " << id_ << " unisten" << std::endl;
    }

  private:
    static ID id_counter;
    ID id_;
};

Logger::ID Logger::id_counter = 0;

void os();
void cs();

int main()
{
  Logger l1;
  Logger l2;
  Logger* l3 = new Logger();
  Logger* l4 = new Logger();

  {
    os();
    Logger l5;

    {
      os();
      Logger l6;
      cs();
    }

    Logger();

    Logger l8;
    delete l3;
    cs();
  }

  Logger l9;
}

void os() { prefix.push_back('\t'); }
void cs() { prefix.pop_back(); }
