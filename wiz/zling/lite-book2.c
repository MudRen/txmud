// literate_book.c
// by dicky

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"��������"NOR, ({ "tianxia lunyu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","������д�����������\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name":     "literate",
			"exp_required":	100,
			"gin_cost":	20,
			"difficulty":	22,
			"max_skill":	71,
			"min_skill":    30,		
		]) );
	}
}

int is_taxue_book() { return 1; }