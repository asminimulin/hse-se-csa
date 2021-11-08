from enum import Enum

from libfilm.film import Film


class Cartoon(Film):
    class CartoonType(Enum):
        PUPPET = 'puppet'
        CLAY = 'clay'
        HANDDRAWN = 'handdrawn'

        def __str__(self):
            return str(self.value)

    def __init__(self, name: str, release_year: int, cartoon_type: CartoonType):
        super().__init__(name, release_year)
        self._cartoon_type = cartoon_type

    @property
    def type(self):
        return self._cartoon_type
