// renshen.c

inherit ITEM;

void create()
{
        set_name("�˲�", ({ "ren shen"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "֦");
                set("long", "һ֦��ͨ���˲Ρ�\n");
        }
}

