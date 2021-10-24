#pragma once

#include <iostream>
#include <memory>

#include "libfilm/film.hpp"

std::unique_ptr<Film> ReadFilm(std::istream& istream);
