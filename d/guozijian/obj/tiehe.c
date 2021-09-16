//	tiehe铁盒

inherit ITEM;
void create()
{
        set_name( "铁盒",({ "tiehe" }) );
        set_weight(420);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long", "这是一口破旧的铁盒，上面有一个洞，好象是一把锁。\n");
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
	if(!arg) return notify_fail("你要干什么？\n");
        sscanf(arg,"%s into %s",key,box);
	if( key != "key" && key != "钥匙")
	   return notify_fail("这个东西好象放不进去。\n");
	if( box != "tiehe" && box != "铁盒")
	   return notify_fail("你要往那里放？\n");

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
	  return notify_fail("你好象没有钥匙啊!\n");
	message_vision("$N将小盒子打开，一不小心却从手中滑落下来。\n",me);
	box_ob = new(__DIR__"tiehe1");
	box_ob->move(environment(me));
	destruct(key_ob);
	destruct(this_object());
	return 1;
}