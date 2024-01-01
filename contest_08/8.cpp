#include <iostream>
#include <string>

class Document{
    std::string data;
public:
    Document(std::string data):data(data){
    }

    const std::string& get() const{
        return data;
    }
};

class PrintStrategy {
public:
    virtual void print(const Document& document) = 0;
};


class Printer {
    PrintStrategy* strategy;
    
public:
    Printer(PrintStrategy* strategy):strategy(strategy){
    }

    void setStrategy(PrintStrategy* strategy) {
        delete this->strategy;
        this->strategy = strategy;
    }
    
    void print(const Document& doc) {
        if (strategy == nullptr) exit(1);
        
        strategy->print(doc);
    }
    
    ~Printer(){
        delete strategy;
    }
};

// Начало вставленного кода
class ScreenPrintStrategy : public PrintStrategy {
public:
    void print(const Document& document) override {
        std::cout << document.get() << "\n";
    }
};

class StringPrintStrategy : public PrintStrategy {
private:
    std::string buff;
    int count;
public:
    StringPrintStrategy() {
        count = 1;
    }
    void print(const Document& document) override {
        buff += "--- doc " + std::to_string(count) + " ---\n";
        buff += document.get();
        buff += "\n";
        count++;
    }
    std::string getPrintedDocuments() {
        return buff;
    }
};

class MockPrintStrategy : public PrintStrategy {
private:
    int count;
public:
    MockPrintStrategy() {
        count = 0;
    }
    void print(const Document& document) override {
        count++;
    }
    int getPrintedDocumentsCount() {
        return count;
    }
};
// Конец вставленного кода

int main(){
    Printer printer(new ScreenPrintStrategy());

    int count;
    std::cin >> count; std::cin.ignore(1);
    while(count--){
        std::string data;
        std::getline(std::cin, data);
        printer.print(Document(data)); // Печать документа на экран
    }
    
    StringPrintStrategy* stringStrategy = new StringPrintStrategy();
    printer.setStrategy(stringStrategy);
    std::cin >> count; std::cin.ignore(1);
    while(count--){
        std::string data;
        std::getline(std::cin, data);
        printer.print(Document(data)); // Печать документа в строку
    }
    std::cout << stringStrategy->getPrintedDocuments() << std::endl;
    
    
    MockPrintStrategy* mockStrategy = new MockPrintStrategy();
    printer.setStrategy(mockStrategy);
    std::cin >> count; std::cin.ignore(1);
    while(count--){
        std::string data;
        std::getline(std::cin, data);
        printer.print(Document(data)); // Имитация печати, на самом деле просто подсчёт
    }
    std::cout << mockStrategy->getPrintedDocumentsCount() << std::endl;
}
