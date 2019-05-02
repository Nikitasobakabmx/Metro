#pragma once
#include <exception>
#include <string>

class except : std::exception
{
    private:
        std::string massage;
    public:
        except(std::string massage)
        {
            this->massage = massage;
        }
        const char* what() const noexcept
        {
            return massage.c_str();
        }
};