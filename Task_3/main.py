import sys
from traceback import format_exc

from libfilm.container import Container
from libfilm.film_generator import FilmGenerator
from libfilm.film_reader import FilmReader, MalformedInput
from libfilm.film_printer import FilmPrinter


MAX_ELEMENTS_IN_CONTAINER = 10**4


def fatal_error(error_message):
    sys.stderr.write(error_message + '\n')
    sys.exit(1)


def print_usage(application_name: str):
    sys.stdout.write(f"{application_name} [-n <number_of_elements>] <input_file> <output_file>\n");


def read_container(input_filename: str) -> Container:
    container = Container()
    try:
        film_reader = FilmReader(input_filename)
        films_count = film_reader.read_films_count()
        for _ in range(films_count):
            film = film_reader.read_film()
            print(f"read film: name={film.name} year={film.release_year}")
            container.append_film(film)
        return container
    except MalformedInput as e:
        fatal_error("Malformed input")


def generate_container(random_seed: int, films_count: int):
    film_generator = FilmGenerator(random_seed)
    container = Container()
    for _ in range(films_count):
        container.append_film(film_generator.generate_film())
    return container


def print_container(container: Container, output_filename):
    film_printer = FilmPrinter(output_filename)
    film_printer.print_container_size(len(container))
    for index in range(len(container)):
        film_printer.print(container[index])


def main():
    if len(sys.argv) == 3:
        input_filename = sys.argv[1]
        output_filename = sys.argv[2]
        container = read_container(input_filename)
    elif len(sys.argv) == 5:
        if sys.argv[1] != "-n":
            print_usage(sys.argv[0])
            return 1
        input_filename = sys.argv[3]
        output_filename = sys.argv[4]

        try:
            films_count = int(sys.argv[2])
            if films_count <= 0:
                raise MalformedInput("Negative films count")
        except Exception as e:
            print_usage(sys.argv[0])
            fatal_error("films count must be positive")

        try:
            random_seed = int(open(input_filename, 'r').readline()[:-1])
            if random_seed < 0:
                raise MalformedInput("Random seed is negative")
        except Exception as e:
            fatal_error("Malformed input")

        container = generate_container(random_seed, films_count)
    else:
        print_usage(sys.argv[0])
        return 1

    container.sort_with_selection_sort()
    print_container(container, output_filename)

if __name__ == "__main__":
    exit(main())
