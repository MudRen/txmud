// dazao.c

inherit ITEM;

void create()
{
        set_name("大枣", ({ "da zao"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "粒");
                set("long", 
"一粒普通的大枣,大枣的性味甘平,用于和胃健脾,益气生精。\n");
        }
}
