#include <gtest/gtest.h>
#include "card.hpp"
#include "Includes/card.hpp"

Card::Card() 
  : m_number(0)/*, m_type(NUMBER), m_color(RED)*/
{
}

int Card::card_sum(int x, int y) {
  return x + y;
}

void Card::set_number(int x) {
  m_number = x;
}

int Card::get_number() const {
  return m_number;
}

/* CARD TESTS */

TEST(CardTest, SumTest) {
    Card card;
    EXPECT_EQ(card.card_sum(2, 3), 5);
    EXPECT_EQ(card.card_sum(-1, 1), 0);
}

TEST(CardTest, SetAndGetNumberTest) {
    Card card;
    card.set_number(10);
    EXPECT_EQ(card.get_number(), 10);
}

