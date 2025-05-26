
#include <string>
using namespace std;
namespace coup{

class Player{
    string name;
    int coins;

    public:
        bool gather();
        bool tax();
        bool bribe();
        bool arrest(Player& who);
        bool sanction(Player& who);
        bool coup(Player& who);
    

};
}