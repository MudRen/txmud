//peking_duck.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("北京烤鸭", ({ "peking duck" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一整只的北京烤鸭，肥得流油，皮酥肉嫩，让你恨不得一口吞下去。\n");
                set("unit", "只");
                set("value", 1000);
                set("food_remaining", 8);
                set("food_supply", 100);
        }
        setup();
}

