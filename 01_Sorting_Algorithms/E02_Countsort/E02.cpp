#include <vector>
#include <iostream>

const int key_max = 10;

struct Person {
    unsigned int key;
    std::string name;
    void show() { std::cout << key << " : " + name << std::endl; };
};

std::vector<Person> countSort(std::vector<Person> personas) {
    std::vector<int> aux(key_max+1, 0);
    std::vector<Person> p2(personas.size(), {0, ""});
    
    for (Person p : personas) {
        aux[p.key]++;
    }

    for (int i = 1; i <= key_max; i++) {
        aux[i] += aux[i - 1];
    }
    
    for (int i = personas.size()-1; i >= 0; i--) {
        p2[aux[personas[i].key]-1] = personas[i];
        aux[personas[i].key]--;
    }

    return p2;
}

int main() {
    std::vector<Person> personas = { {1, "luis"},{3, "pedro"},{2, "ana"},{4, "jaime"},{10, "sara"} };
    personas = countSort(personas);
    
    for (Person persona : personas)
        persona.show();
    
    return 0;
}