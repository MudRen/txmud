// dasuan.c

inherit ITEM;

void create()
{
        set_name("大蒜", ({ "da suan"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "颗");
                set("long", 
"一颗普通的大蒜,大蒜的性味辛温,用于消毒杀菌。\n");
        }
}
