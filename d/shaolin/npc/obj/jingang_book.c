// jingang_book.c

inherit ITEM;

void create()
{
	set_name("《金刚不坏神功入门》", ({ "jingang book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long","蓝色的封面上写着金刚不坏神功入门。\n");
		set("material", "paper");
		set("skill", ([
			"name":		"jingang",
			"exp_required":	5000,
			"sen_cost":	25,
			"difficulty":	25,
			"max_skill":	40,
		]) );
	}
}

int is_shaolin_book() { return 1; }
