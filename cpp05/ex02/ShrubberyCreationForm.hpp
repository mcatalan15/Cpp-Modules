#ifdef PRESIDENTIALPERDONFORM_HPP
# define PRESIDENTIALPERDONFORM_HPP

# include <iostream>
#include "AForm.hpp"

# define MIN_GRADE_SIGN_PP 25
# define MIN_GRADE_EXECUTE_PP 5

using std::string;

class ShrubberyCreationForm : public AForm {

  private:
    const string _target;

  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src) = default;
    ~ShrubberyCreationForm();
    
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
    string  getTarget() const;
    void    executeConcreteForm() const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form);

#endif
