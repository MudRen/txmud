// yujin.c

inherit ITEM;

void create()
{
        set_name("郁金", ({ "yu jin"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "株");
                set("long", 
"一株普通的郁金,郁金的性味辛苦寒,用于行气解郁。\n");
        }
}
