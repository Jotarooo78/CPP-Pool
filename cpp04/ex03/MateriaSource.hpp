#ifndef MATERIASOURCE
#define MATERIASOURCE

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {

    private :
        AMateria *_materias[4];

    public :
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator=(const MateriaSource &copy);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
} ;
#endif