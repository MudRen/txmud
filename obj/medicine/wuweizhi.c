// wuweizhi.c

inherit ITEM;

void create()
{
        set_name("五味子", ({ "wu weizhi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "粒");
                set("long", 
"一粒普通的五味子,五味子的性味酸碱温,用于敛肺滋肾。\n");
        }
}
