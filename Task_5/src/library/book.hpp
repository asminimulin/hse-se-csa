#pragma once

#include <string>

class Book {
 public:
  Book(std::string author, std::string title): m_author(std::move(author)), m_title(std::move(title)) {}

  const std::string& GetAuthor() {
    return m_author;
  }

  const std::string& GetTitle() {
    return m_title;
  }

 private:
  std::string m_author;
  std::string m_title;
};