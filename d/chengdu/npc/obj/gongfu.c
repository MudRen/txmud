// gongfu.c

inherit ITEM;

void create()
{
        set_name("福建功夫茶", ({ "gong fu cha" }) );
        set_weight(100);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "包");
                set("long", "这是一小包茶叶。\n");
                set("value", 2500);
                set("material", "leaf");
        }
        setup();
}

