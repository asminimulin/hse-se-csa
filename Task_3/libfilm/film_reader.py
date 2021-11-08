from libfilm.cartoon import Cartoon
from libfilm.documentary import Documentary
from libfilm.fiction import Fiction
from libfilm.film import Film

class MalformedInput(Exception):
    def __init__(self, *args: object) -> None:
        super().__init__(*args)


class FilmReader:
    def __init__(self, filename: str) -> None:
        self._file = open(filename, 'r')

    def read_films_count(self) -> int:
        try:
            films_count = int(self._file.readline())
            if films_count < 0:
                raise MalformedInput("Films count is negative")
            return films_count
        except Exception as e:
            raise MalformedInput(e)

    def read_film(self) -> Film:
        try:
            film_name = self._file.readline()[:-1]
            release_year = int(self._file.readline()[:-1])
            film_type = Film.FilmType(self._file.readline()[:-1])
            if film_type == Film.FilmType.CARTOON:
                cartoon_type = Cartoon.CartoonType(self._file.readline()[:-1])
                return Cartoon(film_name, release_year, cartoon_type)
            elif film_type == Film.FilmType.DOCUMENTARY:
                duration = int(self._file.readline()[:-1])
                if duration < 0:
                    raise MalformedInput("Duration is negative")
                return Documentary(film_name, release_year, duration)
            else:  # film_type == Film.FilmType.FICTION
                director = self._file.readline()[:-1]
                if len(director) == 0:
                    raise MalformedInput("Empty director name")
                return Fiction(film_name, release_year, director)
        except Exception as e:
            raise MalformedInput(e)
