inherit ITEM;
void create()
{
        set_name("ľͷ", ({ "mu tou" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ľͷ��\n");
                set("value", 5000);
        }
}

