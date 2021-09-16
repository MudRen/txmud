// literate_book.c
// by dicky

inherit ITEM;
void create()
{
    set_name("三字经", ({ "sanzi jing", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","封面上写著「三字经」。\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name":     "literate",
			"exp_required":	100,
			"gin_cost":	20,
			"difficulty":	20,
			"max_skill":	31,		
		]) );
	}
}