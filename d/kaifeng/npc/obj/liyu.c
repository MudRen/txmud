inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("∫Ï…’¿”„", ({ "hongshao liyu"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "“ª≈Ã∫Ï…’¿”„°£\n");
                set("unit", "≈Ã");
                set("value", 3000);
                set("food_remaining", 5);
                set("food_supply", 3);
                set("material", "food");
        }
        setup();
}
