#pragma once
#ifndef ROBOCALC_HPP
#define ROBOCALC_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>



class RoboCalc {
public:
    RoboCalc() = default;
    explicit RoboCalc(std::vector<std::string> commands) : commands_(commands) {}
    ~RoboCalc() = default;

    int get_AX() const noexcept;
    void MOV_AX(int var) noexcept;
    std::vector<std::string> get_commands() const noexcept;
    void set_commands(std::vector<std::string> commands) noexcept;

private:
    int AX_ = 0;
    std::vector<std::string> commands_;
};


class OUT : public RoboCalc {
public:
    OUT() = default;
    OUT(RoboCalc& robo, int v) : robo_(robo), var_(v) {}
    ~OUT() = default;
    void out() noexcept;

private:
    RoboCalc& robo_;
    int var_;
};


class REV : public RoboCalc {
public:
    REV() = default;
    REV(RoboCalc& r, int count) : robo_(r), count_(count) {}
    ~REV() = default;
    void rev();

private:
    RoboCalc& robo_;
    int count_;
};


class ADD : public RoboCalc {
public:
    ADD() = default;
    ADD(RoboCalc& r, int number) : robo_(r), num_(number) {}
    ~ADD() = default;
    void addition() noexcept;

private:
    RoboCalc& robo_;
    int num_;
};


class SUB : public RoboCalc {
public:
    SUB() = default;
    SUB(RoboCalc& r, int number) : robo_(r), num_(number) {}
    ~SUB() = default;
    void subtraction() noexcept;

private:
    RoboCalc& robo_;
    int num_;
};


class MUL : public RoboCalc {
public:
    MUL() = default;
    MUL(RoboCalc& r, int number) : robo_(r), num_(number) {}
    ~MUL() = default;
    void multiply() noexcept;

private:
    RoboCalc& robo_;
    int num_;
};


class DIV : public RoboCalc {
public:
    DIV() = default;
    DIV(RoboCalc& r, int number) : robo_(r), num_(number) {}
    ~DIV() = default;
    void division();

private:
    RoboCalc& robo_;
    int num_;
};


void StartProgram(std::string inputfile, std::string outputfile);

#endif 
