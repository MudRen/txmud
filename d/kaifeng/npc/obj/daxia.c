inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("¥Ûœ∫", ({ "da xia"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "“ª≈Ã”Õ√∆¥Ûœ∫°£\n");
                set("unit", "≈Ã");
                set("value", 5000);
                set("food_remaining", 9);
                set("food_supply", 4);
                set("material", "food");
        }
        setup();
}
