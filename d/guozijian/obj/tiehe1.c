//	tiehe1�򿪵�����

inherit ITEM;
void create()
{
	object book;
        set_name( "����",({ "tiehe" }) );
        set_weight(420);
    set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "����һ���ƾɵ����У������Ѿ����򿪡�\n");
                set("value",20);
        }
	book = new(__DIR__"dujing");
	book->move(this_object());
//        setup();
}
int is_container() { return 1; }