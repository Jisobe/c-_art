#include <iostream>
#include <string>
using namespace std;

class Artist{
   public:
      Artist();

      Artist(string artistName, int birthYear, int deathYear);

      string GetName() const;

      int GetBirthYear() const;

      int GetDeathYear() const;

      void PrintInfo() const;
   
   private:
      string artistName;
      int birthYear;
      int deathYear;

};

Artist::Artist(){
   artistName = "Unknown";
   birthYear = -1;
   deathYear = -1;
}

Artist::Artist(string artistName, int birthYear, int deathYear){
   this->artistName = artistName;
   this->birthYear = birthYear;
   this->deathYear = deathYear;
}

string Artist::GetName() const{
   return artistName;
}

int Artist::GetBirthYear() const{
   return birthYear;
}

int Artist::GetDeathYear() const{
   return deathYear;
}

void Artist::PrintInfo() const{
   cout << "Artist: " << artistName << " ";

   if (birthYear > 0){
      if (deathYear > 0){
         cout << "(" << birthYear << " to " << deathYear << ")" << endl;
      }
      else{
         cout << "(" << birthYear << " to present" << ")" << endl;
      }
   }else{
      cout << "(" << "unknown" << ")" << endl;
   }
   
}

class Artwork{
   public:
      Artwork();

      Artwork(string title, int yearCreated, Artist artist);

      string GetTitle();

      int GetYearCreated();

      void PrintInfo();
   
   private:
      string title;
      int yearCreated;
      Artist artist;
};

Artwork::Artwork(){
   title = "Unknown";
   yearCreated = -1;
}

Artwork::Artwork(string title, int yearCreated, Artist artist){
   this->title = title;
   this->yearCreated = yearCreated;
   this->artist = artist;
}

string Artwork::GetTitle() { return title; }

int Artwork::GetYearCreated() { return yearCreated; }


void Artwork::PrintInfo(){

   artist.PrintInfo();
   cout << "Title:" << title << ", " << yearCreated << endl;

}

int main() {
   string userTitle, userArtistName;
   int yearCreated, userBirthYear, userDeathYear;

   getline(cin, userArtistName);
   getline(cin, userTitle);
   cin >> userBirthYear;
   cin >> userDeathYear;
   cin >> yearCreated;

   Artist userArtist =  Artist(userArtistName, userBirthYear, userDeathYear);

   Artwork newArtwork = Artwork(userTitle, yearCreated, userArtist);

   newArtwork.PrintInfo();
}