inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("牛肉包子", ({ "niurou baozi"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个热腾腾的牛肉包子。\n");
                set("unit", "个");
                set("value", 300);
                set("food_remaining", 8);
                set("food_supply", 3);
                set("material", "food");
        }
        setup();
}
