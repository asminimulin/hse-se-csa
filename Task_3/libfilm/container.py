from typing import List

from libfilm.film import Film

class Container:
    def __init__(self) -> None:
        self._films: List[Film] = []

    def append_film(self, film: Film):
        self._films.append(film)

    def __getitem__(self, key: int):
        if key < 0 or key >= len(self._films):
            raise IndexError()
        return self._films[key]

    def __len__(self):
        return len(self._films)

    def sort_with_selection_sort(self):
        pos = 0
        while pos != len(self._films):
            index_smallest = pos
            for j in range(index_smallest + 1, len(self._films)):
                if self._films[j].release_year_divided_by_film_length() < self._films[index_smallest].release_year_divided_by_film_length():
                    index_smallest = j
            self._films[pos], self._films[index_smallest] = self._films[index_smallest], self._films[pos]
            pos += 1
