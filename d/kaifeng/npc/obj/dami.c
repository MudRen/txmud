// dami.c

inherit ITEM;

void create()
{
        set_name("大米", ({ "da mi"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "袋");
                set("long", "沉甸甸的一袋大米.\n");
                set("value", 8000);
        }
}
