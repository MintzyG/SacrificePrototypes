#pragma once

enum Type {
  NUMBER = 0,
  REVERSE,
  BLOCK,
  PLUS,
  T_NULL
};

enum Color {
  RED = 0,
  GREEN,
  BLUE,
  YELLOW,
  WHITE,
  BLACK,
  C_NULL
};

class Card {
private:
  Type m_type;
  Color m_color;
  int m_number;
public:
  int card_sum(int, int);
  int get_number() const;
  void set_number(int);
  Card();
};
