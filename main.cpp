#include <string>
#include <utility>
#include <sstream>
#include "classes/factories/BrainFactory.h"
#include "classes/repositories/NeuronRepository.h"
#include "classes/repositories/NeuronConrollerRepository.h"

class User {
public:
    unsigned long id = 0;
    std::string name;

    explicit User(std::string newName): name(std::move(newName)) {};
};

class Repository {
public:
    std::vector<User> users;

    Repository() {
        users.reserve(10);
    }

    unsigned long addUser(User user) {
        user.id = users.size();
        users.push_back(user);
        return user.id;
    }

    User* getUser(unsigned long id) {
        return &users[id];
    }

    std::vector<User> getVector() {
        return users;
    }
};

int main() {
    Repository repository;

    for (int i = 0; i < 10; i += 1) {
        std::stringstream ss;
        ss << "User number: " << i;
        repository.addUser(User(ss.str()));
    }

    std::string additionalText (": some additional text");

    for(auto &data: repository.users) {
        data.name = data.name + additionalText;
    }

    return 0;
    NeuronRepository neuronRepository;

    Brain brain = BrainFactory::createBrain();
    brain.proceed();
    return 0;
}