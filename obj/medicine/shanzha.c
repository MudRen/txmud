//shanzha.c

inherit ITEM;

void create()
{
        set_name("山楂", ({ "shan zha"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "粒");
                set("long", 
"一粒普通的山楂,山楂的性味酸干温,用于破气行淤，消积化滞。\n");
        }
}
