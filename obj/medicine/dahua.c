// dahuang.c

inherit ITEM;

void create()
{
        set_name("大黄", ({ "da huang"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "株");
                set("long", 
"一株普通的大黄,大黄的性味苦寒,用于泻热通便。\n");
        }
}
