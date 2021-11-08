from libfilm.film import Film

class Documentary(Film):
    def __init__(self, name: str, release_year: int, duration: int):
        super().__init__(name, release_year)
        self._duration = duration

    @property
    def duration(self):
        return self._duration
