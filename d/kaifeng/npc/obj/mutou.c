inherit ITEM;
void create()
{
        set_name("木头", ({ "mu tou" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根木头。\n");
                set("value", 5000);
        }
}

