//shengjiang.c

inherit ITEM;

void create()
{
        set_name("生姜", ({ "sheng jiang"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "块");
                set("long", 
"一块普通的生姜，生姜的性味辛微温，用于发汗解表，温中止呕。\n");
        }
}
