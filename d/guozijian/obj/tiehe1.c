//	tiehe1打开的铁盒

inherit ITEM;
void create()
{
	object book;
        set_name( "铁盒",({ "tiehe" }) );
        set_weight(420);
    set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long", "这是一口破旧的铁盒，盖子已经被打开。\n");
                set("value",20);
        }
	book = new(__DIR__"dujing");
	book->move(this_object());
//        setup();
}
int is_container() { return 1; }