#include <iostream>
using namespace std;

class MachinePet {
    protected:
        string nickname;
    public:
        MachinePet(const string &name) : nickname(name) {}

        virtual ~MachinePet() = default;  
        string get_nickname() const {
            return nickname;
        }

        virtual string talk() const = 0;  
};

class PetCat : public MachinePet {
    public:
        PetCat(const string &name) : MachinePet(name) {}

        string talk() const override {
            return "Meow";
        }
};

class PetDog : public MachinePet {
    public:
        PetDog(const string &name) : MachinePet(name) {}

        string talk() const override {
            return "Woof";
        }
};
    