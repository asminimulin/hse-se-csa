from libfilm.film import Film

class Fiction(Film):
    def __init__(self, name: str, release_year: int, director: str):
        super().__init__(name, release_year)
        self._director = director

    @property
    def director(self):
        return self._director
