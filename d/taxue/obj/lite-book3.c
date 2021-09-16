// literate_book.c
// by dicky

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"孙子兵法"NOR, ({ "sunzi bingfa", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","封面上写著「孙子兵法」，书角印有「踏雪山庄」的标志！\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"party":        "taxue",
			"name":     "literate",
			"exp_required":	100000,
			"gin_cost":	20,
			"difficulty":	25,
			"max_skill":	120,
			"min_skill":    70,		
		]) );
	}
}