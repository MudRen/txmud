// heshouwu.c

inherit ITEM;

void create()
{
        set_name("何首乌", ({ "he shou wu"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "株");
                set("long", 
"一株普通的何首乌,何首乌的性味苦甘,用于补益心脾。\n");
        }
}
