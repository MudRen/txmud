inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("¿¾Å£Èâ", ({ "kao niurou", "niurou" , "meat" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»ÅÌÏãÅçÅçµÄ¿¾Å£Èâ¡£\n");
                set("unit", "ÅÌ");
                set("value", 300);
                set("food_remaining", 4);
                set("food_supply", 30);
                set("material", "food");
        }
        setup();
}
