//	key铁盒的钥匙

inherit ITEM;
void create()
{
        set_name( "钥匙",({ "key" }) );
	set("ok","真");
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("long", "这是一把铜色的钥匙，但不知是什么地方的钥匙。\n");
                set("value",20);
        }
        setup();
}
