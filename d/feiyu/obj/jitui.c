inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("º¶Õ»", ({ "ji tui" }) );
        set_weight(1200);
        if( clonep() )  
                set_default_object(__FILE__);
        else {
                set("long", "“ªøÈœ„≈Á≈Áº¶¥ÛÕ»°£\n");
                set("unit", "øÈ");
                set("food_remaining", 4);
                set("food_supply", 25);
        }
}
