// bupi.c
// by dicky

inherit ITEM;

void create()
{
        set_name("布匹", ({ "bu pi"}) );
	set("long", "这是一块非常结实的布匹。\n");
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
        }
        setup();
}

