//tianxianteng.c

inherit ITEM;

void create()
{
        set_name("天仙藤", ({ "tian xianteng"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "粒");
                set("long", 
"一粒普通的天仙藤,天仙藤的性味苦温,用于强筋骨，去风湿。\n");
        }
}
