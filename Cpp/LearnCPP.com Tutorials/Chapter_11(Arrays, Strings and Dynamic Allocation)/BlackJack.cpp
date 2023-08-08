#include <array>
#include <iostream>
#include <numeric> // std::reduce
#include <cassert>
#include <algorithm> // for std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt19937

enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};
enum class CardRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};

struct Card
{
    CardRank rank{};
    CardSuit suit{};
};

using Deck = std::array<Card, 52>;
using Index = Deck::size_type;



void printCard(const Card& card)
{
    switch (card.rank)
    {
    case CardRank::rank_2:      std::cout << '2';   break;
    case CardRank::rank_3:      std::cout << '3';   break;
    case CardRank::rank_4:      std::cout << '4';   break;
    case CardRank::rank_5:      std::cout << '5';   break;
    case CardRank::rank_6:      std::cout << '6';   break;
    case CardRank::rank_7:      std::cout << '7';   break;
    case CardRank::rank_8:      std::cout << '8';   break;
    case CardRank::rank_9:      std::cout << '9';   break;
    case CardRank::rank_10:     std::cout << 'T';   break;
    case CardRank::rank_jack:   std::cout << 'J';   break;
    case CardRank::rank_queen:  std::cout << 'Q';   break;
    case CardRank::rank_king:   std::cout << 'K';   break;
    case CardRank::rank_ace:    std::cout << 'A';   break;
    default:
        std::cout << '?';
        break;
    }

    switch (card.suit)
    {
    case CardSuit::club:       std::cout << 'C';   break;
    case CardSuit::diamond:    std::cout << 'D';   break;
    case CardSuit::heart:      std::cout << 'H';   break;
    case CardSuit::spade:      std::cout << 'S';   break;
    default:
        std::cout << '?';
        break;
    }
}


std::array<Card, 52> createDeck()
{
    std::array<Card, 52> deck{};
    long unsigned int currentCard{0};


    for (int rank = 0; rank < static_cast<int>(CardRank::max_ranks); rank++)//picks rank
    {
        for (int suit = 0; suit < static_cast<int>(CardSuit::max_suits); suit++)//assigns each suit to the rank
        {
            deck[currentCard].suit = static_cast<CardSuit>(suit);
            deck[currentCard].rank = static_cast<CardRank>(rank);

            currentCard++;
        }
            
    }

    return deck;
}

void printDeck(const std::array<Card, 52>& deck)
{
    for (long unsigned int i = 0; i < 52; i++)
    {
        printCard(deck[i]);
        std::cout << ' ';
    }
    
    std::cout << '\n';
}


void shuffleDeck(Deck& deck)
{
  // mt is static so it only gets seeded once.
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

  std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& card)
{
  switch (card.rank)
  {
  case CardRank::rank_2:        return 2;
  case CardRank::rank_3:        return 3;
  case CardRank::rank_4:        return 4;
  case CardRank::rank_5:        return 5;
  case CardRank::rank_6:        return 6;
  case CardRank::rank_7:        return 7;
  case CardRank::rank_8:        return 8;
  case CardRank::rank_9:        return 9;
  case CardRank::rank_10:       return 10;
  case CardRank::rank_jack:     return 10;
  case CardRank::rank_queen:    return 10;
  case CardRank::rank_king:     return 10;
  case CardRank::rank_ace:      return 11;
  default:
    assert(false && "should never happen");
    return 0;
  }
}

void addCardToHand(std::vector<Card> &hand, Card cardToAdd)
{
    hand.resize(hand.size() + 1);
    hand[hand.size() - 1] = cardToAdd;
}

int getScore(std::vector<Card> hand)
{
    int score{0};

    for (long unsigned int i = 0; i < hand.size(); i++)
    {
        score = score + getCardValue(hand[i]);
    }
    
    return score;

}

Card pullCardFromTop(std::array<Card, 52>& deck)
{
    static long unsigned int topCardIndex = 0;
    topCardIndex++;
    return deck[topCardIndex];
    
}

void printHand(std::vector<Card> hand)
{
    for (long unsigned int i = 0; i < hand.size(); i++)
    {
        printCard(hand[i]);
        std::cout << ' ';
    }
    std::cout << '\n';

}

void printTableState(std::vector<Card> player, std::vector<Card> dealer)
{
    std::cout << "===========================\n";
    std::cout << "The dealer has: ";
    printHand(dealer);

    std::cout << "You have: ";
    printHand(player);
    std::cout << "===========================\n";
}


bool playBlackjack(std::array<Card, 52>& deck)
{

    //initializing values
    std::vector<Card> dealers_hand(0);
    std::vector<Card> players_hand(0);

    //deal one card to player and dealer
    addCardToHand(dealers_hand, pullCardFromTop(deck));
    addCardToHand(players_hand, pullCardFromTop(deck));

    //let player hit or stand
    std::string playerChoice{};
    do
    {

        addCardToHand(players_hand, pullCardFromTop(deck));
        printTableState(players_hand, dealers_hand);
        
        if (getScore(players_hand) > 21)
        {
            std::cout << "You've lost \n";
            return false;
        }
        
        std::cout << "Hit or Stand? ";
        std::cin >> playerChoice;
    }
    while(playerChoice == "hit");


    //dealer then plays
    std::cout << "--Dealers Turn To Draw--\n";
    while(getScore(dealers_hand) <= 17)
    {
        addCardToHand(dealers_hand, pullCardFromTop(deck));
        printTableState(players_hand, dealers_hand);

        if (getScore(dealers_hand) > 21)
        {
            std::cout << "Dealer Bust, You've Won \n";
            return true;
        }
    }


    //since the game will automatically end when the player goes over 21 this will return the winner
    if (getScore(players_hand) > getScore(dealers_hand))
    {
        std::cout << "You've Won \n";
        return true;
    }
    else
    {
        std::cout << "You've lost \n";
        return false;
    }
    
}


int main()
{
    std::array<Card, 52> deck{ createDeck() };

    printDeck(deck);

    shuffleDeck(deck);

    printDeck(deck);

    playBlackjack(deck);





    return 0;
}