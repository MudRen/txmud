// dami.c

inherit ITEM;

void create()
{
        set_name("����", ({ "da mi"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������һ������.\n");
                set("value", 8000);
        }
}
