// table.c

inherit ITEM;

void create()
{
        set_name("大木桌", ({ "wooden table"}) );

        set_weight(5000000);
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
这是一张很大的木桌。
LONG
                );
                set("value", 1);
        }
}

int is_container()
{
        return 1;
}

