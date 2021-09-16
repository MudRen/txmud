// mine_d.c

#define MINE_DIR	"/obj/mine/"

#include <mine_def.h>

string *valid_mine_classes = ({
	IRON_MINE,
});


int is_valid_mclass(string cs)
{
	if(!stringp(cs) || (member_array(cs, valid_mine_classes) == -1))
		return 0;

	return 1;
}

string chinese_mine_class(string cs)
{
	switch (cs)
	{
		case IRON_MINE:
		case IRON_RES_CU:
			return "´ÖÌú";
		case IRON_RES_JING:
			return "¾«Ìú";
		case STEEL_RES:
			return "¸Ö";
		case BLACK_IRON:
			return "ÐþÌú";
		default:
			return 0;
	}
}

int query_mine_class_value(string cs)
{
	switch (cs)
	{
		case IRON_RES_CU:
			return 5;
		case IRON_RES_JING:
			return 20;
		case STEEL_RES:
			return 70;
		case BLACK_IRON:
			return 100;
		default:
			return 0;
	}
}

object query_mine_class_up_ob(string cs)
{
	switch (cs)
	{
		case IRON_MINE:		// Ìú¿ó -> ´ÖÌú
			return new(MINE_DIR"iron_cu");
		case IRON_RES_CU:	// ´ÖÌú -> ¾«Ìú
			return new(MINE_DIR"iron_jing");
		case IRON_RES_JING:	// ¾«Ìú -> ¸Ö
			return new(MINE_DIR"iron_steel");
		case BLACK_IRON:
			return new(MINE_DIR"black_iron");
		default:
			return 0;
	}
}

int query_mine_class_up_quantity(string cs)
{
	switch (cs)
	{
		case IRON_RES_CU:	// ´ÖÌú -> ¾«Ìú
			return 3;
		case IRON_RES_JING:	// ¾«Ìú -> ¸Ö
			return 3;
		default:
			return 0;
	}
}
