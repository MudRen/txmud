// wujiapi.c

inherit ITEM;

void create()
{
        set_name("五加皮", ({ "wu jiapi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "片");
                set("long", 
"一片普通的五加皮,五加皮的性味辛苦温,用于去风化湿,强筋通络。\n");
        }
}
