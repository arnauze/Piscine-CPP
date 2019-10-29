# include "ShruberryCreationForm.hpp"
# include <fstream>
# include <sstream>

ShruberryCreationForm::ShruberryCreationForm(void) : Form("Shruberry", 145, 37), target("default") {
    return ;
}

ShruberryCreationForm::ShruberryCreationForm(std::string target) : Form("Shruberry", 145, 37), target(target) {
    return ;
}

ShruberryCreationForm::~ShruberryCreationForm(void) {
    return ;
}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm const & form) : Form("Shruberry", 145, 37) {
    *this = form;
    return ;
}

ShruberryCreationForm          &ShruberryCreationForm::operator=(ShruberryCreationForm const & form) {
    this->target = form.getTarget();
    return *this;
}

void                            ShruberryCreationForm::setTarget(std::string const & target) {
    this->target = target;
    return ;
}

std::string                     ShruberryCreationForm::getTarget(void) const {
    return this->target;
}

void                            ShruberryCreationForm::execute(Bureaucrat const & bureaucrat) const {
    if (bureaucrat.getGrade() > this->getMinEx())
        throw Bureaucrat::GradeTooLowException();
    // if (!this->isSigned())
    //     throw Form::FormNotSigned();

    std::ofstream           file;
    std::stringstream       oss;

    oss << this->getTarget() << "_shruberry";
    file.open(oss.str().c_str());

    file << ""
			"                                                         ." << std::endl <<
			"                                              .         ;  " << std::endl <<
			"                 .              .              ;%     ;;   " << std::endl <<
			"                   ,           ,                :;%  %;  " << std::endl <<
			"                    :         ;                   :;%;'     .,  " << std::endl <<
			"           ,.        %;     %;            ;        %;'    ,; " << std::endl <<
			"             ;       ;%;  %%;        ,     %;    ;%;    ,%' " << std::endl <<
			"              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl <<
			"               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl <<
			"                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl <<
			"                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl <<
			"                    `:%;.  :;bd%;          %;@%;'" << std::endl <<
			"                      `@%:.  :;%.         ;@@%;'  " << std::endl << 
			"                        `@%.  `;@%.      ;@@%;  " << std::endl <<       
			"                          `@%%. `@%%    ;@@%;  " << std::endl <<      
			"                            ;@%. :@%%  %@@%;  " << std::endl <<     
			"                              %@bd%%%bd%%:;  " << std::endl <<   
			"                                #@%%%%%:;;" << std::endl <<
			"                                %@@%%%::;" << std::endl <<
			"                                %@@@%(o);  . '   " << std::endl <<      
			"                                %@@@o%;:(.,'  " << std::endl <<       
			"                            `.. %@@@o%::;    " << std::endl <<     
			"                               `)@@@o%::;     " << std::endl <<    
			"                                %@@(o)::;     " << std::endl <<   
			"                               .%@@@@%::;         " << std::endl <<
			"                               ;%@@@@%::;.        " << std::endl <<  
			"                              ;%@@@@%%:;;;. " << std::endl <<
			"                          ...;%@@@@@%%:;;;;,..   " << std::endl;

    file.close();
}