// parrybook.c

inherit ITEM;

void create()
{
        set_name("���м����š�", ({"parry book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("unit", "��");
		set("long", "�������м����š�\n");
		set("value", 2500);
		set("material", "paper");
		set("skill", ([
			"name": "parry",
                        "exp_required": 5000,
			"sen_cost": 20,
			"difficulty": 30,
			"max_skill": 45,
		]) );
	}
}