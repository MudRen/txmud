inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("韭菜包子", ({ "jiucai baozi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个热腾腾的韭菜包子。\n");
                set("unit", "个");
                set("value", 100);
                set("food_remaining", 4);
                set("food_supply", 3);
                set("material", "food");
        }
        setup();
}
