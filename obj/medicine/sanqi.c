// sanqi.c

inherit ITEM;

void create()
{
        set_name("三七", ({ "san qi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "株");
                set("long", 
"一株普通的三七,三七的性味甘微苦温,用于止血化淤，消肿定痛。\n");
        }
}
