// desk.c

inherit ITEM;

void create()
{
        set_name("书桌", ({ "desk"}) );

        set_max_encumbrance(800000);

        set("no_get", 1);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("position", "on");
                set("prep", "on");
                set("unit", "张");
                set("long", @LONG
这就是不好的书桌，书桌玻璃案子底下压着一份《工作室说明》，
桌上摆着一些纸笔字典之类的基本用具，还有一个玻璃杯。
LONG
                );
                set("value", 1);
        }
}

int is_container()
{
        return 1;
}

