// rotten_dan.c

inherit ITEM;

void create()
{
        set_name("腐烂的蛇胆", ({"rotten dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这个蛇胆已经腐烂了，散发着恶臭。\n");
                set("value", 0);
        }
        setup();
}
