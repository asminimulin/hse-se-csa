from libfilm.film import Film
from libfilm.cartoon import Cartoon
from libfilm.documentary import Documentary

class FilmPrinter:
    def __init__(self, output_filename: str) -> None:
        self._file = open(output_filename, 'w')

    def print(self, film: Film):
        self._file.write(f"Film name: {film.name}\n")
        self._file.write(f"Film release year: {film.release_year}\n")
        if isinstance(film, Cartoon):
            self._file.write(f"Film type: cartoon\nCartoon type: {str(film.type)}\n")
        elif isinstance(film, Documentary):
            self._file.write(f"Film type: documentary\nFilm duration: {str(film.duration)}\n")
        else:
            self._file.write(f"Film type: fiction\nFilm director: {film.director}\n")
        self._file.write(f"Release year divided by name length: {film.release_year_divided_by_film_length()}")

    def print_container_size(self, films_count):
        self._file.write(f"Films count in container {films_count}\n")
