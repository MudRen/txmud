inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("����", ({ "da wancha" , "tea"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻ����롣\n");
                set("unit", "ֻ");
                set("value", 50);
                set("max_liquid", 5);
		set("material","glass");
        }

        set("liquid", ([
                "name": "��ˮ",
                "remaining": 5,
		"drunk_apply": 10,
        ]) );
}

