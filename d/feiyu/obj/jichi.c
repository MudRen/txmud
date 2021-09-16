inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("º¶≥·", ({ "ji chi" }) );
        set_weight(1000);
        if( clonep() )  
                set_default_object(__FILE__);
        else {
                set("long", "“ªøÈœ„≈Á≈Áº¶≥·∞Ú°£\n");
                set("unit", "øÈ");
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}

