// baiguo.c

inherit ITEM;

void create()
{
        set_name("白果", ({ "bai guo"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "粒");
                set("long", 
"一粒普通的白果,白果的性味甘苦涩平,用于润肺补虚，消痰下气。\n");
        }
}
