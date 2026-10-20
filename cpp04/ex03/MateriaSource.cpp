/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaunito <armaunito@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:25:12 by armosnie          #+#    #+#             */
/*   Updated: 2026/02/08 16:00:14 by armaunito        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {

    for (int i = 0; i < 4; i++) {
    _materias[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {

    for (int i = 0; i < 4; i++) {
        if (_materias[i] != NULL)
            delete _materias[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &copy) {

    for (int i = 0; i < 4; i++) {
        _materias[i] = NULL;
        if (copy._materias[i] != NULL)
            _materias[i] = copy._materias[i]->clone();
    }
}

MateriaSource & MateriaSource::operator=(const MateriaSource &copy) {

    for (int i = 0; i < 4; i++) {
        if (_materias[i] != NULL) {
            delete _materias[i];
            _materias[i] = NULL;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (copy._materias[i] != NULL)
            _materias[i] = copy._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
    if (m == NULL)
        return ;
    for (int i = 0; i < 4; i++) {
        if (_materias[i] == NULL) {
            _materias[i] = m->clone();
            delete m;
            return ;
        }
    }
    delete m;
}

AMateria *MateriaSource::createMateria(std::string const &materia) {

    for (int i = 0; i < 4; i++) {
        if (_materias[i] != NULL && _materias[i]->getType() == materia) {
            return _materias[i]->clone();
        }
    }
    return NULL;
}