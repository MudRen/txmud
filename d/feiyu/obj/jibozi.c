inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("¼¦²±×Ó", ({ "ji bozi" }) );
        set_weight(500);
        if( clonep() )  
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿éÏãÅçÅç¼¦²±×Ó¡£\n");
                set("unit", "¿é");
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}

