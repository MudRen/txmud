// longyan.c

inherit ITEM;

void create()
{
        set_name("龙眼", ({ "long yan"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "粒");
                set("long", 
"一粒普通的龙眼,龙眼的性味甘平,用于补益心脾，养血安神。\n");
        }
}
