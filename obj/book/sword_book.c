// sword_book.c

inherit ITEM;

void create()
{
	set_name("°ºΩ£ ı«ø…Ì°Ω", ({"sword book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "≤·");
		set("value", 3000);
		set("material", "paper");
		set("skill", ([
                        "name": "sword",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 30,
			"max_skill": 50,
		]) );
        }
}
