from enum import Enum


class Film:
    class FilmType(Enum):
        CARTOON = 'cartoon'
        FICTION = 'fiction'
        DOCUMENTARY = 'documentary'

    def __init__(self, name: str, release_year: int):
        self._name = name
        self._realease_year = release_year

    def release_year_divided_by_film_length(self) -> float:
        if len(self._name) == 0:
            return 0.0
        return self._realease_year / len(self._name)

    @property
    def name(self):
        return self._name

    @property
    def release_year(self):
        return self._realease_year

    def print_details():
        raise NotImplementedError()
