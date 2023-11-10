#include<iostream>
#include<vector>

using namespace std;

struct Movie
{
private:
    string title;
    int year;
    string director;
    float rate;
    vector<float> userRates;
    vector<string> comments;

public:
    Movie(string title, int year, string director, float rate)
        : title(title), year(year), director(director), rate(rate)
    {}
    
        /*Movie(string title, int year, string director, float rate){
            this->title=title;
            this->year = year;
            this->director = director;
            this->rate=rate;
        }*/
    
    void DisplayMovieInfo()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Director: "<<director<<endl;
        cout<<"Rate: "<<rate<<endl;

        for(int i = 0; i < comments.size(); i++)
        {
            cout<<i+1<<": "<<comments[i]<<endl;
        }
        cout<<"----------"<<endl;
    }

    void RateMovie(float yourRate)
    {
        userRates.emplace_back(yourRate);
        rate=0;
        for(int i=0;i < userRates.size();i++)
        {
            rate+=userRates[i];
        }
        rate/=userRates.size();
    }

    void AddComment(string yourComment)
    {
        comments.emplace_back(yourComment);
    }
};


int main()
{    
    Movie movie1("zycie jako wielki Kopernik", 1542, "Mikołaj Kopernik", 0);
    Movie movie2("Moje wlasne obrazy - opinia", 1856, "Jan Matejko", 0);
    Movie movie3("Bitwa pod Grundwaldem", 1410, "Wladyslaw Jagiello", 0);
    Movie movies[3] = {movie1, movie2, movie3};
    
    int selectedMovie = 0;
    int selectedAction = 0;
    float movieRate = 0;
    string comment; 
    while(true)
    {
        movies[0].DisplayMovieInfo();
        movies[1].DisplayMovieInfo();
        movies[2].DisplayMovieInfo();
        cout<<"---------------------------"<<endl;
        cout<<"Wybierz film: (1-3) 0 - wyjscie z programu";
        cin>>selectedMovie;
        
        if(selectedMovie == 0)
            break;
        
        cout<<endl<<"Wybierz akcje: 1 - ocen 2 - dodaj komentarz: ";
        cin>>selectedAction;
        
        if(selectedAction == 1)
        {
            cout<<"Podaj ocene: ";
            cin>>movieRate;
            movies[selectedMovie-1].RateMovie(movieRate);
        }
        if(selectedAction == 2)
        {
            cout<<"Napisz komentarz: ";    
            cin>>comment;
            cin.ignore();
            getline(cin, comment);
            movies[selectedMovie-1].AddComment(comment);
        }
        
    }

    cout<<"Dziekuje za uzycie mojego programu";
}
