// song class
// container of songs
// playlist class with sort methods

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Song
{
  public:
    Song(const std::string& name, const std::string& artist)
      : name_ { name }, artist_ { artist } { }

    void print() const
    {
      std::cout << name_ << " - " << artist_;
    }

    std::string get_name() const
    {
      return name_;
    }

  private:
    std::string name_;
    std::string artist_;
};

void print_songs(const std::vector<Song>&);
bool song_exists(const std::vector<Song>& pjesme, const std::string& ime_pjesme);

int main()
{
  std::vector<Song> pjesme;

  pjesme.push_back(Song("Lane moje", "Zeljko Joksimovic"));
  pjesme.push_back(Song("Milimetar", "Zeljko Joksimovic"));
  pjesme.push_back(Song("Halima", "Dino Merlin"));

  print_songs(pjesme);

  if (song_exists(pjesme, "Halim"))
    std::cout << "Ima pjesma\n";
  else
    std::cout << "Nema pjesme\n";

  auto pred = [](const Song& s) { return s.get_name() == "Halima"; };
  auto res = std::find_if(pjesme.begin(), pjesme.end(), pred);
  if (res != pjesme.end())
    std::cout << "Ima pjesma\n";
  else
    std::cout << "Nema pjesme\n";

  std::sort(
    pjesme.begin(),
    pjesme.end(),
    [](const Song& lijeva, const Song& desna) {
      const std::string& ime_lijeve = lijeva.get_name();
      const std::string& ime_desne = desna.get_name();
      return ime_lijeve < ime_desne;
    });

  print_songs(pjesme);
}

void print_songs(const std::vector<Song>& songs)
{
  for (const auto& el : songs)
  {
    el.print();
    std::cout << std::endl;
  }
}

bool song_exists(const std::vector<Song>& pjesme, const std::string& ime_pjesme)
{
  for (const auto& el : pjesme)
  {
    const auto& el_ime = el.get_name();
    if (el_ime == ime_pjesme)
      return true;
  }
  return false;
}
