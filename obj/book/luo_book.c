
// luo_book.c

inherit ITEM;

void create()
{
        set_name("ー代慕―", ({"luo book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "過");
                set("long", "ー代慕―\n");
                set("value", 1000);
        set("material", "paper");
        set("skill", ([
                        "name": "literate",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 30,
			"max_skill": 30,
		]) );
        }
}