// f_fan.c

inherit ITEM;

void create()
{
        set_name("折扇", ({"folding fan","fan"}));
        set("long", "这是一把丝绸折扇。\n");
        set("unit", "把");
        set("weight", 800);
        set("value", 100);
}