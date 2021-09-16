inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("茶碗", ({ "da wancha" , "tea"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一只大茶碗。\n");
                set("unit", "只");
                set("value", 50);
                set("max_liquid", 5);
		set("material","glass");
        }

        set("liquid", ([
                "name": "茶水",
                "remaining": 5,
		"drunk_apply": 10,
        ]) );
}

