#include <vector>
#include <memory>

#include "libfilm/film.hpp"

class Container {
public:
    static constexpr size_t kMaxElementsInContainer = 10000;

    Container() = default;

    void Add(std::unique_ptr<Film>&& film);

    void SelectionSort();

    friend std::istream& operator>>(std::istream& input_stream, Container& container);
    friend std::ostream& operator<<(std::ostream& output_stream, const Container& container);

private:
    std::vector<std::unique_ptr<Film>> m_films;
};
