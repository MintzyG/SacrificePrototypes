#include "cards.hpp"

const char* StringPlusType(PlusType pt) {
	switch (pt) {
	case EmptyPT:
		return "EmptyPT ";
		break;
	case OnePT:
		return "Plus one";
		break;
	case TwoPT:
		return "Plus two";
		break;
	case FourPT:
		return "Plus four";
		break;
	case TwentyPT:
		return "Plus twenty";
		break;
	case SizePT:
		return "PT size Error ";
		break;
	default:
		return "Default Error PT ";
		break;
	}
}

const char* StringColor(Color c) {
	switch (c) {
	case EmptyC:
		return "EmptyC ";
		break;
	case Blue:
		return "Blue ";
		break;
	case Green:
		return "Green ";
		break;
	case Red:
		return "Red ";
		break;
	case Yellow:
		return "Yellow ";
		break;
	case Black:
		return "";
		break;
	case SizeC:
		return "C Size Error ";
		break;
	default:
		return "Default Error C ";
		break;
	}
}

const char* StringSpecial(SpecialType st) {
	switch (st) {
	case EmptyST:
		return "EmptyST ";
		break;
	case Joker:
		return "Joker";
		break;
	case DefenseRune:
		return "Defense Rune";
		break;
	case PovertyRune:
		return "Poverty Rune";
		break;
	case BanishmentRune:
		return "Banishment Rune";
		break;
	case SizeST:
		return "ST Size Error ";
		break;
	default:
		return "Default Error ST ";	
		break;
	}
}

const char* StringType(Type t) {
	switch (t)
	{
	case EmptyT:
		return "EmptyT ";
		break;
	case Block:
		return "block";
		break;
	case Reverse:
		return "reverse";
		break;
	case SizeT:
		return "T Size Error ";
		break;
	default:
		return "Default Error T ";
		break;
	}
}