// renshen.c

inherit ITEM;

void create()
{
        set_name("人参", ({ "ren shen"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "枝");
                set("long", "一枝普通的人参。\n");
        }
}

