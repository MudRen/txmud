// huangya.c

inherit ITEM;

void create()
{
        set_name("蒙顶黄芽茶", ({ "md huang ya" }) );
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "包");
                set("long", "这是一小包茶叶。\n");
                set("value", 3000);
                set("material", "leaf");
        }
        setup();
}
