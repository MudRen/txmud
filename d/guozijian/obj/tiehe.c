//	tiehe����

inherit ITEM;
void create()
{
        set_name( "����",({ "tiehe" }) );
        set_weight(420);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "����һ���ƾɵ����У�������һ������������һ������\n");
                set("value",20);
        }
//        setup();
}


void init()
{
	add_action("do_insert","insert");
}

int do_insert(string arg)
{
	object key_ob,me,*inv,book,box_ob;
	int i,key_ok;
	string key,box;
	if(!arg) return notify_fail("��Ҫ��ʲô��\n");
        sscanf(arg,"%s into %s",key,box);
	if( key != "key" && key != "Կ��")
	   return notify_fail("�����������Ų���ȥ��\n");
	if( box != "tiehe" && box != "����")
	   return notify_fail("��Ҫ������ţ�\n");

	me=this_player();
	inv = all_inventory(me);
	key_ok = 0;
        if( sizeof(inv) ) {
  	  for(i=0; i<sizeof(inv); i++){
		if((inv[i]->query("id")=="key") && !userp(inv[i])) {
		  key_ob = inv[i];
		  key_ok = 1;
		}
	  }
	}
	if( key_ok != 1) 
	  return notify_fail("�����û��Կ�װ�!\n");
	message_vision("$N��С���Ӵ򿪣�һ��С��ȴ�����л���������\n",me);
	box_ob = new(__DIR__"tiehe1");
	box_ob->move(environment(me));
	destruct(key_ob);
	destruct(this_object());
	return 1;
}