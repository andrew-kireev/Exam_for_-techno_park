//
//  main.cpp
//  SmartString
//
//  Created by Andrew Kireev on 20.02.2020.
//  Copyright © 2020 Andrew Kireev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string_view>
#include <utility>


class SmartStr {
public:
    SmartStr() = default;
    SmartStr(const std::string& s){
        std::string new_s = s;
        std::string_view str = s;
        
        while(true) {
            size_t tab = str.find_first_of('\t');
            storage_s.push_back(str.substr(0, tab));
            if (tab == str.npos){
                break;
                
            } else {
                str.remove_prefix(tab + 1);
                
            }
        }
    }

    void Edit(const std::string& s, const size_t& ind_el) {      //Редактирует поле по индексу
        storage_s[ind_el] = move(s);
    }
    void Delete(const size_t& ind_el) {          //Удаляет поле по индексу
        storage_s.erase(storage_s.begin() + ind_el);
    }
    void Add(const std::string& s, const size_t& ind_el) {         //Добавляет элемент на место ind_el
        storage_s.insert(storage_s.begin() + ind_el, move(s));
    }
    friend std::ostream& operator<<(std::ostream& out, const SmartStr& sm_string) {     //Перегрузка стандартного вывода
        for (auto i : sm_string.storage_s) {
            out << i << '\t';
        }
        return out;
    }
    friend std::istream& operator>>(std::istream &os, SmartStr& s_) {
        std::string sup_str;
        os >> sup_str;
        s_ = {sup_str};
        return os;
    }
    
    
private:
    std::vector<std::string_view> storage_s;
};



int main(int argc, const char * argv[]) {
    //std::string ws;   //Можно вводить через стандарный ввод в string, дальше будет создаваться конструктор
    //std::cin >> ws;   //а дальше будет создаваться наш класс принмая в конструкторе эту переменную
    //SmartStr s(s);
    SmartStr s("Here\tyou\tcan\tfind\tactivities\tto\tpractise\tyour\treading\tskills");
    s.Add("kruto", 4);
    s.Delete(2);
    s.Delete(0);
    s.Edit("Prekrasno", 1);
    std::cout << s;
    return 0;
}
