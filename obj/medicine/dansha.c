// dasha.c

inherit ITEM;

void create()
{
        set_name("丹砂", ({ "dan sha"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "粒");
                set("long", 
"一粒普通的丹砂,丹砂的性味甘微寒,用于安神，定精。解毒。\n");
        }
}
