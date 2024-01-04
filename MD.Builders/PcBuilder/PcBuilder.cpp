#include <iostream>
#include <string>
using namespace std;
// Product class
class Computer {
public:
 void setCPU(const std::string& cpu)
 {
 cpu_ = cpu;
 }

 void setMemory(const std::string& memory)
 {
 memory_ = memory;
 }

 void setStorage(const std::string& storage)
 {
 storage_ = storage;
 }

 void setMOBO(const std::string& mobo)
 {
    mobo_=mobo;
 }

  void setGPU(const std::string& gpu)
 {
    gpu_=gpu;
 }
 void display() {
 std::cout << "CPU: " << cpu_ << std::endl;
 std::cout << "Memory: " << memory_ << std::endl;
 std::cout << "Storage: " << storage_ << std::endl;
 std::cout << "Motherboard: " << mobo_ << std::endl;
 std::cout << "Graphic Card:: " << gpu_ << std::endl;
 }
private:
 std::string cpu_;
 std::string memory_;
 std::string storage_;
 std::string mobo_;
 std::string gpu_;
};
// Builder interface
class ComputerBuilder {
public:
 virtual void buildCPU(const std::string& cpu) = 0;
 virtual void buildMemory(const std::string& memory) = 0;
 virtual void buildStorage(const std::string& storage) = 0;
virtual void buildMOBO(const std::string& mobo) = 0;
 virtual void buildGPU(const std::string& gpu) = 0;
 virtual Computer getResult() = 0;
};
// Concrete Builder
class DesktopComputerBuilder : public ComputerBuilder {
public:
 DesktopComputerBuilder() 
 {
 computer_ = Computer();
 }

 void buildCPU(const std::string& cpu) override 
 {
 computer_.setCPU(cpu);
 }

 void buildMemory(const std::string& memory) override 
 {
 computer_.setMemory(memory);
 }

 void buildStorage(const std::string& storage) override 
 {
 computer_.setStorage(storage);
 }

 void buildMOBO(const std::string& mobo) override 
 {
 computer_.setMOBO(mobo);
 }

 void buildGPU(const std::string& gpu) override 
 {
 computer_.setGPU(gpu);
 }

 Computer getResult() override 
 {
 return computer_;
 }
private:
 Computer computer_;
};
// Director
class ComputerAssembler {
public:
 Computer assembleComputer(ComputerBuilder& builder) {
 builder.buildCPU("Intel i5 7600K");
 builder.buildMemory("2x16GB GDDR4");
 builder.buildStorage("Samsung 970 Evo Plus 512GB M.2");
 builder.buildMOBO("Asus ROG Strix Z270e gaming");
 builder.buildGPU("Asus ROG Strix RX480 OC 8GB");
 return builder.getResult();
 }
};
    class ComputerAssembler2 {
    public:
        Computer assembleComputer(ComputerBuilder& builder) {
            builder.buildCPU("Ryzen 5 7600X");
            builder.buildMemory("2x16GB GDDR5");
            builder.buildStorage("Crucial 1TB M.2");
            builder.buildMOBO("Asus ROG Strix EXTREME X674F");
            builder.buildGPU("Gigabyte RTX4070 Windforce OC 12GB");
            return builder.getResult();
        }
    };

int main() {
 DesktopComputerBuilder desktopBuilder;
 ComputerAssembler assembler;
 Computer desktop = assembler.assembleComputer(desktopBuilder);
 std::cout << "Desktop Computer Configuration:" << std::endl;
 desktop.display();

    cout<<endl<<endl;

    DesktopComputerBuilder desktopBuilder2;
    ComputerAssembler assembler2;
    Computer desktop2 = assembler2.assembleComputer(desktopBuilder2);
    std::cout << "Desktop Computer Configuration:" << std::endl;
    desktop.display();
 return 0;
}
