from random import Random

from libfilm.film import Film
from libfilm.cartoon import Cartoon
from libfilm.documentary import Documentary
from libfilm.fiction import Fiction

class FilmGenerator:
    def __init__(self, seed: int):
        self._random = Random(seed)

    def generate_film(self) -> Film:
        film_type = self._random.choice([Film.FilmType.CARTOON,
                                         Film.FilmType.DOCUMENTARY,
                                         Film.FilmType.FICTION])
        film_name = self._gen_string()
        release_year = self._random.randint(1900, 2000)
        if film_type == Film.FilmType.CARTOON:
            cartoon_type = self._random.choice([Cartoon.CartoonType.CLAY,
                                                Cartoon.CartoonType.PUPPET,
                                                Cartoon.CartoonType.HANDDRAWN])
            return Cartoon(film_name, release_year, cartoon_type)
        elif film_type == Film.FilmType.DOCUMENTARY:
            duration = self._random.randint(100, 1000)
            return Documentary(film_name, release_year, duration)
        else:
            return Fiction(film_name, release_year, self._gen_string())

    def _gen_string(self) -> str:
        alphabet = 'abcdefghijklmnopqrstuvwxyz '
        film_name_length = self._random.randint(5, 15)
        return ''.join(self._random.choices(alphabet, k=film_name_length))
