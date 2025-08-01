#include "robocalc.hpp"

int RoboCalc::get_AX() const noexcept
{
    return AX_;
}

void RoboCalc::MOV_AX(int var) noexcept
{
    AX_ = var;
}

std::vector<std::string> RoboCalc::get_commands() const noexcept
{
    return commands_;
}

void RoboCalc::set_commands(std::vector<std::string> commands) noexcept
{
    commands_ = commands;
}

void OUT::out() noexcept
{
    robo_.MOV_AX(var_);
}

void REV::rev()
{
    if (count_ > robo_.get_commands().size() && count_ <= 0) {
        throw std::invalid_argument("ERR: Invalid argument for REV");
    }
    
    else {
        std::vector<std::string> copy = robo_.get_commands();
        copy.erase(copy.end() - count_, copy.end());
        robo_.set_commands(copy);
    }
    
}

void ADD::addition() noexcept
{
    robo_.MOV_AX(robo_.get_AX() + num_);
}

void SUB::subtraction() noexcept
{
    robo_.MOV_AX(robo_.get_AX() - num_);
}

void MUL::multiply() noexcept
{
    robo_.MOV_AX(robo_.get_AX() * num_);
}

void DIV::division()
{
    if (num_ == 0) {
        throw std::logic_error("ERR: Division by zero!");
    }
    else {
        robo_.MOV_AX(robo_.get_AX() / num_);
    }
    
}

void StartProgram(std::string inputfile, std::string outputfile)
{

    std::ifstream ifile(inputfile);
    std::ofstream ofile(outputfile);

    if (!ifile.is_open()) {
        std::cout << "ERR: File isn't open!";
        exit(1);
    }
    
    std::string line;
    RoboCalc robo;
    while (std::getline(ifile, line)) {
        int number = std::stoi(line.substr(4));

        if (line.substr(0, 3) == "OUT") {
            OUT out(robo, number);
            out.out();
            for (std::string i : robo.get_commands()) {
                int num = std::stoi(i.substr(4));
                if (i.substr(0, 3) == "MUL") {
                    MUL mul(robo, num);
                    mul.multiply();
                }
                else if (i.substr(0, 3) == "DIV") {
                    DIV div(robo, num);
                    div.division();
                }
                else if (i.substr(0, 3) == "ADD") {
                    ADD add(robo, num);
                    add.addition();
                }
                else if (i.substr(0, 3) == "SUB") {
                    SUB sub(robo, num);
                    sub.subtraction();
                }
            }
            ofile << robo.get_AX() << std::endl;
        }
        else if (line.substr(0, 3) == "REV") {
            REV rev(robo, number);
            rev.rev();
        }
        else {
            std::vector<std::string> com = robo.get_commands();
            com.push_back(line);
            robo.set_commands(com);
        }
    }

    ifile.close();
    ofile.close();

}
