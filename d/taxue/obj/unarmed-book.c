// unarmed_book.c
// by dicky

inherit ITEM;
void create()
{
    set_name("扑击格斗之技", ({ "unarmed book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","封面上写著「扑击格斗之技 」，书角印有「踏雪山庄」的标志！\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"party":        "taxue",
			"name":     "unarmed",
			"exp_required":	10000,
			"sen_cost":	15,
			"difficulty":	22,
			"min_skill":    30,
			"max_skill":	100,		
		]) );
	}
}