//	key���е�Կ��

inherit ITEM;
void create()
{
        set_name( "Կ��",({ "key" }) );
	set("ok","��");
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "����һ��ͭɫ��Կ�ף�����֪��ʲô�ط���Կ�ס�\n");
                set("value",20);
        }
        setup();
}
