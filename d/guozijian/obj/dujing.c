// du jing book

inherit ITEM;

void create()
{
	set_name("毒经", ({ "dujing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这是一本用毒的入门书。\n");
           set("value", 100);
            set("material", "");
		set("skill", ([
			"name":	" dujing",	// name of the skill
                   "exp_required": 100,  // minimum combat experience required
                  "jing_cost":  20,   // jing cost every time study this
                   "difficulty": 20,     // the base int to learn this skill
                   "max_skill":   50,  // the maximum level you can learn
		]) );
	}
}
